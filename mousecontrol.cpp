#include "mousecontrol.h"


void MouseControl(sf::RenderWindow& window)
{
    sf::Vector2i mousePositionScreen=sf::Mouse::getPosition();
    sf::Vector2i mousePosWindow=sf::Mouse::getPosition(window);
    sf::Vector2f mousePosView=window.mapPixelToCoords(mousePosWindow);
    sf::Vector2u mousePosGrid;
    if(mousePosView.x>=0.f)
    {
        mousePosGrid.x=mousePosView.x/CONSTANTS::GRID_SIZE_U;
    }
    if(mousePosView.y>=0.f)
    {
        mousePosGrid.y=mousePosView.y/CONSTANTS::GRID_SIZE_U;
    }
    window.setView(window.getDefaultView());

    std::stringstream ss;
    ss<<"Screen: "<<mousePositionScreen.x<<" "<<mousePositionScreen.y<<"\n"
      <<"Window: "<<mousePosWindow.x<<" "<<mousePosWindow.y<<"\n"
      <<"View: "<<mousePosView.x<<" "<<mousePosView.y<<"\n"
      <<"Grid: "<<mousePosGrid.x<<" "<<mousePosGrid.y<<"\n";
}
