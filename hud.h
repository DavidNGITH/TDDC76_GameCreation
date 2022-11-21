#ifndef HUD_H
#define HUD_H
#include "SFML/Graphics.hpp"


//struct Context;

class Hud
{
    public:

    Hud();

    //~Helicopter() = default;
    //void handle(Context& context, sf::Event event);
    //void update(Context& context);
    void render(sf::RenderWindow& window);

    private:
    
    int position_x{};
    int position_y{};
    sf::Sprite hud;
    sf::Texture texture;
};



#endif