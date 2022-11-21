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
    sf::Texture blue_tank_texture{};
    sf::Texture cyan_tank_texture{};
    sf::Texture green_tank_texture{};
    sf::Texture pink_tank_texture{};
    sf::Texture red_tank_texture{};
    sf::Texture yellow_tank_texture{};
    
    

    sf::Sprite map_selection{};
    sf::Sprite title{};
    sf::Sprite player{};
    sf::Sprite background{};
    sf::Sprite start_button{};
    sf::Sprite map_border{};
    sf::Sprite map_preview{};
    sf::Sprite add_player_img{};
    sf::Sprite blue_tank{};
    sf::Sprite cyan_tank{};
    sf::Sprite green_tank{};
    sf::Sprite pink_tank{};
    sf::Sprite red_tank{};
    sf::Sprite yellow_tank{};
    sf::Sprite player_selection{};

    bool player_selected{};
    bool map_selected{};

    bool blue_active{};
    bool cyan_active{};
    bool pink_active{};
    bool yellow_active{};
    bool green_active{};
    bool red_active{};

    


    std::vector<std::string> players;
    std::vector<std::string> barrels;
   
};




#endif
