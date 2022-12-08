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

        context.new_turn = true;
        explode = true;
        
    }

    if((map !=nullptr) && !explode)
    {
        //context.hit_pos.x = position_x;
        //context.hit_pos.y = position_y;
        context.missile = this;
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
        boom_sprite.setPosition(position_x, position_y);
        icon.setPosition(0, 0);
    }
    
    i+= context.delta.asSeconds();
    if(i< 0.2)
    {
        boom_sprite.setScale(2*i,2*i);
    }
    
            
    if(i > 0.5)
    {
        remove();
    }

}
