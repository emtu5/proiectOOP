//
// Created by Paul on 28/05/2023.
//

#include "../headers/Utils.h"

#include <cmath>

sf::Text Utils::getText(sf::Font &font, const std::string &message, int size, const sf::Vector2f &pos, const sf::Color &color) {
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(size);
    text.setPosition(pos);
    text.setFillColor(color);
    return text;
}

void Utils::drawLevelMessage(sf::RenderWindow &window, sf::Font &font, int levelNumber, const std::shared_ptr<Board> &board) {
    sf::Color color = sf::Color::White;

    if (std::dynamic_pointer_cast<FilledBoard>(board)) {
        color = {150, 150, 150};
    }
    else if (std::dynamic_pointer_cast<NoAdjacentBoard>(board)) {
        color = {255, 150, 150};
    }
    else if (std::dynamic_pointer_cast<FilledBut1Board>(board)) {
        color = {150, 255, 150};
    }
    else if (std::dynamic_pointer_cast<No2x2Board>(board)) {
        color = {150, 150, 255};
    }
    else if (std::dynamic_pointer_cast<AllTouchingBoard>(board)) {
        color = {150, 100, 166};
    }

    sf::Vector2f pos = static_cast<sf::Vector2f>(board->getPostion() - sf::Vector2i{0, 24});
    sf::Text levelText = getText(font, "Level " + std::to_string(levelNumber), 23, pos, color);
    window.draw(levelText);
}

void Utils::drawLevelComplete(sf::RenderWindow &window, sf::Font &font) {
    sf::RectangleShape overlay;
    overlay.setSize(static_cast<sf::Vector2f>(window.getSize()));
    overlay.setFillColor({0, 0, 0, 127});
    window.draw(overlay);

    sf::Text completeText = getText(font, "Level Complete", 60, {0, 0}, sf::Color::White);

    // https://learnsfml.com/how-to-center-text/
    sf::Vector2f center = completeText.getGlobalBounds().getSize() / 2.f;
    sf::Vector2f localBounds = center + completeText.getLocalBounds().getPosition();
    sf::Vector2f rounded{std::round(localBounds.x), std::round(localBounds.y)};
    completeText.setOrigin(rounded);
    completeText.setPosition(sf::Vector2f{ window.getSize() / 2u });

    window.draw(completeText);
}