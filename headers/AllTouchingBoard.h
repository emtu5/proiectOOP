//
// Created by Paul on 29/05/2023.
//

#ifndef OOP_ALLTOUCHINGBOARD_H
#define OOP_ALLTOUCHINGBOARD_H

#include "Board.h"

class AllTouchingBoard : public Board {
private:
    unsigned int pieceRequirement;
public:
    AllTouchingBoard(const std::vector<std::string> &, int, char, int, int, const sf::Vector2i &, unsigned int);
    bool checkWinCondition() override;
    [[nodiscard]] std::shared_ptr<Board> clone() const override;
};


#endif //OOP_ALLTOUCHINGBOARD_H
