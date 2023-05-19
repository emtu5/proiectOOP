//
// Created by Paul on 3/24/2023.
//

#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <iostream>
#include <array>
#include <string>

const int CELL_SIZE = 50;
const int PIECE_LENGTH = 5;
const int PIECE_X = 20;
const int PIECE_Y = 20;
const int AREA_TO_SPAWN = 300;

class Piece : public Grid {

private:
    bool canRotate, canFlip;

public:
    // constructor
    Piece(const std::vector<std::string> &, int, char, const sf::Vector2i &, bool, bool);

    // setter
    void updatePosition (const sf::Vector2i &);
    void flipPiece();
    void rotatePiece();

    friend std::ostream& operator<< (std::ostream &, const Piece &);

    [[nodiscard]] bool isClicked(const sf::Vector2i &) const;

};


#endif //OOP_PIECE_H
