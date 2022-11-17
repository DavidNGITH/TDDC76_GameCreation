#ifndef Shower_MISSILE_H
#define Shower_MISSILE_H

#include <string>
#include "Missile.h"

class Shower_Missile : public Missile
{
public:
    void Explosion();
    void split_missile();






private:
    std::string type{"Shower Missile"};
    int const Damage{20}; //Skadar 20 hp per missil som träffar
    float const Exlosion_radius{10};





};

#endif