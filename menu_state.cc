#include "menu_state.h"

#include "SFML/Graphics.hpp"
#include <iostream>

#include <vector>





Menu_state::Menu_state()
{
    load_map("Map/background.png");

    if(!title_texture.loadFromFile("title.png"))
    {
        std::cerr << "Kan inte öppna title.png" << std::endl;
    }
    
    title.setTexture(title_texture);
    //sf::Vector2u titles_size { titles.getSize() };
    title.setOrigin(450,100);
    title.setPosition(450,100);
    title.setScale(1,1);



    if(!map_texture.loadFromFile("map.png"))
    {
        std::cerr << "Kan inte öppna map.png" << std::endl;
    }
    
    map.setTexture(map_texture);
    //sf::Vector2u maps_size { maps.getSize() };
    map.setOrigin(450,500);
    map.setPosition(450,500);
    map.setScale(1,1);

    
    if(!player_texture.loadFromFile("player.png"))
    {
        std::cerr << "Kan inte öppna player.png" << std::endl;
    }
    
    player.setTexture(player_texture);
    //sf::Vector2u players_size { players.getSize() };
    player.setOrigin(450,900);
    player.setPosition(450,900);
    player.setScale(1,1);

  
}

void Menu_state::handle(Context& context, sf::Event event)
{}

void Menu_state::update(Context& context)
{}

void Menu_state::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(title);
    window.draw(map);
    window.draw(player);

}

void Menu_state::add_player()
{
    //players.pushback(new Player*);
}

void Menu_state::choose_map()
{}

void Menu_state::load_map(std::string filename)
{
    if(!background_texture.loadFromFile(filename))
    {
        std::cerr << "Kan inte öppna:" << filename << std::endl;
    }
    
    background.setTexture(background_texture)
    //sf::Vector2u background_size { background.getSize() };
    background.setOrigin(900,0);
    background.setPosition(900,0);
    background.setScale(1,1);
}

void Menu_state::start_game()
{}