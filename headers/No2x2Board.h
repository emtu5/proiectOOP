//
// Created by Paul on 23/05/2023.
//

#ifndef OOP_NO2X2BOARD_H
#define OOP_NO2X2BOARD_H

#include "Board.h"

class No2x2Board : public Board{
private:
    int pieceRequirement;
public:
    No2x2Board(const std::vector<std::string> &, int, char, const sf::Vector2i &, int);
    bool checkWinCondition() override;
    [[nodiscard]] std::shared_ptr<Board> clone() const override;
};


#endif //OOP_NO2X2BOARD_H
