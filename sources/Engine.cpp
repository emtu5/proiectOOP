//
// Created by Paul on 11/03/2023.
//

#include "../headers/Engine.h"

Engine::Engine(sf::Vector2i res) : currentLevel{"resources/level1.txt"}, heldPiece(nullptr) {
    videoMode.width = res.x;
    videoMode.height = res.y;
    window.create(videoMode, "Temple Stones v0.6", sf::Style::Close);
}

void Engine::run() {
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
    window.draw(currentLevel.getCurrentBoard());
    for (auto &piece : currentLevel.getPieceInventory()) {
        window.draw(piece);
    }
    window.display();
}

void Engine::leftClick() {
    //If we don't hold a piece
    if (heldPiece == nullptr) {
        //Grab the Piece
        auto &inv = currentLevel.getPieceInventory();
        for (auto ptr = inv.rbegin(); ptr < inv.rend(); ++ptr) {
            if (ptr->isClicked(sf::Mouse::getPosition(window))) {
                heldPiece = &(*ptr);
                heldPiece->updatePosition(sf::Mouse::getPosition(window));
                break;
            }
        }
        //Remove the Piece if it was on the board
        if (heldPiece != nullptr) {
            auto charToRemove = heldPiece->getId();
            currentLevel.getCurrentBoard().removePiece(charToRemove);
        }
    }
    else {
        //Try to place it
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (currentLevel.getCurrentBoard().placePiece(*heldPiece, mousePos)) {
            std::cout << "wow piece has been placed";
        }
        heldPiece = nullptr;
    }
}

Engine::~Engine() = default;
