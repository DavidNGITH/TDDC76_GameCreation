#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "game_object.h"
#include <string>

class Player : public Game_object
{
public:
    //HARD CODED:
    Player();//(sf::Texture player_texture);

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;

    void collision(Game_object* object) override;
    bool check_collision(Game_object* object) override;
    void move(Context& context) override;

    


protected:
    int hp{};

private:
    void set_barrel_pos();
    void Aim();
    void Fire();

    double bearing{};
    int score{};
    float const barrel_rotation_speed{};

    sf::Sprite barrel_sprite;
    sf::Texture barrel;
};


#endif