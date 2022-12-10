#include "aim.h"
#include "context.h"
#include "player.h"
#include "Missile.h"
#include "standard_missile.h"

Aim::Aim(Game_object* object, Context& context)
{
    Player* player { dynamic_cast<Player*>(object) };
    bearing = player -> get_bearing();
    power = player -> get_power();
    speed_y = sin((180-bearing)*M_PI/180)*(- context.settings["missile"]["power_scale"].asInt()*power); 
    speed_x = cos((180-bearing)*M_PI/180)*context.settings["missile"]["power_scale"].asInt()*power;

    acceleration_y = context.settings["mine"]["acceleration"].asDouble();

    t = (-speed_y + sqrt(pow(speed_y, 2.0) + 200 * acceleration_y))/(acceleration_y);
    position_x = speed_x*t;
    position_y = speed_y*t;

    aim.setPosition(position_x, position_y);
    
}
