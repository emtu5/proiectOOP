//
// Created by Paul on 23/05/2023.
//

#include "../headers/NoAdjacentBoard.h"
#include <unordered_set>

NoAdjacentBoard::NoAdjacentBoard(const std::vector<std::string> &boardLayout, int size, char id, const sf::Vector2i &pos, int no_pieces) : Board(boardLayout, size, id, pos), pieceRequirement(no_pieces){}

std::shared_ptr<Board> NoAdjacentBoard::clone() const {
    return std::make_shared<NoAdjacentBoard>(*this);
}

bool NoAdjacentBoard::checkWinCondition() {
    std::unordered_set<char> used_pieces;
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
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
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH - 1; j++) {
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
    for (int j = 0; j < BOARD_LENGTH; j++) {
        for (int i = 0; i < BOARD_LENGTH - 1; i++) {
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