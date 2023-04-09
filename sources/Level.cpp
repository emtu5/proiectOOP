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
    for (int i = 0; i < MAX_BOARD_LENGTH; i++) {
        fin >> currentLine;
        stringBoard.emplace_back(currentLine);
    }
    currentBoard = Board{stringBoard};

    //Pieces
    char currentId;
    while (fin >> currentId){
        bool rotate, flip; fin >> rotate >> flip;
        std::vector<std::string> stringPiece;
        for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
            fin >> currentLine;
            stringPiece.emplace_back(currentLine);
        }
        pieceInventory.emplace_back(stringPiece, currentId, rotate, flip);
    }
}

std::vector<Piece> &Level::getPieceInventory() {
    return pieceInventory;
}

Board &Level::getCurrentBoard()  {
    return currentBoard;
}

Level::~Level() = default;

