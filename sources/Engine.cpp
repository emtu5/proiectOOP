//
// Created by Paul on 11/03/2023.
//

#include "../headers/Engine.h"

Engine::Engine(sf::Vector2i res) {
    videoMode.width = res.x;
    videoMode.height = res.y;
    window.create(videoMode, "Block Game WIP");
}

void Engine::run() {
    while(window.isOpen()) {
        sf::Event ev{};
        while(window.pollEvent(ev)) {
            if(ev.type == sf::Event::Closed || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                window.close();
            }
        }
    }
}
