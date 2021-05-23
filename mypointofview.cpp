#include "mypointofview.h"

MyPointOfView::MyPointOfView(sf::RenderWindow& window)
{
    sf::View view;
    view.setSize(1920.f,1080.f);
    view.setCenter(window.getSize().x/2.f,window.getSize().y/2.f);
}

