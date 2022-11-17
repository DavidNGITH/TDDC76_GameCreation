#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "game_object.h"
#include "SFML/Graphics.hpp"

class Helicopter :public Game_object
{
    public:

    Helicopter();
    ~Helicopter() = default;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void handle(Context& context, sf::Event event) override;
    void collision(Game_object* object) override;
    bool check_collision(Game_object* object) override;
    bool should_spawn();
    void create_powerup(Context& context) const;
    float stop_position();





    private:
    float stop_coordinate{};
    int is_active{};
    int has_stopped{};
    int has_dropped{};
    int spawn_rate{};  //number 0-100 in likelihood of spawning (percent)
    float speed{};
    Game_object* current_player{};

};



#endif