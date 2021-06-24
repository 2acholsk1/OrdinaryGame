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
    const sf::Vector2f ARROW_MINIMAP_POSITION=sf::Vector2f(WINDOW_WIDTH*6.f/7.f-710.f,WINDOW_HEIGHT*6.f/7.f-400);
    const sf::Vector2f INSTRUCTION_START_POSITION=sf::Vector2f(-5600.f,-5200.f);
    const sf::Vector2f INSTRUCTION_POSITION=sf::Vector2f(-600.f,-400.f);

    const sf::Vector2f GAME_OVER_POSITION=sf::Vector2f(WINDOW_WIDTH/2.f-1125.f,WINDOW_HEIGHT*0.75f-1000.f);
    const sf::Vector2f TOTAL_POINTS_POSITION=sf::Vector2f(WINDOW_WIDTH/2.f-1000.f,WINDOW_HEIGHT*0.6f-700.f);
    const sf::Vector2f POINTS_POSITION=sf::Vector2f(WINDOW_WIDTH/2.f-900.f,WINDOW_HEIGHT*0.45f-450.f);
    const sf::Vector2f PRESS_X_POSITION=sf::Vector2f(WINDOW_WIDTH/2.f-1000.f,WINDOW_HEIGHT*0.2f);



    const float MOB_RANGE=500.f;
    const float MOB_HP=50.f;
    const float MOB_SPEED=35.f;
    const float MOB_FOLLOW_SPEED=100.f;
    const float MOB_PUSH_BACK_FORCE=0.51f;

    const int TREE_QUANTITY=150;
    const int GOLDEN_ORE_QUANTITY=20;
    const int COAL_ORE_QUANTITY=40;
    const int IRON_ORE_QUANTITY=50;
    const int STONES_QUANTITY=100;
    const int LAKES_QUANTITY=20;

    const float EXP_OF_CHOPPING_OR_DIGGING=1.0f;
    const float EXP_OF_FIGHT=2.0f;
    const float EXP_OF_FARMING=5.0f;

    const float LOST_HP_IN_CHOPPING_AND_DIGGIND_WITHOUT_TOOL=-1.0f;
    const float ZOMBIE_ATTACK=-0.1f;

    const float STARVE_OR_THIRST=-1.0f;
    const float TIME_TO_STARVE_AND_THIRST=8.f;

    const float DRINKING=1.0f;
    const float EATING_CARROT=0.25f;
    const float EATING_POTATO=1.f;
    const float EATING_BEET=0.75f;
    const float TIME_TO_PLANTS_GROW_UP=120.f;

    const float HEALING_CARROT=1.f;
    const float HEALING_POTATO=0.25;
    const float HEALING_BEET=0.5;


    const sf::FloatRect MINIMAMP_SIZE=sf::FloatRect(0.883f, 0.87f, 0.064f, 0.1f);
    const sf::FloatRect VIEW_SIZE=sf::FloatRect(0, 0, 1, 1);

    const float POINTS_FOR_FARMLAND=3.f;
    const float POINT_FOR_CHOPPING_AND_DIGGING=1.f;
    const float POINTS_FOR_FIGHT=5.f;
    const float POINT_FOR_HARVEST=1.f;
    const float POINTS_FOR_LEVEL_UP=10.f;

}

#endif // CONSTANTS_H
