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
    start_button.setPosition(960, 480);
    start_button.setScale(0.5,0.5);
    
    map_selection_texture = set_texture("Textures/map_selection.png");
    map_selection.setTexture(map_selection_texture);
    width = map_selection_texture.getSize().x;
    height = map_selection_texture.getSize().y;
    map_selection.setOrigin(width/2, height/2);
    map_selection.setPosition(380, 850);
    map_selection.setScale(0.5,0.5);

    player_texture = set_texture("Textures/player.png");
    player.setTexture(player_texture);
    width = player_texture.getSize().x;
    height = player_texture.getSize().y;
    player.setOrigin(width/2, height/2);
    player.setPosition(450, 650);
    player.setScale(0.5,0.5);

    title_texture = set_texture("Textures/title.png");
    title.setTexture(title_texture);
    width = title_texture.getSize().x;
    height = title_texture.getSize().y;
    title.setOrigin(width/2, height/2);
    title.setPosition(960, 200);
    title.setScale(2,2);

    map_border_texture = set_texture("Textures/map_border.png");
    map_border.setTexture(map_border_texture);
    width = map_border_texture.getSize().x;
    height = map_border_texture.getSize().y;
    map_border.setOrigin(width/2, height/2);
    map_border.setPosition(650, 850);
    map_border.setScale(0.12,0.12);

    map_preview_texture = set_texture("Map/background.png");
    map_preview.setTexture(map_preview_texture);
    width = map_preview_texture.getSize().x;
    height = map_preview_texture.getSize().y;
    map_preview.setOrigin(width/2, height/2);
    map_preview.setPosition(650, 850);
    map_preview.setScale(0.1,0.1);

    add_player_img_texture = set_texture("Textures/add_player_img.png");
    add_player_img.setTexture(add_player_img_texture);
    width = add_player_img_texture.getSize().x;
    height = add_player_img_texture.getSize().y;
    add_player_img.setOrigin(width/2, height/2);
    add_player_img.setPosition(1600, 650);
    add_player_img.setScale(0.25,0.25);
}


void Menu_state::handle(Context& context, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Event::MouseButtonEvent mouse { event.mouseButton };
        if (mouse.button == sf::Mouse::Button::Left)
        {
            if((mouse.x > 747.5 && mouse.x < 1173) && (mouse.y > 326 && mouse.y < 574))
            {  

                context.map = new Map{"Map/background.png", "Map/ground.png"};
                context.next_state = new Game_state{context};
            }
            else if((mouse.x > 1500 && mouse.x < 1700) && (mouse.y > 620 && mouse.y < 680))
            {
                std::cout << "hej" << std::endl;
                //add player
            }
        }
    }
}

void Menu_state::update(Context& context)
{}

void Menu_state::render(sf::RenderWindow& window, Context& context)
{
    window.draw(background);

    window.draw(start_button);

    window.draw(title);

    window.draw(player);

    window.draw(map_selection);

    window.draw(map_preview);

    window.draw(map_border);

    window.draw(add_player_img);
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