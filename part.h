#ifndef PART_H
#define PART_H
#include <SFML/Graphics.hpp>

#include "animation.h"
#include "customtexture.h"
#include "inventory.h"
#include "Constants.h"


enum class PartType
{
    Default,
    Player,
    Mob,
    Item,
    InterfacePart,
    Structure,
    Tree,
    Stone,
    IronOre,
    CoalOre,
    GoldenOre,
    CooperOre,
    HpBar,
    ExpBar,
    StarveBar,
    WaterBar

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
    Part(const sf::Vector2f& position,
         const PartType& type,
         CustomTexture* textures,
         const MyTexture& texture=MyTexture::Default,
         const sf::Vector2u& animationMaxSize={1,1},
         const float& animationTime=1.0f);

    virtual ~Part();
    virtual void Draw(sf::RenderWindow& window)=0;
    virtual void Update(float& dtime)=0;



};

#endif // PART_H
