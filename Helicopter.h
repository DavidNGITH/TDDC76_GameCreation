#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "Game_object.h"
#include "SFML/Graphics.hpp"

class Helicopter :public Game_object
{
    public:

    Helicopter();
    //~Helicopter();
    void update(Context& context) override;
    void render(sf::RenderWindow& window) override;
    void handle{Context& context, sf::Event event} override;
    void Collision() override;
    bool collides() const;
    bool should_spawn() const;
    void create_powerup(double coordinate) const;
    double stop_position() const;





    private:
    sf::Sprite icon;
    sf::Texture texture;
    double start_position{};
    double stop_position{};
    bool is_active{}:
    bool has_stopped{};
    int spawn_rate{};  //number 0-100 in likelihood of spawning (percent)

}



#endif