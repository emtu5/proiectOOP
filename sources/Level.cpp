//
// Created by Paul on 07/04/2023.
//

#include "../headers/Level.h"

#include <fstream>

[[maybe_unused]] Level::Level(const std::string &levelPath) {
    std::ifstream fin(levelPath);
    std::string currentLine;

    //Board
    std::vector<std::string> stringBoard;
    for (int i = 0; i < BOARD_LENGTH; i++) {
        fin >> currentLine;
        stringBoard.emplace_back(currentLine);
    }
    currentBoard = std::make_shared<Board>(stringBoard, TILE_SIZE, 'w', sf::Vector2i{BOARD_X, BOARD_Y});

    //Pieces
    char currentId;
    while (fin >> currentId){
        bool rotate, flip; fin >> rotate >> flip;
        std::vector<std::string> stringPiece;
        for (int i = 0; i < PIECE_LENGTH; i++) {
            fin >> currentLine;
            stringPiece.emplace_back(currentLine);
        }
        pieceInventory.emplace_back(std::make_shared<Piece>(stringPiece, TILE_SIZE, currentId, sf::Vector2i{PIECE_X, PIECE_Y}, rotate, flip));
    }
}

const std::vector<std::shared_ptr<Piece>> &Level::getPieceInventory() const {
    return pieceInventory;
}


const std::shared_ptr<Board> &Level::getCurrentBoard() const {
    return currentBoard;
}


Level::Level() = default;


Level::~Level() = default;

