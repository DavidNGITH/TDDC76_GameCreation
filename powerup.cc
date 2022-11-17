//Hårdkodad kod nedan

#include <stdexcept>
#include <iostream>
//#include "SFML/Graphics.hpp"
#include "PowerUp.h"
//#include "PowerUp.h"
#include "game_object.h"
#include "context.h"

Powerup::Powerup(double position_x, double position_y) //lägg till coordiante
//:int position_y{-45}, int position_x{100}
{
    int randnum = rand() % 2;
    if (randnum == 0)
    {
        //Checks if the file can be loaded
        if (!texture.loadFromFile("shield.png"))
        {
            throw std::runtime_error { "Could not open: 'Powerup.png'" };
        }
    
        //Creates the Powerup at the same position as the helicopter.
        icon.setTexture(texture);    
        sf::Vector2u texture_size { texture.getSize() };
        icon.setOrigin(texture_size.x / 2, texture_size.y / 2);    
        icon.setScale(0.1, 0.1);
        icon.setPosition(position_x, position_y + 40);
    }
    else
    {
        ///Checks if the file can be loaded
        if (!texture.loadFromFile("repair_kit.png"))
        {
            throw std::runtime_error { "Could not open: 'Powerup.png'" };
        }
    
        //Creates the Powerup at the same position as the helicopter.
        icon.setTexture(texture);    
        sf::Vector2u texture_size { texture.getSize() };
        icon.setOrigin(texture_size.x / 2, texture_size.y / 2);    
        icon.setScale(0.1, 0.1);
        icon.setPosition(position_x, position_y + 40);
    }
}

Powerup::Powerup()
{

}



void Powerup::handle(Context& context, sf::Event event)
{
    //Tom?
}

void Powerup::update(Context& context)
{
    //falla från himmelen
    sf::Vector2f old_position { icon.getPosition() };
    //float current_speed = speed;

    //if not kollision med mark
    
        icon.setPosition(old_position.x, old_position.y + 0.5);
    
}

void Powerup::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}


void Powerup::collision(Game_object* object)
{
    //Tom?
}

bool Powerup::check_collision(Game_object* object)
{
    //Kollar om objektet kolliderar med någonting
    //Skicka till remove
    return false;
}     

/*bool Powerup::add_Powerup()
{
    //På något sätt addera ett objekt av Powerup till spelaren som fick powerupen
}*/