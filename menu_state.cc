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
    //load_map("Map/background.png");
    

    unsigned int width{};
    unsigned int height{};

    menu_texture = set_texture("Textures/menu_background.jpg");
    campus_texture = set_texture("Map/campus.png");
    halloween_texture = set_texture("Map/halloween.png");

    campus_foreground_texture = set_texture("Map/campus_foreground.png");
    halloween_foreground_texture = set_texture("Map/halloween_foreground.png");



    start_button_texture = set_texture("Textures/start_game.png");
    start_button.setTexture(start_button_texture);
    width = start_button_texture.getSize().x;
    height = start_button_texture.getSize().y;
    start_button.setOrigin(width/2, height/2);
    start_button.setPosition(960, 480);
    start_button.setScale(0.5,0.5);
    
    map_texture = set_texture("Textures/map.png");
    map.setTexture(map_texture);
    width = map_texture.getSize().x;
    height = map_texture.getSize().y;
    map.setOrigin(width/2, height/2);
    map.setPosition(380, 850);
    map.setScale(0.5,0.5);

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

    map_selection_texture = set_texture("Textures/map_selection.png");
    map_selection.setTexture(map_selection_texture);
    width = map_selection_texture.getSize().x;
    height = map_selection_texture.getSize().y;
    map_selection.setOrigin(width/2, height/2);
    map_selection.setPosition(0, 0);
    map_selection.setScale(0.12,0.12);
    map_selection.setColor(sf::Color::Black);

    
    halloween.setTexture(halloween_texture);
    width = halloween_texture.getSize().x;
    height = halloween_texture.getSize().y;
    halloween.setOrigin(width/2, height/2);
    halloween.setPosition(650, 850);
    halloween.setScale(0.1,0.1);

    campus.setTexture(campus_texture);
    width = campus_texture.getSize().x;
    height = campus_texture.getSize().y;
    campus.setOrigin(width/2, height/2);
    campus.setPosition(950, 850);
    campus.setScale(0.1,0.1);

    halloween_foreground.setTexture(halloween_foreground_texture);
    width = halloween_foreground_texture.getSize().x;
    height = halloween_foreground_texture.getSize().y;
    halloween_foreground.setOrigin(width/2, height/2);
    halloween_foreground.setPosition(650, 850);
    halloween_foreground.setScale(0.1,0.1);

    campus_foreground.setTexture(campus_foreground_texture);
    width = campus_foreground_texture.getSize().x;
    height = campus_foreground_texture.getSize().y;
    campus_foreground.setOrigin(width/2, height/2);
    campus_foreground.setPosition(950, 850);
    campus_foreground.setScale(0.1,0.1);

    add_player_img_texture = set_texture("Textures/add_player_img.png");
    add_player_img.setTexture(add_player_img_texture);
    width = add_player_img_texture.getSize().x;
    height = add_player_img_texture.getSize().y;
    add_player_img.setOrigin(width/2, height/2);
    add_player_img.setPosition(1700, 650);
    add_player_img.setScale(0.25,0.25);

    blue_tank_texture = set_texture("textures_new/blue_tank.png");
    blue_tank.setTexture(blue_tank_texture);
    width = blue_tank_texture.getSize().x;
    height = blue_tank_texture.getSize().y;
    blue_tank.setOrigin(width/2, height/2);
    blue_tank.setPosition(700, 650);
    blue_tank.setScale(2,2);

    cyan_tank_texture = set_texture("textures_new/cyan_tank.png");
    cyan_tank.setTexture(cyan_tank_texture);
    width = cyan_tank_texture.getSize().x;
    height = cyan_tank_texture.getSize().y;
    cyan_tank.setOrigin(width/2, height/2);
    cyan_tank.setPosition(800, 650);
    cyan_tank.setScale(2,2);

    green_tank_texture = set_texture("textures_new/green_tank.png");
    green_tank.setTexture(green_tank_texture);
    width = green_tank_texture.getSize().x;
    height = green_tank_texture.getSize().y;
    green_tank.setOrigin(width/2, height/2);
    green_tank.setPosition(900, 650);
    green_tank.setScale(2,2);

    pink_tank_texture = set_texture("textures_new/pink_tank.png");
    pink_tank.setTexture(pink_tank_texture);
    width = pink_tank_texture.getSize().x;
    height = pink_tank_texture.getSize().y;
    pink_tank.setOrigin(width/2, height/2);
    pink_tank.setPosition(1000, 650);
    pink_tank.setScale(2,2);

    red_tank_texture = set_texture("textures_new/red_tank.png");
    red_tank.setTexture(red_tank_texture);
    width = red_tank_texture.getSize().x;
    height = red_tank_texture.getSize().y;
    red_tank.setOrigin(width/2, height/2);
    red_tank.setPosition(1100, 650);
    red_tank.setScale(2,2);

    yellow_tank_texture = set_texture("textures_new/yellow_tank.png");
    yellow_tank.setTexture(yellow_tank_texture);
    width = yellow_tank_texture.getSize().x;
    height = yellow_tank_texture.getSize().y;
    yellow_tank.setOrigin(width/2, height/2);
    yellow_tank.setPosition(1200, 650);
    yellow_tank.setScale(2,2);

    player_selection.setTexture(map_selection_texture);
    width = map_selection_texture.getSize().x;
    height = map_selection_texture.getSize().y;
    player_selection.setOrigin(width/2, height/2);
    player_selection.setPosition(0, 0);
    player_selection.setScale(0.04,0.06);
    player_selection.setColor(sf::Color::Black);

    input_box_texture = set_texture("textures_new/input_box.png");
    input_box.setTexture(input_box_texture);
    width = input_box_texture.getSize().x;
    height = input_box_texture.getSize().y;
    input_box.setOrigin(width/2, height/2);
    input_box.setPosition(1400, 650);
    input_box.setScale(0.30,0.30);

    font.loadFromFile("Textures/Minecraft.ttf");

    playerText.setPosition(1295,630);
    playerText.setColor(sf::Color::Cyan);
    playerText.setCharacterSize(38);
    playerText.setFont(font);
    playerText.Bold;

    background.setTexture(menu_texture);
    width = menu_texture.getSize().x;
    height = menu_texture.getSize().y;
    background.setOrigin(width/2, height/2);
    background.setPosition(960,540);

    

}


