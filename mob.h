#ifndef MOB_H
#define MOB_H
#include "part.h"



class Mob:public Part
{
private:
    float range;
    float followingSpeed;
    float mobPower=-10.f;
    float hp;
    Part* toFollow;
    float totaltime=0;
    int losuj=0;
    int whichSide=0;


public:
    Mob(const sf::Vector2f& position,
        CustomTexture* ctextures,
        const PartType& cparttype=PartType::Mob,
        const MyTexture& ctexture=MyTexture::Mob,
        const sf::Vector2u& canimationMaxSize=sf::Vector2u(1,1),
        const float& canimationTime=1.0f,
        const float& pushBackForce=0.0f,
        const float& crange=500.f,
        const float& cfollowingSpeed=50.f,
        const float& chp=50.f,
        Part* ctoFollow=nullptr
        );

    ~Mob();
    virtual void Draw(sf::RenderWindow& window);
    virtual void Update(float& dtime,sf::RenderWindow& window);

    static Mob* CreateEnemy(const sf::Vector2f& spawnPosition,CustomTexture* textures,const PartType& type, const MyTexture& texture);
    static float GetRange();
    static float GetHp();
    static float GetFollowSpeed();
    static float GetPushBackForce();
    float GetMobPower();

    void switchWhichSide(float& dtime);
    void WhoToFollow(Part* ctoFollow);
    void Following(float& dtime);

    void Existing(float& dtime);
    void Dead();
};

#endif // MOB_H
