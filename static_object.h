#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include <SFML/Graphics.hpp>
#include "game_object.h"


class Static_object : public Game_object
{
    public:

    Static_object();

    void update() override;
    void Collision() override; 
    void render(sf::RenderWindow& window) override;
    void handle() override;
    bool is_removed() override;
    void remove() override;

    private:

    bool removed();

    Sf::Sprite tree_sprite;
    Sf::Texture tree_texture;

};

#endif