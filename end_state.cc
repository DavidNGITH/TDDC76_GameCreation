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




End_state::End_state(Context& context)
{

    unsigned int width{};
    unsigned int height{};

    round1_texture = set_texture("Textures/round1.png");
    round2_texture = set_texture("Textures/round2.png");
    round3_texture = set_texture("Textures/round3.png");
    background_texture = set_texture("Textures/menu_background.jpg");

    background.setTexture(background_texture);
    width = background_texture.getSize().x;
    height = background_texture.getSize().y;
    background.setOrigin(width/2, height/2);
    background.setPosition(960, 540);
    background.scale(0.6,0.6);


    if(context.round == 1)
    {
        round.setTexture(round1_texture);
        width = round1_texture.getSize().x;
        height = round1_texture.getSize().y;
    }
    else if(context.round == 2)
    {
        round.setTexture(round2_texture);
        width = round2_texture.getSize().x;
        height = round2_texture.getSize().y;
    }
    else
    {
        round.setTexture(round3_texture);
        width = round3_texture.getSize().x;
        height = round3_texture.getSize().y;
    }

    round.setOrigin(width/2, height/2);
    round.setPosition(960,300);

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        context.next_state = new Game_state{context};
    }
}

void End_state::update(Context& context)
{}

void End_state::render(sf::RenderWindow& window, Context& context)
{
    window.draw(background);
    window.draw(round);
}