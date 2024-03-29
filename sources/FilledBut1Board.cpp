//
// Created by Paul on 23/05/2023.
//

#include "../headers/FilledBut1Board.h"

FilledBut1Board::FilledBut1Board(const std::vector<std::string> &boardLayout, int size, char id, int w, int h, const sf::Vector2i &pos) : Board(boardLayout, size, id, w, h, pos){}

std::shared_ptr<Board> FilledBut1Board::clone() const {
    return std::make_shared<FilledBut1Board>(*this);
}

// Win Condition: Place some pieces to cover all tiles except 1

bool FilledBut1Board::checkWinCondition() {
    int unusedAmount = 0;
    for (auto &row : gridLayout) {
        for (auto &tile: row) {
            if (tile == unusedTile) {
                unusedAmount++;
            }
        }
    }
    return unusedAmount == 1;
}