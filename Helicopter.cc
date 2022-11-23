#include "Helicopter.h"
#include "game_object.h"
#include "context.h"
#include "PowerUp.h"
#include <iostream>

Helicopter::Helicopter()
:stop_coordinate{0}, is_active{0}, has_stopped{0}, has_dropped{}, spawn_rate{100}, speed{200}, current_player{nullptr}
{   
    //Hårdkodat
    position_x = 0;
    position_y = 150;

    load_icon("textures_new/helicopter.png");

    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setPosition(position_x, position_y);
    icon.setScale(5,5);

    //sets first stop position
    stop_position();

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
                create_powerup(context);
            }

        }
        
        else 
        {
            if (position_x >= stop_coordinate)
            {
                has_stopped = 1; //helicopter has reached its final destination
            }
            else
            {
                position_x += speed * context.delta.asSeconds();
                icon.setPosition(position_x, position_y); //moves the helicopter in positive x, keeps y.
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


void Helicopter::create_powerup(Context& context) const
{
    //New Power_Up
    context.new_objects.push_back(new Powerup(position_x, position_y));
}

void Helicopter::stop_position()
{
    stop_coordinate = ((rand() % 1520) + 200);
    //randomize stop_position

    
}

