#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "part.h"


enum class IncludedItem
{
    Default,
    Wood,
    SmallStones,
    Iron,
    Coal,
    Gold
};


class environment: public Part
{
protected:
    float strength;
    IncludedItem includedItem;
    sf::RectangleShape EnvShape;

public:
    environment(const sf::Vector2f& position,
                CustomTexture* ctextures,
                const PartType& cparttype=PartType::Default,
                const IncludedItem& cincludedItem=IncludedItem::Default,
                const MyTexture& ctexture=MyTexture::Default,
                const float& cstrength=1.0f,
                const sf::Vector2u& canimationMaxSize=sf::Vector2u(1,1),
                const float& canimationTime=1.0f,
                const float& pushBackForce=0.0f
                );
    ~environment();
    virtual void Draw(sf::RenderWindow& window) override;
    static environment* PrintEnvironment(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                         const PartType& cparttype,const MyTexture& ctexture);
    static IncludedItem GetIncludedItem(const PartType& parttype);
    virtual void Update(float& dtime,sf::RenderWindow& window);
    static MyTexture Matchtexture(const PartType& type);
    static PartType RandomPartEnv();
    void GetOut();
};

#endif // ENVIRONMENT_H
