#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>
#include <string>
#include "context.h"
#include "static_object.h"
#include "Missile.h"
#include "PowerUp.h"
#include <string>
#include <cmath>


//HARD CODED:
Player::Player(std::string player_texture, std::string barrel_texture, std::string player_name, Context& context)
: hp{100}, bearing{90}, score{0}, shield_isActive{false}, playerstring{player_name},
barrel_rotation_speed {30}, old_position{}
{
    ////////////// HARD CODED /////////////
    speed = 100;
    position_x = rand() % (context.map -> get_window_size().x);
    position_y = get_ground_pos(context, position_x);
    //position_y = 878;
    able_to_move = true;
    fired=false;


    ////////////////////// Hard coded: Read texture file

    load_icon(player_texture);

    font.loadFromFile("Textures/Minecraft.ttf");
    name_text.setFont(font);
    name_text.setCharacterSize(20);
    name_text.setColor(sf::Color::Black);
    name_text.setString(player_name);
    name_text.setOrigin(name_text.getLocalBounds().width/2,name_text.getLocalBounds().height/2);
    name_text.setPosition(position_x, position_y - 80);
    
    ////////////// HARD CODED /////////////
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(1.5, 1.5);
    icon.setPosition(position_x, position_y);


    ////////////////////// Hard coded: Read texture file
    if (!barrel.loadFromFile(barrel_texture))
    {
        std::cerr << "Can't open: " << barrel_texture << std::endl;
    }

    barrel_sprite.setTexture(barrel);
    
    ////////////// HARD CODED //////////////
    sf::Vector2u texture_size_barrel { barrel.getSize() };
    barrel_sprite.setOrigin(texture_size_barrel.x, texture_size_barrel.y / 2);
    barrel_sprite.setScale(1, 1);
    barrel_sprite.setRotation(bearing);
    set_barrel_pos();


    hud = new Hud();
    



}

void Player::Aim()
{}

void Player::Fire(Context& context)
{   
    std::cout << get_ground_pos(context, position_x) << std::endl;
    
    if (!fired)
    {
        context.new_objects.push_back(new Missile{calc_x_position(), calc_y_position(), speed, bearing});
        fired = true;
    }
}

void Player::handle(Context& context, sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Fire(context);
        able_to_move = false;
    }
}

void Player::update(Context& context)
{
    hud -> update(hp, bearing, score, playerstring);
}

void Player::move(Context& context)

{
    if(able_to_move)
    {    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            old_position = icon.getPosition();
            position_x += context.delta.asSeconds() * -speed;
            position_y = get_ground_pos(context, position_x);
            icon.setPosition (position_x, position_y);

            set_barrel_pos();
            set_shield_pos();
            set_name_pos();
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            old_position = icon.getPosition();
            position_x += context.delta.asSeconds() * speed;
            position_y = get_ground_pos(context, position_x);
            icon.setPosition (position_x, position_y);

            set_barrel_pos();
            set_shield_pos();
            set_name_pos();
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (bearing <= 180)
            {
                bearing += context.delta.asSeconds() * barrel_rotation_speed;
                barrel_sprite.setRotation(bearing);
                Aim();
            }
            
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (bearing >=0)
            {
                bearing -= context.delta.asSeconds() * barrel_rotation_speed;
                barrel_sprite.setRotation(bearing);
                Aim();
            }

        }
    }    
}

void Player::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
    window.draw(barrel_sprite);
    window.draw(shield_sprite);
    window.draw(name_text);
    if (context.current_player == this)
    {
        hud -> render(window);
    }
}

void Player::collision(Game_object* object, Context& context)
{
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Powerup* powerup { dynamic_cast<Powerup*>(object) };

    if (static_object != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        icon.setPosition(position_x, position_y);
        set_barrel_pos();
        set_name_pos();
    }
    
    
    //Powerup collision//
    else if (powerup != nullptr)
    {
        
        if (powerup -> get_poweruptype() == 0)
        {
            std::cout << "Collided with shield" << std::endl;
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
            std::cout << "Collided with repair kit" << std::endl;
            hp += 20;
        }
    }
}


void Player::set_barrel_pos()
{
    barrel_sprite.setPosition(position_x, position_y - 17);

}

void Player::set_name_pos()
{
    name_text.setPosition(position_x, position_y - 80);
    
}

void Player::set_shield_pos() 
{
    shield_sprite.setPosition(position_x, position_y - 17);
}

double Player::get_bearing() const&
{
    return bearing;
}

int Player::get_score() const&
{
    return score;
}


void Player::reset()
{
    fired = false;
}

double Player::calc_x_position()
{
    return position_x - cos(bearing*M_PI/180) * barrel.getSize().x;
}

double Player::calc_y_position()
{
    return position_y - 30 - sin(bearing * M_PI/180) * barrel.getSize().x;
}