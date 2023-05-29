//
// Created by Paul on 27/05/2023.
//

#include "../headers/BoardFactory.h"

BoardFactory &BoardFactory::get_factory() {
    static BoardFactory boardfactory;
    return boardfactory;
}

std::shared_ptr<Board>
BoardFactory::createBoard(const std::string &type, const std::vector<std::string> &boardLayout, int size, int w, int h, const sf::Vector2i &pos, int no_pieces) {
    if (type == "fill") { return std::make_shared<FilledBoard>(boardLayout, size, 'z', w, h, pos);}
    else if (type == "fill-1") { return std::make_shared<FilledBut1Board>(boardLayout, size, 'y', w, h, pos);}
    else if (type == "noAdjacent") { return std::make_shared<NoAdjacentBoard>(boardLayout, size, 'x', w, h, pos, no_pieces);}
    else if (type == "no2x2") { return std::make_shared<No2x2Board>(boardLayout, size, 'w', w, h, pos, no_pieces);}
    else if (type == "allTouch") { return std::make_shared<AllTouchingBoard>(boardLayout, size, 'v', w, h, pos, no_pieces);}
    return nullptr;
}
