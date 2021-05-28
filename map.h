#ifndef MAP_H
#define MAP_H
#include <vector>
#include<SFML/Graphics.hpp>

#include "Constants.h"
#include "customtexture.h"




class Mymap
{
private:
    std::vector<std::vector<sf::RectangleShape>> tileMap;
    const MyTexture texture=MyTexture::Grass;
    int fromX=0;
    int toX=0;
    int fromY=0;
    int toY=0;
public:
    Mymap();
    void Draw(sf::RenderWindow& window);
    void SetMyMap(CustomTexture* AllTextures);
};

#endif // MAP_H
