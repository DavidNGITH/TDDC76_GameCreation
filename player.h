#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "game_object.h"
#include <string>

class Player : public Game_object
{
public:
    Player(sf::Texture player_texture);

    void Aim();
    void Fire();

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void collision(Game_object* object) override;

protected:
    int hp{};

private:
    int bearing{};
    int score{};
};


#endif