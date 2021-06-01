#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "part.h"
#include "mypointofview.h"
#include "mousecontrol.h"
#include "map.h"
#include "player.h"
#include "bars.h"
#include "interface.h"
#include "environment.h"


class Game
{
private:
    sf::RenderWindow window;
    float dtime=0.f;
    std::vector<Part*> AllParts;
    CustomTexture AllTextures;
    sf::Clock dTclock;
    MyPointOfView MyView;
    sf::Text te;
    Mymap MainMap;
    Player* MainPlayer;


public:
    Game();
    virtual ~Game()=default;
    bool IsWorking();
    void HereWindowEvents();
    void ClearWindow();
    void DisplayWindow();
    void Draw();
    void Update();
    void DrawParts();
    void UpdateParts();
    void LoadTextures();
    void SetPointOfView();
    void SetdtTime();
    void MyViewControl();
    void MapRender();
    void CreatePlayer();
    void CreateInterface();
    void Collisions();


};



#endif // GAME_H
