#include "game.h"


Game::Game():window(sf::VideoMode(CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT), "OrdinaryGame"),time(0.0f)
{
    this->LoadTextures();
    environment* test2=environment::PrintEnvironment({100.0,200.0},&this->AllTextures,PartType::Tree,MyTexture::Grass);
    this->AllParts.emplace_back(test2);
    environment* test1=environment::PrintEnvironment({100.0,200.0},&this->AllTextures,PartType::Tree,MyTexture::Stones);
    this->AllParts.emplace_back(test1);

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
    this->SetPoinOfView();
    this->DrawParts();
    this->DisplayWindow();

}

void Game::Update()
{
    this->HereWindowEvents();
}

void Game::DrawParts()
{
    for(auto& part:this->AllParts)
    {
        part->Draw(this->window);
    }
}

void Game::SetPoinOfView()
{
    //this->window.setView(MyView);
    this->window.setView(window.getDefaultView());
}

void Game::LoadTextures()
{
    //Enviroment
    this->AllTextures.AddTexture(MyTexture::Grass,"textures/grass.png");
    this->AllTextures.AddTexture(MyTexture::Tree,"textures/baum.png");
    this->AllTextures.AddTexture(MyTexture::Stones,"textures/stone.png");
    this->AllTextures.AddTexture(MyTexture::CoalOre,"textures/coalore.png");
    this->AllTextures.AddTexture(MyTexture::IronOre,"textures/ironore.png");
    this->AllTextures.AddTexture(MyTexture::GoldenOre,"textures/goldenore.png");
}
