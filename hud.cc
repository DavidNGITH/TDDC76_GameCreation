#include "hud.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Hud::Hud()
{
    position_x = 960;
    position_y = 0;


    texture.loadFromFile("Textures/HUD1.png");
    hud.setTexture(texture);
    sf::Vector2u texture_size { texture.getSize() };
    hud.setOrigin(texture_size.x / 2, 0);
    hud.setPosition(position_x, position_y);
    hud.setScale(0.8, 0.7);
}

void Hud::render(sf::RenderWindow& window)
{
    window.draw(hud);
    
}