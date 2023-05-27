//
// Created by Paul on 15/05/2023.
//

#include "../headers/Textures.h"

void Textures::loadTextures() {
    // this is disgusting
    tileTextures['a'].loadFromFile("resources/tiles/tile1.png");
    tileTextures['b'].loadFromFile("resources/tiles/tile2.png");
    tileTextures['c'].loadFromFile("resources/tiles/tile3.png");
    tileTextures['d'].loadFromFile("resources/tiles/tile4.png");
    tileTextures['e'].loadFromFile("resources/tiles/tile5.png");
    tileTextures['f'].loadFromFile("resources/tiles/tile6.png");
    tileTextures['g'].loadFromFile("resources/tiles/tile7.png");
    tileTextures['h'].loadFromFile("resources/tiles/tile8.png");
    tileTextures['i'].loadFromFile("resources/tiles/tile9.png");
    tileTextures['j'].loadFromFile("resources/tiles/tile10.png");
    tileTextures['k'].loadFromFile("resources/tiles/tile11.png");
    tileTextures['l'].loadFromFile("resources/tiles/tile12.png");
    tileTextures['w'].loadFromFile("resources/tiles/board1.png");
    tileTextures['x'].loadFromFile("resources/tiles/board2.png");
    tileTextures['y'].loadFromFile("resources/tiles/board3.png");
    tileTextures['z'].loadFromFile("resources/tiles/board4.png");
}

std::shared_ptr<sf::Texture> Textures::getTileTexture(char id) {
    return std::make_shared<sf::Texture>(tileTextures[id]);
}

std::unordered_map<char, sf::Texture> Textures::tileTextures;