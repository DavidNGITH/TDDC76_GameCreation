#include "standard_missile.h"
#include "SFML/Graphics.hpp"

#include "context.h"

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


