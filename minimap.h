#ifndef MINIMAP_H
#define MINIMAP_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "part.h"
#include <iostream>
#include "map.h"



class minimap:public sf::View
{
private:
    float ttime=0;

public:
    minimap();
    ~minimap();
    void Update(float& dtime,sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
    friend void OriginSet(sf::Sprite& sprite);
    void UpdatingMiniMap(minimap& mini, sf::RenderWindow& window);

};

#endif // MINIMAP_H
