//
// Created by Paul on 3/24/2023.
//

#include "../headers/Piece.h"

void Piece::rotatePiece() {
    if (canRotate) {
        std::string tempRow(heightGrid, emptyTile);
        std::vector<std::string> temp(widthGrid, tempRow);
        for (int i = 0; i < heightGrid; i++) {
            for (int j = 0; j < widthGrid; j++) {
                //Rotate clockwise
                temp[j][heightGrid - 1 - i] = gridLayout[i][j];
            }
        }

        gridLayout = temp;

        // If you don't move the cursor, the piece will be misaligned
        // Since piece is anchored to the top-left corner

        if (heightGrid >= widthGrid) {
            int offset = heightGrid - widthGrid;
            position += {-(TILE_SIZE * offset / 2), (TILE_SIZE * offset / 2)};
        }
        else {
            int offset = widthGrid - heightGrid;
            position += {(TILE_SIZE * offset / 2), -(TILE_SIZE * offset / 2)};
        }

        // Swap height and width, now that it's rotated
        std::swap(heightGrid, widthGrid);
    }
}

void Piece::flipPiece() {
    if (canFlip) {
        for (int i = 0; i < heightGrid; i++) {
            for (int j = 0; j < widthGrid / 2; j++) {
                //Flip by vertical axis
                std::swap(gridLayout[i][j], gridLayout[i][widthGrid - 1 - j]);
            }
        }
    }
}



bool Piece::isClicked(const sf::Vector2i &clickPosition) const {
    sf::Vector2i gridCoords = whereClicked(clickPosition);
    return gridCoords.x >= 0 && gridCoords.x < heightGrid &&
            gridCoords.y >=0 && gridCoords.y < widthGrid &&
            gridLayout[gridCoords.x][gridCoords.y] == '#';
}

void Piece::updatePosition(const sf::Vector2i &cursorPosition) {
    unsigned int widthOffset = TILE_SIZE * widthGrid / 2;
    unsigned int heightOffset = TILE_SIZE * heightGrid / 2;
    position = cursorPosition - static_cast<sf::Vector2i>(sf::Vector2u{widthOffset, heightOffset});
}

std::ostream &operator<<(std::ostream &os, const Piece &p) {
    for (int i = 0; i < p.getHeightGrid(); i++) {
        for (int j = 0; j < p.getWidthGrid(); j++) {
            os << p.gridLayout[i][j];
        }
        os << '\n';
    }
    return os;
}

Piece::Piece(const std::vector<std::string> &pieceLayout, int size, char id, int w, int h,
             const sf::Vector2i &pos, bool rotate, bool flip) : Grid(pieceLayout, size, id, w, h, pos),
                                                                                    canRotate{rotate},
                                                                                    canFlip{flip} {}

