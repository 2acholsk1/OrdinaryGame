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
    float time;
    std::vector<Part*> AllParts;
    CustomTexture AllTextures;
    sf::Clock clock;
    //MyPointOfView MyView;


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
    void SetPoinOfView();


};



#endif // GAME_H
