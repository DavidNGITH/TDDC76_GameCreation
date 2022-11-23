#include "game_object.h"
#include <iostream>





/////// Memberfunctions ///////
bool Game_object::is_removed()
{
    return removed;
}

void Game_object::remove()
{
    removed = true;
}

void Game_object::move(Context& context)
{
    return;
}

void Game_object::load_icon(std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Can't open file: " << path << std::endl;
    }

    icon.setTexture(texture);
}

bool Game_object::check_collision(Game_object* object)
{
    return icon.getGlobalBounds().intersects(object -> icon.getGlobalBounds());
}