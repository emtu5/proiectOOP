//
// Created by Paul on 3/24/2023.
//

#include "../headers/Piece.h"

void Piece::rotatePiece() {
    if (canRotate) {
        std::array<std::array<char, MAX_PIECE_LENGTH>, MAX_PIECE_LENGTH> temp{};
        for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
            for (int j = 0; j < MAX_PIECE_LENGTH; j++) {
                //Rotate clockwise
                temp[j][MAX_PIECE_LENGTH - 1 - i] = pieceLayout[i][j];
            }
        }
        pieceLayout = temp;
    }
}

void Piece::flipPiece() {
    if (canFlip) {
        for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
            for (int j = 0; j < MAX_PIECE_LENGTH / 2; j++) {
                //Flip by vertical axis
                std::swap(pieceLayout[i][j], pieceLayout[i][MAX_PIECE_LENGTH - 1 - j]);
            }
        }
    }
}

void Piece::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::Vector2i cellPos;
    sf::RectangleShape rectangle{sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2)};
    rectangle.setFillColor(fillColour);
    rectangle.setOutlineColor(outlineColour);
    rectangle.setOutlineThickness(1);
    cellPos.y = position.y;
    for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
        cellPos.x = position.x;
        for (int j = 0; j < MAX_PIECE_LENGTH; j++) {
            rectangle.setPosition(static_cast<sf::Vector2f>(cellPos));
            if (pieceLayout[i][j] == '#') {
                target.draw(rectangle);
            }
            cellPos.x += CELL_SIZE;
        }
        cellPos.y += CELL_SIZE;
    }
}

bool Piece::isClicked(sf::Vector2i clickPosition) const {
    sf::Vector2i relativePosition = clickPosition - position;
    int x = relativePosition.x / CELL_SIZE, y = relativePosition.y / CELL_SIZE;
    return x >= 0 && x < MAX_PIECE_LENGTH &&
            y >=0 && y < MAX_PIECE_LENGTH &&
            pieceLayout[y][x] == '#';
}

void Piece::updatePosition(const sf::Vector2i &cursorPosition) {
    int offset = CELL_SIZE * MAX_PIECE_LENGTH / 2;
    Piece::position = cursorPosition - sf::Vector2i{offset, offset};
}

Piece::Piece(const std::vector<std::string> &layout, char &_id, bool &rotate, bool &flip) : pieceLayout{{{0}}}, position({std::rand() % AREA_TO_SPAWN, std::rand() % AREA_TO_SPAWN}),
                                                                                            fillColour(std::rand() % 256, std::rand() % 256, std::rand() % 256),
                                                                                            outlineColour(std::rand() % 256, std::rand() % 256, std::rand() % 256),
                                                                                            id{_id}, canRotate{rotate}, canFlip(flip) {
    std::cout << "new piece lol " << id << '\n';
    for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
        for (int j = 0; j < MAX_PIECE_LENGTH; j++) {
            pieceLayout[i][j] = layout[i][j];
        }
    }
}

Piece::Piece() :    pieceLayout{{{0}}},
                    position(PIECE_X, PIECE_Y),
                    fillColour(0, 255, 255), outlineColour(0, 255, 255),
                    id('a'),
                    canRotate(true),
                    canFlip(true) {}

const std::array<std::array<char, MAX_PIECE_LENGTH>, MAX_PIECE_LENGTH> &Piece::getPieceLayout() const {
    return pieceLayout;
}

char Piece::getId() const {
    return id;
}

std::ostream &operator<<(std::ostream &os, const Piece &p) {
    for (int i = 0; i < MAX_PIECE_LENGTH; i++) {
        for (int j = 0; j < MAX_PIECE_LENGTH; j++) {
            os << p.pieceLayout[i][j];
        }
        os << '\n';
    }
    return os;
}

Piece::~Piece() = default;
