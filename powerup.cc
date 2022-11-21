//Hårdkodad kod nedan

#include <iostream>
#include "SFML/Graphics.hpp"
#include "PowerUp.h"
#include "game_object.h"
//#include "context.h"

Powerup::Powerup(double incoming_x, double incoming_y) //lägg till coordiante
: speed{200}
{
    position_x = incoming_x;
    position_y = incoming_y + 40;

    int randnum = rand() % 2;

    if (randnum == 0)
    {
        load_icon("shield.png");

        //Creates the Powerup at the same position as the helicopter.    
        sf::Vector2u texture_size { texture.getSize() };
        icon.setOrigin(texture_size.x / 2, texture_size.y / 2);    
        icon.setScale(0.1, 0.1);
        icon.setPosition(position_x, position_y);
    }
    else
    {
        load_icon("repair_kit.png");
        
        //Creates the Powerup at the same position as the helicopter.   
        sf::Vector2u texture_size { texture.getSize() };
        icon.setOrigin(texture_size.x / 2, texture_size.y / 2);    
        icon.setScale(0.1, 0.1);
        icon.setPosition(position_x, position_y + 40);
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
    //Tom? Yesbox
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