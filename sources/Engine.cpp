//
// Created by Paul on 11/03/2023.
//

#include "../headers/Engine.h"

#include <fstream>

Engine::Engine(sf::Vector2i res) : currentLevelNumber(STARTING_LEVEL), totalLevelCount(TOTAL_LEVELS) {
    Textures::loadTextures();

    try {
        std::ifstream fin("resources/totallevels.txt");
        if (!fin) {
            throw FileNotFound("resources/totallevels.txt");
        }
        fin >> totalLevelCount;
    } catch (FileNotFound &err) {
        std::cout << err.what() << '\n';
        std::ofstream fout("resources/totallevels.txt");
        fout << totalLevelCount;
    }

    try {
        std::ifstream fin("resources/latestlevel.txt");
        if (!fin) {
            throw FileNotFound("resources/latestlevel.txt");
        }
        fin >> currentLevelNumber;
    } catch (FileNotFound &err) {
        std::cout << err.what() << '\n';
        std::ofstream fout("resources/latestlevel.txt");
        fout << currentLevelNumber;
    }

    try {
        if (!gameFont.loadFromFile("resources/trajanus.ttf")) {
            throw FileNotFound("resources/trajanus.ttf");
        }
    } catch (FileNotFound &err) {
        std::cout << err.what() << '\n';
    }

    LevelList::loadLevels(totalLevelCount);
    videoMode.width = res.x;
    videoMode.height = res.y;
    window.create(videoMode, "Temple Stones v1.8.0", sf::Style::Close);
}

void Engine::run() {
    loadLevel(currentLevelNumber);
    while(window.isOpen()) {
        input();
        draw();
    }
}

void Engine::input() {
    sf::Event ev{};
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
        if (ev.type == sf::Event::MouseButtonReleased) {
            if (ev.mouseButton.button == sf::Mouse::Left) {
                if (hasFinishedLevel) {
                    hasFinishedLevel = false;
                    goToNextLevel();
                }
                else {
                    leftClick();
                }
            }
            if(ev.mouseButton.button == sf::Mouse::Right && heldPiece != nullptr) {
                heldPiece->rotatePiece();
            }
            if(ev.mouseButton.button == sf::Mouse::Middle && heldPiece != nullptr) {
                heldPiece->flipPiece();
            }
        }
        if(ev.type == sf::Event::MouseMoved && heldPiece != nullptr) {
            heldPiece->updatePosition(sf::Mouse::getPosition(window));
        }
    }
}

void Engine::draw() {
    window.clear(sf::Color::Black);
    window.draw(*currentBoard);
    for (auto &piece : currentPieceInventory) {
        window.draw(*piece);
    }

    Utils::drawLevelMessage(window, gameFont, currentLevelNumber, currentBoard);

    if (hasFinishedLevel) {
        Utils::drawLevelComplete(window, gameFont);
    }
    window.display();
}

void Engine::leftClick() {
    //If we don't hold a piece
    if (heldPiece == nullptr) {
        //Grab the Piece
        auto &inv = currentPieceInventory;
        for (auto it = inv.rbegin(); it < inv.rend(); ++it) {
            if ((*it)->isClicked(sf::Mouse::getPosition(window))) {
                heldPiece = *it;
                heldPiece->updatePosition(sf::Mouse::getPosition(window));

                // move the held piece to the very front
                auto x = std::move(*it);
                currentPieceInventory.erase(std::next(it).base()); // convert reverse iterator to iterator, black magic
                currentPieceInventory.emplace_back(std::move(x));

                break;
            }
        }
        //Remove the Piece if it was on the board
        if (heldPiece != nullptr) {
            auto charToRemove = heldPiece->getId();
            currentBoard->removePiece(charToRemove);
        }
    }
    else {
        //Try to place it
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (currentBoard->placePiece(*heldPiece, mousePos)) {
            // move the placed piece to the very back
            auto it = std::find(currentPieceInventory.begin(), currentPieceInventory.end(), heldPiece);
            auto x = std::move(*it);
            currentPieceInventory.erase(it);
            currentPieceInventory.insert(currentPieceInventory.begin(), std::move(x));

            if (currentBoard->checkWinCondition()) {
                hasFinishedLevel = true;
            }
        }
        heldPiece = nullptr;
    }
}

Engine &Engine::get_engine(sf::Vector2i res) {
    static Engine engine{res};
    return engine;
}

void Engine::loadLevel(int levelNum) {
    currentLevel = LevelList::getLevel(levelNum);
    currentPieceInventory.clear();
    for (auto &p : currentLevel.getPieceInventory()) {
        currentPieceInventory.emplace_back(std::make_shared<Piece>(p));
    }
    currentBoard = currentLevel.getCurrentBoard()->clone();
}

void Engine::goToNextLevel() {
    hasFinishedLevel = false;
    while (true) {
        try {
            currentLevelNumber = currentLevelNumber < totalLevelCount ? currentLevelNumber + 1 : 1;
            std::ofstream fout("resources/latestlevel.txt");
            fout << currentLevelNumber;
            loadLevel(currentLevelNumber);
            break;
        } catch (BadLevelID &err) {
            std::cout << err.what() << '\n';
        }
    }
}

Engine::~Engine() = default;
