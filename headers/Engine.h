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
    Piece* heldPiece;
    sf::RenderWindow window;
    sf::VideoMode videoMode;
public:
    explicit Engine(sf::Vector2i res);
    void run();
    void input();
    void draw();
    void leftClick();
    ~Engine();
};


#endif //OOP_ENGINE_H
