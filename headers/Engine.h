//
// Created by Paul on 11/03/2023.
//

#ifndef OOP_ENGINE_H
#define OOP_ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
private:
    sf::RenderWindow window;
    sf::VideoMode videoMode;
public:
    explicit Engine(sf::Vector2i res);
    void run();
};


#endif //OOP_ENGINE_H
