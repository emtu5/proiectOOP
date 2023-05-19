//
// Created by Paul on 11/03/2023.
//

#ifndef OOP_ENGINE_H
#define OOP_ENGINE_H

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Board.h"
#include "Level.h"
#include <iostream>
#include <memory>

class Engine {
private:
    Level currentLevel;
    std::shared_ptr<Board> currentBoard;
    std::vector<std::shared_ptr<Piece>> currentPieceInventory;
    std::shared_ptr<Piece> heldPiece;
    sf::RenderWindow window;
    sf::VideoMode videoMode;

    // Singleton
    explicit Engine(sf::Vector2i res);

public:
    Engine(const Engine &) = delete;
    Engine &operator= (const Engine &) = delete;
    static Engine& get_engine(sf::Vector2i);

    void run();
    void input();
    void draw();
    void leftClick();
    ~Engine();
};


#endif //OOP_ENGINE_H
