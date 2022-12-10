#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

#include "context.h"
#include "state.h"
#include "menu_state.h"
#include "game_state.h"
#include "game_object.h"

#include <vector>

int main()
{
    //read file
    std::ifstream file("settings.json");
    //json reader
    Json::Reader reader;
    //contain complete JSON data
    Json::Value settings;
    // reader reads the data and stores it in settings
    reader.parse(file, settings);

    srand (time(NULL));

    sf::RenderWindow window { sf::VideoMode {settings["setup"]["width"].asUInt(), settings["setup"]["height"].asUInt()}, settings["setup"]["name"].asString()};
    
    State* state = new Menu_state{};

    sf::Clock clock;

    std::vector<Game_object*>  objects{};
    std::vector<Game_object*>  new_objects{};
    std::vector<Game_object*>  players{};
    Game_object*               current_player{};
    bool                       new_turn{false};
    Game_object*               missile{nullptr};

    Context context{clock.restart(), nullptr, nullptr, objects, new_objects, players, current_player, new_turn, missile, settings};


    while (window.isOpen())
    {
        sf::Event event;

        context.delta = clock.restart();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            state -> handle(context, event);
            if (context.next_state != nullptr)
            {
                delete state;
                state = context.next_state;
                context.next_state = nullptr;
                break;
            }
        }

        state -> update(context);

        if (context.next_state != nullptr)
        {
            delete state;
            state = context.next_state;
            context.next_state = nullptr;

        }

        window.clear();
        state -> render(window, context);
        window.display();

        
        
    }

    delete context.next_state;

    delete state;

    if(context.map != nullptr)
    {
        delete context.map;
    }

    for (long unsigned int i{0}; i < context.objects.size(); i++)
    {
        delete context.objects.at(i);
    }

    for (long unsigned int i{0}; i < context.new_objects.size(); i++)
    {
        delete context.new_objects.at(i);
    }

    for (long unsigned int i{0}; i < context.players.size(); i++)
    {
        delete context.players.at(i);
    }

}