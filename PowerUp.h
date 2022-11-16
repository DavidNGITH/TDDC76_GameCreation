#ifndef POWERUP_H
#define POWERUP_H

#include "SFML/Graphics.hpp"
#include "Game_object.h"

class PowerUp :public Game_object
{
    public:

        PowerUp();
        //~PowerUp();

        void random_powerup() const;

        void update(Context& context) override;
        void render(Context& context) virtual;
        void handle(Context& context, sf::Event event) virtual;
        void Collision() override;
        bool is_removed() override;
        void remove() override;



    private:

}



#endif