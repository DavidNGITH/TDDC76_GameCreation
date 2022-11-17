#include "SFML/Graphics.hpp"

#include "game_state.h"
#include "context.h"
#include "game_object.h" 
#include "map.h"
#include "Helicopter.h"
#include "player.h"
#include "PowerUp.h"


Game_state::Game_state(Context& context)
{
    context.objects.push_back(new Helicopter);
    context.objects.push_back(new Powerup);
    context.players.push_back(new Player);
    context.current_player = context.players.at(0);
}

void Game_state::handle(Context& context, sf::Event event)
{
    context.current_player -> handle(context, event);

    /*//Check collsion with other objects
    for (unsigned int i{0}; i < context.objects.size(); i++)
    {
        if (context.current_player -> check_collision(context.objects.at(i)))
        {
            context.current_player -> collision(context.objects.at(i));
            
            context.objects.at(i) -> collision(context.current_player);
        }
    }

    //Check collision with other players
    for (unsigned int i{0}; i < context.players.size(); i++)
    {
        if (context.current_player -> check_collision(context.players.at(i)) && context.current_player != context.players.at(i))
        {
            context.current_player -> collision(context.players.at(i));
        }
    }

    //Check collsion with wall*/
    
}

void Game_state::update(Context& context)
{
    
    for (Game_object* object : context.objects)
    {
        object -> update(context);
    }

    for (Game_object* player : context.players)
    {
        player -> update(context);
    }


    //Check collsion between objects
    for (unsigned int i{0}; i < context.objects.size(); i++)
    {
        for (unsigned int j{i+1}; j < context.objects.size(); j++)
        {
            if (context.objects.at(i) -> check_collision(context.objects.at(j)))
            {
                context.objects.at(i) -> collision(context.objects.at(j));
                context.objects.at(j) -> collision(context.objects.at(i));
            }
        }
    }
    
    //Check collision with ground

    //Check whether an object should be deleted
    for (unsigned int i{0}; i < context.objects.size();)
    {
        if (context.objects.at(i) -> is_removed())
        {
            std::swap(context.objects.at(i), context.objects.back());
            delete context.objects.back();
            context.objects.pop_back();
        }
        else
        {
            ++i;
        }
    }

    
    //Check if player dead
    for (unsigned int i{0}; i < context.players.size(); i++)
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
    while (!context.new_objects.empty())
    {
        context.new_objects.pop_back();
    }

    //Check collision between players and objects
    for (unsigned int i{0}; i < context.players.size(); i++)
    {
        for (unsigned int j{0}; j < context.objects.size(); j++)
        {
            if (context.players.at(i) -> check_collision(context.objects.at(j)))
            {
                context.players.at(i) -> collision(context.objects.at(j));
                context.objects.at(j) -> collision(context.players.at(i));
            }
        }
    }   

    //Check if next players turn

    //Check if someones won

    


}


void Game_state::render(sf::RenderWindow& window, Context& context)
{
    context.map ->render(window);

    for (Game_object* object: context.objects)
    {
        object -> render(window, context);
    }

    for (Game_object* player: context.players)
    {
        player -> render(window, context);
    }



}