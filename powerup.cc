//Hårdkodad kod nedan

#include <stdexcept>
#include <iostream>
//#include "SFML/Graphics.hpp"
#include "PowerUp.h"
//#include "PowerUp.h"
#include "game_object.h"
#include "context.h"

Powerup::Powerup(double incoming_x, double incoming_y) //lägg till coordiante
: speed{200}
{
    position_x = incoming_x;
    position_y = incoming_y + 40;

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
        icon.setPosition(position_x, position_y);
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
    position_y += context.delta.asSeconds() * speed;
    //float current_speed = speed;

    //if not kollision med mark
    
        icon.setPosition(position_x, position_y);
    
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