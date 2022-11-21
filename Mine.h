#ifndef MINE_H
#define MINE_H

#include "Missile.h"


class Mine : public Missile
{
public:
    Mine(double incoming_position_x, double incoming_position_y, 
    double  speed, double  bearing);
    ~Mine() = default;
    Mine();
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void handle(Context& context, sf::Event event) override;


    void collision(Game_object* object) override; 
    bool check_collision(Game_object* object) override;



private:



};

#endif