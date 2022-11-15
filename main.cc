#include "SFML/Graphics.hpp"

#include "context.h"
#include "state.h"
#include "menu_state.h"
#include "game_state.h"

int main()
{
    unsigned const screen_width {1920};
    unsigned const screen_height {1080};

    sf::RenderWindow window { sf::VideoMode {screen_width, screen_height}, "DANK TANKS"}
    
    State* state = new Menu_state{};

    sf::Clock clock;

    Context context {clock.restart(), nullptr}

    while (window.isOpen())
    {
        sf::Event event;
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
        state -> render(context);
        window.display();

        if (context.next_state != nullptr)
        {
            delete state;
            state = context.next_state;
            context.next_state = nullptr;

        }
        
    }
}