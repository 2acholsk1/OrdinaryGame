#include "game.h"


Game::Game():window(sf::VideoMode(CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT), "OrdinaryGame"),dtime(0.0f),MyView(window),MiniMapView1(window)
{
    window.setFramerateLimit(120);
    this->LoadTextures();

    MainMap.SetMyMap(&this->AllTextures);
    MiniMapView.UpdatingMiniMap(MiniMapView,window);
    this->CreateEnvironment();
    this->CreatePlayer();
    this->CreateInterface();
    this->CreateMobs();

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
    this->AllBars.emplace_back(HpBar);
    Bars* ExpBar=Bars::PrintBar(CONSTANTS::EXP_BAR_POSITION,&this->AllTextures,PartType::ExpBar,MyTexture::ExpBar,BarType::ExpBar,0.f);
    this->AllParts.emplace_back(ExpBar);
    this->AllBars.emplace_back(ExpBar);
    Bars* StarveBar=Bars::PrintBar(CONSTANTS::STARVE_BAR_POSITION,&this->AllTextures,PartType::StarveBar,MyTexture::StarveBar,BarType::StarveBar,100.f);
    this->AllParts.emplace_back(StarveBar);
    this->AllBars.emplace_back(StarveBar);
    Bars* WaterBar=Bars::PrintBar(CONSTANTS::WATER_BAR_POSITION,&this->AllTextures,PartType::WaterBar,MyTexture::WaterBar,BarType::WaterBar,100.f);
    this->AllParts.emplace_back(WaterBar);
    this->AllBars.emplace_back(WaterBar);

    Interface* GPS=Interface::PrintInterface(CONSTANTS::ARROW_MINIMAP_POSITION,&this->AllTextures,PartType::GPSArrow,MyTexture::GPSArrow);
    this->AllParts.emplace_back(GPS);

    this->instruction=Interface::PrintInterface(CONSTANTS::INSTRUCTION_START_POSITION,&this->AllTextures,PartType::Instruction,MyTexture::Instruction);

}



void Game::CreateEnvironment()
{
    using namespace CONSTANTS;
    srand(time(NULL));

    for(int i=0;i<LAKES_QUANTITY;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;

        environment* Lake=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::Lake,MyTexture::Lake);
        this->AllEnvironments.emplace_back(Lake);
    }
    for(int i=0;i<GOLDEN_ORE_QUANTITY;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;

        environment* Gore=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::GoldenOre,MyTexture::GoldenOre);
        this->AllEnvironments.emplace_back(Gore);
    }
    for(int i=0;i<COAL_ORE_QUANTITY;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;

        environment* Core=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::CoalOre,MyTexture::CoalOre);
        this->AllEnvironments.emplace_back(Core);
    }
    for(int i=0;i<IRON_ORE_QUANTITY;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;

        environment* Iore=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::IronOre,MyTexture::IronOre);
        this->AllEnvironments.emplace_back(Iore);
    }
    for(int i=0;i<STONES_QUANTITY;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;

        environment* Stone=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::Stone,MyTexture::Stones);
        this->AllEnvironments.emplace_back(Stone);
    }
    for(int i=0;i<TREE_QUANTITY;i++)
    {
        int losowa1=rand()%10000;
        int losowa2=rand()%10000;

        environment* Tree=environment::PrintEnvironment({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::Tree,MyTexture::Tree);
        this->AllEnvironments.emplace_back(Tree);
    }

}

void Game::CreateMobs()
{
    srand(time(NULL));
    for(int i=0;i<50;i++)
    {
        int losowa1=(rand()%10000)+100;
        int losowa2=(rand()%10000)+150;
        Mob* mobik=Mob::CreateEnemy({(float)losowa1,(float)losowa2},&this->AllTextures,PartType::Mob,MyTexture::MobMoveLeft);
        this->AllMobs.emplace_back(mobik);
    }

}

