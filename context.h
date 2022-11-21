#ifndef CONTEXT_H
#define CONTEXT_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "game_object.h"
#include "state.h"


struct Context
{
    sf::Time                    delta;
    State*                      next_state;
    Game_object*                map;
    std::vector<Game_object*>&  objects;
    std::vector<Game_object*>&  new_objects;
    std::vector<Game_object*>&  players;
    Game_object*                current_player;
    
};

#endif