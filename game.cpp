#include "game.h"


Game::Game():window(sf::VideoMode(CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT), "OrdinaryGame"),dtime(0.0f),MyView(window)
{
    window.setFramerateLimit(120);
    this->LoadTextures();
    this->CreatePlayer();
    this->CreateInterface();
//    environment* test2=environment::PrintEnvironment({100.0,200.0},&this->AllTextures,PartType::Tree,MyTexture::Grass);
//    this->AllParts.emplace_back(test2);
//    environment* test1=environment::PrintEnvironment({100.0,200.0},&this->AllTextures,PartType::Tree,MyTexture::Stones);
//    this->AllParts.emplace_back(test1);
      MainMap.SetMyMap(&this->AllTextures);

}

void Game::CreatePlayer()
{
    Player* player=Player::PrintPlayer(CONSTANTS::PLAYER_MIDDLE_POSITION,&this->AllTextures,PartType::Player,MyTexture::Player);
    this->AllParts.emplace_back(player);
    this->MainPlayer=player;
}

void Game::CreateInterface()
{
    Interface* interface=Interface::PrintInterface(CONSTANTS::INTERFACE_POSITION,&this->AllTextures,PartType::InterfacePart,MyTexture::InterfaceDown);
    this->AllParts.emplace_back(interface);
    Bars* HpBar=Bars::PrintBar(CONSTANTS::HP_BAR_POSITION,&this->AllTextures,PartType::HpBar,MyTexture::HpBar,BarType::HpBar,100.f);
    this->AllParts.emplace_back(HpBar);
    Bars* ExpBar=Bars::PrintBar(CONSTANTS::EXP_BAR_POSITION,&this->AllTextures,PartType::ExpBar,MyTexture::ExpBar,BarType::ExpBar,0.f);
    this->AllParts.emplace_back(ExpBar);
    Bars* StarveBar=Bars::PrintBar(CONSTANTS::STARVE_BAR_POSITION,&this->AllTextures,PartType::StarveBar,MyTexture::StarveBar,BarType::StarveBar,100.f);
    this->AllParts.emplace_back(StarveBar);
    Bars* WaterBar=Bars::PrintBar(CONSTANTS::WATER_BAR_POSITION,&this->AllTextures,PartType::WaterBar,MyTexture::WaterBar,BarType::WaterBar,100.f);
    this->AllParts.emplace_back(WaterBar);

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
        switch(event.type)
        {
        case sf::Event::Closed:
        {
            this->window.close();
            break;
        }
        case sf::Event::Resized:
        {
            this->MyView.Resize(this->window);
            break;
        }
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
    this->SetPointOfView();


    this->MapRender();
    this->DrawParts();
    this->MyView.PrintPosition(this->window);//printuje pozycje
    this->window.setView(window.getDefaultView());

    this->DisplayWindow();

}

void Game::Update()
{
    this->SetdtTime();
    this->MyViewControl();
    this->UpdateParts();
    this->HereWindowEvents();


}

void Game::DrawParts()
{
    for(auto& part:this->AllParts)
    {
        part->Draw(this->window);
    }
}

void Game::UpdateParts()
{
    for(auto& part:this->AllParts)
    {
        part->Update(this->dtime);

    }
}

void Game::SetPointOfView()
{
    this->window.setView(MyView);

}

void Game::SetdtTime()
{
    this->dtime=this->dTclock.restart().asSeconds();
}
void Game::MyViewControl()
{
    this->MyView.SetRect();

    this->MyView.MouseControl(this->window);
    this->MyView.PrintPosition(this->window);
    this->MyView.Moving(dtime);

}

void Game::MapRender()
{
    MainMap.Draw(this->window);
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
    this->AllTextures.AddTexture(MyTexture::Player,"textures/Player/Player.png");
    this->AllTextures.AddTexture(MyTexture::PlayerMR,"textures/Player/PlayerMoveRight.png");
    this->AllTextures.AddTexture(MyTexture::PlayerML,"textures/Player/PlayerMoveLeft.png");
    this->AllTextures.AddTexture(MyTexture::InterfaceDown,"textures/interface/down.png");
    this->AllTextures.AddTexture(MyTexture::HpBar,"textures/bars/hpbar.png");
    this->AllTextures.AddTexture(MyTexture::ExpBar,"textures/bars/expbar.png");
    this->AllTextures.AddTexture(MyTexture::StarveBar,"textures/bars/starvebar.png");
    this->AllTextures.AddTexture(MyTexture::WaterBar,"textures/bars/waterbar.png");
}



