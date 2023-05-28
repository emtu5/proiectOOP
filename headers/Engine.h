//
// Created by Paul on 11/03/2023.
//

#ifndef OOP_ENGINE_H
#define OOP_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Piece.h"
#include "Board.h"
#include "Level.h"
#include "Utils.h"
#include "Exceptions.h"

const int STARTING_LEVEL = 1;
const int TOTAL_LEVELS = 30;

class Engine {
private:
    Level currentLevel{};
    std::shared_ptr<Piece> heldPiece = nullptr;
    bool hasFinishedLevel = false;
    std::shared_ptr<Board> currentBoard;
    std::vector<std::shared_ptr<Piece>> currentPieceInventory;
    sf::RenderWindow window;
    sf::VideoMode videoMode;
    short currentLevelNumber;
    short totalLevelCount;
    sf::Font gameFont;
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
    void loadLevel(int);
    void goToNextLevel();
    ~Engine();
};


#endif //OOP_ENGINE_H
