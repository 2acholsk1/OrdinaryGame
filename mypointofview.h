#ifndef MYPOINTOFVIEW_H
#define MYPOINTOFVIEW_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <iostream>

#define WINDOW_WIDTH 1600.f
#define WINDOW_HEIGHT 900.f
#define MY_POINT_OF_VIEW_HEIGHT  static_cast<float>(WINDOW_HEIGHT)
#define MY_POINT_OF_VIEW_WIDTH  static_cast<float>(WINDOW_WIDTH)
#define GRID_SIZE_F 100.f
#define GRID_SIZE_U static_cast<unsigned>(GRID_SIZE_F)

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
