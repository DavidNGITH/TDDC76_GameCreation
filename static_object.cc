#include "static_object.h"
#include "context.h"
#include "Missile.h"
#include "SFML/Graphics.hpp"

#include <iostream> //TA BORT SEN





Static_object::Static_object(Context& context)
{
    load_icon("textures_new/tree.png");

    position_x = rand() % (context.map -> get_window_size().x - 100) + 100;
    position_y = get_ground_pos(context, position_x);

    icon.setScale(2, 2);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setPosition(position_x, position_y);    
}

void Static_object::handle(Context& context, sf::Event event)
{}

void Static_object::update(Context& context)
{}

void Static_object::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}

void Static_object::collision(Game_object* object, Context& context)
{
    Missile* missile{dynamic_cast<Missile*>(object)};

    if (missile != nullptr)
    {
        remove();
    }
}


