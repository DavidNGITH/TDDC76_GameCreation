#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SFML/Graphics.hpp"
#include "game_state.h"

class Game_object : public Game_state
{
public:
    Game_object();
    ~Game_object();
    
    void update();
    void collosion(); 
    void render();
    void handle();




private:
    sf::Sprite icon;
    int position_x{};
    int position_y{};


};
#endif