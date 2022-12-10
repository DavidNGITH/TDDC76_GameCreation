#ifndef Shower_MISSILE_H
#define Shower_MISSILE_H

#include <string>
#include "Missile.h"

class Shower_Missile : public Missile
{
public:
    Shower_Missile(Context& context, double incoming_position_x, double incoming_position_y, double speed, double bearing);

    void update(Context& context) override;

    void split_missile();

private:
    std::string type{"Shower Missile"};

    bool if_split{};




};

#endif