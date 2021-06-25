#include "map.h"

Mymap::Mymap()
{

}

void Mymap::SetMyMap(CustomTexture* AllTextures)
{
    this->tileMap.resize(MAP_SIZE,std::vector<sf::RectangleShape>());


    for(int x=0;x<MAP_SIZE;x++)
    {
        tileMap[x].resize(MAP_SIZE,sf::RectangleShape());
        for(int y=0;y<MAP_SIZE;y++)
        {
            tileMap[x][y].setSize(sf::Vector2f(GRID_SIZE_F,GRID_SIZE_F));
            tileMap[x][y].setTexture(&AllTextures->GettTexture(texture));
            tileMap[x][y].setPosition(x*GRID_SIZE_F,y*GRID_SIZE_F);

        }
    }
    this->BigBox.setSize(sf::Vector2f( GRID_SIZE_F* MAP_SIZE, GRID_SIZE_F* MAP_SIZE));
    this->Landscape.setSize(sf::Vector2f( GRID_SIZE_F* MAP_SIZE*1.25f, GRID_SIZE_F* MAP_SIZE*1.25f));
    this->textureWater=AllTextures->GettTexture(MyTexture::Water);
    this->textureWater.setRepeated(true);
    this->Landscape.setTexture(&textureWater);
    this->Landscape.setOrigin(this->Landscape.getSize().x/2.f,this->Landscape.getSize().y/2.f);
    this->Landscape.setPosition(sf::Vector2f( GRID_SIZE_F* MAP_SIZE/2.f, GRID_SIZE_F* MAP_SIZE/2.f));

}

void Mymap::Draw(sf::RenderWindow& window)
{

    window.draw(this->BigBox);
    window.draw(this->Landscape);
    sf::Vector2i PlayerCenterPoint( WINDOW_WIDTH/2.f, WINDOW_HEIGHT/2.f);
    sf::Vector2f PlayerPosView=window.mapPixelToCoords(PlayerCenterPoint);
    sf::Vector2u PlayerPosGrid;
    if(PlayerPosView.x>=0.f)
    {
        PlayerPosGrid.x=PlayerPosView.x/ GRID_SIZE_U;
    }
    if(PlayerPosView.y>=0.f)
    {
        PlayerPosGrid.y=PlayerPosView.y/ GRID_SIZE_U;
    }

    fromX=PlayerPosGrid.x-12;
    toX=PlayerPosGrid.x+12;
    fromY=PlayerPosGrid.y-6;
    toY=PlayerPosGrid.y+6;


    if(fromX<0)
    {
        fromX=0;
    }
    else if(fromX>=MAP_SIZE)
    {
        fromX=MAP_SIZE-1;
    }
    if(toX<0)
    {
        toX=0;
    }
    else if(toX>=MAP_SIZE)
    {
        toX=MAP_SIZE-1;
    }
    if(fromY<0)
    {
        fromY=0;
    }
    else if(fromY>=MAP_SIZE)
    {
        fromY=MAP_SIZE-1;
    }
    if(toY<0)
    {
        toY=0;
    }
    else if(toY>=MAP_SIZE)
    {
        toY=MAP_SIZE-1;
    }


    for(int x=fromX;x<toX;x++)
    {
        for(int y=fromY;y<toY;y++)
        {
            window.draw(tileMap[x][y]);
        }
    }
}
