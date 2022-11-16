#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include <vector>
#include "state.h"

class Menu_state : public State
{

    public:
    Menu_state();

    

    //Map map;

    virtual void handle(Context& context, sf::Event event) override;
    virtual void update(Context& context) override;
    virtual void render(sf::RenderWindow& window, Context& context) override;


    //~Menu_state();

    private:
    void add_player();
    void choose_map();
    void load_map(std::string filename);
    void start_game();

    sf::Texture set_texture(std::string path);

    sf::Texture title_texture{};
    sf::Texture map_selection_texture{};
    sf::Texture player_texture{};
    sf::Texture background_texture{};
    sf::Texture start_button_texture{};
    sf::Texture map_border_texture{};
    sf::Texture map_preview_texture{};
    sf::Texture add_player_img_texture{};
    

    sf::Sprite map_selection{};
    sf::Sprite title{};
    sf::Sprite player{};
    sf::Sprite background{};
    sf::Sprite start_button{};
    sf::Sprite map_border{};
    sf::Sprite map_preview{};
    sf::Sprite add_player_img{};


    //std::vector<Player*> players;
   
};




#endif
