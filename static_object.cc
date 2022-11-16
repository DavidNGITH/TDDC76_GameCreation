#include "SFML/Graphics.hpp"
#include "static_object.h"


Static_object()
{
    if(!tree_texture.loadFromFile("Textures/tree"))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    
    tree_sprite.setTexture(tree_texture);

};

void update()
{};

void Collision()
{};

void render()
{};

void handle()
{};

bool is_removed()
{};

void remove()
{};

bool removed()
{}