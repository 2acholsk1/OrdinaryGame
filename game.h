#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "part.h"
#include "Constants.h"


class Game
{
private:
    sf::RenderWindow window;
    float time;
    std::vector<Part*> AllParts;
    CustomTexture AllTextures;
    sf::Clock clock;


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


};



#endif // GAME_H
