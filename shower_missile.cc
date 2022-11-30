#include "shower_missile.h"
#include "context.h"
#include "SFML/Graphics.hpp"
#include "Missile.h"
#include "player.h"

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
        if(speed_y > 0)
        {
            context.new_objects.push_back(new Missile(position_x-10, position_y, 0 , 0));
            //context.new_objects.push_back(new Missile{position_x+10, position_y, power, bearing});
        }
    }
}

void Shower_Missile::split_missile()
{

}


