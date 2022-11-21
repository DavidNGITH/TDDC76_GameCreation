#include "Missile.h"
#include <cmath>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "Helicopter.h"
#include "static_object.h"
#include "map.h"
#include "context.h"
#include <iostream>

Missile::Missile(double incoming_position_x, double incoming_position_y,double speed, double bearing)
:speed_x{cos((bearing)*M_PI/180)*1000}, speed_y{sin((180-bearing)*M_PI/180)*-1000}, acceleration_y{400}
{
    position_x = incoming_position_x;
    position_y = incoming_position_y+10;
    missile.setRadius(5);
    missile.setFillColor(sf::Color::Black);
    missile.setPosition(position_x, position_y);
    
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
    speed_y += acceleration_y * context.delta.asSeconds();
    position_x += speed_x*context.delta.asSeconds();
    position_y += speed_y*context.delta.asSeconds()+ acceleration_y*context.delta.asSeconds()*context.delta.asSeconds()/2;
    missile.setPosition(position_x, position_y);
    std::cout<<position_x <<std::endl;

    if(missile.getPosition().x < 0 || missile.getPosition().x > 1920)
    {
        std::cout<< "tog bort" << std::endl;
        remove();
    }

    //std::cout<< bearing << std::endl;



}

void Missile::render(sf::RenderWindow& window, Context& context)
{
    window.draw(missile);
}

void Missile::collision(Game_object* object)
{
    // Koliderar tank, helicoter mark eller statiska obeject

    Player* player { dynamic_cast<Player*>(object) };
    Helicopter* helicopter { dynamic_cast<Helicopter*>(object) };
    Static_object* static_object { dynamic_cast<Static_object*>(object) };
    Map* map { dynamic_cast<Map*>(object) };

    if(player !=nullptr || helicopter!=nullptr || static_object!=nullptr || map !=nullptr)
    {
        //Explosion();
    }




    // Missil utanför map 
    if(missile.getPosition().x < 0 || missile.getPosition().x > 1920.f)
    {
        std::cout<< "tog bort" << std::endl;
        remove();
    }


}

