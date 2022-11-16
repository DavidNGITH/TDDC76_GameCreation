#include "SFML/Graphics.hpp"
#include "game_object.h"


class Static_object : public Game_object
{
    public:

    void update() override;
    void Collision() override; 
    void render() override;
    void handle() override;
    bool is_removed() override;
    void remove() override<;

}