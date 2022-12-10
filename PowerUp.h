#ifndef POWERUP_H
#define POWERUP_H

#include "SFML/Graphics.hpp"
#include "game_object.h"

class Powerup :public Game_object
{
    public:
        Powerup(Context& context, double incoming_x, double incoming_y);
        ~Powerup() = default;
        Powerup();
        void update(Context& context) override;
        void render(sf::RenderWindow& window, Context& context) override;
        void handle(Context& context, sf::Event event) override;

        void collision(Game_object* object, Context& context) override; 

        int randnum{};

    private:
        int old_position_x{};
        int old_position_y{};

        float speed{};
        bool has_stopped{};
};



#endif