#include "Helicopter.h"
#include "game_object.h"
#include "context.h"
#include "PowerUp.h"
#include "Missile.h"
#include <cmath>

Helicopter::Helicopter(Context& context)
: stop_coordinate{0}, is_active{0}, has_stopped{0}, has_dropped{}, 
  spawn_rate{context.settings["helicopter"]["spawn_rate"].asInt()}, 
  speed{context.settings["helicopter"]["speed"].asFloat()}, current_player{nullptr}
{   
    load_icon("textures_new/helicopter_2.png");

    reset(context);

    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setScale(1,1);


}

bool Helicopter::should_spawn()
{
    //check if helicopter should spawn, given it's not already in flight
    int v1 = rand() % 100; //rand int between 0-100
    return (v1 <= spawn_rate);
}

void Helicopter::update(Context& context)
{
    if (is_active == 1)
    {
        if (has_stopped == 1)
        {
            if (has_dropped == 1)
            {
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

    if (missile != nullptr)
    {
        reset(context);
    }
}

void Helicopter::handle(Context& context, sf::Event event)
{
    //Empty, no inputs to helicopter
}


void Helicopter::create_powerup(Context& context) const
{
    //New Power_Up
    context.new_objects.push_back(new Powerup(context, position_x, position_y));
}

void Helicopter::stop_position(Context& context)
{
    //randomizes the stop_position.
    stop_coordinate = (rand() % (context.settings["setup"]["width"].asUInt() - 2*context.settings["map"]["align_pos"].asInt())
                       + context.settings["map"]["align_pos"].asInt());
}

void Helicopter::reset(Context& context)
{
    position_x = context.settings["helicopter"]["position_x"].asDouble();
    position_y = context.settings["helicopter"]["position_y"].asDouble();

    is_active = 0;
    has_stopped = 0;
    has_dropped = 0;
        
    icon.setPosition(position_x, position_y);

    stop_position(context);
}

