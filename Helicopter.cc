#include "Helicopter.h"
#include "game_object.h"
#include "context.h"
#include <iostream>

Helicopter::Helicopter()
:stop_coordinate{0}, is_active{0}, has_stopped{0}, has_dropped{}, spawn_rate{100}, speed{1}, current_player{nullptr}
{   

    //Checks if the file can be loaded
    if (!texture.loadFromFile("helicopter.png"))
    {
        std::cerr << "Kan inte Ã¶ppna: helkopeter.png" << std::endl;
        //return 1;
    }

    //creates the helicopter, spawns it outside the map. 
    icon.setTexture(texture);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setPosition(0, 40);

    //sets first stop position
    stop_coordinate = stop_position();
    //current_player = context.current_player

}

bool Helicopter::should_spawn()
{
    //check if helicopter should spawn, given it's not already in flight
    int v1 = rand() % 100; //rand int between 0-100
    if (v1 <= spawn_rate)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Helicopter::update(Context& context)
{
    sf::Vector2f old_position { icon.getPosition() }; //get the old position
    float active_speed = speed;  
    if (is_active == 1)
    {
        if (has_stopped == 1)
        {
            if (has_dropped == 1)
            {
                //stay still
            }
            else
            {
                has_dropped = 1; //lets us know we've dropped the powerup.
                //check for collision
                //drop power up and stop.
                create_powerup();
            }

        }
        
        else 
        {
            if (old_position.x == stop_coordinate)
            {
                has_stopped = 1; //helicopter has reached its final destination
            }
            else
            {
                icon.setPosition(old_position.x + active_speed, old_position.y); //moves the helicopter in positive x, keeps y.
            }
        }
    }

    //first check if it's a new turn, and if it is, run randomize spawn.
    else
    {
        if ((current_player == context.current_player) || (current_player == nullptr))
        {
        
            if (should_spawn())
            {
                current_player = context.current_player;
                is_active = 1;

            }
        }
    }



}

void Helicopter::render(sf::RenderWindow& window, Context& context)
{
    
    window.draw(icon);
    
}

void Helicopter::collision(Game_object* object)
{
    /*//reset all parameters, and reset position.
    //is_active = 0;
    has_stopped = 0;
    has_dropped = 0;
    //icon.setPosition(-40, 100);
    stop_coordinate = stop_position();*/
}

void Helicopter::handle(Context& context, sf::Event event)
{
    //ska vara tom ty inga inputs styr helikoptern.
}

bool Helicopter::check_collision(Game_object* object)
{
    //check if helicopter has collided with a missile.
    return false;
}

void Helicopter::create_powerup() const
{
    //New Power_Up
    //new Powerup(icon.getPosition().x)
}

float Helicopter::stop_position()
{
    stop_coordinate = ((rand() % 1520) + 200);
    return stop_coordinate;
    //randomize stop_position

    
}

