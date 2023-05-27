//
// Created by Paul on 23/05/2023.
//

#ifndef OOP_FILLEDBUT1BOARD_H
#define OOP_FILLEDBUT1BOARD_H

#include "Board.h"

class FilledBut1Board : public Board{
public:
    FilledBut1Board(const std::vector<std::string> &, int, char, const sf::Vector2i &);
    bool checkWinCondition() override;
    [[nodiscard]] std::shared_ptr<Board> clone() const override;
};


#endif //OOP_FILLEDBUT1BOARD_H
