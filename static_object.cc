#include "static_object.h"
#include "SFML/Graphics.hpp"





Static_object::Static_object()
{
    load_icon("Textures/tree.png");
};

void Static_object::handle(Context& context, sf::Event event)
{};

void Static_object::update(Context& context)
{};

void Static_object::render(sf::RenderWindow& window, Context& context)
{
    window.draw(icon);
};

void Static_object::collision(Game_object* object)
{};
