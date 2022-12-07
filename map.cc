#include "map.h"
#include "SFML/Graphics.hpp"
#include <iostream>
//#include <cmath>


Map::Map(std::string background, std::string foreground)
:background_texture{}, background_sprite{}, foreground_texture{}, foreground_sprite{}
{

    if(!background_texture.loadFromFile(background))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(0,0);

    

    if(!foreground_texture.loadFromFile(foreground))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    
    foreground_sprite.setTexture(foreground_texture);
    foreground_sprite.setPosition(0,0);


    if(!foreground_image.loadFromFile(foreground))
    {
        std::cerr << "Kunde inte öppna" << std::endl;
    }
    

}


void Map::render(sf::RenderWindow& window, Context& context)
{
    window.draw(background_sprite);
    window.draw(foreground_sprite);
}

bool Map::check_collision(Game_object* object)
{   
    if (object -> icon.getPosition().y < 500)
    {
        return false;
    }

    return (static_cast<int>
    (foreground_image.getPixel(object -> icon.getPosition().x, object -> icon.getPosition().y).a) != 0);
}

sf::Vector2u Map::get_window_size()
{
    return background_texture.getSize();
}

void Map::handle(Context& context, sf::Event event){};
void Map::update(Context& context){};
void Map::collision(Game_object* object, Context& context){}; 


