#include "map.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include <iostream>


Map::Map(std::string background, std::string foreground)
:background_texture{}, background_sprite{}, foreground_texture{}, foreground_sprite{}
{

    if(!background_texture.loadFromFile(background))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    
    background_sprite.setTexture(background_texture);

    

    if(!foreground_texture.loadFromFile(foreground))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    
    foreground_sprite.setTexture(foreground_texture);


    if(!foreground_image.loadFromFile(foreground))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    

}

//Map::update(Context& context)
//{}

void Map::render(sf::RenderWindow& window, Context& context)
{
    window.draw(background_sprite);
    window.draw(foreground_sprite);
}

bool Map::check_collision(Game_object* object)
{   
    return (static_cast<int>
    (foreground_image.getPixel(object -> icon.getPosition().x, object -> icon.getPosition().y).a) != 0);
}

void Map::handle(Context& context, sf::Event event){};
void Map::update(Context& context){};
void Map::collision(Game_object* object, Context& context){}; 


