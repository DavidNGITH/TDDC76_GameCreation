#ifndef MISSILE_H
#define MISSILE_H

#include "SFML/Graphics.hpp"
//#include "Player.h"
#include "game_object.h"
class Missile
{
public:
// Constructors / destructors
    Missile(int position_x, int position_y);
    virtual ~Missile();

//Functions
    virtual void move();
    virtual void position();
    
//variables
    int bearing{};
    int speed{};




private:
    sf::Sprite icon;
    sf::CircleShape missile;
    sf::Vector2f Velocity;
    sf::Vector2f acceleration_yhut;


};

#endif