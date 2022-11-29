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
:speed_x{cos((180-bearing)*M_PI/180)*15*power}, speed_y{sin((180-bearing)*M_PI/180)*(-15*power)}, acceleration_y{400}, expolde{false}
{
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;

    /*missile.setRadius(4);
    missile.setFillColor(sf::Color::Black);
    missile.setOrigin(4, 4);
    missile.setPosition(position_x, position_y);*/

    load_icon("textures_new/ball.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    icon.setPosition(position_x, position_y-10);
    
}

Missile::~Missile()
{

}



void Missile::handle(Context& context, sf::Event event)
{
    //inga inputs som stry missilerna
}

void Missile::update(Context& context)
{
    if(expolde)
    {
        Explosion(context);
        
    }
    else
    {

    
        speed_y += acceleration_y * context.delta.asSeconds();
        position_x += speed_x*context.delta.asSeconds();
        position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
        icon.setPosition(position_x, position_y);

        if(icon.getPosition().x < 0 || icon.getPosition().x > 1920)
        {
            std::cout<< "tog bort" << std::endl;
            context.new_turn = true;
            able_to_move = true;


            remove();
        }
    }


}

void Missile::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);

    window.draw(boom_sprite);
}

void Missile::collision(Game_object* object, Context& context)
{
    // Koliderar tank, helicoter mark eller statiska obeject

    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    if((player !=nullptr || helicopter!=nullptr || static_object!=nullptr || map !=nullptr) && !expolde)
    {
        //Explosion();
        std::cout<< "Kollision" << std::endl;
        if(player != nullptr && context.current_player != player)
        {
            context.current_player -> update_score(context);
        }
        context.new_turn = true;
        able_to_move = true;
        expolde = true;
        
    }

}

void Missile::Explosion(Context& context)
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

    i+= context.delta.asSeconds();
            
    /*load_icon("textures_new/helicopter.png");
    std::cout<< "boom" << std::endl;
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    //icon.setPosition(position_x, position_y);
    icon.setPosition(500, 500);
    icon.setScale(5,5);
    i+= context.delta.asSeconds();
    std::cout<< i << std::endl;
    std::cout<< position_x << position_y << std::endl;
    */



    if(i > 0.5)
    {
        remove();
    }

}
