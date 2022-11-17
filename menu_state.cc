#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "context.h"
#include "menu_state.h"
#include "game_state.h"
#include "map.h"


Menu_state::Menu_state()
{
    load_map("Map/background.png");
    

    unsigned int width{};
    unsigned int height{};

    /*
    title_texture = set_texture("Textures/title.png");
    title.setTexture(title_texture);
    title.setPosition(450,100);

    map_texture = set_texture("Textures/map_selection");
    map.setTexture(map_texture);
    map.setPosition(450,500);

    player_texture = set_texture("Textures/map_selection");
    player.setTexture(player_texture);
    player.setPosition(450,900);*/

    

    start_button_texture = set_texture("Textures/start_game.png");
    start_button.setTexture(start_button_texture);
    width = start_button_texture.getSize().x;
    height = start_button_texture.getSize().y;
    start_button.setOrigin(width/2, height/2);
    start_button.setPosition(960, 540);
  
}

void Menu_state::handle(Context& context, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Event::MouseButtonEvent mouse { event.mouseButton };
        if (mouse.button == sf::Mouse::Button::Left)
        {
            context.map = new Map{"Map/background.png", "Map/ground.png"};
            context.next_state = new Game_state{context};
        }
    }
}

void Menu_state::update(Context& context)
{}

void Menu_state::render(sf::RenderWindow& window, Context& context)
{
    window.draw(background);
    //window.draw(title);
    //window.draw(map);
    //window.draw(player);

    window.draw(start_button);

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
    
    background.setTexture(background_texture);
    //sf::Vector2u background_size { background.getSize() };
}

void Menu_state::start_game()
{}

sf::Texture Menu_state::set_texture(std::string path)
{
    sf::Texture texture{};
    if(!texture.loadFromFile(path))
    {
        //Här borde vi throwa något
        std::cerr << "Kan inte öppna title.png" << std::endl;
    }

    return texture;
}