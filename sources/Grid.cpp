//
// Created by Paul on 02/05/2023.
//

#include "../headers/Grid.h"

Grid::Grid(const std::vector<std::string> &layout, int size, char id_, const sf::Vector2i &pos = {20, 20}) : gridLayout{layout},
                                                                                                                   tileSize{size},
                                                                                                                   id{id_},
                                                                                                                   position{pos} {
    tileTexture = Textures::getTileTexture(id);
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
    return {relativePosition.y / tileSize, relativePosition.x / tileSize};
}

char Grid::getId() const {
    return id;
}