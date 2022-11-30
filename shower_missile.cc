#include "shower_missile.h"
#include "context.h"
#include "SFML/Graphics.hpp"
#include "Missile.h"
#include "player.h"
#include <iostream>
#include "standard_missile.h"
#include "split_missile.h"
#include <cmath>



Shower_Missile::Shower_Missile(double incoming_position_x, double incoming_position_y,double power, double bearing)
:if_split{false}
{
    speed_x = cos((180-bearing)*M_PI/180)*12*power;
    speed_y = sin((180-bearing)*M_PI/180)*(-12*power); 
    acceleration_y= 400;
    explode=false;
    i=0;
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;

    load_icon("textures_new/ball.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    icon.setPosition(position_x, position_y-10);
    
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
        position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
        icon.setPosition(position_x, position_y);
        if(icon.getPosition().x < 0 || icon.getPosition().x > 1920)
        {
            context.new_turn = true;
            remove();
        }
        //Create new missiles
        if(speed_y > 0 && !if_split)
        {
            if_split = true;
            std::cout<< "shower" << std::endl;
            std::cout<< speed_x << std::endl;
            
            context.new_objects.push_back(new Split_Missile(position_x-20, position_y, speed_x, 0));
            context.new_objects.push_back(new Split_Missile(position_x+20, position_y, speed_x, 0));
            std::cout<< speed_x << std::endl;
            //context.new_objects.push_back(new Missile{position_x+10, position_y, power, bearing});
        }
    }
}

void Shower_Missile::split_missile()
{

}


