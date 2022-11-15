#ifndef MENU_STATE.H
#define MENU_STATE.H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

class Menu_state
{

    public:
    Menu_state();

    

    Map map;

    virtual void handle(Context& context, sf::Event event) override;
    virtual void update(Context& context) override;
    virtual void render(sf::RenderWindow& window) override;


    ~Menu_state();

    private:
    void add_player();
    void choose_map();
    void load_map(std::string filename);
    void start_game();

    std::vector<Player*> players;
   
};




#endif
