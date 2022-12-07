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
    background_texture = set_texture("Textures/endstate_background.jpg");

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

    list_name.setPosition(600,550);
    list_name.setColor(sf::Color::White);
    list_name.setCharacterSize(70);
    list_name.setFont(font);
    list_name.Bold;

    list_score.setPosition(1200,550);
    list_score.setColor(sf::Color::White);
    list_score.setCharacterSize(70);
    list_score.setFont(font);
    list_score.Bold;

    std::stringstream ss_name;
    std::stringstream ss_score;
    std::string output_name;
    std::string output_score;

    score_lists = sort_list(score_list);

    for(int i = 0; i < score_lists.size(); i++)
    {

        ss_name << score_lists[i][0] << std::endl;
        ss_score << score_lists[i][1] << std::endl;
    }
    output_name = ss_name.str();
    list_name.setString(output_name);
    output_score = ss_score.str();
    list_score.setString(output_score);





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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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
    window.draw(list_name);
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
