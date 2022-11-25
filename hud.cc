#include "hud.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>


Hud::Hud()
{
    position_x = 960;
    position_y = 0;


    texture.loadFromFile("Textures/HUD1.png");
    hud.setTexture(texture);
    sf::Vector2u texture_size { texture.getSize() };
    hud.setOrigin(texture_size.x / 2, 0);
    hud.setPosition(position_x, position_y);
    hud.setScale(0.8, 0.7);

    font.loadFromFile("Textures/Minecraft.ttf");

    //HP
    hp_text.setFont(font);
    hp_text.setCharacterSize(35);
    hp_text.setColor(sf::Color::Black);
    hp_text.setString("");
    hp_text.setOrigin(hp_text.getLocalBounds().width/2,hp_text.getLocalBounds().height/2);

    //PLAYERNAME
    player_text.setFont(font);
    player_text.setCharacterSize(40);
    player_text.setColor(sf::Color::Black);
    player_text.setString("");
    player_text.setOrigin(player_text.getLocalBounds().width/2,player_text.getLocalBounds().height/2);

    //BEARING
    bearing_text.setFont(font);
    bearing_text.setCharacterSize(35);
    bearing_text.setColor(sf::Color::Black);
    bearing_text.setString("");
    bearing_text.setOrigin(bearing_text.getLocalBounds().width/2,bearing_text.getLocalBounds().height/2);

    //SCORE
    
    score_text.setFont(font);
    score_text.setCharacterSize(35);
    score_text.setColor(sf::Color::Black);
    score_text.setString("");
    score_text.setOrigin(score_text.getLocalBounds().width/2,score_text.getLocalBounds().height/2);
    
    //hard-coded
    hp_text.setPosition(563, 65);
    player_text.setPosition(526, 8);
    bearing_text.setPosition(920, 64);
    
    
    score_text.setPosition(1100, 64);
}

void Hud::render(sf::RenderWindow& window)
{
    //window.draw(hp_text);
    /*window.draw(bearing_text);
    window.draw(score_text);*/
    window.draw(hud);
    window.draw(hp_text);
    window.draw(player_text);
    window.draw(bearing_text);
    window.draw(score_text);
}

void Hud::update(int player_hp, double player_bearing, double player_score, std::string player_string)
{
    hp_text.setString(std::to_string(player_hp));
    player_text.setString(player_string);
    int bearing = player_bearing;
    int score = player_score;
    bearing_text.setString(std::to_string(bearing));
    score_text.setString(std::to_string(score));
}
/*
    sf::Font font{};
    if ( !font.loadFromFile ("Textures/CaviarDreams.ttf") )
    {
        // kunde inte ladda typsnitt
        std::cerr << "Can't open: CaviarDreams.ttf" << std::endl;
    }

    // skapa text objekt
    sf::Text bearing_text { "Aim: " + std::to_string(bearing), font };
    bearing_text.setFillColor(sf::Color::Black);
    auto bounds { bearing_text.getGlobalBounds () };
    bearing_text.setPosition ((1920) / 2 - bounds, 200);
    //GLÖM EJ WINDOW.DRAW i render!!*/