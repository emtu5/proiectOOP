//
// Created by Paul on 07/04/2023.
//

#ifndef OOP_BOARD_H
#define OOP_BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <array>

const int BOARD_CELL_SIZE = 50;
const int MAX_BOARD_LENGTH = 11;
const int BOARD_X = 125;
const int BOARD_Y = 25;

class Board : public sf::Drawable {
private:
    std::array<std::array<char, MAX_BOARD_LENGTH>, MAX_BOARD_LENGTH> boardLayout /*= {{
      {0,0,1,1,1,1,1,1,1,1,0},
      {0,0,0,1,1,1,1,1,1,1,1},
      {0,0,1,1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1,1,1,0},
      {1,1,1,1,1,1,1,1,1,1,0},
      {1,1,1,1,1,1,1,1,1,1,1},
      {0,0,1,1,1,0,1,1,1,1,1},
      {0,0,1,1,1,1,1,0,1,1,0},
      {0,1,1,1,1,1,1,1,1,1,1},
      {0,1,1,1,1,1,1,1,1,1,1},
      {0,1,1,0,0,1,1,0,1,0,1}
    }}*/;
    sf::Vector2i position;
public:
    Board();

    explicit Board(const std::vector<std::string>&);
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    [[nodiscard]] sf::Vector2i isClicked(const sf::Vector2i &) const;
    bool placePiece(Piece &, const sf::Vector2i &);
    void removePiece(const char &);

    [[maybe_unused]] Board(const Board&);
    friend std::ostream& operator<< (std::ostream &, const Board &);

    ~Board() override;
};


#endif //OOP_BOARD_H
