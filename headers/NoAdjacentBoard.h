//
// Created by Paul on 23/05/2023.
//

#ifndef OOP_NOADJACENTBOARD_H
#define OOP_NOADJACENTBOARD_H

#include "Board.h"

class NoAdjacentBoard : public Board{
private:
    unsigned int pieceRequirement;
public:
    NoAdjacentBoard(const std::vector<std::string> &, int, char, int, int, const sf::Vector2i &, unsigned int);
    bool checkWinCondition() override;
    [[nodiscard]] std::shared_ptr<Board> clone() const override;
};

#endif //OOP_NOADJACENTBOARD_H
