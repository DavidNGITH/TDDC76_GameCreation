#include "shower_missile.h"
#include "context.h"
#include "SFML/Graphics.hpp"
#include "Missile.h"
#include "player.h"
#include "standard_missile.h"
#include "split_missile.h"
#include <cmath>



Shower_Missile::Shower_Missile(Context& context, double incoming_position_x, double incoming_position_y, double power, double bearing)
:if_split{false}
{
    dmg = context.settings["shower_missile"]["damage"].asDouble();
    speed_x = cos((180-bearing)*M_PI/180)*context.settings["missile"]["power_scale"].asInt()*power;
    speed_y = sin((180-bearing)*M_PI/180)*(-context.settings["missile"]["power_scale"].asInt()*power);
    acceleration_y = context.settings["shower_missile"]["acceleration"].asDouble();
    explode=false;
    explosion_timer=0;
    position_x = incoming_position_x;
    position_y = incoming_position_y;

    load_icon("textures_new/ball.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setPosition(position_x, position_y);

    this_player = context.current_player;
    
}




void Shower_Missile::update(Context& context)
{
    if(explode)
    {
        Explosion(context);
    }
    else
    {
        speed_y += acceleration_y * context.delta.asSeconds();
        position_x += speed_x*context.delta.asSeconds();
        position_y += speed_y*context.delta.asSeconds() + acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
        icon.setPosition(position_x, position_y);
        if(icon.getPosition().x < 0 || icon.getPosition().x > context.settings["setup"]["width"].asInt())
        {
            context.new_turn = true;
            remove();
        }
        //Create new missiles
        if(speed_y > 0 && !if_split)
        {
            if_split = true;
            
            context.new_objects.push_back(new Split_Missile(context, position_x, position_y, 
            speed_x*context.settings["shower_missile"]["acc_1"].asDouble(), context.settings["shower_missile"]["acceleration"].asDouble()));
            context.new_objects.push_back(new Split_Missile(context, position_x, position_y, 
            speed_x*context.settings["shower_missile"]["acc_2"].asDouble(), context.settings["shower_missile"]["acceleration"].asDouble()));
        }
    }
}



