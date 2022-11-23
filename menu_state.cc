#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "context.h"
#include "menu_state.h"
#include "game_state.h"
#include "map.h"
#include "player.h"
#include "hud.h"
#include <string>
//test

Menu_state::Menu_state()
{
    load_map("Map/background.png");
    

    unsigned int width{};
    unsigned int height{};

    

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
    map_border.setPosition(0, 0);
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
    add_player_img.setPosition(1700, 650);
    add_player_img.setScale(0.25,0.25);

    blue_tank_texture = set_texture("Textures/blue_tank.png");
    blue_tank.setTexture(blue_tank_texture);
    width = blue_tank_texture.getSize().x;
    height = blue_tank_texture.getSize().y;
    blue_tank.setOrigin(width/2, height/2);
    blue_tank.setPosition(700, 650);
    blue_tank.setScale(0.10,0.10);

    cyan_tank_texture = set_texture("Textures/cyan_tank.png");
    cyan_tank.setTexture(cyan_tank_texture);
    width = cyan_tank_texture.getSize().x;
    height = cyan_tank_texture.getSize().y;
    cyan_tank.setOrigin(width/2, height/2);
    cyan_tank.setPosition(800, 650);
    cyan_tank.setScale(0.10,0.10);

    green_tank_texture = set_texture("Textures/green_tank.png");
    green_tank.setTexture(green_tank_texture);
    width = green_tank_texture.getSize().x;
    height = green_tank_texture.getSize().y;
    green_tank.setOrigin(width/2, height/2);
    green_tank.setPosition(900, 650);
    green_tank.setScale(0.10,0.10);

    pink_tank_texture = set_texture("Textures/pink_tank.png");
    pink_tank.setTexture(pink_tank_texture);
    width = pink_tank_texture.getSize().x;
    height = pink_tank_texture.getSize().y;
    pink_tank.setOrigin(width/2, height/2);
    pink_tank.setPosition(1000, 650);
    pink_tank.setScale(0.10,0.10);

    red_tank_texture = set_texture("Textures/red_tank.png");
    red_tank.setTexture(red_tank_texture);
    width = red_tank_texture.getSize().x;
    height = red_tank_texture.getSize().y;
    red_tank.setOrigin(width/2, height/2);
    red_tank.setPosition(1100, 650);
    red_tank.setScale(0.10,0.10);

    yellow_tank_texture = set_texture("Textures/yellow_tank.png");
    yellow_tank.setTexture(yellow_tank_texture);
    width = yellow_tank_texture.getSize().x;
    height = yellow_tank_texture.getSize().y;
    yellow_tank.setOrigin(width/2, height/2);
    yellow_tank.setPosition(1200, 650);
    yellow_tank.setScale(0.10,0.10);

    player_selection.setTexture(map_border_texture);
    width = map_border_texture.getSize().x;
    height = map_border_texture.getSize().y;
    player_selection.setOrigin(width/2, height/2);
    player_selection.setPosition(0, 0);
    player_selection.setScale(0.04,0.06);

    input_box_texture = set_texture("textures_new/input_box.png");
    input_box.setTexture(input_box_texture);
    width = input_box_texture.getSize().x;
    height = input_box_texture.getSize().y;
    input_box.setOrigin(width/2, height/2);
    input_box.setPosition(1400, 650);
    input_box.setScale(0.30,0.30);

    font.loadFromFile("Textures/CaviarDreams.ttf");

    playerText.setPosition(1295,615);
    playerText.setColor(sf::Color::Cyan);
    playerText.setCharacterSize(60);
    playerText.setFont(font);
    playerText.Bold;


}


