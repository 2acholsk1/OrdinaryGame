#include "minimap.h"

minimap::minimap()

{

}


minimap::~minimap()
{

}

void minimap::Draw(sf::RenderWindow& window)
{

}

void minimap::Update(float &dtime,sf::RenderWindow& window)
{
    using namespace CONSTANTS;
    sf::Vector2i mousePosWindow=sf::Mouse::getPosition(window);
    float deltaX=mousePosWindow.x-PLAYER_MIDDLE_POSITION.x;
    float deltaY=mousePosWindow.y-PLAYER_MIDDLE_POSITION.y;
    float fi=atan2f(deltaX,deltaY);


}

void minimap::UpdatingMiniMap(minimap &mini, sf::RenderWindow &window)
{
    int xSize = window.getSize().x * 0.25;
            int ySize = window.getSize().y * 0.23;

            float xFloat = (float)xSize/window.getSize().x;
            float yFloat = (float)ySize/window.getSize().y;

            mini.reset(sf::FloatRect(0.f, 0.f, xSize, ySize));
            mini.setViewport(sf::FloatRect(0.f, 0.77, xFloat, yFloat));
}




