#include "map.h"

Mymap::Mymap()
{

}

void Mymap::SetMyMap(CustomTexture* AllTextures)
{
    this->tileMap.resize(CONSTANTS::MAP_SIZE,std::vector<sf::RectangleShape>());


    for(int x=0;x<CONSTANTS::MAP_SIZE;x++)
    {
        tileMap[x].resize(CONSTANTS::MAP_SIZE,sf::RectangleShape());
        for(int y=0;y<CONSTANTS::MAP_SIZE;y++)
        {
            tileMap[x][y].setSize(sf::Vector2f(CONSTANTS::GRID_SIZE_F,CONSTANTS::GRID_SIZE_F));
            tileMap[x][y].setTexture(&AllTextures->GettTexture(texture));
            //tileMap[x][y].setOutlineColor(sf::Color::Blue);
            //tileMap[x][y].setOutlineThickness(1.f);
            tileMap[x][y].setPosition(x*CONSTANTS::GRID_SIZE_F,y*CONSTANTS::GRID_SIZE_F);

        }
    }
}

void Mymap::Draw(sf::RenderWindow& window)
{

    sf::Vector2i PlayerCenterPoint(CONSTANTS::WINDOW_WIDTH/2.f,CONSTANTS::WINDOW_HEIGHT/2.f);
    sf::Vector2f PlayerPosView=window.mapPixelToCoords(PlayerCenterPoint);
    sf::Vector2u PlayerPosGrid;
    if(PlayerPosView.x>=0.f)
    {
        PlayerPosGrid.x=PlayerPosView.x/CONSTANTS::GRID_SIZE_U;
    }
    if(PlayerPosView.y>=0.f)
    {
        PlayerPosGrid.y=PlayerPosView.y/CONSTANTS::GRID_SIZE_U;
    }

    fromX=PlayerPosGrid.x-9;
    toX=PlayerPosGrid.x+9;
    fromY=PlayerPosGrid.y-6;
    toY=PlayerPosGrid.y+6;


    if(fromX<0)
    {
        fromX=0;
    }
    else if(fromX>=CONSTANTS::MAP_SIZE)
    {
        fromX=CONSTANTS::MAP_SIZE-1;
    }
    if(toX<0)
    {
        toX=0;
    }
    else if(toX>=CONSTANTS::MAP_SIZE)
    {
        toX=CONSTANTS::MAP_SIZE-1;
    }
    if(fromY<0)
    {
        fromY=0;
    }
    else if(fromY>=CONSTANTS::MAP_SIZE)
    {
        fromY=CONSTANTS::MAP_SIZE-1;
    }
    if(toY<0)
    {
        toY=0;
    }
    else if(toY>=CONSTANTS::MAP_SIZE)
    {
        toY=CONSTANTS::MAP_SIZE-1;
    }


    for(int x=fromX;x<toX;x++)
    {
        for(int y=fromY;y<toY;y++)
        {
            window.draw(tileMap[x][y]);
        }
    }
}
