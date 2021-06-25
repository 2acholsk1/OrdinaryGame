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
        this->mousePosGrid.x=this->mousePosView.x/GRID_SIZE_U;
    }
    if(this->mousePosView.y>=0.f)
    {
        this->mousePosGrid.y=this->mousePosView.y/GRID_SIZE_U;
    }
    ss<<"Screen: "<<mousePositionScreen.x<<" "<<mousePositionScreen.y<<"\n"
      <<"Window: "<<mousePosWindow.x<<" "<<mousePosWindow.y<<"\n"
      <<"View: "<<mousePosView.x<<" "<<mousePosView.y<<"\n"
      <<"Grid: "<<mousePosGrid.x<<" "<<mousePosGrid.y<<"\n";
    window.setView(window.getDefaultView());




    this->tileSelect.setPosition(mousePosGrid.x*GRID_SIZE_F,mousePosGrid.y*GRID_SIZE_F);

}

void MyPointOfView::PrintPosition(sf::RenderWindow& window)
{

//    window.draw(this->text);
    window.draw(this->tileSelect);
    ss.str("");
}

void MyPointOfView::SetRect()
{
    sf::RectangleShape specialShape(sf::Vector2f(GRID_SIZE_F,GRID_SIZE_F));
    specialShape.setFillColor(sf::Color::Transparent);
    specialShape.setOutlineThickness(1.f);
    specialShape.setOutlineColor(sf::Color::Red);

    tileSelect=specialShape;


}


void MyPointOfView::Resize(sf::RenderWindow &window)
{
    float ratio=static_cast<float>(window.getSize().x)/static_cast<float>(window.getSize().y);
    this->setSize(sf::Vector2f(ratio*MY_POINT_OF_VIEW_HEIGHT,MY_POINT_OF_VIEW_HEIGHT));
}



