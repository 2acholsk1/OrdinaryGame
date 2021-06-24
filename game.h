#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "part.h"
#include "mypointofview.h"
#include "mousecontrol.h"
#include "map.h"
#include "minimap.h"
#include "player.h"
#include "bars.h"
#include "interface.h"
#include "inventory.h"
#include "environment.h"
#include "collider.h"
#include "mob.h"
#include "functions.h"


class Game
{
private:
    sf::RenderWindow window;
    float dtime=0.f;

    std::vector<Part*> AllParts;
    std::vector<environment*> AllEnvironments;
    std::vector<Mob*> AllMobs;
    std::vector<Bars*> AllBars;
    std::vector<farmland> miniFarm;
    CustomTexture AllTextures;
    sf::Clock dTclock;
    MyPointOfView MyView;
    MyPointOfView MiniMapView1;
    sf::Text te;
    Mymap MainMap;
    minimap MiniMapView;
    Player* MainPlayer;
    Inventory inventory;
    int oneOverTwo=0;
    int ExpGained=0;
    int ereasingEnvironment=0;
    int totalPoints=0;

    bool click=true;
    bool Zpressed=true;
    bool Epressed=true;
    bool Rpressed=true;
    bool Tpressed=true;
    bool miniorNot=true;
    bool theEnd=true;




public:
    Game();
    virtual ~Game();
    bool IsWorking();
    void HereWindowEvents();
    void ClearWindow();
    void DisplayWindow();
    void Draw();
    void DrawEndStates();
    void Update();
    void DrawParts();
    void UpdateParts();
    void LoadTextures();
    void SetPointOfView();
    void SetMinimap();
    void SetdtTime();
    void MyViewControl();
    void MinMapControl();
    void MapRender();
    void CreatePlayer();
    void CreateInterface();
    void CreateEnvironment();
    void CreateMiniMap();
    void CreateMobs();
    void CreateFarmland();
    void Collisions();
    void Crushing();
    void LevelUP();
    void MobAttack();
    void Eating();
    void TheEnd();


};



#endif // GAME_H
