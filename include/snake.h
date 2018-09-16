#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <../project_settings.h>
#include <Fruit.h>
enum Direction
{
    BUTTON_UP=0,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT
};
class snake{
public:

    snake();
    ~snake();
    //int length(){return mLengh;}
    //void setLength(int length){mLength=length;}

    sf::Vector2<int> pos(){return mPos;}
    void setPos(sf::Vector2<int> pos){mPos=pos;}
    void advance();
    void draw(sf::RenderWindow& window);
    bool eatFruit(Fruit& fruit);
    Direction direction()const{return mDirection;}
    void setDirection(Direction dir);
    bool collision();
    void setKey(const sf::Keyboard::Key& key){mKey = key;}
    void reset();
    std::vector<sf::Vector2f>& getSnakePos(){return snk;}

private:
     int mLength;
     Direction mDirection;
     sf::Keyboard::Key mKey;
     bool mExtend;
     sf::Vector2<int> mPos;
     std::vector<sf::Vector2f> snk;
};

#endif // SNAKE_H
