#include "Missile.h"
#include <cmath>
#include "SFML/Graphics.hpp"

Missile::Missile(int position_x, int position_y,int speed, int bearing)
:speed_x{cos(bearing)*speed}, speed_y{sin(bearing)*speed}, acceleration_y{4}
{
    missile.setRadius(2);
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
    speed_y += acceleration_y;//* delta
    missile.setPosition(position_x + speed_x,position_y + speed_y);

}

void Missile::render(sf::RenderWindow& window, Context& context)
{
    window.draw(missile);
}

void Missile::collision(Game_object* object)
{
    

}

bool check_collision(Game_object* object)
{

}

