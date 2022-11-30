#include "Missile.h"
#include <cmath>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "Helicopter.h"
#include "static_object.h"
#include "map.h"
#include "context.h"
#include <iostream>
#include "standard_missile.h"

Missile::Missile(double incoming_position_x, double incoming_position_y,double power, double bearing)
:speed_x{cos((180-bearing)*M_PI/180)*15*power}, speed_y{sin((180-bearing)*M_PI/180)*(-15*power)}, acceleration_y{400}, explode{false}, i{0}
{
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;

    load_icon("textures_new/ball.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    icon.setPosition(position_x, position_y-10);
    
}


void Missile::handle(Context& context, sf::Event event)
{
    //inga inputs som stry missilerna
}

void Missile::update(Context& context)
{
    if(explode)
    {
        Explosion(context);
    }
    else
    {
        speed_y += acceleration_y * context.delta.asSeconds();
        position_x += speed_x*context.delta.asSeconds();
        position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
        icon.setPosition(position_x, position_y);
    }
    if(icon.getPosition().x < 0 || icon.getPosition().x > 1920)
    {
        std::cout<< "tog bort" << std::endl;
        context.new_turn = true;
        remove();
    }



}

void Missile::render(sf::RenderWindow& window, Context& context)
{
    if(!explode)
    {
        window.draw(icon);
    }
    else
    {
        window.draw(boom_sprite);
    }
}

void Missile::collision(Game_object* object, Context& context)
{
    // Koliderar tank, helicoter mark eller statiska obeject

    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    if((player !=nullptr || helicopter!=nullptr || static_object!=nullptr) && !explode)
    {
        //Explosion();
        std::cout<< "Kollision" << std::endl;
        if(player != nullptr && context.current_player != player)
        {
            context.current_player -> update_score(context);
        }
        context.new_turn = true;
        explode = true;
        
    }

    if((map !=nullptr) && !explode)
    {
        //Explosion();
        context.hit_pos.x = position_x;
        context.hit_pos.y = position_y;
        std::cout<< "Kollision" << std::endl;
        if(player != nullptr && context.current_player != player)
        {
            context.current_player -> update_score(context);
        }
        context.new_turn = true;
        explode = true;
        
    }

}

void Missile::Explosion(Context& context)
{   
    if(!i)
    {
        if (!boom.loadFromFile("textures_new/boom_2.png"))
        {
            std::cerr << "Can't open: boom.png" << std::endl;
        }

        boom_sprite.setTexture(boom);
            
        ////////////// HARD CODED //////////////
        sf::Vector2u texture_size_boom { boom.getSize() };
        boom_sprite.setOrigin(texture_size_boom.x/2, texture_size_boom.y/2);
        boom_sprite.setScale(0.3, 0.3);
        boom_sprite.setPosition(position_x, position_y);
    }
    
    i+= context.delta.asSeconds();
            
    if(i > 0.5)
    {
        remove();
    }

}
