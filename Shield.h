#ifndef SHIELD_H
#define SHIELD_H

#include "SFML/Graphics.hpp"

#include "PowerUp.h"
#include "context.h"

class Shield :public PowerUp
{
    public:
        Shield();
        
        ~Shield() = default;

        void update(Context& context) override;
        void render(sf::RenderWindow& window, Context& context) override;
        void handle(Context& context, sf::Event event) override;

        void collision(Game_object* object) override; 
        bool check_collision(Game_object* object) override;
        void remove() override;
        bool is_removed() override;

        bool add_shield();

    private:
        sf::Sprite sprite;
        sf::Texture texture;

        int position_x{};
        int position_y{};

        float speed{};

        //bool removed;
};



#endif