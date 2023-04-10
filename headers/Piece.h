//
// Created by Paul on 3/24/2023.
//

#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string>

const int CELL_SIZE = 50;
const int MAX_PIECE_LENGTH = 5;
const int PIECE_X = 20;
const int PIECE_Y = 20;
const int AREA_TO_SPAWN = 300;

class Piece : public sf::Drawable {

private:
    std::array<std::array<char, MAX_PIECE_LENGTH>, MAX_PIECE_LENGTH> pieceLayout;
    sf::Vector2i position;
    sf::Uint8 rf, gf, bf, ro, go, bo;
    char id;
    bool canRotate;
    bool canFlip;

public:
    // constructor
    Piece();
    Piece(const std::vector<std::string> &, char &, bool &, bool &);

    [[nodiscard]] char getId() const;

    [[nodiscard]] const std::array<std::array<char, MAX_PIECE_LENGTH>, MAX_PIECE_LENGTH> &getPieceLayout() const;

    // setter
    void updatePosition (const sf::Vector2i &);
    void flipPiece();
    void rotatePiece();

    friend std::ostream& operator<< (std::ostream &, const Piece &);
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    [[nodiscard]] bool isClicked(sf::Vector2i) const;

    ~Piece() override;
};


#endif //OOP_PIECE_H
