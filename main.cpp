#include "headers/Engine.h"

int main()
{
    std::srand(time(nullptr));
    sf::Vector2i resolution(800, 600);
    Engine engine(resolution);
    engine.run();
    return 0;
}