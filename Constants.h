#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics.hpp>

namespace CONSTANTS
{
    const float WINDOW_WIDTH=1600.f;
    const float WINDOW_HEIGHT=900.f;

    const float MY_POINT_OF_VIEW_HEIGHT = static_cast<float>(WINDOW_HEIGHT);
    const float MY_POINT_OF_VIEW_WIDTH = static_cast<float>(WINDOW_HEIGHT);

    const float GRID_SIZE_F=100.f;
    const unsigned GRID_SIZE_U=static_cast<unsigned>(GRID_SIZE_F);

    const int MAP_SIZE=1000;

    const sf::Vector2f PLAYER_MIDDLE_POSITION=sf::Vector2f(WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f);
    const float PLAYER_MOVING_SPEED=300.f;

    const sf::Vector2f INTERFACE_POSITION=sf::Vector2f(-200,WINDOW_HEIGHT*6.f/7.f);
    const sf::Vector2f HP_BAR_POSITION=sf::Vector2f(100,WINDOW_HEIGHT*6.f/7.f+10);
    const sf::Vector2f EXP_BAR_POSITION=sf::Vector2f(100,WINDOW_HEIGHT*6.f/7.f+40);
    const sf::Vector2f STARVE_BAR_POSITION=sf::Vector2f(100,WINDOW_HEIGHT*6.f/7.f+70);
    const sf::Vector2f WATER_BAR_POSITION=sf::Vector2f(100,WINDOW_HEIGHT*6.f/7.f+100);
}

#endif // CONSTANTS_H
