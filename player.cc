#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>
#include <string>
#include "context.h"
#include "static_object.h"
#include "PowerUp.h"
#include <string>

//HARD CODED:
Player::Player(std::string player_texture, std::string barrel_texture)
: hp{100}, bearing{-90}, score{0}, shield_isActive{false},
barrel_rotation_speed {30}, old_position{}
{
    ////////////// HARD CODED /////////////
    speed = 100;
    position_x = rand() % 1900;
    position_y = 878;


    ////////////////////// Hard coded: Read texture file

    load_icon(player_texture);
    
    ////////////// HARD CODED /////////////
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(0.05, 0.05);
    icon.setPosition(position_x, position_y);


    ////////////////////// Hard coded: Read texture file
    if (!barrel.loadFromFile(barrel_texture))
    {
        std::cerr << "Can't open: " << barrel_texture << std::endl;
    }

    barrel_sprite.setTexture(barrel);
    
    ////////////// HARD CODED //////////////
    sf::Vector2u texture_size_barrel { barrel.getSize() };
    barrel_sprite.setOrigin(10, texture_size_barrel.y / 2);
    barrel_sprite.setScale(0.025, 0.025);
    barrel_sprite.setRotation(bearing);
    set_barrel_pos();

    hud = new Hud;
    



}

void Player::Aim()
{}

void Player::Fire()
{}

void Player::handle(Context& context, sf::Event event)
{}

void Player::update(Context& context)
{}

void Player::move(Context& context)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        old_position = icon.getPosition();
        position_x += context.delta.asSeconds() * -speed;
        icon.setPosition (position_x, position_y);

        set_barrel_pos();
        set_shield_pos();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        old_position = icon.getPosition();
        position_x += context.delta.asSeconds() * speed;
        icon.setPosition (position_x, position_y);

        set_barrel_pos();
        set_shield_pos();
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
    window.draw(shield_sprite);
    hud -> render(window);
}

void Player::collision(Game_object* object)
{
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Powerup* powerup { dynamic_cast<Powerup*>(object) };

    if (static_object != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        icon.setPosition(position_x, position_y);
        set_barrel_pos();
         
    }
    
    
    //Powerup collision//
    else if (powerup != nullptr)
    {
        
        if (powerup -> get_poweruptype() == 0)
        {
            std::cout << "Vi kom in här" << std::endl;
            ////////////////////// Hard coded: Read texture file
            
            if (!shield.loadFromFile("shield.png"))
            {
                std::cerr << "Can't open: shield.png" << std::endl;
            }

            shield_sprite.setTexture(shield);
            
            ////////////// HARD CODED //////////////
            sf::Vector2u texture_size_shield { shield.getSize() };
            shield_sprite.setOrigin((texture_size_shield.x / 2), 
            (texture_size_shield.y / 2));
            shield_sprite.setScale(0.3, 0.3);
            shield_sprite.setPosition(position_x - 3, position_y - 17);
            shield_isActive = true;

        }
        else if(powerup -> get_poweruptype() == 1)
        {
            hp += 20;
        }
    }
}

bool Player::check_collision(Game_object* object)
{
    return false;
}

void Player::set_barrel_pos()
{
    barrel_sprite.setPosition(position_x - 3, position_y - 17);
}

void Player::set_shield_pos()
{
    shield_sprite.setPosition(position_x - 3, position_y - 17);
}

double Player::get_bearing() const&
{
    return bearing;
}

int Player::get_score() const&
{
    return score;
}
