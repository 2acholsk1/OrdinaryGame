#include "game.h"


Game::Game():window(sf::VideoMode(CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT), "OrdinaryGame"),time(0.0f)
{

}


bool Game::IsWorking()
{
    return this->window.isOpen();
}

void Game::HereWindowEvents()
{
    sf::Event event;
    while(this->window.pollEvent(event))
    {
        if(event.type==sf::Event::Closed)
        {
            this->window.close();
        }
    }
}

void Game::ClearWindow()
{
    this->window.clear(sf::Color::Black);
}

void Game::DisplayWindow()
{
    this->window.display();
}

void Game::Draw()
{
    this->ClearWindow();
    this->DisplayWindow();
}

void Game::Update()
{
    this->HereWindowEvents();
}

void Game::DrawParts()
{

}
