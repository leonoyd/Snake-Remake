#ifndef GAME_H
#define GAME_H

#include <snake.h>
#include <Fruit.h>
#include <Platform.h>
#include <SFML/Graphics.hpp>
#include <MainMenu.h>
#include <top_score.h>

class Game
{
    enum GameState
    {
        eMainMenu=0,
        eSubMenu,
        ePlayGame,
        eTopScore,
        ePractice,
        eGameOver
    };
    public:
        Game();
        virtual ~Game();
        void run();
        void draw();
        void gameOver();
        void drawScore();

    protected:

    private:
        void EventHandler(sf::Event& event);
        void Main_Menu();
        void Practice();
        int PlayGame();
        void TopScore();
        void SubMenu();
    private:
        snake mSnake;
        Platform mPlatform;
        Fruit mFruit;
        MainMenu mMainMenu;
        top_score mTopScore;

        int mScore;
        GameState mGameState;
        sf::RenderWindow window;
};

#endif // GAME_H
