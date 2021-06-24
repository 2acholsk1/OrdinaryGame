#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Constants.h"


class Menu
{
private:
    sf::RenderWindow window;
    sf::RectangleShape background;
    sf::RectangleShape StartButton;
    sf::Text text;
    sf::Text start;
    sf::Font font;
    sf::Vector2i MousePosition;
public:
    Menu();
    void Update();
    void Draw();
    bool IsWorking();

};

#endif // MENU_H
