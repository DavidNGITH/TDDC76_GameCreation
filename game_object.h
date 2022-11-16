#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SFML/Graphics.hpp"
#include "game_state.h"
#include "menu_state.h"

struct Context; //fwd declartation

class Game_object
{
public:
    //Game_object() = default;

    virtual ~Game_object() = default;
    
    virtual void update(Context& context) = 0;
    virtual void collision(Game_object* object) = 0; 
    virtual void render(sf::RenderWindow& window, Context& context) = 0;
    virtual void handle(Context& context, sf::Event event) = 0;
    virtual bool is_removed() = 0;
    virtual void remove() = 0;
    virtual bool check_collision(Game_object* object) = 0;

protected:
    bool removed{};


private:
    sf::Sprite icon;
    sf::Texture texture;
    int position_x{};
    int position_y{};


};
#endif