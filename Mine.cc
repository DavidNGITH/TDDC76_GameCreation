#include "Mine.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "Helicopter.h"
#include "static_object.h"
#include "map.h"
#include "context.h"
#include <iostream>

Mine::Mine(double incoming_position_x, double incoming_position_y, double speed, double bearing)
:speed_x{cos((180-bearing)*M_PI/180)*800}, speed_y{sin((180-bearing)*M_PI/180)*-800}, acceleration_y{400}
{
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;

    load_icon("bomb.png");
    sf::Vector2u texture_size { texture.getSize() };
    icon.setOrigin(texture_size.x / 2, texture_size.y/2);
    icon.setPosition(position_x, position_y);
}

Mine::~Mine()
{

}

void Mine::update(Context& context)
{
    speed_y += acceleration_y * context.delta.asSeconds();
    position_x += speed_x*context.delta.asSeconds();
    position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
    icon.setPosition(position_x, position_y);

    if(icon.getPosition().x < 0 || icon.getPosition().x > 1920)
    {
        std::cout<< "tog bort" << std::endl;
        context.new_turn = true;
        remove();
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

    if(player !=nullptr || helicopter!=nullptr || static_object!=nullptr || map !=nullptr)
    {
        //Explosion();
        std::cout<< "Kollision" << std::endl;
        context.new_turn = true;
        remove();

    }
}