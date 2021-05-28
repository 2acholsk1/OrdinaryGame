#include "mypointofview.h"

MyPointOfView::MyPointOfView(sf::RenderWindow& window)
{
    window.setView(static_cast<sf::View>(*this));
    this->setSize(window.getSize().x,window.getSize().y);
    this->setCenter(window.getSize().x/2.f,window.getSize().y/2.f);
    this->text.setPosition(20.f,20.f);
}

void MyPointOfView::Moving(float& dtime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//left
    {
        this->move(-movingSpeed*dtime,0.f);
        this->text.move(-movingSpeed*dtime,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))//right
    {
        this->move(movingSpeed*dtime,0.f);
        this->text.move(movingSpeed*dtime,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
    {
        this->move(0.f,movingSpeed*dtime);
        this->text.move(0.f,movingSpeed*dtime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
    {
        this->move(0.f,-movingSpeed*dtime);
        this->text.move(0.f,-movingSpeed*dtime);
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
    ss<<"Screen: "<<mousePositionScreen.x<<" "<<mousePositionScreen.y<<"\n"
      <<"Window: "<<mousePosWindow.x<<" "<<mousePosWindow.y<<"\n"
      <<"View: "<<mousePosView.x<<" "<<mousePosView.y<<"\n"
      <<"Grid: "<<mousePosGrid.x<<" "<<mousePosGrid.y<<"\n";
    window.setView(window.getDefaultView());



//    std::cout<<"Y:"<<mousePositionScreen.x<<std::endl;
//    std::cout<<"X:"<<mousePositionScreen.y<<std::endl;
    this->fontinio.loadFromFile("fonts/Aspergit Bold.otf");
    this->text.setCharacterSize(20);
    this->text.setFillColor(sf::Color::White);
    this->text.setFont(fontinio);
    this->text.setString(ss.str());

    this->tileSelect.setPosition(mousePosGrid.x*CONSTANTS::GRID_SIZE_F,mousePosGrid.y*CONSTANTS::GRID_SIZE_F);

}

void MyPointOfView::PrintPosition(sf::RenderWindow& window)
{

    window.draw(this->text);
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




