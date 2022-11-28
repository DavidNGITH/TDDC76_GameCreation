#ifndef HUD_H
#define HUD_H
#include "SFML/Graphics.hpp"
#include "context.h"


//struct Context;

class Hud
{
    public:

    Hud();

    //~Helicopter() = default;
    //void handle(Context& context, sf::Event event);
    void update(int player_hp, double player_bearing, double player_score, double player_power, std::string playerstring);
    void render(sf::RenderWindow& window);
    void text_init(sf::Text& text, int char_size);

    private:
    
    int position_x{};
    int position_y{};

    std::string playerstring;
    sf::Sprite hud;
    sf::Texture texture;

    sf::Font font;

    sf::Text hp_text;
    sf::Text player_text;
    sf::Text bearing_text;
    sf::Text score_text;
    sf::Text power_text;
};



#endif