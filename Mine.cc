#include <cmath>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "Mine.h"
#include "player.h"
#include "Helicopter.h"
#include "static_object.h"
#include "map.h"
#include "context.h"

//Konstruktor för minan
Mine::Mine(Context& context, double incoming_position_x, double incoming_position_y, double power, double bearing)
{
    dmg = context.settings["mine"]["damage"].asDouble();
    speed_x = cos((180-bearing)*M_PI/180)*context.settings["missile"]["power_scale"].asInt()*power;
    speed_y = sin((180-bearing)*M_PI/180)*(-context.settings["missile"]["power_scale"].asInt()*power);
    acceleration_y = context.settings["mine"]["acceleration"].asDouble();
    
    explode = false;
    has_stopped = false;
    is_active = false;

    position_x = incoming_position_x;
    position_y = incoming_position_y;

    load_icon("textures_new/bomb.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(0.02, 0.02);
    icon.setPosition(position_x, position_y);
}


void Mine::update(Context& context)
{
    //Kallar på explosionsfunktionen ifall minan kolliderat med något objekt förutom marken
    if(explode)
    {
        Explosion(context);
       
    }
    
    //Annars åker missilen i en parabel
    else if (!has_stopped)
    {
        speed_y += acceleration_y * context.delta.asSeconds();
        position_x += speed_x*context.delta.asSeconds();
        position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
        icon.setPosition(position_x, position_y);
        old_position_x = icon.getPosition().x;
        old_position_y = icon.getPosition().y;

        if(icon.getPosition().x < 0 || icon.getPosition().x > context.settings["setup"]["width"].asInt())
        {
            context.new_turn = true;
            remove();
        }
    }
        
}


//Hanterar kollision med olika objekt
void Mine::collision(Game_object* object, Context& context)
{
    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    //Vid kollidering med helikoptern eller träden exploderar minan och turen går över
    if (( static_object != nullptr || helicopter != nullptr ) && !explode)
    {    
        explode = true;
        context.new_turn = true;
    }

    //Vid kollidering med en spelare exploderar minan och 
    //turen går över bara ifall det är en direkträff
    else if (player != nullptr && !explode)
    {   
        explode = true;
        
        if (!is_active)
        {
            context.new_turn = true;
        }
    }
    
    //Vid kollidering med marken, stannar minan på samma ställe på marken
    if (map != nullptr && !is_active)
    {
        position_x = old_position_x;
        position_y = old_position_y;
        icon.setPosition(position_x, position_y);
        

        has_stopped = true;
        is_active = true;     
        context.new_turn = true;
    }
}