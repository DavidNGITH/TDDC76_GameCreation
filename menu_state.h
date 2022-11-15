#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "state.h"

class Menu_state : public State
{

    public:
    Menu_state();

    

    //Map map;

    virtual void handle(Context& context, sf::Event event) override;
    virtual void update(Context& context) override;
    virtual void render(sf::RenderWindow& window) override;


    ~Menu_state();

    private:
    void add_player();
    void choose_map();
    void load_map(std::string filename);
    void start_game();

    sf::Texture title_texture{};
    sf::Texture map_texture{};
    sf::Texture player_texture{};
    sf::Texture background_texture{};
    

    sf::Sprite map{};
    sf::Sprite title{};
    sf::Sprite player{};
    sf::Sprite background{};



    //std::vector<Player*> players;
   
};




#endif
