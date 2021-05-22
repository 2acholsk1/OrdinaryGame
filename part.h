#ifndef PART_H
#define PART_H
#include <SFML/Graphics.hpp>

#include "animation.h"
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
    Animation animation;



public:
    Part(sf::Vector2f& position,
         const PartType& type,
         CustomTexture* textures,
         const MyTexture& texture=MyTexture::Default,
         const sf::Vector2u& animationMaxSize={1,1},
         const double& animationTime=1.0f);

    virtual ~Part();


};

#endif // PART_H
