//
// Created by Paul on 11/03/2023.
//

#include "../headers/Engine.h"

Engine::Engine(sf::Vector2i res)  {
    Textures::loadTextures();
    currentLevel = Level{"resources/level1.txt"};
    heldPiece = nullptr;
    videoMode.width = res.x;
    videoMode.height = res.y;
    window.create(videoMode, "Temple Stones v1.1.0", sf::Style::Close);
}

void Engine::run() {
    currentPieceInventory = currentLevel.getPieceInventory();
    currentBoard = std::make_shared<Board>(*currentLevel.getCurrentBoard());
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
                leftClick();
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

            std::cout << "wow piece has been placed";
        }
        heldPiece = nullptr;
    }
}

Engine &Engine::get_engine(sf::Vector2i res) {
    static Engine engine{res};
    return engine;
}

Engine::~Engine() = default;
