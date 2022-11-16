#include "SFML/Graphics.hpp"

#include "player.h"
#include "context.h"

Player::Player()
{}

void Player::Aim()
{


}

void Player::Fire()
{

}

void Player::handle(Context& context, sf::Event event)
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

void Player::update(Context& context)
{

}

void Player::render(Context& context)
{

}

void Player::Collision()
{

}