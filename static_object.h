#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include <SFML/Graphics.hpp>
#include "game_object.h"


class Static_object : public Game_object
{
    public:

    Static_object(Context& context);

    ~Static_object() = default;

    void handle(Context& context, sf::Event event) override;
    void update(Context& context) override;
    void render(sf::RenderWindow& window, Context& context) override;
    void collision(Game_object* object, Context& context) override;

    private:

    bool removed();

};

#endif