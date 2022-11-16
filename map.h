#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"
#include <string>

struct Context; //Forward declaration

class Map
{
    public:

    Map(std::string background, std::string foreground);

    //void update(Context& context);

    void render(sf::RenderWindow& window);

    void Collision();

    private:

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    sf::Texture foreground_texture;
    sf::Sprite foreground_sprite;

    //auto image = foreground.getTexture().copyToImage();
    //auto color = image.getPixel(1,1);
};
#endif