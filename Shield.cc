#include <stdexcept>
#include "SFML/Graphics.hpp"
#include "Shield.h"
#include "PowerUp.h"

using namespace std;

Shield::Shield()
:position_x{}, position_y{}
{
    //sf::Texture texture { };

    //Checks if the file can be loaded
    if (!texture.loadFromFile("shield.png"))
        {
            throw std::runtime_error { "Could not open: 'shield.png'" };
        }
    
    //Creates the shield at the same position as the helicopter.
    sprite.setTexture(texture);    
    sf::Vector2u texture_size { texture.getSize() };
    sprite.setOrigin(texture_size.x / 2, texture_size.y / 2);    
    sprite.setPosition(position_x, position_y);
}


void Shield::handle(Context& context, sf::Event event)
{
    //Tom?
}

void Shield::update(Context& context)
{
    //Hantera falla från himmelen
    sf::Vector2f old_position { sprite.getPosition() };
    float current_speed { delta.asSeconds() * speed };
}

void Shield::render(sf::RenderWindow& window, Context& context)
{
    window.draw(sprite);
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

void Shield::remove()
{
    //Tar bort objektet från spelplanen
    //Skicka till is_removed
}

bool Shield::is_removed()
{
    //If true skicka till add shield
}
        

bool Shield::add_shield()
{
    //På något sätt addera ett objekt av shield till spelaren som fick powerupen
}