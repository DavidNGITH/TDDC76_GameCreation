#ifndef Standard_MISSILE_H
#define Standard_MISSILE_H

#include "Missile.h"
#include <string>


class Standard_Missile : public Missile
{
public:

    void Exlosion();




private:
    std::string type{"Standard Missile"};
    int Damage{};
    int Exlosion_radius{};





};

#endif