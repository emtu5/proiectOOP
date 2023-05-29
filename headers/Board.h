//
// Created by Paul on 07/04/2023.
//

#ifndef OOP_BOARD_H
#define OOP_BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <unordered_map>
#include <functional>
#include <memory>

const int BOARD_X = 125;
const int BOARD_Y = 25;

class Board : public Grid {

public:
    // constructor
    Board(const std::vector<std::string> &, int, char, int, int, const sf::Vector2i &);

    // board managing piece placement
    bool placePiece(Piece &, const sf::Vector2i &);
    void removePiece(const char &);

    friend std::ostream& operator<< (std::ostream &, const Board &);
    virtual bool checkWinCondition() = 0;
    [[nodiscard]] virtual std::shared_ptr<Board> clone() const = 0;


    virtual ~Board() = default;
};


#endif //OOP_BOARD_H
