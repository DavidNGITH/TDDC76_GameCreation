#ifndef CONTEXT_H
#define CONTEXT_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "game_object.h"
#include "map.h"
#include "state.h"


struct Context
{
    sf::Time                    delta;
    State*                      next_state;
    Map*                        map;
    std::vector<Game_object*>&  objects;
    std::vector<Game_object*>&  new_objects;
    std::vector<Game_object*>&  players;
    Game_object*                current_player;
    bool                        new_turn;
    sf::Vector2f                hit_pos; 
};

#endif