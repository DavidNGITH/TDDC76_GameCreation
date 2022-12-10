#include "Missile.h"
#include <cmath>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "Helicopter.h"
#include "static_object.h"
#include "map.h"
#include "context.h"
#include <iostream>
#include "standard_missile.h"
#include "split_missile.h"



Split_Missile::Split_Missile(Context& context, double incoming_position_x, double incoming_position_y,double same_speed, double bearing)
{
    dmg = context.settings["shower_missile"]["damage"].asDouble(); //dmg för splitmissilerna
    speed_x = same_speed;
    speed_y = 0; 
    acceleration_y= bearing;
    explode=false;
    explosion_timer=0;
    position_x = incoming_position_x;
    position_y = incoming_position_y;

    load_icon("textures_new/ball.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    icon.setPosition(position_x, position_y);

    this_player = context.current_player;
    
}

void Split_Missile::collision(Game_object* object, Context& context)
{
    // Koliderar tank, helicoter mark eller statiska obeject

    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    if((player !=nullptr || helicopter!=nullptr || static_object!=nullptr && !explode))
    {
        explode = true;        
    }

    if (map !=nullptr && !explode)
    {
        context.missile = this;
        explode = true;
    }

}

void Split_Missile::update(Context& context)
{
    if(explode)
    {
        Explosion(context);
    }
    else
    {
        speed_y += acceleration_y * context.delta.asSeconds();
        position_x += speed_x*context.delta.asSeconds();
        position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
        icon.setPosition(position_x, position_y);
    }
    if(icon.getPosition().x < 0 || icon.getPosition().x > 1920)
    {
        remove();
    }
}