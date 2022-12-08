#ifndef SPLIT_MISSILE_H
#define SPLIT_MISSILE_H

#include "Missile.h"
#include <string>
#include "player.h"




class Split_Missile : public Missile
{

public:
    Split_Missile(Context& context, double  incoming_position_x, double  incoming_position_y, double  speed, double  bearing);

    void collision(Game_object* object, Context& context) override;

    void update(Context& context) override;





};


#endif