#ifndef END_STATE_H
#define END_STATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "context.h"
#include <list>
#include <string>
#include <vector>

class End_state: public State
{
    public:
    End_state(Context& context);

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;

    ~End_state() = default;

    private:
    
    sf::Texture set_texture(std::string path);

    sf::Texture round1_texture{};
    sf::Texture round2_texture{};
    sf::Texture round3_texture{};
    sf::Texture background_texture{};

    sf::Sprite round{};
    sf::Sprite background{};
    
};

#endif