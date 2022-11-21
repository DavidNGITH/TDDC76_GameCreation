#include <SFML/Graphics.hpp>

#include "context.h"
#include "state.h"
#include "menu_state.h"
#include "game_state.h"
#include "game_object.h"

#include <vector>

int main()
{
    unsigned const screen_width {1920};
    unsigned const screen_height {1080};
    srand (time(NULL));

    sf::RenderWindow window { sf::VideoMode {screen_width, screen_height}, "DANK TANKS"};
    
    State* state = new Menu_state{};

    sf::Clock clock;

    std::vector<Game_object*>  objects{};
    std::vector<Game_object*>  new_objects{};
    std::vector<Game_object*>  players{};
    Game_object*               current_player{};

    Context context{clock.restart(), nullptr, nullptr, objects, new_objects, players, current_player};


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
        }

        state -> update(context);

        window.clear();
        state -> render(window, context);
        window.display();

        if (context.next_state != nullptr)
        {
            delete state;
            state = context.next_state;
            context.next_state = nullptr;

        }
        
    }
}