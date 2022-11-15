#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

struct Context; //Forward declaration

class State
{
    public:

    virtual void handle(Context& context, sf::Event event) = 0;
    virtual void update(Context& context) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    virtual ~State() = default;
};

#endif