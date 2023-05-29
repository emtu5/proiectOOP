//
// Created by Paul on 28/05/2023.
//

#ifndef OOP_UTILS_H
#define OOP_UTILS_H

#include <SFML/Graphics.hpp>
#include "BoardFactory.h"

namespace Utils {
    void drawLevelMessage(sf::RenderWindow &window, sf::Font &, int levelNumber, const std::shared_ptr<Board> &);
    void drawLevelComplete(sf::RenderWindow &window, sf::Font &);
    sf::Text getText(sf::Font &, const std::string &, int, const sf::Vector2f &, const sf::Color &);
}


#endif //OOP_UTILS_H
