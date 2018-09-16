#include "Platform.h"
#include <../project_settings.h>

Platform::Platform()
{
    //ctor
}

Platform::~Platform()
{
    //dtor
}

void Platform::draw(sf::RenderWindow& window)
{
    sf::Vector2f tmp(platform_w,platform_h);
    sf::RectangleShape shape(tmp);
    shape.setFillColor(sf::Color::Transparent);

    //shape.setPosition(snk.at(i).x, snk.at(i).y);

    window.draw(shape);

}
