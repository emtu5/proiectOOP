//
// Created by Paul on 3/24/2023.
//

#include "../headers/Piece.h"

void Piece::rotatePiece() {
    if (canRotate) {
        std::string tempRow(heightGrid, emptyTile);
        std::vector<std::string> temp(widthGrid, tempRow);
        for (unsigned int i = 0; i < heightGrid; i++) {
            for (unsigned int j = 0; j < widthGrid; j++) {
                //Rotate clockwise
                temp[j][heightGrid - 1 - i] = gridLayout[i][j];
            }
        }

        gridLayout = temp;

        // If you don't move the cursor, the piece will be misaligned
        // Since piece is anchored to the top-left corner

        if (heightGrid >= widthGrid) {
            unsigned int offset = heightGrid - widthGrid; std::cout << offset;
            position += {-static_cast<int>(TILE_SIZE * offset / 2), static_cast<int>(TILE_SIZE * offset / 2)};
        }
        else {
            unsigned int offset = widthGrid - heightGrid;
            position += {static_cast<int>(TILE_SIZE * offset / 2), -static_cast<int>(TILE_SIZE * offset / 2)};
        }

        // Swap height and width, now that it's rotated
        std::swap(heightGrid, widthGrid);
    }
}

void Piece::flipPiece() {
    if (canFlip) {
        for (unsigned int i = 0; i < heightGrid; i++) {
            for (unsigned int j = 0; j < widthGrid / 2; j++) {
                //Flip by vertical axis
                std::swap(gridLayout[i][j], gridLayout[i][widthGrid - 1 - j]);
            }
        }
    }
}



bool Piece::isClicked(const sf::Vector2i &clickPosition) const {
    sf::Vector2i gridCoords = whereClicked(clickPosition);
    return gridCoords.x >= 0 && gridCoords.x < static_cast<int>(heightGrid) &&
            gridCoords.y >=0 && gridCoords.y < static_cast<int>(widthGrid) &&
            gridLayout[gridCoords.x][gridCoords.y] == '#';
}

void Piece::updatePosition(const sf::Vector2i &cursorPosition) {
    unsigned int widthOffset = TILE_SIZE * widthGrid / 2;
    unsigned int heightOffset = TILE_SIZE * heightGrid / 2;
    position = cursorPosition - static_cast<sf::Vector2i>(sf::Vector2u{widthOffset, heightOffset});
}

std::ostream &operator<<(std::ostream &os, const Piece &p) {
    for (unsigned int i = 0; i < p.getWidthGrid(); i++) {
        for (unsigned int j = 0; j < p.getHeightGrid(); j++) {
            os << p.gridLayout[i][j];
        }
        os << '\n';
    }
    return os;
}

Piece::Piece(const std::vector<std::string> &pieceLayout, int size, char id, unsigned int w, unsigned int h,
             const sf::Vector2i &pos, bool rotate, bool flip) : Grid(pieceLayout, size, id, w, h, pos),
                                                                                    canRotate{rotate},
                                                                                    canFlip{flip} {}

