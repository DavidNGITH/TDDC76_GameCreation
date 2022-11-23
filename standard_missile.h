#ifndef Standard_MISSILE_H
#define Standard_MISSILE_H

#include "Missile.h"
#include <string>


class Standard_Missile : public Missile
{
public:
    void Explosion();

private:
    std::string type{"Standard Missile"};
    int const Damage{20}; //bestämd antal hp som missilen skall skada
    int const Exlosion_radius{10}; // bestämd explosions radie





};

#endif