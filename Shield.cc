#include <stdexcept>
//#include "SFML/Graphics.hpp"
#include "Shield.h"
//#include "PowerUp.h"
#include "game_object.h"

Shield::Shield()
:position_x{}, position_y{}, check_collision{false}
{
    //Checks if the file can be loaded
    if (!texture.loadFromFile("shield.png"))
        {
            throw std::runtime_error { "Could not open: 'shield.png'" };
        }
    
    //Creates the shield at the same position as the helicopter.
    icon.setTexture(texture);    
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);    
    icon.setPosition(position_x, position_y);
}


void Shield::handle(Context& context, sf::Event event)
{
    //Tom?
}

void Shield::update(Context& context)
{
    //falla från himmelen
    sf::Vector2f old_position { icon.getPosition() };
    float current_speed { delta.asSeconds() * speed };

    //if not kollision med mark
    
        icon.setPosition(old_position.x, old_position.y + current_speed)
    
}

void Shield::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}


void Shield::Collision()
{
    //Tom?
}

bool Shield::check_collision()
{
    //Kollar om objektet kolliderar med någonting
    //Skicka till remove
}

/*void Shield::remove()
{
    //Tar bort objektet från spelplanen
    //Skicka till is_removed

}

bool Shield::is_removed()
{
    //If true skicka till add shield
}*/
        

/*bool Shield::add_shield()
{
    //På något sätt addera ett objekt av shield till spelaren som fick powerupen
}*/