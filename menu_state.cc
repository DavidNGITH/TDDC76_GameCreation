#include "menu_state.h"

#include "SFML/Graphics.hpp"

#include <vector>



Menu_state()
{
    load_map("Map/background.png");

    sf::Texture title{};

    if(!title.loadFromFile("title.png"))
    {
        std::cerr << "Kan inte öppna title.png" << std::endl;
        return 1;
    }
    
    sf::Sprite titles { title };
    sf::Vector2u titles_size { titles.getSize() };
    titles.setOrigin(450,100);
    titles.setPosition(450,100);
    titles.setScale(1,1);

    sf::Texture map{};

    if(!map.loadFromFile("map.png"))
    {
        std::cerr << "Kan inte öppna map.png" << std::endl;
        return 1;
    }
    
    sf::Sprite maps { map };
    sf::Vector2u maps_size { maps.getSize() };
    maps.setOrigin(450,500);
    maps.setPosition(450,500);
    maps.setScale(1,1);

    sf::Texture player{};

    if(!player.loadFromFile("player.png"))
    {
        std::cerr << "Kan inte öppna player.png" << std::endl;
        return 1;
    }
    
    sf::Sprite players { player };
    sf::Vector2u players_size { players.getSize() };
    players.setOrigin(450,900);
    players.setPosition(450,900);
    players.setScale(1,1);

  
}

void Menu_state::handle(Context& context, sf::Event event)
{}

void Menu_state::update(Context& context)
{}

void Menu_state::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(titles);
    window.draw(maps);
    window.draw(players);

}

void Menu_state::add_player()
{
    players.pushback(new Player*);
}

void Menu_state::choose_map()
{}

void Menu_state::load_map(std::string filename)
{
    if(!campus.loadFromFile(filename))
    {
        std::cerr << "Kan inte öppna:" << filename << std::endl;
        return 1;
    }
    
    sf::Sprite background { campus };
    sf::Vector2u background_size { background.getSize() };
    background.setOrigin(900,0);
    background.setPosition(900,0);
    background.setScale(1,1);
}

void Menu_state::start_game()
{}