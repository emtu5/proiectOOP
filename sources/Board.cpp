//
// Created by Paul on 07/04/2023.
//

#include "../headers/Board.h"

Board::Board(const std::vector<std::string> &boardLayout, int size, char id, const sf::Vector2i &pos) : Grid(boardLayout, size, id, pos) {}

bool Board::placePiece(Piece &piece, const sf::Vector2i &clickPosition) {
    //Check if piece fits
    //NOTE: Piece is centered according to the cursor

    sf::Vector2i boardClick = whereClicked(clickPosition);
    auto layout = piece.getGridLayout();
    for (int i = 0; i < PIECE_LENGTH; i++) {
        for (int j = 0; j < PIECE_LENGTH; j++) {

            //Is that part of the piece filled?
            if (layout[i][j] == '.') {
                continue;
            }

            //Is that part of the piece out of the board's bounds?
            //absoluteXY - the actual coords where a piece section would go
            int absoluteX = boardClick.x + i - PIECE_LENGTH / 2,
                absoluteY = boardClick.y + j - PIECE_LENGTH / 2;

            if (absoluteX < 0 || absoluteX >= BOARD_LENGTH ||
                absoluteY < 0 || absoluteY >= BOARD_LENGTH) {
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
    for (int i = 0; i < PIECE_LENGTH; i++) {
        for (int j = 0; j < PIECE_LENGTH; j++) {
            if (layout[i][j] == '.') {
                continue;
            }
            int absoluteX = boardClick.x + i - PIECE_LENGTH / 2,
                absoluteY = boardClick.y + j - PIECE_LENGTH / 2;
            gridLayout[absoluteX][absoluteY] = pieceID;
        }
    }

    //Snap piece to the board
    std::cout << "Placed at: "<< boardClick.x << " " << boardClick.y << "\n";
    piece.updatePosition(sf::Vector2i{BOARD_X + boardClick.y * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2,
                                      BOARD_Y + boardClick.x * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2});
    std::cout << *this;
    return true;
}

void Board::removePiece(const char &id) {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (gridLayout[i][j] == id) {
                gridLayout[i][j] = '#';
            }
        }
    }
    std::cout << *this;
}

std::ostream &operator<<(std::ostream &os, const Board &b) {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
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