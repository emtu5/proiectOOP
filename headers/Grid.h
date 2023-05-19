//
// Created by Paul on 02/05/2023.
//

#ifndef OOP_GRID_H
#define OOP_GRID_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Textures.h"

const char emptyTile = '.';
const int TILE_SIZE = 50;

class Grid : public sf::Drawable {
protected:
    std::vector<std::string> gridLayout;
    int tileSize;
    char tileId;
    sf::Vector2i position;
    std::shared_ptr<sf::Texture> tileTexture;

protected:
    Grid(const std::vector<std::string> &, int, char, const sf::Vector2i &);

public:
    [[nodiscard]] const std::vector<std::string> &getGridLayout() const;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    [[nodiscard]] sf::Vector2i whereClicked(const sf::Vector2i &) const;

    [[nodiscard]] char getId() const;

};


#endif //OOP_GRID_H
