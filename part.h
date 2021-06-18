#ifndef PART_H
#define PART_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "animation.h"
#include "customtexture.h"
#include "Constants.h"
#include "functions.h"
#include "collider.h"

#include <vector>


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
    WaterBar,
    GPSArrow,
    Slot1,
    Slot2,
    Slot3,
    Slot4,
    Slot5

};

class Part
{
protected:
    sf::Sprite sprite;
    PartType parttype;
    CustomTexture* textures;
    MyTexture texture;
    Animation animation;
    float pushBackForce;



public:
    Part(const sf::Vector2f& position,
         const PartType& type,
         CustomTexture* textures,
         const MyTexture& texture=MyTexture::Default,
         const sf::Vector2u& animationMaxSize={1,1},
         const float& animationTime=1.0f,
         const float& pushBackForce=0.5f);

    virtual ~Part();
    virtual void Draw(sf::RenderWindow& window)=0;
    virtual void Update(float& dtime,sf::RenderWindow& window)=0;
    void UpdatePos(Part* PlaySpri,Part *partSpri);
    friend void OriginSet(sf::Sprite& sprite);
    PartType GetPartType();
    Collider GetCollider();
    float GetPushForce();
    sf::Vector2f GetPosition();




};

#endif // PART_H
