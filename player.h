#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "game_object.h"
#include "hud.h"
#include <string>

class Player : public Game_object
{
public:
    //HARD CODED:
    Player(std::string player_texture, std::string barrel_texture, Context& context);

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;

    void collision(Game_object* object, Context& context) override;
    void move(Context& context) override;

    double get_bearing() const&;
    int get_score() const&;

    void reset();
    
    

protected:
    int hp{};

private:
    void set_barrel_pos();
    void set_shield_pos();
    void Aim();
    void Fire(Context& context);

    int score{};
    double bearing{};
    float const barrel_rotation_speed{};
    sf::Vector2f old_position{};

    sf::Sprite barrel_sprite;
    sf::Texture barrel;

    bool shield_isActive{};
    sf::Sprite shield_sprite;
    sf::Texture shield;

    Hud* hud;

    double calc_y_position();
    double calc_x_position();
    
    
    
};


#endif