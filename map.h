#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"
#include <string>

#include "game_object.h"

struct Context; //Forward declaration

class Map : public Game_object
{
    public:

    Map(std::string background, std::string foreground);

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void collision(Game_object* object, Context& context) override; 
    bool check_collision(Game_object* object) override;

    sf::Image foreground_image;    

    private:

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    sf::Texture foreground_texture;
    sf::Sprite foreground_sprite;

   

    //auto image = foreground.getTexture().copyToImage();
    //auto color = image.getPixel(1,1);
};
#endif