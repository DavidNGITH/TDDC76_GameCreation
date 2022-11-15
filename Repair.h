#ifndef REPAIR_H
#define REPAIR_H

#include "SFML/Graphics.hpp"

#include "PowerUp"

class Repair :public PowerUp
{
    public:
        Repair();
        
        bool handle(Context& context, sf::Event event) override;
        void update(Context& context) override;
        void render(sf::RenderWindow& window) override;


        void collision() override;
        void move() override;
        void remove() override;
        bool is_removed() override;
        
        
        
        int increase_hp();


    private:
        sf::Sprite sprite;
        sf::Texture texture;

        int position_x;
        int position_y;

        bool removed;


}




#endif