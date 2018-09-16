#include "MainMenu.h"
#include <../project_settings.h>

MainMenu::MainMenu()
:Menu()
,mBoxSeparation(80)
,mBoxStrtPos(180)
{
    //ctor
    //initailize the menu string
    mMenuItems.push_back("Play Game");
    mMenuItems.push_back("Top Score");
    mMenuItems.push_back("Practice");
    mTileX = (platform_w-mTileWidth)/2;
}

MainMenu::~MainMenu()
{
    //dtor
}

bool MainMenu::processEvent()
{
    bool rc = false;
    if((mKey==sf::Keyboard::Down)&&(mCursorPos<mMenuItems.size()-1))
        mCursorPos++;
    if((mKey==sf::Keyboard::Up)&&(mCursorPos>0))
        mCursorPos--;
    if(mKey==sf::Keyboard::Enter)
    {
        rc=true;
    }

    mKey = sf::Keyboard::Unknown;
    return rc;
}
void MainMenu::drawTitle(sf::RenderWindow& window)
{
    sf::Font font;
    sf::Text text;
    bool st = font.loadFromFile("BEBAS___.ttf");

    text.setFont(font);
    text.scale(sf::Vector2f(2,2));
    text.setColor(sf::Color::Red);
    text.setString("Main Menu");
    text.setPosition((platform_w-(text.getGlobalBounds().width))/2,25);

    window.draw(text);
}

void MainMenu::draw(sf::RenderWindow& window)
{
    sf::Font font;
    sf::Text text;
    bool st = font.loadFromFile("BEBAS___.ttf");

    text.setFont(font);
    drawTitle(window);
    text.setColor(mTextColour);

    int i=0;
    for(auto& x: mMenuItems)
    {
        //sf::IntRect tmp(mTileX, mBoxStrtPos+mBoxSeparation*i, mTileWidth, mTileHeight);

        sf::RectangleShape tmp(sf::Vector2f(mTileWidth, mTileHeight));


        tmp.setFillColor(sf::Color::Blue);
        tmp.setPosition(mTileX, mBoxStrtPos+mBoxSeparation*i);

        if(i==mCursorPos)
        {
            tmp.setSize(sf::Vector2f(mTileWidth+50, mTileHeight));
            tmp.setPosition(mTileX-25, mBoxStrtPos+mBoxSeparation*i);
        }

        //we position the text inthe center of the box here
        text.setString(x);

        text.setPosition(mTileX+(mTileWidth-text.getGlobalBounds().width)/2,mBoxStrtPos+mBoxSeparation*i+(mTileHeight-text.getGlobalBounds().height)/2);
        window.draw(tmp);
        window.draw(text);

        i++;
    }
}

