#include "Helicopter.h"
#include "game_object.h"
#include "context.h"
#include "PowerUp.h"
#include "Missile.h"
#include "Mine.h"
#include <iomanip>
#include <iostream>

Helicopter::Helicopter()
:stop_coordinate{0}, is_active{0}, has_stopped{0}, has_dropped{0}, spawn_rate{33}, speed{200}, current_player{nullptr}
{   
    load_icon("textures_new/helicopter.png");

    reset();

    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setScale(0.4,0.4);


}

bool Helicopter::should_spawn()
{
    //check if helicopter should spawn, given it's not already in flight
    int v1 = rand() % 100; //rand int between 0-100
    //std::cout << v1 << std::endl;
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

    //Checks whether the helicopter should spawn after it has had an collision
    
    else
    {   
        
        if (current_player != context.current_player)
        {
            if (should_spawn())
            {
                current_player = context.current_player;
                is_active = 1;
            }      
            else
            {
                current_player = context.current_player;
            } 
        }
    }
}

void Helicopter::render(sf::RenderWindow& window, Context& context)
{
    
    window.draw(icon);
    
}

void Helicopter::collision(Game_object* object, Context& context)
{
    //reset all parameters, and reset position.
    Missile* missile { dynamic_cast<Missile*>(object) };
    Mine* mine { dynamic_cast<Mine*>(object) };

    if (missile != nullptr)
    {
        reset();
    }
    if (mine != nullptr)
    {
        reset();
    }
}

void Helicopter::handle(Context& context, sf::Event event)
{
    //Empty, no inputs to helicopter
}


void Helicopter::create_powerup(Context& context) const
{
    //New Power_Up
    context.new_objects.push_back(new Powerup(position_x, position_y));
}

void Helicopter::stop_position()
{
    //randomizes the stop_position.
    stop_coordinate = ((rand() % 1520) + 200);

}

void Helicopter::reset()
{
    //Hårdkodat
    position_x = -100;
    position_y = 160;

    is_active = 0;
    has_stopped = 0;
    has_dropped = 0;
        
    icon.setPosition(position_x, position_y);

    stop_position();
}

