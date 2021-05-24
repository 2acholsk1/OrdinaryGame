#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "part.h"
#include "environment.h"
#include "Constants.h"
#include "customtexture.h"
#include "mypointofview.h"


class Game
{
private:
    sf::RenderWindow window;
    float dtime=0.f;
    std::vector<Part*> AllParts;
    CustomTexture AllTextures;
    sf::Clock dTclock;
    MyPointOfView MyView;


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
    void LoadTextures();
    void SetPointOfView();
    void SetdtTime();
    void MyViewControl();


};



#endif // GAME_H
