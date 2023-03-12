#include "headers/Engine.h"

int main()
{
    sf::Vector2 resolution(800, 600);
    Engine engine(resolution);
    engine.run();
    return 0;
}