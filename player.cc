#include "SFML/Graphics.hpp"
#include "player.h"
#include <iostream>
#include <string>
#include "context.h"
#include "static_object.h"
#include "Missile.h"
#include "PowerUp.h"
#include "Mine.h"
#include <string>
#include <cmath>
#include "shower_missile.h"
#include "standard_missile.h"
#include "split_missile.h"




//HARD CODED

///////////// Constructor /////////////////////
Player::Player(std::string player_texture, std::string barrel_texture, std::string player_name, Context& context)
:hp{100}, bearing{90}, score{0}, power{50}, shield_isActive{false}, curr_weapon{1},
barrel_rotation_speed {30}, old_position{}, player_name_var{player_name}, last_missile{nullptr}
{
    ////////////// HARD CODED /////////////
    speed = 100;
    //position_x = rand() % (context.map -> get_window_size().x);
    position_x = rand() % (context.map -> get_window_size().x-200 + 1) + 100;
    position_y = get_ground_pos(context, position_x);
    able_to_move = true;
    fired=false;
    std::cout << "Ammo array at 0: " << ammo_array[0] << std::endl;
    std::cout << "Ammo array at 1: " << ammo_array[1] << std::endl;
    std::cout << "Ammo array at 2: " << ammo_array[2] << std::endl;
    std::cout << position_x << std::endl;
    

    ////////// Player name /////////////////////
    font.loadFromFile("Textures/Minecraft.ttf");
    name_text.setFont(font);
    name_text.setCharacterSize(20);
    name_text.setColor(sf::Color::Black);
    name_text.setString(player_name_var);
    name_text.setOrigin(name_text.getLocalBounds().width/2,name_text.getLocalBounds().height/2);
    name_text.setPosition(position_x, position_y - 80);
    
    /////////// Player sprite /////////////
    load_icon(player_texture);

    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(1.5, 1.5);
    icon.setPosition(position_x, position_y);

    if (!barrel.loadFromFile(barrel_texture))
    {std::cerr << "Can't open: " << barrel_texture << std::endl;}

    barrel_sprite.setTexture(barrel);
    

    sf::Vector2u texture_size_barrel { barrel.getSize() };
    barrel_sprite.setOrigin(texture_size_barrel.x, texture_size_barrel.y / 2);
    barrel_sprite.setScale(1, 1);
    barrel_sprite.setRotation(bearing);
    set_barrel_pos();


    ///////// HUD //////////////
    hud = new Hud();

}

///////////////////// Destructor ///////////////////
/*Player::~Player()
{
    //Spara undan det som ska sparas, score
    //Ta bort hud och sen ta bort player
    hud -> ~Hud();
    delete hud;

    delete context.currentplayer;
    


}*/

void Player::Fire(Context& context)
{   
    std::cout << get_ground_pos(context, position_x) << std::endl;
    
    if (!fired)
    {
        context.new_objects.push_back(new Shower_Missile{calc_x_position(), calc_y_position(), power, bearing});
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
    hud -> update(hp, bearing, power, fuel, curr_weapon, ammo_array, score, player_name_var);
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

            if (icon.getGlobalBounds().left < 0)
            {
                position_x = old_position.x;
                position_y = old_position.y;
            }
            
            set_pos();

        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            old_position = icon.getPosition();
            position_x += context.delta.asSeconds() * speed;
            position_y = get_ground_pos(context, position_x);

            if (icon.getGlobalBounds().left + icon.getGlobalBounds().width > context.map -> get_window_size().x)
            {
                position_x = old_position.x;
                position_y = old_position.y;
            }
            
            set_pos();

        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (bearing <= 180)
            {
                bearing += context.delta.asSeconds() * barrel_rotation_speed;
                barrel_sprite.setRotation(bearing);
            }
            
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (bearing >=0)
            {
                bearing -= context.delta.asSeconds() * barrel_rotation_speed;
                barrel_sprite.setRotation(bearing);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
        {
            if (power <100)
            {
                power += context.delta.asSeconds() * 10;
                std::cout << power << std::endl;
            }
        
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
        {
            if (power >0)
            {
                power -= context.delta.asSeconds() * 10;
                std::cout << power << std::endl;

            }
        
        }    
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ) 
        {
            if (curr_weapon != 1)
            {
                curr_weapon = 1;
            }
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)  )
        {
            if (curr_weapon != 2)
            {
                curr_weapon = 2;
            }
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))  
        {
            if (curr_weapon != 3)
            {
                curr_weapon = 3;
            }
        } 
    }    
}

void Player::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
    window.draw(barrel_sprite);
    if (shield_isActive)
    {
        window.draw(shield_sprite);
    }
    window.draw(name_text);
    if (context.current_player == this)
    {
        hud -> render(window);
    }
}

void Player::collision(Game_object* object, Context& context)
{
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Player* other_player { dynamic_cast<Player*>(object) };
    Powerup* powerup { dynamic_cast<Powerup*>(object) };
    Mine* mine { dynamic_cast<Mine*>(object) };
    Missile* missile { dynamic_cast<Missile*>(object) };

    
    /////////////// Static object (tree) Collision /////////////////
    if (other_player != nullptr || static_object != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        set_pos();
    }
    
    if (other_player != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        icon.setPosition(position_x, position_y);
        set_barrel_pos();
        set_name_pos();
    }


    ////////////// Powerup collision ///////////////////7//
    else if (powerup != nullptr)
    {
        
        if ((powerup -> get_poweruptype() == 0) && (shield_isActive == false))
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
            set_shield_pos();
            shield_isActive = true;

        }
        else if(powerup -> get_poweruptype() == 1)
        {
            std::cout << "Collided with repair kit" << std::endl;
            hp += 20;
        }
    }

    /////////////// MISSILE COLLISION /////////////////
    else if (missile != nullptr)
    {
        if (last_missile != missile)
        {
            last_missile = missile;

            if (shield_isActive && (context.current_player != this))
            {
                shield_isActive = false;
                std::cout << "Shield hit!" << std::endl;
                return;
            }
            else
            {
                hp -= 50;
                std::cout << "HP för " << player_name_var
                        << " kvar: " << hp << std::endl;
            }
        }
    }


    else if (context.hit_pos.x != 0 && context.hit_pos.y != 0)
    {
        check_damage(context, 50.0);
    }
}

void Player::check_damage(Context& context, double missile_dmg) 
{
    double dist_from_player{};
    dist_from_player = sqrt((pow((context.hit_pos.x - position_x), 2) 
    + pow((context.hit_pos.y - position_y), 2)));
    std::cout << "Distance from player " << player_name_var 
              << ": " << dist_from_player << std::endl;

    if(dist_from_player <= 200)
    {
        missile_dmg = missile_dmg - (dist_from_player/(200/missile_dmg));
        std::cout << "Missile damage: " << missile_dmg << std::endl;
        hp -= missile_dmg;
    }

    std::cout << "HP för " << player_name_var
              << " kvar: " << hp << std::endl;
}

void Player::set_pos()
{
    icon.setPosition (position_x, position_y);
    set_barrel_pos();
    set_shield_pos();
    set_name_pos();
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

void Player::reset()
{
    fired = false;
}

double Player::calc_x_position()
{
    return position_x - cos(bearing*M_PI/180) * (barrel.getSize().x + 7);
}

double Player::calc_y_position()
{
    return position_y - 30 - sin(bearing * M_PI/180) * (barrel.getSize().x + 7);
}

void Player::update_score(Context & context)
{
    if(context.current_player == this)
    {
        score += 10;
    }

    
}