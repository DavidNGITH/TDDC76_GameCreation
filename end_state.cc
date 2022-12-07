#include <SFML/Graphics.hpp>
#include "end_state.h"
#include <iostream>
#include "context.h"
#include "menu_state.h"
#include "game_state.h"
#include <list>
#include <string>
#include <vector>
#include "map.h"
#include "player.h"
#include "hud.h"
#include <sstream>
#include <iomanip>
#include <algorithm>




End_state::End_state(Context& context, std::vector<std::vector<std::string>> score_list)
{

    unsigned int width{};
    unsigned int height{};

    gameover_texture = set_texture("Textures/gameover.png");
    background_texture = set_texture("Textures/menu_background.jpg");

    background.setTexture(background_texture);
    width = background_texture.getSize().x;
    height = background_texture.getSize().y;
    background.setOrigin(width/2, height/2);
    background.setPosition(960, 540);
    background.scale(1,1);



    gameover.setTexture(gameover_texture);
    width = gameover_texture.getSize().x;
    height = gameover_texture.getSize().y;

    gameover.setOrigin(width/2, height/2);
    gameover.setPosition(960,300);

    font.loadFromFile("Textures/Minecraft.ttf");

    list_score.setPosition(700,450);
    list_score.setColor(sf::Color::White);
    list_score.setCharacterSize(70);
    list_score.setFont(font);
    list_score.Bold;

    std::stringstream ss;
    std::string output;

    score_lists = sort_list(score_list);

    for(int i = 0; i < score_lists.size(); i++)
    {

        ss << score_lists[i][0] << std::setfill(' ') << std::setw(10) 
        << score_lists[i][1] << std::flush << std::endl;
    

        
    }
    output = ss.str();
    std::cout << output << std::endl;
    list_score.setString(output);




}

sf::Texture End_state::set_texture(std::string path)
{
    sf::Texture texture{};
    if(!texture.loadFromFile(path))
    {
        //Här borde vi throwa något
        std::cerr << "Kan inte öppna title.png" << std::endl;
    }

    return texture;
}

void End_state::handle(Context& context, sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        context.next_state = new Menu_state{};
    }
}

void End_state::update(Context& context)
{}

void End_state::render(sf::RenderWindow& window, Context& context)
{
    window.draw(background);
    window.draw(gameover);
    window.draw(list_score);
}

std::vector<std::vector<std::string>> End_state::sort_list(std::vector<std::vector<std::string>> unsorted_list)
{

    int m;
    int n;
    std::vector<std::string> temp;
    
    for(m = 0; m < unsorted_list.size(); m++) 
    {
        for(n = m+1; n < unsorted_list.size(); n++)
        { 
            if(stoi(unsorted_list[n][1]) > stoi(unsorted_list[m][1])) 
            {

                temp = unsorted_list[m];
                unsorted_list[m] = unsorted_list[n];
                unsorted_list[n] = temp;
            }
        }
    }

    
    return unsorted_list;
}
