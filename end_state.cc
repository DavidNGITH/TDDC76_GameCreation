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
}