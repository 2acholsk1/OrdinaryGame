#ifndef PLAYER_H
#define PLAYER_H
#include "part.h"
#include "bars.h"


class Player: public Part
{
public:
    sf::Vector2u toanimationMaxSize=sf::Vector2u(1,1);
    float hp=100;
    float exp=0;
    float starve=100;
    float water=100;
private:

    Inventory slot_1;
    Inventory slot_2;
    Inventory slot_3;
    Inventory slot_4;

public:
    Player(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype=PartType::Default,
           const MyTexture& ctexture=MyTexture::Default,
           const sf::Vector2u& canimationMaxSize=sf::Vector2u(1,1),
           const float& canimationTime=1.0f);
    virtual void Draw(sf::RenderWindow &window);
    ~Player();
    static Player* PrintPlayer(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                         const PartType& cparttype,const MyTexture& ctexture);
    void Update(float& dtime);
    void UpdateBars(float& dtime,float& hp,float& exp,float& starve,float& water);

};

#endif // PLAYER_H
