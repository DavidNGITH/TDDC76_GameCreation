#include <SFML/Graphics.hpp>
#include "end_state.h"
#include <iostream>


End_state::End_state()
{

    unsigned int width{};
    unsigned int height{};

    round1_texture = set_texture("Textures/round1.png");
    round2_texture = set_texture("Textures/round2.png");
    round3_texture = set_texture("Textures/round3.png");
    background_texture = set_texture("Texture/menu_background.jpg");

    background.setTexture(background_texture);
    width = background_texture.getSize().x;
    height = background_texture.getSize().y;
    background.setOrigin(width/2, height/2);
    background.setPosition(0, 0);


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
{}

void End_state::update(Context& context)
{}

void End_state::render(sf::RenderWindow& window, Context& context)
{}