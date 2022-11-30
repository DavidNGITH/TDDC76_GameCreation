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



Split_Missile::Split_Missile(double incoming_position_x, double incoming_position_y,double power, double bearing)
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

void Split_Missile::collision(Game_object* object, Context& context)
{
    // Koliderar tank, helicoter mark eller statiska obeject

    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    if((player !=nullptr || helicopter!=nullptr || static_object!=nullptr || map !=nullptr) && !explode)
    {
        //Explosion();
        std::cout<< "Kollision" << std::endl;
        if(player != nullptr && context.current_player != player)
        {
            context.current_player -> update_score(context);
        }
        explode = true;
        
    }

}