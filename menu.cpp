#include "menu.h"

Menu::Menu():window(sf::VideoMode(CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT),"OrdinaryGame")
{
    this->background.setFillColor(sf::Color::Cyan);
    this->background.setSize(sf::Vector2f(CONSTANTS::WINDOW_WIDTH,CONSTANTS::WINDOW_HEIGHT));

    this->StartButton.setFillColor(sf::Color::Red);
    this->StartButton.setPosition(700.f,550.f);
    this->StartButton.setSize(sf::Vector2f(200.f,100.f));

    this->font.loadFromFile("fonts/Ace Records.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(150);
    this->text.setFillColor(sf::Color::Red);
    this->text.setPosition(350.f,200.f);
    this->text.setString("OrdinaryGame");

    this->start.setFont(this->font);
    this->start.setFillColor(sf::Color::Cyan);
    this->start.setCharacterSize(50);
    this->start.setPosition(710.f,560.f);
    this->start.setString("START");

}

void Menu::Update()
{
    sf::Event event;
    while(this->window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
        {
            this->window.close();
            break;
        }
        }
    }
    this->MousePosition=sf::Mouse::getPosition(this->window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if((this->MousePosition.x>700.f)&&(this->MousePosition.y>550.f)&&(this->MousePosition.x<900.f)&&(this->MousePosition.y<650.f))
        {
            this->window.close();
        }
    }


}

void Menu::Draw()
{
    this->window.clear(sf::Color::Black);
    this->window.draw(this->background);
    this->window.draw(this->StartButton);
    this->window.draw(this->text);
    this->window.draw(this->start);
    this->window.display();
}

bool Menu::IsWorking()
{
    return this->window.isOpen();
}
