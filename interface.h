#ifndef INTERFACE_H
#define INTERFACE_H
#include "part.h"


enum class items
{
    Default,
    Sword,
    Pickaxe,
    Axe,
    Shovel,
    Wood,
    SmallStones,
    Iron,
    Coal,
    Gold

};



class Interface: public Part
{

public:
    Interface(const sf::Vector2f& position,
              const PartType& type,
              CustomTexture* textures,
              const MyTexture& texture=MyTexture::Default,
              const sf::Vector2u& animationMaxSize={1,1},
              const float& animationTime=1.0f,
              const float& pushBackForce=0.5f
              );
    ~Interface();
    static Interface* PrintInterface(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture);
    void InitializeInterface();
    virtual void Update(float& dtime,sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);
//    virtual Collider GetCollider();
//    virtual sf::Vector2f GetPositionCol();
public:
    sf::RectangleShape box;

private:



};

#endif // INTERFACE_H
