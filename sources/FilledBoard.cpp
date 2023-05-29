//
// Created by Paul on 23/05/2023.
//

#include "../headers/FilledBoard.h"

FilledBoard::FilledBoard(const std::vector<std::string> &boardLayout, int size, char id, int w, int h, const sf::Vector2i &pos) : Board(boardLayout, size, id, w, h, pos){}

std::shared_ptr<Board> FilledBoard::clone() const {
    return std::make_shared<FilledBoard>(*this);
}

// Win Condition: Place some pieces to cover the entire board

bool FilledBoard::checkWinCondition() {
    for (auto &row : gridLayout) {
        for (auto &tile: row) {
            if (tile == unusedTile) {
                return false;
            }
        }
    }
    return true;
}