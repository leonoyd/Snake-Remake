#include "Fruit.h"
#include <../project_settings.h>

//Fruit::mFruitColour = sf::Color::Blue;
Fruit::Fruit()
{
    sf::Vector2f tmp(50.0f,50.0f);
    mFruitRect.setSize(tmp);
    //ctor
}

Fruit::~Fruit()
{
    //dtor
}

sf::Vector2f Fruit::spawnFruit(const std::vector<sf::Vector2f>& snkPos)
{
    sf::Vector2f fruitPos(0,0);
    bool snkFruitSame;
    srand(time(NULL));
    static int tuuump = 0;

    do
    {
        snkFruitSame=0;
        fruitPos.x =  rand()%MAX_FRUIT_SPAWN;
        fruitPos.y = rand()%MAX_FRUIT_SPAWN;

        //check x and y withthe whole length f the snake
        for(auto& pos: snkPos)
        {
            if((pos.x==fruitPos.x)&&(pos.y==fruitPos.y))
            {
                snkFruitSame = 1;
                tuuump++;
                break;

            }
        }

    }while(snkFruitSame);


    mFruitRect.setPosition(BLOCK_SIZE_PIXELS*fruitPos.x, BLOCK_SIZE_PIXELS*fruitPos.y);
    return fruitPos;
}

void Fruit::draw(sf::RenderWindow& window)
{
    sf::Vector2f tmp(BLOCK_SIZE_PIXELS,BLOCK_SIZE_PIXELS);
    //sf::RectangleShape shape(tmp);
    mFruitRect.setSize(tmp);
    mFruitRect.setFillColor(sf::Color::Magenta);

    //shape.setPosition(snk.at(i).x, snk.at(i).y);

    window.draw(mFruitRect);
}
