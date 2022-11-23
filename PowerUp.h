#ifndef POWERUP_H
#define POWERUP_H

#include "SFML/Graphics.hpp"
#include "game_object.h"

class Powerup :public Game_object
{
    public:
        Powerup(double incoming_x, double incoming_y); //(double position_x);
        ~Powerup() = default;
        Powerup();
        void update(Context& context) override;
        void render(sf::RenderWindow& window, Context& context) override;
        void handle(Context& context, sf::Event event) override;

        void collision(Game_object* object) override; 

        int get_poweruptype() const&;

        //bool add_powerup();

    private:
        void give_powerup(Game_object* object);
        //sf::Sprite icon;
        //sf::Texture texture;

        int old_position_x{};
        int old_position_y{};

        float speed{};
        int randnum{};
        bool has_stopped{};
};



#endif