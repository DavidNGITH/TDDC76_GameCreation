#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "game_object.h"
#include "hud.h"
#include "Missile.h"
#include <string>

class Player : public Game_object
{
public:
    //HARD CODED:
    Player(std::string player_texture, std::string barrel_texture, std::string player_name, Context& context);
    ~Player() override;
    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;

    void collision(Game_object* object, Context& context) override;
    void move(Context& context) override;

    void update_score(Context & context) override;

    double get_bearing() const&;
    int get_score() const&;
    void check_damage(Context& context, double missile_dmg);

    void reset();
    
    

protected:
    int hp{};

private:
    void set_pos();
    void set_barrel_pos();
    void set_shield_pos();
    void set_name_pos();
    void Fire(Context& context);
    double calc_y_position();
    double calc_x_position();
    
    //Player vars
    int score{};
    int fuel{};
    double bearing{};
    double power{};
    int curr_weapon{};
    float const barrel_rotation_speed{};
    Missile* last_missile{};
    sf::Vector2f old_position{};

    //Barrel vars
    sf::Sprite barrel_sprite;
    sf::Texture barrel;

    //Name vars
    std::string player_name_var{};
    sf::Text name_text;
    sf::Font font;

    //Shield vars
    bool shield_isActive{};
    sf::Sprite shield_sprite;
    sf::Texture shield;

    //Hud vars
    Hud* hud;

    //Ammo vars
    int ammo_array [3]= { 2, 10, 4 };
    
    
};


#endif