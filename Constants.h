#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics.hpp>

namespace CONSTANTS
{
    const float WINDOW_WIDTH=1600.f;
    const float WINDOW_HEIGHT=900.f;

    const float MY_POINT_OF_VIEW_HEIGHT = static_cast<float>(WINDOW_HEIGHT);
    const float MY_POINT_OF_VIEW_WIDTH = static_cast<float>(WINDOW_WIDTH);

    const float GRID_SIZE_F=100.f;
    const unsigned GRID_SIZE_U=static_cast<unsigned>(GRID_SIZE_F);

    const int MAP_SIZE=100;

    const sf::Vector2f PLAYER_MIDDLE_POSITION=sf::Vector2f(WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f);
    const float PLAYER_MOVING_SPEED=300.f;

    const sf::Vector2f DEFAULT_INTERFACE_PART_START_POSITION(WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f);
    const sf::Vector2f INTERFACE_POSITION=sf::Vector2f(-1000,WINDOW_HEIGHT*6.f/7.f-450);
    const sf::Vector2f HP_BAR_POSITION=sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+10-450);
    const sf::Vector2f EXP_BAR_POSITION=sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+40-450);
    const sf::Vector2f STARVE_BAR_POSITION=sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+70-450);
    const sf::Vector2f WATER_BAR_POSITION=sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+100-450);
    const sf::Vector2f ARROW_MINIMAP_POSITION=sf::Vector2f(WINDOW_WIDTH*6.f/7.f-720.f,WINDOW_HEIGHT*6.f/7.f-400);

    const sf::Vector2f SLOT_1_POSITION=sf::Vector2f(-200,WINDOW_HEIGHT*6.f/7.f+10-450);
    const sf::Vector2f SLOT_2_POSITION=sf::Vector2f(-90,WINDOW_HEIGHT*6.f/7.f+10-450);
    const sf::Vector2f SLOT_3_POSITION=sf::Vector2f(20,WINDOW_HEIGHT*6.f/7.f+10-450);
    const sf::Vector2f SLOT_4_POSITION=sf::Vector2f(130,WINDOW_HEIGHT*6.f/7.f+10-450);
    const sf::Vector2f SLOT_5_POSITION=sf::Vector2f(240,WINDOW_HEIGHT*6.f/7.f+10-450);

}

#endif // CONSTANTS_H
