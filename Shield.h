#ifndef SHIELD_H
#define SHIELD_H

#include "SFML/Graphics.hpp"

#include "PowerUp"

class Shield :public PowerUp
{
    public:
        Shield();
        
        bool handle(Context& context, sf::Event event) override
        void update(Context& context) override
        void render(sf::RenderWindow& window) override
        
        void collision() override;
        void remove() override;
        bool is_removed() override;
        
        bool add_shield();

    private:
        sf::Sprite sprite;
        sf::Texture texture;

        int position_x{};
        int position_y{};

        //bool removed;
}



#endif