void Menu_state::handle(Context& context, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Event::MouseButtonEvent mouse { event.mouseButton };
        if (mouse.button == sf::Mouse::Button::Left)
        {
            if(start_button.getGlobalBounds().contains(mouse.x,mouse.y))
            {  //start button
                if(map_selection.getPosition().x == campus.getPosition().x && map_selection.getPosition().y == campus.getPosition().y)
                {
                    map_foreground = "Map/campus_foreground.png";
                    map_background = "Map/campus.png";
                }
                else if(map_selection.getPosition().x == halloween.getPosition().x && map_selection.getPosition().y == halloween.getPosition().y)
                {
                    map_foreground = "Map/halloween_foreground.png";
                    map_background = "Map/halloween.png";
                }

                if((players.size() > 1) && (map_selection.getPosition().x != 0))
                {
                    context.map = new Map{map_background, map_foreground};

                    for(unsigned int i{0} ; i < players.size(); i++)
                    {   
                        context.start_players.push_back(new Player(players[i], barrels[i], names[i], context));
                    }
                    context.next_state = new Game_state{context};


                }
                //std::cout<< players.size() << std::endl;

                
                //std::cout << context.players.size() << std::endl;
            }
            else if(add_player_img.getGlobalBounds().contains(mouse.x,mouse.y))
            {
                add_player();
            }
            else if(blue_tank.getGlobalBounds().contains(mouse.x,mouse.y) && !blue_active)
            {
                player_selection.setPosition(blue_tank.getPosition().x, blue_tank.getPosition().y);
                player_selected = true;
                //blue
            }
            else if(cyan_tank.getGlobalBounds().contains(mouse.x,mouse.y) && !cyan_active)
            {
                player_selection.setPosition(cyan_tank.getPosition().x, cyan_tank.getPosition().y);
                player_selected = true;
                //cyan
            }
            else if(green_tank.getGlobalBounds().contains(mouse.x,mouse.y) && !green_active)
            {
                player_selection.setPosition(green_tank.getPosition().x, green_tank.getPosition().y);
                player_selected = true;
                //green
            }
            else if(pink_tank.getGlobalBounds().contains(mouse.x,mouse.y) && !pink_active)
            {
                player_selection.setPosition(pink_tank.getPosition().x, pink_tank.getPosition().y);
                player_selected = true;
                //pink
            }
            else if(red_tank.getGlobalBounds().contains(mouse.x,mouse.y)&& !red_active)
            {
                player_selection.setPosition(red_tank.getPosition().x, red_tank.getPosition().y);
                player_selected = true;
                //red
            }
            else if(yellow_tank.getGlobalBounds().contains(mouse.x,mouse.y) && !yellow_active)
            {
                player_selection.setPosition(yellow_tank.getPosition().x, yellow_tank.getPosition().y);
                player_selected = true;
                //yellow
            }
            else if(campus.getGlobalBounds().contains(mouse.x,mouse.y))
            {
                map_selection.setPosition(campus.getPosition().x, campus.getPosition().y);
                map_selected = true;
                //background.setTexture(campus_texture);
                //campus
            }
            else if(halloween.getGlobalBounds().contains(mouse.x,mouse.y))
            {
                map_selection.setPosition(halloween.getPosition().x, halloween.getPosition().y);
                map_selected = true;
                //background.setTexture(halloween_texture);
                //campus
            }
            


                
           
        }

    }
    if(playerInput.length() < 7)
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

    window.draw(map);

    window.draw(campus);

    window.draw(halloween);

    window.draw(campus_foreground);

    window.draw(halloween_foreground);

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
        window.draw(map_selection);
    }
}

