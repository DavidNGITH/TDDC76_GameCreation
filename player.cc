#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>

//HARD CODED:
Player::Player()//(sf::Texture player_texture)
:bearing(90), hp(100), score(0)
{
    //Hard coded: Read texture file
    if (!texture.loadFromFile("Textures/blue_tank.png"))
    {
        std::cerr << "Can't open: blue_tank.png" << std::endl;
    }


    //Commented away due to hard code above 
    //Set whick tank color/texture this player should have
    //texture = player_texture;

    //Spawns a player in the middle of the map. 
    icon.setTexture(texture);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(0.1, 0.1);
    ////////////// HARD CODED //////////////
    position_x = 900;
    position_y = 880;
    ////////////// HARD CODED //////////////
    icon.setPosition(position_x, position_y);

    

}

void Player::Aim()
{

}

void Player::Fire()
{

}

void Player::handle(Context& context, sf::Event event)
{
    if ( event.type == sf::Event::KeyPressed )   
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            position_x = position_x - speed;
            icon.setPosition (position_x, position_y);
            
        }
        if(event.key.code == sf::Keyboard::Right)
        {
            position_x = position_x + speed;
            icon.setPosition (position_x, position_y);
        }
    }
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

bool Player::check_collision(Game_object* object)
{
    return false;
}