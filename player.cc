#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>

Player::Player(sf::Texture player_texture)
:bearing(90), hp(100), score(0)
{
    //Hard coded: Read texture file
    if (!texture.loadFromFile("blue_tank.png"))
    {
        std::cerr << "Can't open: blue_tank.png" << std::endl;
    }


    //Commented away due to hard code above 
    //Set whick tank color/texture this player should have
    //texture = player_texture;

    //Spawns a player in the middle of the map. 
    icon.setTexture(texture);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y / 2);
    icon.setPosition(900, 400);

}

void Player::Aim()
{

}

void Player::Fire()
{

}

void Player::handle(Context& context, sf::Event event)
{

}

void Player::update(Context& context)
{

}

void Player::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}

void Player::collision(Game_object* object)
{
    /*context.current_player -> handle(Context& context, sf::Event event);

    //Check collsion with other
    for (unsigned int i{0}; i < context.active_player.size(); i++)
    {
        for (unsigned int j{i+1}; j < context.active_player.size(); j++)
        {
            if context.active_player.at(i) -> collides(context.active_player.at(j))
            {
                context.active_player.at(i) -> collision(context.active_player.at(j));
                context.active_player.at(j) -> collision(context.active_player.at(1));
            }
        }
    }

    //Check collision with other players
    for (unsigned int i{0}; i < context.players.size(); i++)
    {
        if (current_player -> collides(context.players.at(i)) && current_player != context.players.at(i))
        {
            current_player -> collision(context.players.at(i));
        }
    }*/

}