//
// Created by Paul on 15/05/2023.
//

#ifndef OOP_TEXTURES_H
#define OOP_TEXTURES_H

#include "SFML/Graphics.hpp"
#include "Exceptions.h"
#include <unordered_map>
#include <memory>
#include <iostream>

class Textures {
private:
    static std::unordered_map<char, sf::Texture> tileTextures;

public:
    static void loadTextures();
    static std::shared_ptr<sf::Texture> getTileTexture(char);
};


#endif //OOP_TEXTURES_H
