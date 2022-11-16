#include "SFML/Graphics.hpp"
#include "Shield.h"
#include "PowerUp.h"

using namespace std;

Shield::Shield()
:position_x{}, position_y{}
{
    sf::Texture texture { };

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

}

void Shield::update(Context& context)
{
    //Hantera falla från himmelen
}

void Shield::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}


void Shield::Collision()
{
    //Kollar om objektet kolliderar med någonting
    //if kollision --> skicka till collided
}

void Shield::collided()
{
    
}

void Shield::remove()
{

}

bool Shield::is_removed()
{

}
        

bool Shield::add_shield()
{

}