//
// Created by Paul on 27/05/2023.
//

#include "../headers/BoardFactory.h"

BoardFactory &BoardFactory::get_factory() {
    static BoardFactory boardfactory;
    return boardfactory;
}

std::shared_ptr<Board>
BoardFactory::createBoard(const std::string &type, const std::vector<std::string> &boardLayout, int size, const sf::Vector2i &pos, int no_pieces) {
    if (type == "fill") { return std::make_shared<FilledBoard>(boardLayout, size, 'w', pos);}
    else if (type == "fill-1") { return std::make_shared<FilledBut1Board>(boardLayout, size, 'x', pos);}
    else if (type == "noOrtho") { return std::make_shared<NoAdjacentBoard>(boardLayout, size, 'y', pos, no_pieces);}
    else if (type == "no2x2") { return std::make_shared<No2x2Board>(boardLayout, size, 'z', pos, no_pieces);}
    return nullptr;
}