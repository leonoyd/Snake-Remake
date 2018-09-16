#include "Game.h"

Game::Game()
:mScore(0)
,mGameState(eMainMenu)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    window.create(sf::VideoMode(platform_w, platform_h), "Snakes++");
    sf::Clock gameover_clock;
    /*
    sf::Vector2f tmp(50.0f,50.0f);
    sf::RectangleShape shape(tmp);
    shape.setFillColor(sf::Color::Blue);*/

    mFruit.spawnFruit(mSnake.getSnakePos());

    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            EventHandler(event);
        }

        switch(mGameState)
        {
        case eMainMenu:
            Main_Menu();
            break;
        case eSubMenu:
            break;
        case ePlayGame:
            if(-1==PlayGame())
                gameover_clock.restart();
            break;
        case ePractice:
            break;
        case eTopScore:
            TopScore();
            break;
        case eGameOver:
            {
                gameOver();
                float ElapsedTime = gameover_clock.getElapsedTime().asMilliseconds();
                if(ElapsedTime>3000)
                {
                    mSnake.reset();
                    if(mScore>mTopScore.lowestTopScore())
                    {
                       // mGame
                    }
                    else
                    {
                        mScore =0;
                        mGameState = eMainMenu;
                    }


                }
            }

        default:
            break;
        }
    }

    //return 0;
}
void Game::Practice()
{

}
void Game::SubMenu()
{

}
void Game::Main_Menu()
{
    static sf::Clock clock;


    float ElapsedTime = clock.getElapsedTime().asMilliseconds();
    if(ElapsedTime>300)
    {
        if(mMainMenu.processEvent())
        {
            switch((GameState)(mMainMenu.cursor()+2))
            {
            case ePlayGame:
                mGameState=ePlayGame;
                break;
            case eTopScore:
                mGameState = eTopScore;
                break;

            }
        }
        window.clear();
        mPlatform.draw(window);
        mMainMenu.draw(window);
        window.display();
        clock.restart();


    }
}

void Game::TopScore()
{
    static sf::Clock clock;


    float ElapsedTime = clock.getElapsedTime().asMilliseconds();
    if(ElapsedTime>500)
    {
        #if 0
        if(mMainMenu.processEvent())
        {
            switch((GameState)(mMainMenu.cursor()+2))
            {
            case ePlayGame:
                mGameState=ePlayGame;
            case eTopScore:
                mGameState = eTopScore;

            }
        }
        #endif
        window.clear();
        mPlatform.draw(window);
        mTopScore.draw(window);
        window.display();
        clock.restart();


    }
}

int Game::PlayGame()
{
    static sf::Clock clock;


    float ElapsedTime = clock.getElapsedTime().asMilliseconds();
    if(ElapsedTime>505)
    {
        clock.restart();
        if(mSnake.eatFruit(mFruit))
        {
            mFruit.spawnFruit(mSnake.getSnakePos());
            mScore+=10;
        }


        if(mSnake.collision())
        {
            mGameState = eGameOver;
            return -1;
        }

        mSnake.advance();

        window.clear();
        draw();
        window.display();
    }
    return 0;
}

void Game::draw()
{
    mPlatform.draw(window);
    mSnake.draw(window);
    mFruit.draw(window);
    drawScore();

}

void Game::drawScore()
{
    sf::Font font;
    sf::Text text;
    bool st = font.loadFromFile("BEBAS___.ttf");

    text.setFont(font);

    text.setPosition(440,20);
    text.setColor(sf::Color::White);
    text.setString(std::to_string(mScore));
    window.draw(text);

}

void Game::gameOver()
{
    sf::Font font;
    sf::Text text;
    bool st = font.loadFromFile("BEBAS___.ttf");

    text.setFont(font);

    text.setPosition(180,230);
    text.setColor(sf::Color::Red);
    text.setString("GAME OVER");

    window.clear();
    window.draw(text);
    window.display();
}
void Game::EventHandler(sf::Event& event)
{
    if(sf::Event::KeyPressed)
    {
        switch(mGameState)
        {
        case eSubMenu:
            //mSubMenu.setKey(event.key.code);
            break;
        case eMainMenu:
            mMainMenu.setKey(event.key.code);
            break;
        case ePlayGame:
            if(event.key.code==sf::Keyboard::Down)
                mSnake.setDirection(BUTTON_DOWN);
            else if(event.key.code==sf::Keyboard::Up)
                mSnake.setDirection(BUTTON_UP);
            else if(event.key.code==sf::Keyboard::Left)
                mSnake.setDirection(BUTTON_LEFT);
            else if(event.key.code==sf::Keyboard::Right)
                mSnake.setDirection(BUTTON_RIGHT);
            else;
            break;
        case eTopScore:
            mTopScore.eventHandler(event);
            break;
        case ePractice:
            break;
        default:
            break;

        }
    }
    if(event.type==sf::Event::Closed)
        window.close();


}
/*
void Game::EventHandlerMenu(sf::Event& event)
{
    switch(event.type)
    {
        case sf::Event::KeyPressed:
            mMainMenu.setKey(event.key.code);
            break;
        default:
            break;
    }
}
void Game::EventHandlerPlayGame()
{
    switch(event.type)
    {
        case sf::Event::KeyPressed:
            if(event.key.code==sf::Keyboard::Down)
                mSnake.setDirection(BUTTON_DOWN);
            else if(event.key.code==sf::Keyboard::Up)
                mSnake.setDirection(BUTTON_UP);
            else if(event.key.code==sf::Keyboard::Left)
                mSnake.setDirection(BUTTON_LEFT);
            else if(event.key.code==sf::Keyboard::Right)
                mSnake.setDirection(BUTTON_RIGHT);
            else;

            break;
        default:
            break;
    }

}*/
