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
#include <fstream>




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

    sorted_score_list = sort_list(score_list);

    for(int i = 0; i < sorted_score_list.size(); i++)
    {

        ss_name << sorted_score_list[i][0] << std::endl;
        ss_score << sorted_score_list[i][1] << std::endl;
    }
    output_name = ss_name.str();
    list_name.setString(output_name);
    output_score = ss_score.str();
    list_score.setString(output_score);

    writeTo_File(sorted_score_list);




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

void End_state::writeTo_File(std::vector<std::vector<std::string>> sorted_score_list)
{
    std::fstream data_csv;
    data_csv.open("Data_file_1.csv"); //std::ofstream::out | std::ofstream::trunc

    std::string line{""};
    std::vector<std::string> combined_info;
    std::vector<std::vector<std::string>> data_from_csv;
    std::vector<std::vector<std::string>> data_to_csv;

    while (getline(data_csv, line)) {

        std::string name{""};
        std::string high_score{""};
        std::stringstream inputString(line);

        getline(inputString, name, ',');
        getline(inputString, high_score, ',');

        combined_info.push_back(name);
        combined_info.push_back(high_score);
        data_from_csv.push_back(combined_info);
        combined_info.clear();
        line = "";

    }

    data_csv.clear();

    bool found_name{false};
    for (int i = 0; i < sorted_score_list.size(); i++)
    {
        found_name = false;
        for (int j = 0; j < data_from_csv.size(); j++)
        {
            if (data_from_csv[j][0] == sorted_score_list[i][0])
            {
                found_name = true;
                if (stoi(data_from_csv[j][1]) < stoi(sorted_score_list[i][1]))
                {
                    data_from_csv[j][1] = sorted_score_list[i][1];
                }
            }
            
        }
        if (!found_name)
        {
            data_from_csv.push_back(sorted_score_list[i]);
        }
    }

    data_to_csv = sort_list(data_from_csv);
    data_csv.seekp(0);

    for (int k = 0; k < data_to_csv.size(); k++ )
    {
        data_csv << data_to_csv[k][0] << ','
                 << data_to_csv[k][1] << '\n';
    }

    data_csv.close();

}