void Menu_state::handle(Context& context, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Event::MouseButtonEvent mouse { event.mouseButton };
        if (mouse.button == sf::Mouse::Button::Left)
        {
            if((mouse.x > 747.5 && mouse.x < 1173) && (mouse.y > 326 && mouse.y < 574))
            {  //start button

                //std::cout<< players.size() << std::endl;
                for(unsigned int i{0} ; i < players.size(); i++)
                {   
                    std::cout << i << std::endl;
                    context.players.push_back(new Player(players[i], barrels[i],names[i]));
                    
                }
                if(!(players.size() == 0))
                {
                    context.map = new Map{"Map/background.png", "Map/ground.png"};
                    context.next_state = new Game_state{context};
                }
                
                std::cout << context.players.size() << std::endl;
            }
            else if((mouse.x > 1600 && mouse.x < 1800) && (mouse.y > 620 && mouse.y < 680))
            {
                add_player();
            }
            else if(((mouse.x > 659 && mouse.x < 741) && (mouse.y > 600 && mouse.y < 700)) && !blue_active)
            {
                player_selection.setPosition(695,650);
                player_selected = true;
                //blue
            }
            else if(((mouse.x > 759 && mouse.x < 841) && (mouse.y > 600 && mouse.y < 700)) && !cyan_active)
            {
                player_selection.setPosition(795,650);
                player_selected = true;
                //cyan
            }
            else if(((mouse.x > 859 && mouse.x < 941) && (mouse.y > 600 && mouse.y < 700)) && !green_active)
            {
                player_selection.setPosition(895,650);
                player_selected = true;
                //green
            }
            else if(((mouse.x > 959 && mouse.x < 1041) && (mouse.y > 600 && mouse.y < 700)) && !pink_active)
            {
                player_selection.setPosition(995,650);
                player_selected = true;
                //pink
            }
            else if(((mouse.x > 1059 && mouse.x < 1141) && (mouse.y > 600 && mouse.y < 700)) && !red_active)
            {
                player_selection.setPosition(1095,650);
                player_selected = true;
                //red
            }
            else if(((mouse.x > 1159 && mouse.x < 1241) && (mouse.y > 600 && mouse.y < 700)) && !yellow_active)
            {
                player_selection.setPosition(1195,650);
                player_selected = true;
                //yellow
            }
            else if(((mouse.x > 458 && mouse.x < 842) && (mouse.y > 742 && mouse.y < 958)))
            {
                map_border.setPosition(650,850);
                map_selected = true;
                //campus
            }
                
           
        }

    }
    if(playerInput.length() < 6)
    {
        if(event.type == sf::Event::TextEntered)
        {
            
            playerInput += static_cast<char>(event.text.unicode);
            playerText.setString(playerInput);
            
        }
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
    {   
        if(playerInput.length() > 0)
        {
            playerInput.pop_back();
            playerText.setString(playerInput);
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

    window.draw(add_player_img);

    window.draw(input_box);

    window.draw(playerText);


    if(!blue_active)
    {
        window.draw(blue_tank);
    }

    if(!red_active)
    {
        window.draw(red_tank);
    }

    if(!cyan_active)
    {
        window.draw(cyan_tank);
    }

    if(!yellow_active)
    {
        window.draw(yellow_tank);
    }

    if(!pink_active)
    {
        window.draw(pink_tank);
    }

    if(!green_active)
    {
        window.draw(green_tank);
    }

    if(player_selected)
    {
        window.draw(player_selection);
    }
    else
    {
        player_selection.setPosition(-100,-100);
    }
    if(map_selected)
    {
        window.draw(map_border);
    }
}

void Menu_state::add_player()
{
    if(player_selection.getPosition().x == 695 && player_selection.getPosition().y == 650)
    {   
        //blue
        std::cout << "blue_tank_added" << std::endl;
        blue_active = true;
        player_selected = false;
        players.push_back("textures_new/blue_tank.png");
        barrels.push_back("textures_new/blue_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);

        
    }
    else if(player_selection.getPosition().x == 795 && player_selection.getPosition().y == 650)
    {   
        //cyan
        std::cout << "cyan_tank_added" << std::endl;
        cyan_active = true;
        player_selected = false;
        players.push_back("textures_new/cyan_tank.png");
        barrels.push_back("textures_new/cyan_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == 895 && player_selection.getPosition().y == 650)
    {   
        //green
        std::cout << "green_tank_added" << std::endl;
        green_active = true;
        player_selected = false;
        players.push_back("textures_new/green_tank.png");
        barrels.push_back("textures_new/green_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == 995 && player_selection.getPosition().y == 650)
    {   
        //pink
        std::cout << "pink_tank_added" << std::endl;
        pink_active = true;
        player_selected = false;
        players.push_back("textures_new/pink_tank.png");
        barrels.push_back("textures_new/pink_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == 1095 && player_selection.getPosition().y == 650)
    {
        //red
        std::cout << "red_tank_added" << std::endl;
        red_active = true;
        player_selected = false;
        players.push_back("textures_new/red_tank.png");
        barrels.push_back("textures_new/red_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == 1195 && player_selection.getPosition().y == 650)
    {   
        //yellow
        std::cout << "yellow_tank_added" << std::endl;
        yellow_active = true;
        player_selected = false;
        players.push_back("textures_new/yellow_tank.png");
        barrels.push_back("textures_new/yellow_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
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