#ifndef MINE_H
#define MINE_H

#include "Missile.h"
#include "SFML/Graphics.hpp"
#include <vector>

class Mine : public Missile
{
public:
    Mine(double incoming_position_x, double incoming_position_y, double speed, double bearing);

    void update(Context& context) override;

    void collision(Game_object* object, Context& context) override; 

private:
    bool has_stopped{};
    bool is_active{};

    int old_position_x{};
    int old_position_y{};

};

#endif