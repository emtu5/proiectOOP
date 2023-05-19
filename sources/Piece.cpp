//
// Created by Paul on 3/24/2023.
//

#include "../headers/Piece.h"

void Piece::rotatePiece() {
    if (canRotate) {
        std::vector<std::string> temp = {
                ".....",
                ".....",
                ".....",
                ".....",
                "....."
        };
        for (int i = 0; i < PIECE_LENGTH; i++) {
            for (int j = 0; j < PIECE_LENGTH; j++) {
                //Rotate clockwise
                temp[j][PIECE_LENGTH - 1 - i] = gridLayout[i][j];
            }
        }
        gridLayout = temp;
    }
}

void Piece::flipPiece() {
    if (canFlip) {
        for (int i = 0; i < PIECE_LENGTH; i++) {
            for (int j = 0; j < PIECE_LENGTH / 2; j++) {
                //Flip by vertical axis
                std::swap(gridLayout[i][j], gridLayout[i][PIECE_LENGTH - 1 - j]);
            }
        }
    }
}



bool Piece::isClicked(const sf::Vector2i &clickPosition) const {
    sf::Vector2i gridCoords = whereClicked(clickPosition);
    return gridCoords.x >= 0 && gridCoords.x < PIECE_LENGTH &&
            gridCoords.y >=0 && gridCoords.y < PIECE_LENGTH &&
            gridLayout[gridCoords.x][gridCoords.y] == '#';
}

void Piece::updatePosition(const sf::Vector2i &cursorPosition) {
    int offset = CELL_SIZE * PIECE_LENGTH / 2;
    position = cursorPosition - sf::Vector2i{offset, offset};
}



std::ostream &operator<<(std::ostream &os, const Piece &p) {
    for (int i = 0; i < PIECE_LENGTH; i++) {
        for (int j = 0; j < PIECE_LENGTH; j++) {
            os << p.gridLayout[i][j];
        }
        os << '\n';
    }
    return os;
}

Piece::Piece(const std::vector<std::string> &pieceLayout, int size, char id, const sf::Vector2i &pos, bool rotate, bool flip) : Grid(pieceLayout, size, id, pos),
                                                                                                                    canRotate{rotate},
                                                                                                                    canFlip{flip} {}
