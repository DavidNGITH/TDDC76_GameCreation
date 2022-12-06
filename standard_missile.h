#ifndef Standard_MISSILE_H
#define Standard_MISSILE_H

#include "Missile.h"
#include <string>



class Standard_Missile : public Missile
{
public:
    Standard_Missile(double  incoming_position_x, double  incoming_position_y, double  speed, double  bearing);
    //void Explosion(Context& context);
    //void render(sf::RenderWindow& window, Context& context) override;

private:
    //sf::CircleShape explosion_2;
    std::string type{"Standard Missile"};
     //bestämd antal hp som missilen skall skada
    //int const Exlosion_radius{10}; // bestämd explosions radie
    //int i{0};





};

#endif