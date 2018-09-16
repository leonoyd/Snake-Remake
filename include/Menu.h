#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>

class Menu
{
    public:
        Menu();
        virtual ~Menu();

    protected:
        sf::Color mTextColour;
        sf::Color mBackgroundColor;
        std::vector<std::string> mMenuItems;
        virtual void draw(sf::RenderWindow& window);
        int mTileX;
        int mTileWidth;
        int mTileHeight;
        unsigned int mCursorPos;
        sf::Keyboard::Key mKey;
    private:




};

#endif // MENU_H
