#include <cmath>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "Mine.h"
#include "game_object.h"
#include "player.h"
#include "Helicopter.h"
#include "static_object.h"
#include "map.h"
#include "context.h"


Mine::Mine(double incoming_position_x, double incoming_position_y, double speed, double bearing)
:speed_x{cos((180-bearing)*M_PI/180)*800}, speed_y{sin((180-bearing)*M_PI/180)*-800}, acceleration_y{500}, has_stopped{false}, is_active{false}
{
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;

    load_icon("bomb.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(0.02, 0.02);
    icon.setPosition(position_x, position_y);
}

/*Mine::~Mine()
{

}*/

void Mine::update(Context& context)
{
    /*speed_y += acceleration_y * context.delta.asSeconds();
    position_x += speed_x*context.delta.asSeconds();
    position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
    icon.setPosition(position_x, position_y);*/
    //if (!is_active)
    //{
        /*if (is_active)
        {
            context.new_turn = true;
            std::cout << "Vi kom in här i denna kuliga funktionen" << std::endl;
        }*/
        if (!has_stopped)
        {
            //std::cout<< "Här då?" << std::endl;
            speed_y += acceleration_y * context.delta.asSeconds();
            position_x += speed_x*context.delta.asSeconds();
            position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
            icon.setPosition(position_x, position_y);
            old_position_x = icon.getPosition().x;
            old_position_y = icon.getPosition().y;

            if(icon.getPosition().x < 0 || icon.getPosition().x > 1920)
            {
                std::cout<< "tog bort" << std::endl;
                context.new_turn = true;
                remove();
            }
            
        }

    
}

void Mine::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
}

void Mine::handle(Context& context, sf::Event event)
{
    
}


void Mine::collision(Game_object* object, Context& context)
{
    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    if(helicopter!=nullptr)
    {
        std::cout<< "Kollision" << std::endl;
        context.new_turn = true;
        //able_to_move = true;
        
        remove();

    }
    else if (static_object != nullptr)
    {
        std::cout<< "Kollision" << std::endl;
        static_object -> remove();
        context.new_turn = true;

        remove();
        
    }
    //////////////////////// Ta bort new turn senare
    else if (player != nullptr)
    {
        //Damage
        //context.new_turn = true;
        
        remove();
    }
    
    if (map != nullptr && !is_active)
    {
        //context.new_turn = true;
        position_x = old_position_x;
        position_y = old_position_y;
        icon.setPosition(position_x, position_y);
        

        has_stopped = true;
        is_active = true;
        
        context.new_turn = true;
        //able_to_move = true;
    }
}