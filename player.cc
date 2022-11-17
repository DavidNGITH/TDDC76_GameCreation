#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>
#include "context.h"

//HARD CODED:
Player::Player()//(sf::Texture player_texture)
: hp{100}, bearing{-90}, score{0}, barrel_rotation_speed {30}
{
    speed = 100;
    position_x = 900;
    position_y = 880;
    //Commented away due to hard code below 
    //Set whick tank color/texture this player should have
    //texture = player_texture;

    ////////////////////// Hard coded: Read texture file

    load_icon("Textures/blue_tank.png");
    
    ////////////// HARD CODED /////////////
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(0.1, 0.1);
    icon.setPosition(position_x, position_y);


    ////////////////////// Hard coded: Read texture file
    if (!barrel.loadFromFile("Textures/blue_barrel.png"))
    {
        std::cerr << "Can't open: blue_barrel.png" << std::endl;
    }
    
    ////////////// HARD CODED //////////////
    barrel_sprite.setTexture(barrel);
    sf::Vector2u texture_size_barrel { barrel.getSize() };
    barrel_sprite.setOrigin(10, texture_size_barrel.y / 2);
    barrel_sprite.setScale(0.05, 0.05);
    barrel_sprite.setRotation(bearing);
    
    set_barrel_pos();


    

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

void Player::move(Context& context)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position_x += context.delta.asSeconds() * -speed;
        icon.setPosition (position_x, position_y);

        set_barrel_pos();    
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position_x += context.delta.asSeconds() * speed;
        icon.setPosition (position_x, position_y);

        set_barrel_pos();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (bearing <= 0)
        {
            bearing += context.delta.asSeconds() * barrel_rotation_speed;
            barrel_sprite.setRotation(bearing);
        }
        
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (bearing >=-180)
        {
            bearing -= context.delta.asSeconds() * barrel_rotation_speed;
            barrel_sprite.setRotation(bearing);
        }

    }
}

void Player::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
    window.draw(barrel_sprite);
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

void Player::set_barrel_pos()
{
    barrel_sprite.setPosition(position_x - 5, position_y - 35);
}
