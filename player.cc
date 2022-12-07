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
: hp{100}, score{0}, fuel{100}, bearing{90}, power{50}, curr_weapon{1}, barrel_rotation_speed {30},
  last_missile{nullptr}, old_position{}, barrel_sprite{}, barrel{}, player_name_var{player_name}, name_text{}, font{}, 
  shield_isActive{false}, shield_sprite{}, shield{}, hud{new Hud()}, ammo_array{ 2, 10, 4 }
{
    ////////////// HARD CODED /////////////
    speed = 100;
    //position_x = rand() % (context.map -> get_window_size().x);
    
    able_to_move = true;
    fired=false;
    //std::cout << "Ammo array at 0: " << ammo_array[0] << std::endl;
    //std::cout << "Ammo array at 1: " << ammo_array[1] << std::endl;
    //std::cout << "Ammo array at 2: " << ammo_array[2] << std::endl;
    //std::cout << position_x << std::endl;
    

    ////////// Player name /////////////////////
    font.loadFromFile("Textures/Minecraft.ttf");
    name_text.setFont(font);
    name_text.setCharacterSize(20);
    name_text.setFillColor(sf::Color::Black);
    name_text.setString(player_name_var);
    name_text.setOrigin(name_text.getLocalBounds().width/2,name_text.getLocalBounds().height/2);
    name_text.setPosition(position_x, position_y - 80);
    
    /////////// Player sprite /////////////
    
    load_icon(player_texture);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(1.5, 1.5);

    bool bad_pos{true};

    while(bad_pos)
    {
        position_x = rand() % (context.map -> get_window_size().x-200) + 100;
        position_y = get_ground_pos(context, position_x);
        icon.setPosition(position_x, position_y);
        bad_pos = false;

        for(unsigned long int i{0}; i < context.players.size(); i++)
        {
            if (check_collision(context.players.at(i)))
            {
                bad_pos = true;
            }
        }
    }

    if (!barrel.loadFromFile(barrel_texture))
    {std::cerr << "Can't open: " << barrel_texture << std::endl;}

    barrel_sprite.setTexture(barrel);
    

    sf::Vector2u texture_size_barrel { barrel.getSize() };
    barrel_sprite.setOrigin(texture_size_barrel.x, texture_size_barrel.y / 2);
    barrel_sprite.setScale(1, 1);
    barrel_sprite.setRotation(bearing);
    set_barrel_pos();

}

///////////////////// Destructor ///////////////////
Player::~Player()
{
    //Spara undan det som ska sparas, score
    //Ta bort hud och sen ta bort player
    delete hud;



}

void Player::Fire(Context& context)
{   
    //std::cout << get_ground_pos(context, position_x) << std::endl;
    
    if (!fired)
    {
        if (curr_weapon == 1)
        {
            context.new_objects.push_back(new Standard_Missile{calc_x_position(),
            calc_y_position(), round(power), round(bearing)});
            fired = true;
        }
        else if (ammo_array[curr_weapon - 1] > 0)
        {
            ammo_array[curr_weapon-1] -= 1;

            if (curr_weapon == 2)
            {
                context.new_objects.push_back(new Shower_Missile{calc_x_position(),
                calc_y_position(), round(power), round(bearing)});
            }

            else if (curr_weapon == 3)
            {
                context.new_objects.push_back(new Mine{calc_x_position(),
                calc_y_position(), round(power), round(bearing)});
            }
            fired = true;
        }
        else
        {
            fired = false;
        }
    }
}

void Player::handle(Context& context, sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Fire(context);
        if (fired)
        {
            able_to_move = false;
        }
    }
}

void Player::update(Context& context)
{
    hud -> update(hp, 180 - round(bearing), round(power), fuel, curr_weapon, ammo_array, score, player_name_var);

    if (hp <=0)
    {
        //std::cout << "Här" << std::endl;
        remove();
    }
}

void Player::move(Context& context)
{
    if(able_to_move)
    {    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && fuel > 0)
        {
            old_position = icon.getPosition();
            position_x += context.delta.asSeconds() * -speed;
            position_y = get_ground_pos(context, position_x);
            fuel -= (context.delta.asSeconds()*speed)/10;

            if (icon.getGlobalBounds().left < 0)
            {
                position_x = old_position.x;
                position_y = old_position.y;
            }
            
            set_pos();

        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && fuel > 0)
        {
            old_position = icon.getPosition();
            position_x += context.delta.asSeconds() * speed;
            position_y = get_ground_pos(context, position_x);
            fuel -= (context.delta.asSeconds()*speed)/10;

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
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            if (power <100)
            {
                power += context.delta.asSeconds() * 10;
                //std::cout << power << std::endl;
            }
        
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            if (power >0)
            {
                power -= context.delta.asSeconds() * 10;
                //std::cout << power << std::endl;

            }
        
        }    
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ) 
        {
            curr_weapon = 1;
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)  )
        {
            curr_weapon = 2;
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))  
        {
            curr_weapon = 3;
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
            //std::cout << "Collided with shield" << std::endl;
            ////////////////////// Hard coded: Read texture file
            
            if (!shield.loadFromFile("textures_new/shield.png"))
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
            //std::cout << "Collided with repair kit" << std::endl;
            hp += 40;
        }
        else if(powerup -> get_poweruptype() == 2)
        {
            ammo_array[2] += 1;
        }
        else if (powerup -> get_poweruptype() == 3)
        {
            ammo_array[1] += 1;
        }

    }

    /////////////// MISSILE COLLISION /////////////////
    else if (missile != nullptr)
    {
        if (shield_isActive && (context.current_player != this))
        {
            shield_isActive = false;
            //std::cout << "Shield hit!" << std::endl;
            return;
        }
        else
        {
            //////////////////// OBS /////////////////////
            hp -= 50;
            //std::cout << "HP för " << player_name_var << " kvar: " << hp << std::endl;
            update_score(context, 50); //////////////////// OBS /////////////////////
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
    //std::cout << "Distance from player " << player_name_var << ": " << dist_from_player << std::endl;

    if(dist_from_player <= 100)
    {
        missile_dmg = missile_dmg - (dist_from_player/(100/missile_dmg));
        //std::cout << "Missile damage: " << missile_dmg << std::endl;
        hp -= missile_dmg;
        update_score(context, missile_dmg);
    }

    //std::cout << "HP för " << player_name_var << " kvar: " << hp << std::endl;
    
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

void Player::update_score(Context & context, double damage)
{
    //std::cout << "är i update_score" << std::endl;
    if(context.current_player != this)
    {
        Player* player { dynamic_cast<Player*>(context.current_player) };
        //std::cout << "kom in i if-satsen" << std::endl;
        player -> score += damage;
    }


    
}
std::vector<std::string> Player::get_info()
{
    std::vector<std::string> info;

    info.push_back(player_name_var);
    info.push_back(std::to_string(int(score)));

    return info;
}