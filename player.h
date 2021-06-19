#ifndef PLAYER_H
#define PLAYER_H
#include "part.h"
#include "bars.h"
#include "math.h"
#include <iostream>



class Player: public Part
{
public:
    sf::Vector2u toanimationMaxSize=sf::Vector2u(1,1);
    float hp=100;
    float exp=0;
    float starve=100;
    float water=100;
    float acceleration=0;
    float range=150.f;
    bool isMove=false;
    bool MovingLeft=false;

    sf::RectangleShape body;
    sf::Vector2f currentPosition;
    sf::Vector2f lastPosition;
    float displacment;

    int lastItemInUse=0;


public:
    Player(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype=PartType::Player,
           const MyTexture& ctexture=MyTexture::Player,
           const sf::Vector2u& canimationMaxSize=sf::Vector2u(2,1),
           const float& canimationTime=1.0f,
           const float& pushBackForce=1.0f);
    virtual void Draw(sf::RenderWindow &window);
    ~Player();
    static Player* PrintPlayer(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                         const PartType& cparttype,const MyTexture& ctexture);
    void Update(float& dtime,sf::RenderWindow& window);
    void UpdateBars(float& dtime,float& hp,float& exp,float& starve,float& water);
    void ShowPosition();
    void IsMoving();
    bool InRange(sf::RenderWindow& window);
    sf::Vector2f GetCurrentPosition();
    void AnimationUp(float& dtime);
//    Collider GetCollider();
//    sf::Vector2f GetPositionCol();


};

#endif // PLAYER_H
