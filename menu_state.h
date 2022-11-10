#ifndef MENU_STATE.H
#define MENU_STATE.H

#include <SFML/Graphics.hpp>
#include <list>

class Menu_state
{

    public:
    Menu_state();

    list<Tanks*> players;

    Map map;

    override void handle(sf::Event event);

    override void update(sf::Time delta);

    override void render(sf::RenderWindow& window);

    ~Menu_state();

    private:
    void add_player();
    void choose_map();
   
};




#endif
