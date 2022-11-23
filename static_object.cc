#include "static_object.h"
#include "SFML/Graphics.hpp"

#include <iostream> //TA BORT SEN





Static_object::Static_object()
{
    load_icon("Textures/tree.png");

    position_x = rand()%(1820-100 + 1) + 100;
    position_y = 872;

    icon.setScale(0.03, 0.03);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setPosition(position_x, position_y);    
};

void Static_object::handle(Context& context, sf::Event event)
{};

void Static_object::update(Context& context)
{};

void Static_object::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
};

void Static_object::collision(Game_object* object, Context& context)
{};


