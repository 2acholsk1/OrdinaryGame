#ifndef PART_H
#define PART_H
#include <SFML/Graphics.hpp>

#include "game.h"
#include "customtexture.h"


enum class PartType
{
    Default,
    Player,
    Mob,
    Item,
    InterfacePart,
    Tree,
    Structure,
    Minerals

};

class Part
{
protected:
    sf::Sprite sprite;
    PartType parttype;
    CustomTexture* textures;
    MyTexture texture;



public:
    Part(sf::Vector2f& position,
         const PartType& type,
         CustomTexture* textures,
         const MyTexture& texture=MyTexture::Default
            );
    virtual ~Part();


};

#endif // PART_H
