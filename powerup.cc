//Hårdkodad kod nedan

#include <iostream>
#include "SFML/Graphics.hpp"
#include "PowerUp.h"
#include "game_object.h"
#include "context.h"
#include "map.h"
#include "player.h"

Powerup::Powerup(double incoming_x, double incoming_y)
: speed{200}, has_stopped{false}
{
    position_x = incoming_x;
    position_y = incoming_y + 120;

    randnum = rand() % 4;

    if (randnum == 0)
    {
        load_icon("shield.png");
    }
    else if (randnum == 1)
    {
        load_icon("repair_kit.png");
    }
    else if (randnum == 2)
    {
        load_icon("ammo_c4.png");
    }
    else
    {
        load_icon("showermissile2.png");
    }
    
    //Creates the Powerup at the same position as the helicopter.   
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);    
    icon.setScale(0.1, 0.1);
    icon.setPosition(position_x, position_y);
    get_poweruptype(); //0 for shield and 1 for repair
}

Powerup::Powerup()
{

}

void Powerup::handle(Context& context, sf::Event event)
{

}

void Powerup::update(Context& context)
{
    if (!has_stopped)
    {
        old_position_x = icon.getPosition().x;
        old_position_y = icon.getPosition().y;
    
        position_y += context.delta.asSeconds() * speed;
        icon.setPosition(position_x, position_y);
    }
   
    
}

void Powerup::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}


void Powerup::collision(Game_object* object, Context& context)
{
    Map* map { dynamic_cast<Map*>(object) };
    Player* player { dynamic_cast<Player*>(object) };

    if (map != nullptr)
    {
        position_x = old_position_x;
        position_y = old_position_y;

        icon.setPosition(position_x, position_y);
        has_stopped = true;
    }
    
    else if (player != nullptr)
    {
        remove();
    }
}

int Powerup::get_poweruptype() const&
{
    //return the value 0 for shield
    //return the value 1 for repair
    return randnum;
}