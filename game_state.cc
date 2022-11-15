#include "SFML/Graphics.hpp"

#include "game_state.h"

Game_state(Map & map, Context& context)
{
    current_player = context.players[0];
    context.map = map;
}

void Game_state::handle(Context& context, sf::Event event)
{
    context.current_player -> handle(Context& context, sf::Event event);

    //Check collsion with other
    for (unsigned int i{0}; i < context.active_player.size(); i++)
    {
        for (unsigned int j{i+1}; j < context.active_player.size(); j++)
        {
            if context.active_player.at(i) -> collides(context.active_player.at(j))
            {
                context.active_player.at(i) -> collision(context.active_player.at(j));
                context.active_player.at(j) -> collision(context.active_player.at(1));
            }
        }
    }

    //Check collision with other players
    for (unsigned int i{0}; i < context.players.size(); i++)
    {
        if (current_player -> collides(context.players.at(i)) && current_player != context.players.at(i))
        {
            current_player -> collision(context.players.at(i));
        }
    }

    //Check collsion with wall
}

void Game_state::update(Context& context)
{
    //Update players and objects
    context.objects -> update(Context& context)
    context.players -> update(Context& context)

    //Check collision between players and objects
    for (unsigned int i{0}; i < context.players.size(); i++)
    {
        for (unsigned int j{0}; j < context.objects.size(); j++)
        {
            if (context.players.at(i) -> collides(context.objects.at(j)))
            {
                context.players.at(i) -> collision(context.objects.at(j));
                context.objects.at(j) -> collision(context.players.at(i));
            }
        }
    }   

    //Check collsion between objects
    for (unsigned int i{0}; i < context.objects.size(); i++)
    {
        for (unsigned int j{i+1}; j < context.objects.size(); j++)
        {
            if (context.objects.at(i) -> collides(context.objects.at(j))
            {
                context.objects.at(i) -> collision(context.objects.at(j));
                context.objects.at(j) -> collision(context.objects.at(i));
            }
        }
    }

    //Check collision with ground

    //Check whether an object should be deleted
    for (unsigned int i{0}; i < context.objects.size())
    {
        if (context.objects.at(i) -> is_removed())
        {
            std::swap(context.objects.at(i), objects.back());
            delete context.objects.back();
            context.objects.pop();
        }
        else
        {
            ++i;
        }
    }

    //Check if player dead
    for (unsigned int i{0}; i < context.players.size())
    {
        if (context.objects.at(i) -> is_removed())
        {
            //Add implementation for deletion of player
        }
    }

    //Adding new objects to objects
    for (Game_object* object : context.new_objects)
    {
        context.objects.push_back(object);
    }

    //Remove all objects from new_objects
    while (!context.new_objects.empty)
    {
        context.new_object.pop();
    }

    //Check if next players turn

    //Check if someones won
}


void Game_state::render(Context& context)
{
    context.map -> render();

    for (Game_object* object: context.objects)
    {
        object -> render(Context& context);
    }

    for (Game_object* player: context.players)
    {
        player -> render(Context& context);
    }

}