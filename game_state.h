#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SFML/Graphics.hpp"
#include "state.h"
#include "map.h"
#include "context.h"


class Game_state : public State
{
    public:
    //Game_state(Map & map, list<Game_object*> & players);
    Game_state(Context& context);

    //~Game_state() = default;

    void handle(Context& context, sf::Event event) override;

    void update(Context& context) override;

    void render(sf::RenderWindow& window, Context& context) override;

    

    private:
    //Game_object* current_player;

    void delete_all(Context& context);

    int active_player{0};

    bool update_need = false;

    void switch_player(Context& context);

    std::vector<std::vector<std::string>> score_list;
    
};


#endif