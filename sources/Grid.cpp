//
// Created by Paul on 02/05/2023.
//

#include "../headers/Grid.h"

Grid::Grid(const std::vector<std::string> &layout, int size, char id, unsigned int w, unsigned int h, const sf::Vector2i &pos = {20, 20}) : gridLayout{layout},
                                                                                                                   tileSize{size},
                                                                                                                   tileId{id},
                                                                                                                   widthGrid{w},
                                                                                                                   heightGrid{h},
                                                                                                                   position{pos} {
    tileTexture = Textures::getTileTexture(tileId);
}

const std::vector<std::string> &Grid::getGridLayout() const {
    return gridLayout;
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates) const {
    sf::Vector2i tilePos;
    tilePos.y = position.y;
    sf::Sprite tileSprite;
    tileSprite.setTexture(*tileTexture);
    for (auto &line : gridLayout) {
        tilePos.x = position.x;
        for (auto &tile : line) {
            tileSprite.setPosition(static_cast<sf::Vector2f>(tilePos));
            if (tile != emptyTile) {
                target.draw(tileSprite);
            }
            tilePos.x += tileSize;
        }
        tilePos.y += tileSize;
    }
}

sf::Vector2i Grid::whereClicked(const sf::Vector2i &clickPosition) const {
    sf::Vector2i relativePosition = clickPosition - position;
    return {static_cast<int>(std::floor(1. * relativePosition.y / tileSize )), static_cast<int>(std::floor(1. * relativePosition.x / tileSize))};
}

char Grid::getId() const {
    return tileId;
}

sf::Vector2i &Grid::getPostion() {
    return position;
}

unsigned int Grid::getWidthGrid() const {
    return widthGrid;
}

unsigned int Grid::getHeightGrid() const {
    return heightGrid;
}
