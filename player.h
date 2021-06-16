#ifndef PLAYER_H
#define PLAYER_H
#include "part.h"
#include "bars.h"
#include "math.h"



class Player: public Part
{
public:
    sf::Vector2u toanimationMaxSize=sf::Vector2u(1,1);
    float hp=100;
    float exp=0;
    float starve=100;
    float water=100;
    float acceleration=0;
    bool isMove=0;
    sf::RectangleShape body;
    sf::Vector2f currentPosition;
    sf::Vector2f lastPosition;
    float displacment;


public:
    Player(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype=PartType::Default,
           const MyTexture& ctexture=MyTexture::Default,
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
//    Collider GetCollider();
//    sf::Vector2f GetPositionCol();


};

#endif // PLAYER_H
