#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "game_object.h"
#include "SFML/Graphics.hpp"

class Helicopter :public Game_object
{
    public:

    Helicopter();
    //~Helicopter();
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void handle(Context& context, sf::Event event) override;
    void collision() override;
    bool check_collision() const;
    bool should_spawn() const;
    void create_powerup(int coordinate) const;
    int stop_position() const;
    bool new_turn();




    private:
    sf::Sprite icon;
    sf::Texture texture;
    int stop_coordinate{};
    float speed{};
    int is_active{};
    int has_stopped{};
    int has_dropped{};
    int spawn_rate{};  //number 0-100 in likelihood of spawning (percent)

}



#endif