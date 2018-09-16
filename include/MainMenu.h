#ifndef MAINMENU_H
#define MAINMENU_H
#include <Menu.h>

class MainMenu:Menu
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void draw(sf::RenderWindow& window);
        void drawTitle(sf::RenderWindow& window);
        void setKey(const sf::Keyboard::Key& key){mKey = key;}
        bool processEvent();
        unsigned int cursor(){return mCursorPos;}

    protected:

    private:
        int mBoxSeparation;
        int mBoxStrtPos;
};

#endif // MAINMENU_H
