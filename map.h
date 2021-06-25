#ifndef MAP_H
#define MAP_H
#include <vector>
#include<SFML/Graphics.hpp>

#include "customtexture.h"

#define WINDOW_WIDTH 1600.f
#define WINDOW_HEIGHT 900.f

#define GRID_SIZE_F 100.f
#define GRID_SIZE_U static_cast<unsigned>(GRID_SIZE_F)

#define MAP_SIZE 100


class Mymap
{
private:
    std::vector<std::vector<sf::RectangleShape>> tileMap;
    const MyTexture texture=MyTexture::Grass;
    int fromX=0;
    int toX=0;
    int fromY=0;
    int toY=0;
    sf::RectangleShape BigBox;
    sf::RectangleShape Landscape;
    sf::Texture textureWater;
public:
    Mymap();
    void Draw(sf::RenderWindow& window);
    void SetMyMap(CustomTexture* AllTextures);
};

#endif // MAP_H
