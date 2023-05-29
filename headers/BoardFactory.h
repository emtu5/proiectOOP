//
// Created by Paul on 27/05/2023.
//

#ifndef OOP_BOARDFACTORY_H
#define OOP_BOARDFACTORY_H

#include "FilledBoard.h"
#include "FilledBut1Board.h"
#include "NoAdjacentBoard.h"
#include "No2x2Board.h"

class BoardFactory {
private:
    BoardFactory() = default;
public:
    BoardFactory(const BoardFactory&) = delete;
    BoardFactory& operator= (const BoardFactory&) = delete;
    static BoardFactory& get_factory();
    static std::shared_ptr<Board> createBoard(const std::string &, const std::vector<std::string> &, int, int, int, const sf::Vector2i &, int);
};


#endif //OOP_BOARDFACTORY_H
