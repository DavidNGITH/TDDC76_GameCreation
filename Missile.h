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
    Missile(int position_x, int position_y, int speed, int bearing);
    virtual ~Missile();

//Functions
    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void collision(Game_object* object) override;
    bool check_collision(Game_object* object) override;
//variables
 



private:
    sf::CircleShape missile;

    //variables
    int speed_x{};
    int speed_y{};
    int acceleration_y{};


};

#endif