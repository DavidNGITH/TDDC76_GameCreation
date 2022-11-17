#include "game_object.h"





/////// Memberfunctions ///////
bool Game_object::is_removed()
{
    return removed;
}

void Game_object::remove()
{
    removed = true;
}