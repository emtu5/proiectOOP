//
// Created by Paul on 07/04/2023.
//

#include "../headers/Board.h"

void Board::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::Vector2f cellPos;
    sf::RectangleShape rectangle{sf::Vector2f(BOARD_CELL_SIZE - 2, BOARD_CELL_SIZE - 2)};
    rectangle.setFillColor(sf::Color (150, 150, 150));
    rectangle.setOutlineColor(sf::Color (70, 70, 70));
    rectangle.setOutlineThickness(1);
    cellPos.y = position.y;
    for (int i = 0; i < MAX_BOARD_LENGTH; i++) {
        cellPos.x = position.x;
        for (int j = 0; j < MAX_BOARD_LENGTH; j++) {
            rectangle.setPosition(cellPos);
            if (boardLayout[i][j] == '#') {
                target.draw(rectangle);
            }
            cellPos.x += BOARD_CELL_SIZE;
        }
        cellPos.y += BOARD_CELL_SIZE;
    }
}

Board::Board() : boardLayout{{{0}}}, position{BOARD_X, BOARD_Y} {}

Board::Board(const std::vector<std::string> &layout) : boardLayout{{{0}}}, position{BOARD_X, BOARD_Y} {
    for (int i = 0; i < MAX_BOARD_LENGTH; i++) {
        for (int j = 0; j < MAX_BOARD_LENGTH; j++) {
            boardLayout[i][j] = layout[i][j];
        }
    }
}

//
sf::Vector2i Board::isClicked(sf::Vector2i &clickPosition) const {
    sf::Vector2i relativePosition = clickPosition - position;
    return {relativePosition.y / BOARD_CELL_SIZE, relativePosition.x / BOARD_CELL_SIZE};
}

bool Board::placePiece(Piece &piece, sf::Vector2i &clickPosition) {
    //Check if piece fits
    //NOTE: Piece is centered according to the cursor

    sf::Vector2i boardClick = isClicked(clickPosition);
    auto layout = piece.getPieceLayout();
    for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
        for (int j = 0; j < MAX_PIECE_LENGTH; j++) {

            //Is that part of the piece filled?
            if (layout[i][j] == '.') {
                continue;
            }

            //Is that part of the piece out of the board's bounds?
            //absoluteXY - the actual coords where a piece section would go
            int absoluteX = boardClick.x + i - MAX_PIECE_LENGTH / 2,
                absoluteY = boardClick.y + j - MAX_PIECE_LENGTH / 2;

            if (absoluteX < 0 || absoluteX >= MAX_BOARD_LENGTH ||
                absoluteY < 0 || absoluteY >= MAX_BOARD_LENGTH) {
                return false;
            }

            //Is that part of the board occupied?
            if (boardLayout[absoluteX][absoluteY] != '#') {
                return false;
            }
        }
    }

    //Piece does fit, let's place it
    auto pieceID = piece.getId();
    for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
        for (int j = 0; j < MAX_PIECE_LENGTH; j++) {
            if (layout[i][j] == '.') {
                continue;
            }
            int absoluteX = boardClick.x + i - MAX_PIECE_LENGTH / 2,
                absoluteY = boardClick.y + j - MAX_PIECE_LENGTH / 2;
            boardLayout[absoluteX][absoluteY] = pieceID;
        }
    }

    //Snap piece to the board
    std::cout << boardClick.x << boardClick.y;
    piece.updatePosition(sf::Vector2i{BOARD_X + boardClick.y * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2,
                                      BOARD_Y + boardClick.x * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2});
    std::cout << *this;
    return true;
}

void Board::removePiece(char &id) {
    for (int i = 0; i < MAX_BOARD_LENGTH; i++) {
        for (int j = 0; j < MAX_BOARD_LENGTH; j++) {
            if (boardLayout[i][j] == id) {
                boardLayout[i][j] = '#';
            }
        }
    }
    std::cout << *this;
}

std::ostream &operator<<(std::ostream &os, const Board &b) {
    for (int i = 0; i < MAX_BOARD_LENGTH; i++) {
        for (int j = 0; j < MAX_BOARD_LENGTH; j++) {
            os << b.boardLayout[i][j];
        }
        os << '\n';
    }
    return os;
}


Board::~Board() = default;
