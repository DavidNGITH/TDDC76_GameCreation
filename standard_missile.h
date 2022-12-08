#ifndef Standard_MISSILE_H
#define Standard_MISSILE_H

#include "Missile.h"
#include <string>



class Standard_Missile : public Missile
{
public:
    Standard_Missile(Context& context, double incoming_position_x, double incoming_position_y, double speed, double bearing);

private:
    std::string type{"Standard Missile"};
    //int const Damage{20}; //bestämd antal hp som missilen skall skada





};

#endif