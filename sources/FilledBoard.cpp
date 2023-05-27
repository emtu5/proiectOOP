//
// Created by Paul on 23/05/2023.
//

#include "../headers/FilledBoard.h"

FilledBoard::FilledBoard(const std::vector<std::string> &boardLayout, int size, char id, const sf::Vector2i &pos) : Board(boardLayout, size, id, pos){}

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
std::shared_ptr<Board> FilledBoard::clone() const {
    return std::make_shared<FilledBoard>(*this);
}