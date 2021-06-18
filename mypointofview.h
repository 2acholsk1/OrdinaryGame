#ifndef MYPOINTOFVIEW_H
#define MYPOINTOFVIEW_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Constants.h"
#include <sstream>
#include <iostream>

class MyPointOfView: public sf::View
{
protected:
    sf::Vector2i mousePositionScreen=sf::Mouse::getPosition();
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;
    std::stringstream ss;
    sf::Text text;
    sf::Font fontinio;
    sf::RectangleShape tileSelect;
public:
    MyPointOfView(sf::RenderWindow& window);
    void MouseControl(sf::RenderWindow& window);
    void PrintPosition(sf::RenderWindow& window);
    void SetRect();
    void Resize(sf::RenderWindow& window);
};

#endif // MYPOINTOFVIEW_H
