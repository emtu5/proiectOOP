//
// Created by Paul on 28/05/2023.
//

#ifndef OOP_GAMEUTILS_H
#define OOP_GAMEUTILS_H

#include <SFML/Graphics.hpp>
#include "BoardFactory.h"

class GameUtils {
public:
    static void drawLevelMessage(sf::RenderWindow &window, sf::Font &, int levelNumber, const std::shared_ptr<Board> &);
    static void drawLevelComplete(sf::RenderWindow &window, sf::Font &);
    static sf::Text getText(sf::Font &, const std::string &, int, const sf::Vector2f &, const sf::Color &);
};


#endif //OOP_GAMEUTILS_H
