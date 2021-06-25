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
#include "structures.h"
#include "menu.h"

#define WINDOW_WIDTH 1600.f
#define WINDOW_HEIGHT 900.f

#define MINIMAMP_SIZE sf::FloatRect(0.883f, 0.87f, 0.064f, 0.1f)
#define VIEW_SIZE sf::FloatRect(0, 0, 1, 1)

#define TREE_QUANTITY 150
#define GOLDEN_ORE_QUANTITY 20
#define COAL_ORE_QUANTITY 40
#define IRON_ORE_QUANTITY 50
#define STONES_QUANTITY 100
#define LAKES_QUANTITY 20

#define POINTS_FOR_FARMLAND 3.f
#define POINT_FOR_CHOPPING_AND_DIGGING 1.f
#define POINTS_FOR_FIGHT 5.f
#define POINT_FOR_HARVEST 1.f
#define POINTS_FOR_LEVEL_UP 10.f

#define EXP_OF_CHOPPING_OR_DIGGING 1.0f
#define EXP_OF_FIGHT 2.0f
#define EXP_OF_FARMING 5.0f

#define HEALING_CARROT 1.f
#define HEALING_POTATO 0.25
#define HEALING_BEET 0.5

#define DRINKING 1.0f
#define EATING_CARROT 0.25f
#define EATING_POTATO 1.f
#define EATING_BEET 0.75f

#define LOST_HP_IN_CHOPPING_AND_DIGGIND_WITHOUT_TOOL -1.0f
#define ZOMBIE_ATTACK -0.1f


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
    std::vector<Structures*> AllStructures;
    CustomTexture AllTextures;
    sf::Clock dTclock;
    MyPointOfView MyView;
    MyPointOfView MiniMapView1;
    sf::Text te;
    Mymap MainMap;
    minimap MiniMapView;
    Player* MainPlayer;
    Inventory inventory;
    Interface* instruction;
    int oneOverTwo=0;
    int ExpGained=0;
    int ereasingEnvironment=0;
    int totalPoints=0;

    bool click=true;
    bool Zpressed=true;
    bool Epressed=true;
    bool Rpressed=true;
    bool Tpressed=true;
    bool Ipressed=true;
    bool Bpressed=true;
    bool Onepressed=true;
    bool Twopressed=true;
    bool Threepressed=true;
    bool miniorNot=true;
    bool theEnd=true;




public:
    Game();
    virtual ~Game();
    bool IsWorking();
    void MenuWorking();
    void HereWindowEvents();
    void ClearWindow();
    void DisplayWindow();
    void Draw();
    void DrawEndStates();
    void Update();
    void DrawParts();
    void UpdateParts();
    void UpdateInstruction();
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
    void CreateStructures();
    void CreateFarmland();
    void Collisions();
    void Crushing();
    void LevelUP();
    void MobAttack();
    void Eating();
    void TheEnd();


};



#endif // GAME_H
