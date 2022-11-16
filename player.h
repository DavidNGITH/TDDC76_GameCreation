#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "game_object.h"
#include <string>

class Player : public Game_object
{
public:
    Player();

    void Aim();
    void Fire();

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(Context& context) override;
    void Collision() override;



    std::string name{};
    std::string color{};
    int score{};
    //Hud* hud{};

protected:
    int hp{};



private:
    sf::Sprite tank{};
    int bearing{};
    sf::Sprite icon{};
    sf::Texture texture{};



};


#endif