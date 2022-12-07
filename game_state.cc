#include "SFML/Graphics.hpp"

#include "game_state.h"
#include "context.h"
#include "game_object.h" 
#include "map.h"
#include "Helicopter.h"
#include "player.h"
#include "PowerUp.h"
#include "static_object.h"
#include "state.h"
#include "menu_state.h"
#include <vector>
#include "end_state.h"


Game_state::Game_state(Context& context)
:score_list{}
{

    context.objects.push_back(new Helicopter);
    context.objects.push_back(new Powerup);
    context.objects.push_back(new Static_object{context});
    context.current_player = context.players.at(active_player);

}

void Game_state::handle(Context& context, sf::Event event)
{   


    context.current_player -> handle(context, event);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {   
        delete_all(context);
        context.next_state = new Menu_state{};
 
        
    }
    
}

void Game_state::update(Context& context)
{

    context.current_player -> move(context);
    
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
                context.objects.at(i) -> collision(context.objects.at(j), context);
                context.objects.at(j) -> collision(context.objects.at(i), context);
            }
        }
    }

    //Check collision with ground
    for (unsigned int i{0}; i < context.objects.size(); i++)
    {
        if(context.map -> check_collision(context.objects.at(i)))
        {
            context.objects.at(i) -> collision(context.map, context); //Update hit_pos
        }
    }

    //Check collision with other players
    if (context.hit_pos.x != 0 && context.hit_pos.y != 0)
    {
        for (unsigned int i{0}; i < context.players.size(); i++)
        {
            context.players.at(i) -> collision(nullptr, context);
        }
    }

    context.hit_pos.x = 0;
    context.hit_pos.y = 0;
    



    //Check collision between players and objects
    for (unsigned int i{0}; i < context.players.size(); i++)
    {   
        for (unsigned int j{0}; j < context.objects.size(); j++)
        {
            if (context.objects.at(j) -> check_collision(context.players.at(i)))
            {
                context.players.at(i) -> collision(context.objects.at(j), context);
                context.objects.at(j) -> collision(context.players.at(i), context);
            }
        }
    } 

    //Check collision with other players
    for (unsigned int i{0}; i < context.players.size(); i++)
    {
        if (context.current_player -> check_collision(context.players.at(i)) && context.current_player != context.players.at(i))
        {
            context.current_player -> collision(context.players.at(i), context);
        }
    }


    //std::cout << "3" << std::endl;

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
    for (unsigned int i{0}; i < context.players.size();)
    {   
        if (context.players.at(i) -> is_removed())
        {   
            if (context.players.at(i) == context.current_player)
            {
                switch_player(context);
            }
            Player* player { dynamic_cast<Player*>(context.players.at(i)) };
            score_list.push_back(player->get_info());

        

            std::swap(context.players.at(i), context.players.back());
            delete context.players.back(); 
            context.players.pop_back();
            std::swap(context.players.at(0), context.players.back());
        }
        else
        {
            ++i;
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

    

    //Check if next players turn
    if(context.new_turn)
    {
        switch_player(context);
    }


    //Check if someones won*/
    if(context.players.size() == 1)
    {   
        Player* player { dynamic_cast<Player*>(context.players.at(0)) };
        score_list.push_back(player->get_info());
        delete_all(context);
        context.next_state = new End_state{context, score_list};

    }
}



void Game_state::render(sf::RenderWindow& window, Context& context)
{
    context.map ->render(window, context);

    for (Game_object* object: context.objects)
    {
        object -> render(window, context);
    }

    for (Game_object* player: context.players)
    {
        player -> render(window, context);
    }
}

void Game_state::switch_player(Context& context)
{
    context.new_turn = false;
    long unsigned int i{0};

        while ((context.current_player != context.players.at(i)) == true)
        {
            i += 1;
        } 

        if (i == context.players.size() - 1)
        {
            context.current_player = context.players.at(0);
        }
        
        else
        {
            context.current_player = context.players.at(i+1);
        }
        context.current_player->able_to_move = true;
        context.current_player->fired = false;
}

void Game_state::delete_all(Context& context)
{
    for(unsigned int i{0} ; i < context.objects.size(); i++)
    {   
        delete context.objects[i];
    }
       
    //std::cout << context.objects.size() << std::endl;
    for(unsigned int j{0} ; j < context.players.size(); j++)
    {   
        delete context.players[j];
    }
    
    delete context.map;
    context.map = nullptr;

    context.players.clear();
    context.objects.clear();

}