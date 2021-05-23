#ifndef MYPOINTOFVIEW_H
#define MYPOINTOFVIEW_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class MyPointOfView: public sf::View
{
public:
    MyPointOfView(sf::RenderWindow& window);
};

#endif // MYPOINTOFVIEW_H
