#ifndef MISSILE_H
#define MISSILE_H

#include "SFML/Graphics.hpp"
//#include "Player.h"
#include "game_object.h"
#include <vector>
class Missile : public Game_object
{
public:
// Constructors / destructors
    Missile(double  incoming_position_x, double  incoming_position_y, double  speed, double  bearing);
    virtual ~Missile();

//Functions
    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void collision(Game_object* object, Context& context) override;
    void Explosion(Context& context);
 

protected:
    bool expolde{};

private:
    sf::CircleShape missile;

    //variables
    double speed_x{};
    double speed_y{};
    double acceleration_y{};
    double i{0};


};

#endif