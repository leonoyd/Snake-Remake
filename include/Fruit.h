#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

class Fruit
{
    public:
        Fruit();
        virtual ~Fruit();
        sf::Vector2f spawnFruit(const std::vector<sf::Vector2f>& snkPos);
        void draw(sf::RenderWindow& window);
        sf::Vector2f getPos(){return mFruitRect.getPosition();}
    protected:

    private:
        sf::RectangleShape mFruitRect;
        static const sf::Color mFruitColour;
};

#endif // FRIUT_H
