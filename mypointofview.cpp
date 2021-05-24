#include "mypointofview.h"

MyPointOfView::MyPointOfView(sf::RenderWindow& window)
{
    window.setView(static_cast<sf::View>(*this));
    this->setSize(window.getSize().x,window.getSize().y);
    this->setCenter(window.getSize().x/2.f,window.getSize().y/2.f);
}

void MyPointOfView::Moving(float& dtime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//left
    {
        move(-movingSpeed*dtime,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))//right
    {
        move(movingSpeed*dtime,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
    {
        move(0.f,movingSpeed*dtime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
    {
        move(0.f,-movingSpeed*dtime);
    }
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
    window.setView(window.getDefaultView());

    std::stringstream ss;
    ss<<"Screen: "<<mousePositionScreen.x<<" "<<mousePositionScreen.y<<"\n"
      <<"Window: "<<mousePosWindow.x<<" "<<mousePosWindow.y<<"\n"
      <<"View: "<<mousePosView.x<<" "<<mousePosView.y<<"\n"
      <<"Grid: "<<mousePosGrid.x<<" "<<mousePosGrid.y<<"\n";

//    std::cout<<"Y:"<<mousePositionScreen.x<<std::endl;
//    std::cout<<"X:"<<mousePositionScreen.y<<std::endl;
}

void MyPointOfView::PrintPosition(sf::RenderWindow& window)
{
    this->fontinio.loadFromFile("fonts/Ace Records.ttf");
    this->text.setCharacterSize(100);
    this->text.setFillColor(sf::Color::White);
    this->text.setFont(fontinio);
    this->text.setPosition(20.f,20.f);
    this->text.setString(ss.str());
    window.draw(text);
}
