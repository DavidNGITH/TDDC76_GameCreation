#include "standard_missile.h"
#include "SFML/Graphics.hpp"
#include "context.h"
#include <iostream>




void Standard_Missile::Explosion(Context& context)
{
    if(expolde)
    {
    load_icon("textures_new/boom.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    icon.setPosition(position_x, position_y);
        i+= context.delta.asSeconds();
        if(i ==1)
        {
            remove();
        }
    }
}

void Standard_Missile::render(sf::RenderWindow& window, Context& context)
{   
    std::cout << "Standard_missile" << std::endl;

    window.draw(icon);
}

