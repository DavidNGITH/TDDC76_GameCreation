#ifndef MISSILE_H
#define MISSILE_H

#include "SFML/Graphics.hpp"
#include "game_object.h"
#include <vector>

class Missile : public Game_object
{
//Functions
public:
    virtual void handle(Context& context, sf::Event event) override;
    virtual void update(Context& context) override;
    virtual void render(sf::RenderWindow& window, Context& context) override;
    virtual void collision(Game_object* object, Context& context) override;
    virtual void Explosion(Context& context);
 
    double dmg{};
    Game_object* this_player{};
protected:
    bool explode{};
    double speed_x{};
    double speed_y{};
    double acceleration_y{};
    double explosion_timer{};
    
    sf::Sprite boom_sprite;
    sf::Texture boom;

};

#endif