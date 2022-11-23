#include "game_object.h"
#include "map.h"
#include "context.h"
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

int Game_object::get_ground_pos(Context& context, double x)
{
    //HÅRKODAT MÅSTE FIXAS
    int i{1919};

    while (context.map -> foreground_image.getPixel(x , i).a != 0)
    {
        i -= 1;
    }

    return i;

    /*return (static_cast<int>
    (foreground_image.getPixel(object -> icon.getPosition().x, object -> icon.getPosition().y).a) != 0);*/
}