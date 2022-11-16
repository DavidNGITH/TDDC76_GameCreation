#include "static_object.h"
#include "SFML/Graphics.hpp"





Static_object()
{
    if(!tree_texture.loadFromFile("Textures/tree.png"))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    };
    
    tree_sprite.setTexture(tree_texture);

};

void update()
{};

void Collision()
{};

void render(sf::RenderWindow& window)
{
    window.draw(tree_sprite);

};

void handle()
{};

bool is_removed()
{};

void remove()
{};

bool removed()
{}