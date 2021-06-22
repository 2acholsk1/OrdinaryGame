#include "mypointofview.h"

MyPointOfView::MyPointOfView(sf::RenderWindow& window)
{
    window.setView(static_cast<sf::View>(*this));
    this->setSize(window.getSize().x,window.getSize().y);
}

void MyPointOfView::MouseControl(sf::RenderWindow& window)
{
    this->mousePositionScreen=sf::Mouse::getPosition();
    this->mousePosWindow=sf::Mouse::getPosition(window);
    window.setView(*this);
    this->mousePosView=window.mapPixelToCoords(this->mousePosWindow);
    if(this->mousePosView.x>=0.f)
    {
        this->mousePosGrid.x=this->mousePosView.x/CONSTANTS::GRID_SIZE_U;
    }
    if(this->mousePosView.y>=0.f)
    {
        this->mousePosGrid.y=this->mousePosView.y/CONSTANTS::GRID_SIZE_U;
    }
    ss<<"Screen: "<<mousePositionScreen.x<<" "<<mousePositionScreen.y<<"\n"
      <<"Window: "<<mousePosWindow.x<<" "<<mousePosWindow.y<<"\n"
      <<"View: "<<mousePosView.x<<" "<<mousePosView.y<<"\n"
      <<"Grid: "<<mousePosGrid.x<<" "<<mousePosGrid.y<<"\n";
    window.setView(window.getDefaultView());



//    std::cout<<"Y:"<<mousePositionScreen.x<<std::endl;
//    std::cout<<"X:"<<mousePositionScreen.y<<std::endl;
//    this->fontinio.loadFromFile("fonts/Aspergit Bold.otf");
//    this->text.setCharacterSize(20);
//    this->text.setFillColor(sf::Color::White);
//    this->text.setFont(fontinio);
//    this->text.setString(ss.str());

    this->tileSelect.setPosition(mousePosGrid.x*CONSTANTS::GRID_SIZE_F,mousePosGrid.y*CONSTANTS::GRID_SIZE_F);

}

void MyPointOfView::PrintPosition(sf::RenderWindow& window)
{

//    window.draw(this->text);
    window.draw(this->tileSelect);
    ss.str("");
}

void MyPointOfView::SetRect()
{
    sf::RectangleShape specialShape(sf::Vector2f(CONSTANTS::GRID_SIZE_F,CONSTANTS::GRID_SIZE_F));
    specialShape.setFillColor(sf::Color::Transparent);
    specialShape.setOutlineThickness(1.f);
    specialShape.setOutlineColor(sf::Color::Red);

    tileSelect=specialShape;


}


void MyPointOfView::Resize(sf::RenderWindow &window)
{
    float ratio=static_cast<float>(window.getSize().x)/static_cast<float>(window.getSize().y);
    this->setSize(sf::Vector2f(ratio*CONSTANTS::MY_POINT_OF_VIEW_HEIGHT,CONSTANTS::MY_POINT_OF_VIEW_HEIGHT));
}



