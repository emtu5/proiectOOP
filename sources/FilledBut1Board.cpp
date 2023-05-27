//
// Created by Paul on 23/05/2023.
//

#include "../headers/FilledBut1Board.h"

FilledBut1Board::FilledBut1Board(const std::vector<std::string> &boardLayout, int size, char id, const sf::Vector2i &pos) : Board(boardLayout, size, id, pos){}

std::shared_ptr<Board> FilledBut1Board::clone() const {
    return std::make_shared<FilledBut1Board>(*this);
}

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