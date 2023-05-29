//
// Created by Paul on 07/04/2023.
//

#include "../headers/Board.h"

Board::Board(const std::vector<std::string> &boardLayout, int size, char id, int w, int h, const sf::Vector2i &pos) : Grid(boardLayout, size, id, w, h, pos) {}

bool Board::placePiece(Piece &piece, const sf::Vector2i &clickPosition) {
    //Check if piece fits
    //NOTE: Piece is centered according to the cursor

    sf::Vector2i boardClick = whereClicked(clickPosition);
    auto layout = piece.getGridLayout();
    int pieceWidth = piece.getWidthGrid();
    int pieceHeight = piece.getHeightGrid();
    for (int i = 0; i < pieceHeight; i++) {
        for (int j = 0; j < pieceWidth; j++) {

            //Is that part of the piece filled?
            if (layout[i][j] == '.') {
                continue;
            }

            //Is that part of the piece out of the board's bounds?
            //absoluteXY - the actual coords where a piece section would go
            int absoluteX = boardClick.x + i - pieceHeight / 2,
                absoluteY = boardClick.y + j - pieceWidth / 2;

            if (absoluteX < 0 || absoluteX >= heightGrid ||
                absoluteY < 0 || absoluteY >= widthGrid) {
                return false;
            }

            //Is that part of the board occupied?
            if (gridLayout[absoluteX][absoluteY] != '#') {
                return false;
            }
        }
    }

    //Piece does fit, let's place it
    auto pieceID = piece.getId();
    for (int i = 0; i < pieceHeight; i++) {
        for (int j = 0; j < pieceWidth; j++) {
            if (layout[i][j] == '.') {
                continue;
            }
            int absoluteX = boardClick.x + i - pieceHeight / 2,
                absoluteY = boardClick.y + j - pieceWidth / 2;
            gridLayout[absoluteX][absoluteY] = pieceID;
        }
    }

    //Snap piece to the board
    std::cout << "Placed at: "<< boardClick.x << " " << boardClick.y << "\n";
    piece.updatePosition(sf::Vector2i{BOARD_X + boardClick.y * TILE_SIZE + TILE_SIZE / 2,
                                      BOARD_Y + boardClick.x * TILE_SIZE + TILE_SIZE / 2});
    std::cout << *this;
    return true;
}

void Board::removePiece(const char &id) {
    for (int i = 0; i < heightGrid; i++) {
        for (int j = 0; j < widthGrid; j++) {
            if (gridLayout[i][j] == id) {
                gridLayout[i][j] = '#';
            }
        }
    }
    std::cout << *this;
}

std::ostream &operator<<(std::ostream &os, const Board &b) {
    for (int i = 0; i < b.heightGrid; i++) {
        for (int j = 0; j < b.widthGrid; j++) {
            os << b.gridLayout[i][j];
        }
        os << '\n';
    }
    return os;
}


//bool Board::checkWinCondition() {
//    for (auto &row : gridLayout) {
//        for (auto &tile: row) {
//            if (tile == unusedTile) {
//                return false;
//            }
//        }
//    }
//    return true;
//}