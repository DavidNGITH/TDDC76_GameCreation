#include <stdexcept>
#include <iostream>
//#include "SFML/Graphics.hpp"
#include "PowerUp.h"
//#include "PowerUp.h"
#include "game_object.h"
//#include "context.h"

Powerup::Powerup(double position_x, double position_y)
{
    int randnum = rand() % 2;
    if (randnum == 0)
    {
        //Checks if the file can be loaded
        if (!texture.loadFromFile("shield.png"))
        {
            throw std::runtime_error { "Could not open: 'Powerup.png'" };
        }
    }
    else
    {
        ///Checks if the file can be loaded
        if (!texture.loadFromFile("repair_kit.png"))
        {
            throw std::runtime_error { "Could not open: 'Powerup.png'" };
        }
    }
    
    //Creates the Powerup at the same position as the helicopter.
    icon.setTexture(texture);    
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);    
    icon.setScale(0.1, 0.1);
    icon.setPosition(position_x, position_y + 40);
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
    if (old_position.y == 860) //Hårdkodad nu när vi inte har kollision
    {
        icon.setPosition(old_position.x, old_position.y);
    }
    else
    {
        icon.setPosition(old_position.x, old_position.y + 0.5); //Hårdkodad speed
    }
}

void Powerup::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}


void Powerup::collision(Game_object* object)
{
    //Tom?
    //Kolla om objektet kolliderar med marken
    /*
    if ()
    {
        icon.setPosition(old_position);
    }
    else
    {
        //Uppdatera attribut för player
        remove();
    }*/
}

bool Powerup::check_collision(Game_object* object)
{
    //Kolla om objektet kolliderar med marken
    //if ()
    //{
    //    return true;
    //}

    //Kolla om objektet kolliderar med något annat objekt
    //Skicka till remove
    //else
    //{
        return false;
    //*/

}     

/*bool Powerup::add_powerup()
{
    //På något sätt addera ett objekt av Powerup till spelaren som fick powerupen
}*/