#include "game.h"


Game::Game():window(sf::VideoMode(CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT), "OrdinaryGame"),dtime(0.0f),MyView(window)
{
    window.setFramerateLimit(120);
    this->LoadTextures();

    MainMap.SetMyMap(&this->AllTextures);
    MiniMapView.UpdatingMiniMap(MiniMapView,window);
    this->CreateEnvironment();
    this->CreatePlayer();
    this->CreateInterface();

}

void Game::CreatePlayer()
{
    Player* player=Player::PrintPlayer(CONSTANTS::PLAYER_MIDDLE_POSITION,&this->AllTextures,PartType::Player,MyTexture::Player);
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
//    Inventory* Slot1=Inventory::PrintInventorySlot(CONSTANTS::SLOT_1_POSITION,&this->AllTextures,PartType::Slot1,MyTexture::Slot);
//    this->AllParts.emplace_back(Slot1);
//    Inventory* Slot2=Inventory::PrintInventorySlot(CONSTANTS::SLOT_2_POSITION,&this->AllTextures,PartType::Slot2,MyTexture::Slot);
//    this->AllParts.emplace_back(Slot2);
//    Inventory* Slot3=Inventory::PrintInventorySlot(CONSTANTS::SLOT_3_POSITION,&this->AllTextures,PartType::Slot3,MyTexture::Slot);
//    this->AllParts.emplace_back(Slot3);
//    Inventory* Slot4=Inventory::PrintInventorySlot(CONSTANTS::SLOT_4_POSITION,&this->AllTextures,PartType::Slot4,MyTexture::Slot);
//    this->AllParts.emplace_back(Slot4);
//    Inventory* Slot5=Inventory::PrintInventorySlot(CONSTANTS::SLOT_4_POSITION,&this->AllTextures,PartType::Slot5,MyTexture::Slot);
//    this->AllParts.emplace_back(Slot5);
//    minimap* Minimap=minimap::PrintMiniMap(CONSTANTS::ARROW_MINIMAP_POSITION,&this->AllTextures,PartType::GPSArrow,MyTexture::GPSArrow);
//    this->AllParts.emplace_back(Minimap);

}



void Game::CreateEnvironment()
{
    srand(time(NULL));

    for(int i=0;i<1000;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;
        environment* test4=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::GoldenOre,MyTexture::GoldenOre);
        AllEnvironments.emplace_back(test4);
    }
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

    for(auto& part: this->AllEnvironments)
    {
        part->Draw(this->window);
    }
    for(auto& part:this->AllParts)
    {
        part->Draw(this->window);
    }
    this->MainPlayer->Draw(this->window);
}

void Game::UpdateParts()
{
    for(auto& part:this->AllParts)
    {
        part->UpdatePos(this->MainPlayer,part);

    }
    for(auto& part:this->AllParts)
    {
        part->Update(this->dtime,this->window);

    }
    for(auto& part:this->AllEnvironments)
    {
        part->Update(this->dtime,this->window);

    }

    this->MainPlayer->Update(this->dtime,this->window);

    this->Collisions();
}

void Game::Collisions()
{
    //Collisions beetwen:

    //Init PLayer Collider and Push Force
    Collider PlayerCollider=this->MainPlayer->GetCollider();
    float PLayerPF=this->MainPlayer->GetPushForce();


    //Collider All environments parts with Player
    for(auto& part:this->AllEnvironments)
    {
        Collider EnvpartCollider=part->GetCollider();
        float EnvpartPF=part->GetPushForce();

        if(PLayerPF>EnvpartPF)
        {
            PlayerCollider.CheckCollision(EnvpartCollider,PLayerPF);
        }
        else
        {
            EnvpartCollider.CheckCollision(PlayerCollider,EnvpartPF);
        }
    }

    //Collider Water and Player

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
    this->MyView.setCenter(this->MainPlayer->currentPosition);
    this->MyView.SetRect();
    this->MyView.MouseControl(this->window);
    this->MyView.PrintPosition(this->window);

}

void Game::MapRender()
{
    this->MainMap.Draw(this->window);

}

void Game::LoadTextures()
{
    //Enviroment
    this->AllTextures.AddTexture(MyTexture::Grass,"textures/Environment/grass.png");
    this->AllTextures.AddTexture(MyTexture::Water,"textures/Environment/water.png");
    this->AllTextures.AddTexture(MyTexture::Tree,"textures/Environment/baum.png");
    this->AllTextures.AddTexture(MyTexture::Stones,"textures/Environment/stone.png");
    this->AllTextures.AddTexture(MyTexture::CoalOre,"textures/Environment/coalore.png");
    this->AllTextures.AddTexture(MyTexture::IronOre,"textures/Environment/ironore.png");
    this->AllTextures.AddTexture(MyTexture::GoldenOre,"textures/Environment/goldenore.png");
    this->AllTextures.AddTexture(MyTexture::Player,"textures/Player/Player.png");
    this->AllTextures.AddTexture(MyTexture::PlayerMR,"textures/Player/PlayerMoveRight.png");
    this->AllTextures.AddTexture(MyTexture::PlayerML,"textures/Player/PlayerMoveLeft.png");
    this->AllTextures.AddTexture(MyTexture::PlayerMD,"textures/Player/PlayerMoveDown.png");
    this->AllTextures.AddTexture(MyTexture::PlayerMU,"textures/Player/PlayerMoveUp.png");
    this->AllTextures.AddTexture(MyTexture::PlayerShovelL,"textures/Player/PlayerShovelLeft.png");
    this->AllTextures.AddTexture(MyTexture::PlayerShovelR,"textures/Player/PlayerShovelRight.png");
    this->AllTextures.AddTexture(MyTexture::PlayerSwordL,"textures/Player/PlayerSwordLeft.png");
    this->AllTextures.AddTexture(MyTexture::PlayerSwordR,"textures/Player/PlayerSwordRight.png");
    this->AllTextures.AddTexture(MyTexture::PlayerPickaxeL,"textures/Player/PlayerPickaxeLeft.png");
    this->AllTextures.AddTexture(MyTexture::PlayerPickaxeR,"textures/Player/PlayerPickaxeRight.png");
    this->AllTextures.AddTexture(MyTexture::PlayerAxeL,"textures/Player/PlayerAxeLeft.png");
    this->AllTextures.AddTexture(MyTexture::PlayerAxeR,"textures/Player/PlayerAxeRight.png");
    this->AllTextures.AddTexture(MyTexture::InterfaceDown,"textures/interface/down.png");
    this->AllTextures.AddTexture(MyTexture::Slot,"textures/interface/slot.png");
    this->AllTextures.AddTexture(MyTexture::HpBar,"textures/bars/hpbar.png");
    this->AllTextures.AddTexture(MyTexture::ExpBar,"textures/bars/expbar.png");
    this->AllTextures.AddTexture(MyTexture::StarveBar,"textures/bars/starvebar.png");
    this->AllTextures.AddTexture(MyTexture::WaterBar,"textures/bars/waterbar.png");
    this->AllTextures.AddTexture(MyTexture::Shovel,"textures/Tools/shovel.png");
    this->AllTextures.AddTexture(MyTexture::Sword,"textures/Tools/sword.png");
    this->AllTextures.AddTexture(MyTexture::Pickaxe,"textures/Tools/pickaxe.png");
    this->AllTextures.AddTexture(MyTexture::Axe,"textures/Tools/axe.png");

}

Game::~Game()
{
    delete this->MainPlayer;

    for(auto& i:AllParts)
    {
        delete i;
    }
    for(auto& i:AllEnvironments)
    {
        delete i;
    }
}

