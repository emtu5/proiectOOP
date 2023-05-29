//
// Created by Paul on 23/05/2023.
//

#ifndef OOP_FILLEDBOARD_H
#define OOP_FILLEDBOARD_H

#include "Board.h"

class FilledBoard : public Board{
public:
    FilledBoard(const std::vector<std::string> &, int, char, int, int, const sf::Vector2i &);
    bool checkWinCondition() override;
    [[nodiscard]] std::shared_ptr<Board> clone() const override;
};


#endif //OOP_FILLEDBOARD_H
