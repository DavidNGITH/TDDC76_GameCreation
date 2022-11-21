#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SFML/Graphics.hpp"
#include "game_state.h"
#include "menu_state.h"

struct Context; //fwd declartation

class Game_object
{
public:
    Game_object() : icon{}, texture{} {};

    virtual ~Game_object() = default;
    
    virtual void handle(Context& context, sf::Event event) = 0;
    virtual void update(Context& context) = 0;
    virtual void render(sf::RenderWindow& window, Context& context) = 0;
    virtual void collision(Game_object* object) = 0; 
    virtual bool check_collision(Game_object* object) = 0;
    virtual void move(Context& context);
    
    bool is_removed();
    void remove();
    void load_icon(std::string path);

    sf::Sprite icon;

protected:
    bool removed{};
    sf::Texture texture;
    double position_x{};
    double position_y{};
    float speed {};


};
#endif