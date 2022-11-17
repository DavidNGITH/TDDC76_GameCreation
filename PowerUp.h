#ifndef POWERUP_H
#define POWERUP_H

#include "SFML/Graphics.hpp"
//#include "PowerUp.h"
#include "game_object.h"

class Powerup :public Game_object
{
    public:
        Powerup(double position_x, double position_y); //(double position_x);
        ~Powerup() = default;
        Powerup();
        void update(Context& context) override;
        void render(sf::RenderWindow& window, Context& context) override;
        void handle(Context& context, sf::Event event) override;

        void collision(Game_object* object) override; 
        bool check_collision(Game_object* object) override;

        //bool add_powerup();

    private:
        //sf::Sprite icon;
        //sf::Texture texture;

        //int position_x{};
        //int position_y{};

        float speed{};
};



#endif