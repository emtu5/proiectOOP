#include "headers/Engine.h"

int main()
{
    sf::Vector2i resolution(800, 600);
    Engine &engine = Engine::get_engine(resolution);
    engine.run();
    return 0;
}