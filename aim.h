#ifndef AIM_H
#define AIM_H
#include "game_object.h"
#include "math.h"

class Aim: Game_object
{
    public:
    
    Aim(Game_object* object, Context& context);
    
    private:
    sf::Texture aim_texture{};
    sf::Sprite aim{};

    double speed_x{};
    double speed_y{};
    double acceleration_y{};

    double bearing{};
    double power{};

    double position_x{};
    double position_y{};

    double t{};
};

#endif