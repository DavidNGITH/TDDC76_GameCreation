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
    End_state(Context& context, std::vector<std::vector<std::string>> score_list);

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    std::vector<std::vector<std::string>> writeTo_File(std::vector<std::vector<std::string>> sorted_score_list);

    ~End_state() = default;

    private:
    
    sf::Texture set_texture(std::string path);

    sf::Texture gameover_texture{};
    sf::Texture background_texture{};
    sf::Texture highscore_texture{};
    sf::Texture score_texture{};

    sf::Font font{};

    sf::Sprite gameover{};
    sf::Sprite background{};
    sf::Sprite highscore{};
    sf::Sprite score{};

    sf::Text list_name{};
    sf::Text list_score{};
    sf::Text list_highScore_name{};
    sf::Text list_highScore_score{};

    std::vector<std::vector<std::string>> high_score_list;

    std::vector<std::vector<std::string>> sort_list(std::vector<std::vector<std::string>> unsorted_list);

    std::vector<std::vector<std::string>> sorted_score_list;
    
};

#endif