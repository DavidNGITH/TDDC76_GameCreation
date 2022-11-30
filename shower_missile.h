#ifndef Shower_MISSILE_H
#define Shower_MISSILE_H

#include <string>
#include "Missile.h"

class Shower_Missile : public Missile
{
public:
    Shower_Missile(double  incoming_position_x, double  incoming_position_y, double  speed, double  bearing);

    void update(Context& context) override;

    void split_missile();

private:
    std::string type{"Shower Missile"};
    int const Damage{20}; //Skadar 20 hp per missil som träffar
    float const Exlosion_radius{10};
    bool if_split{};




};

#endif