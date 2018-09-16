#ifndef PLATFORM_H
#define PLATFORM_H


#include <SFML/Graphics.hpp>

class Platform
{
    public:
        Platform();
        virtual ~Platform();
        void drawPlatform();
        void draw(sf::RenderWindow& window);

    protected:

    private:
};

#endif // PLATFORM_H
