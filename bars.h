#ifndef BARS_H
#define BARS_H
#include "part.h"

enum class BarType
{
    Default,
    HpBar,
    ExpBar,
    StarveBar,
    WaterBar
};

class Bars: public Part
{
protected:
    float filling;
    float maxFilling;
    BarType type;
    sf::IntRect oneBar=sf::IntRect(0,0,250,25);
    std::vector<float> infos;

public:
    Bars(const sf::Vector2f& position,
         CustomTexture* ctextures,
         const PartType& cparttype=PartType::Default,
         const MyTexture& ctexture=MyTexture::Default,
         const sf::Vector2u& canimationMaxSize=sf::Vector2u(1,1),
         const float& canimationTime=1.0f,
         const BarType& cbartype=BarType::Default,
         const float& cfilling=0.f,
         const float& cmaxFilling=0.f,
         const float& pushBackForce=0.5f
         );

    ~Bars();
    virtual void Update(float& dtime,sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);
    static Bars* PrintBar(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                          const PartType& cparttype,const MyTexture& ctexture,const BarType& cbartype,
                          const float& cfilling);
    void UpdateBar(BarType& BT);
    BarType GetBartType();
};

#endif // BARS_H
