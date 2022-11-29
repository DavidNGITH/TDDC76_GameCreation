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
:speed_x{cos((180-bearing)*M_PI/180)*800}, speed_y{sin((180-bearing)*M_PI/180)*-800}, acceleration_y{500}, has_stopped{false}, is_active{false}, explode{false}
{
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;

    load_icon("bomb.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y);
    icon.setScale(0.02, 0.02);
    icon.setPosition(position_x, position_y);
}

Mine::~Mine()
{

}

void Mine::update(Context& context)
{
    if(explode)
    {
        explosion(context);
        //std::cout << "Heeeeej" << std::endl;
    }
    
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
    window.draw(expl_sprite);
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

    if(helicopter != nullptr && !explode)
    {
        std::cout<< "Kollision" << std::endl;
        
        explode = true;
        context.new_turn = true;
        
        
        //remove();
        //explosion(context); //context, position_x, position_y);
        

    }
    else if (static_object != nullptr && !explode)
    {
        std::cout<< "Kollision" << std::endl;
        
        explode = true;
        static_object -> remove();
        context.new_turn = true;
        //remove();

        
        explosion(context); //context, position_x, position_y);
        
    }

    else if (player != nullptr && !explode)
    {
        explode = true;
        //remove();
        //explosion(context); //context, position_x, position_y);
        
        if (!is_active)
        {
            context.new_turn = true;
            
        }
        /*else 
        {
            explosion(context);
        }*/


    }
    
    if (map != nullptr && !is_active)
    {
        position_x = old_position_x;
        position_y = old_position_y;
        icon.setPosition(position_x, position_y);
        

        has_stopped = true;
        is_active = true;
        
        context.new_turn = true;
    }
}

void Mine::explosion(Context& context) //, int incoming_position_x, int incoming_position_y)
{
    //explode = true;
    //remove();

    if (!expl.loadFromFile("explosion.png"))
    {
        std::cerr << "Can't open: explosion.png" << std::endl;
    }

    expl_sprite.setTexture(expl);

    sf::Vector2u texture_size_expl { expl.getSize() };
    expl_sprite.setOrigin((texture_size_expl.x / 2), (texture_size_expl.y/2));
    expl_sprite.setScale(0.1, 0.1);
    expl_sprite.setPosition(position_x, position_y);

    i += context.delta.asSeconds();

    if (i > 0.3)
    {
        std::cout<< "mjölk" << std::endl;
        return;
    }
}