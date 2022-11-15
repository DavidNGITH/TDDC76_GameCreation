#ifndef MAP.H
#define MAP.H

class Map:
{
    public:

    void handle(Context& context, sf::Event event) override;

    void update(Context& context) override;

    void render(sf::RenderWindow& window) override;

    void Collision();

    private:

    virtual const map_maker();
}
#endif