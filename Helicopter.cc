#include "Helicopter.h"
#include "Game_object.h"
#include <iostream>

Helicopter::Helicopter()
:start_position{0}, is_active{0}, spawn_rate{33}, speed{100}
{   
    /*
    sf::Texture texture { };

    //Checks if the file can be loaded
    if (!texture.loadFromFile("helicopter.png"))
    {
        std::cerr << "Kan inte Ã¶ppna: fighter.png" << std::endl;
        return 1;
    }

    //creates the helicopter, spawns it outside the map. 
    sf::Sprite icon  { texture };
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setPosition(-40, 100);
    */

}

bool Helicopter::should_spawn()
{
    //check if helicopter is already in the air
    /*if (is_active == 1) 
    {
        return 0
    }
    else
    {
        v1 = rand() % 100;
        if (v1 <= spawn_rate)
        {
            is_active = 1; //is_active lets system know that an helicopter is in the air
            return 1
        }
        else
        {
            return 0
        }
    }*/
}

void Helicopter::update(Context& context) override
{
    /*sf::Vector2f old_position { icon.getPosition() }; //get the old position

    float active_speed { context.time.asSeconds() * speed} 
    if (should_spawn())*/

}

void Helicopter::render(sf::RenderWindow& window) override
{
    /*
    window.draw(icon);
    */
}

void Helicopter::Collision() override
{

}

bool Helicopter::collides() const
{

}

void Helicopter::create_powerup(double coordinate) const
{

}

double Helicopter::stop_position() const
{

}