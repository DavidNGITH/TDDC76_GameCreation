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




//HARD CODED //MBY not anymore/////////////////////////

///////////// Constructor /////////////////////
Player::Player(std::string player_texture, std::string barrel_texture, std::string player_name, Context& context)
: hp{context.settings["player"]["start_hp"].asInt()}, dmg_radius{context.settings["player"]["dmg_radius"].asInt()}, score{context.settings["player"]["start_score"].asDouble()}, 
  fuel{context.settings["player"]["start_fuel"].asDouble()}, bearing{context.settings["player"]["start_bearing"].asDouble()}, 
  power{context.settings["player"]["start_power"].asDouble()}, curr_weapon{context.settings["player"]["start_weapon"].asInt()}, 
  barrel_rotation_speed{context.settings["player"]["barrel_rotation_speed"].asFloat()}, last_missile{nullptr}, old_position{}, 
  barrel_sprite{}, barrel{}, player_name_var{player_name}, name_text{}, font{}, shield_isActive{false}, shield_sprite{}, shield{}, 
  hud{new Hud()}, ammo_array{ context.settings["player"]["start_standard_ammo"].asInt(), context.settings["player"]["start_shower_ammo"].asInt(), context.settings["player"]["start_mine_ammo"].asInt() }

{
    speed = context.settings["player"]["speed"].asInt();
    
    able_to_move = true;
    fired=false;    

    /////////// Player sprite /////////////
    load_icon(player_texture);
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(1.5, 1.5);

    bool bad_pos{true};

    while(bad_pos)
    {
        position_x = rand() % (context.map -> get_window_size().x - context.settings["map"]["align_pos"].asInt()) + context.settings["map"]["align_pos"].asInt()/2;
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

    ////////// Player name /////////////////////
    font.loadFromFile("Textures/Minecraft.ttf");
    name_text.setFont(font);
    name_text.setCharacterSize(20);
    name_text.setColor(sf::Color::Black);
    name_text.setString(player_name_var);
    name_text.setOrigin(name_text.getLocalBounds().width/2,name_text.getLocalBounds().height/2);
    name_text.setPosition(position_x, position_y - context.settings["player"]["player_text_pos"].asInt());
    

    if (!barrel.loadFromFile(barrel_texture))
    {std::cerr << "Can't open: " << barrel_texture << std::endl;}

    barrel_sprite.setTexture(barrel);
    

    sf::Vector2u texture_size_barrel { barrel.getSize() };
    barrel_sprite.setOrigin(texture_size_barrel.x, texture_size_barrel.y / 2);
    barrel_sprite.setScale(1, 1);
    barrel_sprite.setRotation(bearing);
    set_barrel_pos(context);

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
    
    if (!fired)
    {
        if (curr_weapon == 1)
        {
            context.new_objects.push_back(new Standard_Missile{context, calc_x_position(),
            calc_y_position(), round(power), round(bearing)});
            fired = true;
        }
        else if (ammo_array[curr_weapon - 1] > 0)
        {
            ammo_array[curr_weapon-1] -= 1;

            if (curr_weapon == 2)
            {
                context.new_objects.push_back(new Shower_Missile{context, calc_x_position(),
                calc_y_position(), round(power), round(bearing)});
            }

            else if (curr_weapon == 3)
            {
                context.new_objects.push_back(new Mine{context, calc_x_position(),
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
            
            set_pos(context);

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
            
            set_pos(context);

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
            }
        
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            if (power >0)
            {
                power -= context.delta.asSeconds() * 10;

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
    Missile* missile { dynamic_cast<Missile*>(object) };

    
    /////////////// Static object (tree) Collision /////////////////
    if (other_player != nullptr || static_object != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        set_pos(context);
    }
    
    if (other_player != nullptr)
    {
        position_x = old_position.x;
        position_y = old_position.y;

        icon.setPosition(position_x, position_y);
        set_barrel_pos(context);
        set_name_pos(context);
    }


    ////////////// Powerup collision ///////////////////7//
    else if (powerup != nullptr)
    {
        
        if ((powerup -> get_poweruptype() == 0) && (shield_isActive == false))
        {
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
            set_shield_pos(context);
            shield_isActive = true;

        }
        else if(powerup -> get_poweruptype() == 1)
        {
            hp += context.settings["player"]["health_boost"].asInt();
        }
        else if(powerup -> get_poweruptype() == 2)
        {
            ammo_array[2] += 1;
        }
        else if (powerup -> get_poweruptype() == 3)
        {
            ammo_array[1] += 1;
        }
        else if (powerup -> get_poweruptype() == 4)
        {
            fuel += 50;
        }

    }

    /////////////// MISSILE COLLISION /////////////////
    else if (missile != nullptr)
    {
        if (shield_isActive) // && (context.current_player != this))
        {
            shield_isActive = false;
            return;
        }
        else
        {
            hp -= missile->dmg;
            std::cout << player_name_var << " - damage: " << missile -> dmg << std::endl;
            if(missile -> this_player != this)
            {
                Player* player { dynamic_cast<Player*>(missile -> this_player) };
                player -> update_score(missile -> dmg);
            }
        }
    }

    else if (context.missile != nullptr)
    {
        Missile* missile { dynamic_cast<Missile*>(context.missile) };
        check_damage(context, missile);
    }
}

void Player::check_damage(Context& context, Missile* missile) 
{
    double dist_from_player{};

    dist_from_player = sqrt((pow((context.missile -> position_x - position_x), 2) 
    + pow((context.missile -> position_y - position_y), 2)));

    if(dist_from_player <= dmg_radius) // dmg radius = 100
    {
        if (shield_isActive && (context.current_player != this))
        {
            shield_isActive = false;
            return;
        }

        int missile_dmg = (missile -> dmg - (dist_from_player/(dmg_radius/(missile -> dmg))));

        hp -= missile_dmg;
        std::cout << player_name_var << " - damage: " << missile_dmg << std::endl;
        
        if(missile -> this_player != this)
        {
            Player* player { dynamic_cast<Player*>(missile -> this_player) };
            player -> update_score(missile_dmg);
        }
    }

    
}

void Player::set_pos(Context& context)
{
    icon.setPosition (position_x, position_y);
    set_barrel_pos(context);
    set_shield_pos(context);
    set_name_pos(context);
}

void Player::set_barrel_pos(Context& context)
{
    barrel_sprite.setPosition(position_x, position_y - context.settings["player"]["barrel_pos_y"].asInt());
}

void Player::set_name_pos(Context& context)
{
    name_text.setPosition(position_x, position_y - context.settings["player"]["player_text_pos"].asInt());
}

void Player::set_shield_pos(Context& context) 
{
    shield_sprite.setPosition(position_x, position_y - context.settings["player"]["shield_pos_y"].asInt());
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

void Player::update_score(double damage)
{
    score += damage;
    std::cout << player_name_var << " + score: " << damage << std::endl;   
}

std::vector<std::string> Player::get_info()
{
    std::vector<std::string> info;

    info.push_back(player_name_var);
    info.push_back(std::to_string(int(score)));

    return info;
}