void Menu_state::add_player()
{
    if(player_selection.getPosition().x == blue_tank.getPosition().x && player_selection.getPosition().y == blue_tank.getPosition().y)
    {   
        //blue
        //std::cout << "blue_tank_added" << std::endl;
        blue_active = true;
        player_selected = false;
        players.push_back("textures_new/blue_tank.png");
        barrels.push_back("textures_new/blue_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);

        
    }
    else if(player_selection.getPosition().x == cyan_tank.getPosition().x && player_selection.getPosition().y == cyan_tank.getPosition().y)
    {   
        //cyan
        //std::cout << "cyan_tank_added" << std::endl;
        cyan_active = true;
        player_selected = false;
        players.push_back("textures_new/cyan_tank.png");
        barrels.push_back("textures_new/cyan_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == green_tank.getPosition().x && player_selection.getPosition().y == green_tank.getPosition().y)
    {   
        //green
        //std::cout << "green_tank_added" << std::endl;
        green_active = true;
        player_selected = false;
        players.push_back("textures_new/green_tank.png");
        barrels.push_back("textures_new/green_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == pink_tank.getPosition().x && player_selection.getPosition().y == pink_tank.getPosition().y)
    {   
        //pink
        //std::cout << "pink_tank_added" << std::endl;
        pink_active = true;
        player_selected = false;
        players.push_back("textures_new/pink_tank.png");
        barrels.push_back("textures_new/pink_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == red_tank.getPosition().x && player_selection.getPosition().y == red_tank.getPosition().y)
    {
        //red
        //std::cout << "red_tank_added" << std::endl;
        red_active = true;
        player_selected = false;
        players.push_back("textures_new/red_tank.png");
        barrels.push_back("textures_new/red_barrel.png");
        names.push_back(playerInput);

        playerInput = "";
        playerText.setString(playerInput);
    }
    else if(player_selection.getPosition().x == yellow_tank.getPosition().x && player_selection.getPosition().y == yellow_tank.getPosition().y)
    {   
        //yellow
        //std::cout << "yellow_tank_added" << std::endl;
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