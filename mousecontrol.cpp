#include "mousecontrol.h"

//void PrintPosition(sf::RenderWindow& window)
//{
//    std::stringstream ss;
//    sf::Text text;
//    sf::Font fontinio;
//    fontinio.loadFromFile("fonts/Ace Records.ttf");
//    text.setCharacterSize(100);
//    text.setFillColor(sf::Color::White);
//    text.setFont(fontinio);
//    text.setPosition(20.f,20.f);
//    text.setString(ss.str());
//    window.draw(text);
//}

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

//    std::cout<<"Y:"<<mousePositionScreen.x<<std::endl;
//    std::cout<<"X:"<<mousePositionScreen.y<<std::endl;
}
