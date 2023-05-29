//
// Created by Paul on 23/05/2023.
//

#include "../headers/No2x2Board.h"
#include <unordered_set>

No2x2Board::No2x2Board(const std::vector<std::string> &boardLayout, int size, char id, int w, int h, const sf::Vector2i &pos, unsigned int no_pieces) : Board(boardLayout, size, id, w, h, pos), pieceRequirement(no_pieces) {}

std::shared_ptr<Board> No2x2Board::clone() const {
    return std::make_shared<No2x2Board>(*this);
}

// Win Condition: Place all pieces without covering any 2x2 region on the board

bool No2x2Board::checkWinCondition() {
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
        return false;
    }
    for (int i = 0; i < heightGrid - 1; i++) {
        for (int j = 0; j < widthGrid - 1; j++) {
            if (gridLayout[i][j] == emptyTile || gridLayout[i][j] == unusedTile
                || gridLayout[i][j + 1] == emptyTile || gridLayout[i][j + 1] == unusedTile
                || gridLayout[i + 1][j] == emptyTile || gridLayout[i + 1][j] == unusedTile
                || gridLayout[i + 1][j + 1] == emptyTile || gridLayout[i + 1][j + 1] == unusedTile) {
                continue;
            }
            std::cout << "failed 2x2 check on " << i << " " << j << '\n';
            return false;
        }
    }
    return true;
}