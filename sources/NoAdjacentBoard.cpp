//
// Created by Paul on 23/05/2023.
//

#include "../headers/NoAdjacentBoard.h"
#include <unordered_set>

NoAdjacentBoard::NoAdjacentBoard(const std::vector<std::string> &boardLayout, int size, char id, int w, int h, const sf::Vector2i &pos, unsigned int no_pieces) : Board(boardLayout, size, id, w, h, pos), pieceRequirement(no_pieces){}

std::shared_ptr<Board> NoAdjacentBoard::clone() const {
    return std::make_shared<NoAdjacentBoard>(*this);
}

// Win Condition: Place all pieces on the board without any of them touching

bool NoAdjacentBoard::checkWinCondition() {
    std::unordered_set<char> used_pieces;
    for (int i = 0; i < heightGrid; i++) {
        for (int j = 0; j < widthGrid; j++) {
            if (gridLayout[i][j] == emptyTile || gridLayout[i][j] == unusedTile) {
                continue;
            }
            used_pieces.insert(gridLayout[i][j]);
        }
    }
    if (used_pieces.size() != pieceRequirement) {
        std::cout << "Current piece count: " << used_pieces.size() << '\n';
        return false;
    }
    // horizontal adjacency
    std::cout << "Checking adjacency...\n";
    for (int i = 0; i < heightGrid; i++) {
        for (int j = 0; j < widthGrid - 1; j++) {
            if (gridLayout[i][j] == emptyTile || gridLayout[i][j] == unusedTile
            || gridLayout[i][j + 1] == emptyTile || gridLayout[i][j + 1] == unusedTile) {
                continue;
            }
            if (gridLayout[i][j] != gridLayout[i][j + 1]) {
                std:: cout << "failed horizontal check at " << i << " " << j << '\n';
                return false;
            }
        }
    }
    // vertical adjacency
    for (int j = 0; j < heightGrid; j++) {
        for (int i = 0; i < widthGrid - 1; i++) {
            if (gridLayout[i][j] == emptyTile || gridLayout[i][j] == unusedTile
            || gridLayout[i+ 1][j] == emptyTile || gridLayout[i + 1][j] == unusedTile) {
                continue;
            }
            if (gridLayout[i][j] != gridLayout[i + 1][j]) {
                std:: cout << "failed vertical check at " << i << " " << j << '\n';
                return false;
            }
        }
    }
    return true;
}