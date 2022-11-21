#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>
#include <string>
#include "context.h"
#include "static_object.h"
#include <string>

//HARD CODED:
Player::Player(std::string player_texture)
: hp{100}, bearing{-90}, score{0}, barrel_rotation_speed {30}, old_position{}
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
    if (!barrel.loadFromFile("Textures/blue_barrel.png"))
    {
        std::cerr << "Can't open: blue_barrel.png" << std::endl;
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
{
    /*
    Skapa text 
    
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
    bearing_text.setPosition ((1920 - bounds.width) / 2, 200);
    //GLÖM EJ WINDOW.DRAW i render!!
    */

    



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
        old_position = icon.getPosition();
        position_x += context.delta.asSeconds() * -speed;
        icon.setPosition (position_x, position_y);

        set_barrel_pos();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        old_position = icon.getPosition();
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
            Aim();
        }
        
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (bearing >=-180)
        {
            bearing -= context.delta.asSeconds() * barrel_rotation_speed;
            barrel_sprite.setRotation(bearing);
            Aim();
        }

    }
}

void Player::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
    window.draw(barrel_sprite);
    hud -> render(window);
}

void Player::collision(Game_object* object)
{
    Static_object* static_object { dynamic_cast<Static_object*>(object) };

    if (static_object != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        icon.setPosition(position_x, position_y);
        set_barrel_pos(); 
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

double Player::get_bearing() const&
{
    return bearing;
}

int Player::get_score() const&
{
    return score;
}

/*void Player::activate_powerup()
{
    Powerup* powerup { dynamic_cast<Powerup*>(object) };
    if (powerup != nullptr)
    {
        powerup.remove();
        if (powerup.get_pwrup_type() == 0)
        {

        }
        else if(powerup.get_pwrup_type() == 1)
        {

        }
        //if collision with shield, load icon shield
        //if collision with repairkit, add HP
    }
    
}*/