void Game::CreateStructures()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            if(this->Onepressed)
            {
                this->Onepressed=false;

                sf::Vector2f pos;
                PartType type=PartType::Boards;
                if(this->inventory.Building(type))
                {
                    if((this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
                    {
                        pos=this->MainPlayer->GetPosition()+sf::Vector2f(-120.f,0.f);

                    }
                    else if((!this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
                    {
                       pos=this->MainPlayer->GetPosition()+sf::Vector2f(120.f,0.f);
                    }
                    Structures* structure=Structures::PrintStructures(pos,&this->AllTextures,PartType::Boards,MyTexture::Boards);
                    this->AllStructures.emplace_back(structure);
                }

            }
            else
            {
                this->Onepressed=true;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            if(this->Twopressed)
            {
                this->Twopressed=false;
                sf::Vector2f pos;
                PartType type=PartType::Cobble;
                if(this->inventory.Building(type))
                {
                    if((this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
                    {
                        pos=this->MainPlayer->GetPosition()+sf::Vector2f(-120.f,0.f);

                    }
                    else if((!this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
                    {
                       pos=this->MainPlayer->GetPosition()+sf::Vector2f(120.f,0.f);
                    }
                    Structures* structure=Structures::PrintStructures(pos,&this->AllTextures,PartType::Cobble,MyTexture::Cobble);
                    this->AllStructures.emplace_back(structure);
                }

            }
            else
            {
                this->Twopressed=true;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            if(this->Threepressed)
            {
                this->Threepressed=false;
                sf::Vector2f pos;
                PartType type=PartType::WoodenFence;
                if(this->inventory.Building(type))
                {
                    if((this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
                    {
                        pos=this->MainPlayer->GetPosition()+sf::Vector2f(-80.f,0.f);

                    }
                    else if((!this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
                    {
                       pos=this->MainPlayer->GetPosition()+sf::Vector2f(50.f,0.f);
                    }
                    Structures* structure=Structures::PrintStructures(pos,&this->AllTextures,PartType::WoodenFence,MyTexture::WoodenFence);
                    this->AllStructures.emplace_back(structure);
                }

            }
            else
            {
                this->Threepressed=true;
            }
        }
    }
}

void Game::CreateFarmland()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {

        if(this->Zpressed)
        {
            this->Zpressed=false;
            sf::Vector2f pos;
            if((this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
            {
                pos=this->MainPlayer->GetPosition()+sf::Vector2f(-80.f,0.f);

            }
            else if((!this->MainPlayer->MLeft())&&(!this->MainPlayer->IMove()))
            {
               pos=this->MainPlayer->GetPosition()+sf::Vector2f(50.f,0.f);
            }

            farmland field=farmland(&this->AllTextures,pos);
            this->miniFarm.emplace_back(field);
            this->totalPoints+=CONSTANTS::POINTS_FOR_FARMLAND;
        }
    }
    else
    {
        this->Zpressed=true;
    }

}

void Game::Eating()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        if(this->Epressed)
        {
            this->Epressed=false;
            FieldType type=FieldType::Carrot;
            if(this->inventory.Eating(type))
            {
                this->AllBars[0]->ChangeFilling(CONSTANTS::HEALING_CARROT);
                this->AllBars[2]->ChangeFilling(CONSTANTS::EATING_CARROT);
            }
        }
    }
    else
    {
        this->Epressed=true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        if(this->Rpressed)
        {
            this->Rpressed=false;
            FieldType type=FieldType::Potato;
            if(this->inventory.Eating(type))
            {
                this->AllBars[0]->ChangeFilling(CONSTANTS::HEALING_POTATO);
                this->AllBars[2]->ChangeFilling(CONSTANTS::EATING_POTATO);
            }
        }
    }
    else
    {
        this->Rpressed=true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        if(this->Tpressed)
        {
            this->Tpressed=false;
            FieldType type=FieldType::Beet;
            if(this->inventory.Eating(type))
            {
                this->AllBars[0]->ChangeFilling(CONSTANTS::HEALING_BEET);
                this->AllBars[2]->ChangeFilling(CONSTANTS::EATING_BEET);
            }
        }
    }
    else
    {
        this->Tpressed=true;
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
            this->MiniMapView1.Resize(this->window);
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
    if(this->theEnd)
    {
        this->ClearWindow();
        this->SetPointOfView();
        this->MapRender();
        this->DrawParts();
        this->inventory.Draw(this->window);
        this->SetMinimap();
        this->miniorNot=false;
        this->DrawParts();
        this->window.setView(window.getDefaultView());
        this->miniorNot=true;
        this->DisplayWindow();
    }
    if(this->theEnd==false)
    {
        this->ClearWindow();
        this->SetPointOfView();
        this->DrawEndStates();
        this->DisplayWindow();
    }
}

void Game::Update()
{
    if(this->theEnd)
    {
        this->SetdtTime();
        this->MyViewControl();
        this->UpdateParts();
        this->MinMapControl();

        this->TheEnd();
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            window.close();
        }
    }
    this->HereWindowEvents();
}

void Game::DrawParts()
{

    for(auto& part: this->AllEnvironments)
    {
        part->Draw(this->window);
    }
    for(auto& mob: this->AllMobs)
    {
        mob->Draw(this->window);
    }
    for(auto& field: this->miniFarm)
    {
        field.Draw(this->window);
    }
    for(auto& structure:this->AllStructures)
    {
        structure->Draw(this->window);
    }
    if(miniorNot)
    {
        for(auto& part:this->AllParts)
        {
            part->Draw(this->window);
        }
        this->MainPlayer->Draw(this->window);
        if(!this->Ipressed)
        {
            sf::Vector2f pos=this->MainPlayer->GetPosition()+CONSTANTS::INSTRUCTION_POSITION;
            this->instruction->SetPosition(pos);
            this->instruction->Draw(this->window);
        }

    }




}

void Game::DrawEndStates()
{
    sf::Text text[4];
    sf::Font font;
    font.loadFromFile("fonts/Ace Records.ttf");

    for(int i=0;i<4;i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(50);
        text[i].setFillColor(sf::Color::Red);
        switch(i)
        {
        case 0:
        {
            std::string string="GAME OVER";
            text[i].setPosition(CONSTANTS::GAME_OVER_POSITION+this->MainPlayer->GetPosition());
            text[i].setCharacterSize(100);
            text[i].setString(string);
            break;
        }
        case 1:
        {
            std::string string="TOTAL POINTS";
            text[i].setPosition(CONSTANTS::TOTAL_POINTS_POSITION+this->MainPlayer->GetPosition());
            text[i].setCharacterSize(60);
            text[i].setString(string);
            break;
        }
        case 2:
        {
            std::string string=std::to_string(this->totalPoints);
            text[i].setPosition(CONSTANTS::POINTS_POSITION+this->MainPlayer->GetPosition());
            text[i].setCharacterSize(60);
            text[i].setString(string);
            break;
        }
        case 3:
        {
            std::string string="PRESS  X  TO QUIT";
            text[i].setPosition(CONSTANTS::PRESS_X_POSITION+this->MainPlayer->GetPosition());
            text[i].setCharacterSize(35);
            text[i].setString(string);
            break;
        }
            break;
        }



        window.draw(text[i]);
    }


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
    for(auto& mob: this->AllMobs)
    {

        mob->WhoToFollow(this->MainPlayer);
        mob->Update(this->dtime,this->window);
        if(this->oneOverTwo%2==0)
        {
             mob->switchWhichSide(dtime);
        }
        oneOverTwo++;
    }
    for(auto& field:this->miniFarm)
    {
        field.Update(this->dtime,this->window);
    }

    this->Crushing();
    this->CreateFarmland();
    this->CreateStructures();
    this->Eating();
    this->MainPlayer->Update(this->dtime,this->window);
    this->Collisions();
    this->inventory.UpdatePos(this->MainPlayer);
    this->inventory.Update(this->dtime,this->window);
    this->MobAttack();
    this->LevelUP();
    this->UpdateInstruction();
    this->CreateStructures();
}

void Game::UpdateInstruction()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        this->Ipressed=false;
    }
    else
    {
        this->Ipressed=true;
    }
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
    //Collider AllStructures with Player
    for(auto& structure:this->AllStructures)
    {
        Collider StrupartCollider=structure->GetCollider();
        float StrupartPF=structure->GetPushForce();

        if(PLayerPF>StrupartPF)
        {
            PlayerCollider.CheckCollision(StrupartCollider,PLayerPF);
        }
        else
        {
            StrupartCollider.CheckCollision(PlayerCollider,StrupartPF);
        }
    }

    //Collider Mobs and AllEnvironments
    for(auto& mob:this->AllMobs)
    {
        Collider MobCollider=mob->GetCollider();
        float MobPF=mob->GetPushForce();
        for(auto& part:this->AllEnvironments)
        {
            Collider EnvpartCollider=part->GetCollider();
            float EnvpartPF=part->GetPushForce();
            if(MobPF>EnvpartPF)
            {
                MobCollider.CheckCollision(EnvpartCollider,MobPF);


            }
            else
            {
                EnvpartCollider.CheckCollision(MobCollider,EnvpartPF);
            }
        }
        }

    //Collider Mobs with player
    //Collider All environments parts with Player
    for(auto& mob:this->AllMobs)
    {
        Collider MobCollider=mob->GetCollider();
        float MobvpartPF=mob->GetPushForce();

        if(PLayerPF>MobvpartPF)
        {
            PlayerCollider.CheckCollision(MobCollider,PLayerPF);


        }
        else
        {
            MobCollider.CheckCollision(PlayerCollider,MobvpartPF);

        }
    }



}

void Game::Crushing()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(click)
        {
            this->click=false;
            sf::Vector2i mousePosWindow=sf::Mouse::getPosition(window);
            sf::Vector2f copyMouse=window.mapPixelToCoords(mousePosWindow);
            sf::Vector2f cur=this->MainPlayer->GetCurrentPosition()+sf::Vector2f(-CONSTANTS::PLAYER_MIDDLE_POSITION);
            sf::Vector2f MousePosition=sf::Vector2f((float)copyMouse.x,(float)copyMouse.y);
            bool IsInRange=this->MainPlayer->InRange(this->window);
            for(auto& i:this->AllEnvironments)
            {
                if((IsInRange)&&(MousePosition.x>=i->GetSize().left-cur.x)&&(MousePosition.x<=i->GetSize().left+i->GetSize().width-cur.x)&&
                        (MousePosition.y>=i->GetSize().top-cur.y)&&(MousePosition.y<+i->GetSize().top+i->GetSize().height-cur.y))
                {
                    PartType type=i->GetPartType();
                    this->inventory.AddingItem(type);
                    if((this->inventory.GetItemInUse()==0)&&(type!=PartType::Lake))
                    {
                        this->AllBars[0]->ChangeFilling(CONSTANTS::LOST_HP_IN_CHOPPING_AND_DIGGIND_WITHOUT_TOOL);
                    }
                    if((this->inventory.GetItemInUse()==0)&&(type==PartType::Lake))
                    {
                        this->AllBars[3]->ChangeFilling(CONSTANTS::DRINKING);
                    }
                    i->GetOut();
                    this->totalPoints+=CONSTANTS::POINT_FOR_CHOPPING_AND_DIGGING;

                }
            }
            for(auto& mob:this->AllMobs)
            {
                if((IsInRange)&&(MousePosition.x>=mob->GetSize().left-cur.x)&&(MousePosition.x<=mob->GetSize().left+mob->GetSize().width-cur.x)&&
                        (MousePosition.y>=mob->GetSize().top-cur.y)&&(MousePosition.y<+mob->GetSize().top+mob->GetSize().height-cur.y))
                {
                    this->AllBars[1]->ChangeFilling(CONSTANTS::EXP_OF_FIGHT);
                    mob->Dead();
                    this->totalPoints+=CONSTANTS::POINTS_FOR_FIGHT;

                }
            }

            for(auto& field:this->miniFarm)
            {
                if((IsInRange)&&(MousePosition.x>=field.GetSize().left-cur.x)&&(MousePosition.x<=field.GetSize().left+field.GetSize().width-cur.x)&&
                        (MousePosition.y>=field.GetSize().top-cur.y)&&(MousePosition.y<+field.GetSize().top+field.GetSize().height-cur.y))
                {
                    if((this->inventory.GetItemInUse()==0)&&(field.GetFieldType()!=FieldType::Common))
                    {
                        this->AllBars[1]->ChangeFilling(CONSTANTS::EXP_OF_FARMING);
                    }

                    FieldType type=field.GetFieldType();
                    this->inventory.AddingItem(type);
                    field.Remove();
                    this->totalPoints+=CONSTANTS::POINT_FOR_HARVEST;
                }
            }



        }


    }
    else
    {
        this->click=true;
    }

}

void Game::LevelUP()
{
    if(this->AllBars[1]->GetFilling()>=100)
    {
        this->totalPoints+=CONSTANTS::POINTS_FOR_LEVEL_UP;
    }
}

void Game::MobAttack()
{
    auto PlayerBounds=this->MainPlayer->GetGlobalBounds();
    for(auto& i:this->AllMobs)
    {
        if((PlayerBounds.left<i->GetSize().left+i->GetSize().width+5.f)&&
                (PlayerBounds.left+PlayerBounds.width>i->GetSize().left-5)&&
                (PlayerBounds.top+PlayerBounds.height>=i->GetSize().top-5)&&
                (PlayerBounds.top<i->GetSize().top+i->GetSize().height+5))
        {
            this->AllBars[0]->ChangeFilling(CONSTANTS::ZOMBIE_ATTACK);
        }
    }
}

void Game::SetPointOfView()
{

    this->window.setView(MyView);
    this->MyView.setViewport(CONSTANTS::VIEW_SIZE);

}

void Game::SetMinimap()
{
    this->window.setView(MiniMapView1);
    this->MiniMapView1.setViewport(CONSTANTS::MINIMAMP_SIZE);
}

void Game::SetdtTime()
{
    this->dtime=this->dTclock.restart().asSeconds();
}
void Game::MyViewControl()
{
    this->MyView.setCenter(this->MainPlayer->GetCurrentPosition());
    this->MyView.SetRect();


}

void Game::MinMapControl()
{
    this->MiniMapView1.setCenter(this->MainPlayer->GetCurrentPosition());
    this->MiniMapView1.SetRect();


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
    this->AllTextures.AddTexture(MyTexture::Lake,"textures/Environment/lake.png");
    this->AllTextures.AddTexture(MyTexture::Stones,"textures/Environment/stone.png");
    this->AllTextures.AddTexture(MyTexture::CoalOre,"textures/Environment/coalore.png");
    this->AllTextures.AddTexture(MyTexture::IronOre,"textures/Environment/ironore.png");
    this->AllTextures.AddTexture(MyTexture::GoldenOre,"textures/Environment/goldenore.png");
    this->AllTextures.AddTexture(MyTexture::Player,"textures/Player/Player.png");
    this->AllTextures.AddTexture(MyTexture::PlayerDead,"textures/Player/PlayerDead.png");
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
    this->AllTextures.AddTexture(MyTexture::Bel,"textures/interface/Bel.png");
    this->AllTextures.AddTexture(MyTexture::Instruction,"textures/interface/Instruction.png");
    this->AllTextures.AddTexture(MyTexture::GPSArrow,"textures/interface/minimapArrow.png");
    this->AllTextures.AddTexture(MyTexture::Slot,"textures/interface/slot.png");
    this->AllTextures.AddTexture(MyTexture::HpBar,"textures/bars/hpbar.png");
    this->AllTextures.AddTexture(MyTexture::ExpBar,"textures/bars/expbar.png");
    this->AllTextures.AddTexture(MyTexture::StarveBar,"textures/bars/starvebar.png");
    this->AllTextures.AddTexture(MyTexture::WaterBar,"textures/bars/waterbar.png");
    this->AllTextures.AddTexture(MyTexture::Shovel,"textures/Tools/shovel.png");
    this->AllTextures.AddTexture(MyTexture::Sword,"textures/Tools/sword.png");
    this->AllTextures.AddTexture(MyTexture::Pickaxe,"textures/Tools/pickaxe.png");
    this->AllTextures.AddTexture(MyTexture::Axe,"textures/Tools/axe.png");
    this->AllTextures.AddTexture(MyTexture::MobMoveLeft,"textures/Mob/MobMoveLeft.png");
    this->AllTextures.AddTexture(MyTexture::MobMoveRight,"textures/Mob/MobMoveRight.png");
    this->AllTextures.AddTexture(MyTexture::Field,"textures/Environment/Field.png");
    this->AllTextures.AddTexture(MyTexture::CarrotField,"textures/Environment/CarrotField.png");
    this->AllTextures.AddTexture(MyTexture::PotatoField,"textures/Environment/PotatoField.png");
    this->AllTextures.AddTexture(MyTexture::BeetField,"textures/Environment/BeetField.png");
    this->AllTextures.AddTexture(MyTexture::WoodenFence,"textures/Structures/WoodenFence.png");
    this->AllTextures.AddTexture(MyTexture::Cobble,"textures/Structures/Cobble.png");
    this->AllTextures.AddTexture(MyTexture::Boards,"textures/Structures/Boards.png");


}

void Game::TheEnd()
{
    for(int i=0;i<4;i++)
    {
        if(this->AllBars[i]->GetFilling()<0)
        {
            this->theEnd=false;

        }
    }
}

Game::~Game()
{
    delete this->MainPlayer;

    for(auto& i:this->AllParts)
    {
        delete i;
    }
    for(auto& i:this->AllEnvironments)
    {
        delete i;
    }
    for(auto& i:this->AllMobs)
    {
        delete i;
    }
    for(auto& i:this->AllBars)
    {
        delete i;
    }
    for(auto& i:this->miniFarm)
    {
        delete &i;
    }

}

