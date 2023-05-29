//
// Created by Paul on 02/05/2023.
//

#ifndef OOP_GRID_H
#define OOP_GRID_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <cmath>
#include "Textures.h"

const char emptyTile = '.';
const char unusedTile = '#';
const int TILE_SIZE = 50;

class Grid : public sf::Drawable {
protected:
    std::vector<std::string> gridLayout;
    int tileSize;
    char tileId;
    int widthGrid, heightGrid;
    sf::Vector2i position;
    std::shared_ptr<sf::Texture> tileTexture;

protected:
    Grid(const std::vector<std::string> &, int, char, int, int, const sf::Vector2i &);

public:
    [[nodiscard]] int getWidthGrid() const;
    [[nodiscard]] int getHeightGrid() const;

    sf::Vector2i &getPostion();
    [[nodiscard]] const std::vector<std::string> &getGridLayout() const;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    [[nodiscard]] sf::Vector2i whereClicked(const sf::Vector2i &) const;

    [[nodiscard]] char getId() const;

};


#endif //OOP_GRID_H
