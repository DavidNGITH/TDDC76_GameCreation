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
    /*
    hp_text.setFont(font);
    hp_text.setCharacterSize(35);
    hp_text.setColor(sf::Color::Black);
    hp_text.setString("");
    hp_text.setOrigin(hp_text.getLocalBounds().width/2,hp_text.getLocalBounds().height/2);
    */
    text_init(hp_text, 35);
    text_init(player_text, 40);
    text_init(score_text, 35);
    text_init(power_text, 35);
    text_init(bearing_text, 35);

    //hard-coded
    hp_text.setPosition(563, 65);
    player_text.setPosition(522, 6.5);
    bearing_text.setPosition(920, 65);
    score_text.setPosition(1191, 40);
    power_text.setPosition(920, 6.5);
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
    window.draw(power_text);
}

void Hud::update(int player_hp, double player_bearing, double player_score, double player_power, std::string player_string)
{
    hp_text.setString(std::to_string(player_hp));
    player_text.setString(player_string);
    int bearing = player_bearing;
    int score = player_score;
    int power = player_power;
    bearing_text.setString(std::to_string(bearing));
    score_text.setString(std::to_string(score));
    power_text.setString(std::to_string(power));
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

void Hud::text_init(sf::Text& text, int char_size)
{
    text.setFont(font);
    text.setCharacterSize(char_size);
    text.setColor(sf::Color::Black);
    text.setString("");
    text.setOrigin(text.getLocalBounds().width/2,text.getLocalBounds().height/2);
    std::cout << char_size << std::endl;
}