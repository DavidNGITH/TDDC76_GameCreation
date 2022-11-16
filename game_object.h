#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SFML/Graphics.hpp"
#include "game_state.h"
#include "menu_state.h"

class Game_object
{
public:
    Game_object();
    
    virtual void update(Context& context);
    virtual void Collision(); 
    virtual void render(Context& context);
    virtual void handle(Context& context, sf::Event event);
    virtual bool is_removed();
    virtual void remove();

protected:
    bool removed{};


private:
    sf::Sprite icon;
    sf::Texture texture;
    int position_x{};
    int position_y{};


};
#endif