#include <snake.h>

snake::snake()
:mLength(SNAKE_START_LENGTH)
,mDirection(BUTTON_RIGHT)
,mExtend(0)
{
    mPos.x = SNAKE_HEAD_START_X_POS;
    mPos.y = SNAKE_HEAD_START_Y_POS;

    sf::Vector2f tmp(mPos.x,mPos.y );
    for(int  i=0;i<mLength;i++)
    {
        snk.push_back(tmp);
        tmp.x--;
    }
}

snake::~snake()
{

}

void snake::reset()
{
    snk.clear();
    mPos.x = SNAKE_HEAD_START_X_POS;
    mPos.y = SNAKE_HEAD_START_Y_POS;

    sf::Vector2f tmp(mPos.x,mPos.y );
    for(int  i=0;i<mLength;i++)
    {
        snk.push_back(tmp);
        tmp.x--;
    }

    mDirection = BUTTON_RIGHT;
}

void snake::advance()
{
    sf::Vector2f tmp = snk.at(0);
    sf::Vector2f tmp2;

    for(std::vector<sf::Vector2f>::iterator it = snk.begin();it!=snk.end();++it)
    {
        tmp2 = *it;
        *it = tmp;
        tmp = tmp2;
    }
    if(mExtend)
    {
        snk.push_back(tmp);
        mExtend = 0;
    }
    switch(mDirection)
    {
        case BUTTON_DOWN:
            if(snk.at(0).y<snake_max_y-1)
                snk.at(0).y++;
            else
                snk.at(0).y = platform_y_strt;
            break;
        case BUTTON_UP:
            if(snk.at(0).y>platform_y_strt)
                snk.at(0).y--;
            else
                snk.at(0).y = snake_max_y-1;
            break;
        case BUTTON_LEFT:
            if(snk.at(0).x>platform_x_strt)
                snk.at(0).x--;
            else
                snk.at(0).x = snake_max_x-1;
            break;
        case BUTTON_RIGHT:
            if(snk.at(0).x<snake_max_x-1)
                snk.at(0).x++;
            else
                snk.at(0).x = platform_x_strt;
            break;
        default:
            break;
    }
}

bool snake::eatFruit(Fruit& fruit)
{

    sf::Vector2f tmp = fruit.getPos();
    if((tmp.x==BLOCK_SIZE_PIXELS*snk.at(0).x)&&(tmp.y==BLOCK_SIZE_PIXELS*snk.at(0).y))
    {
        mExtend = 1;
    }
}

void snake::setDirection(Direction dir)
{
    if(((dir<2)&&!(mDirection<2))||(dir>=2)&&!(mDirection>=2))
        mDirection = dir;
}

bool snake::collision()
{
    sf::Vector2f tmp = snk.at(0);
    sf::Vector2f tmp2;

    for(std::vector<sf::Vector2f>::iterator it = snk.begin()+1;it!=snk.end();++it)
    {
        tmp2 = *it;
        if((tmp.x==tmp2.x)&&(tmp.y==tmp2.y))
            return true;
    }

    return false;
}
void snake::draw(sf::RenderWindow& window)
{
    sf::Vector2f tmp(BLOCK_SIZE_PIXELS,BLOCK_SIZE_PIXELS);


    for(int i =0;i<snk.size();i++)
    {
        sf::RectangleShape shape(tmp);
        shape.setFillColor(sf::Color::Blue);

        shape.setPosition(BLOCK_SIZE_PIXELS*snk.at(i).x, BLOCK_SIZE_PIXELS*snk.at(i).y);

        window.draw(shape);
    }

}

