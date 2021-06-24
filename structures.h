#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "part.h"



class Structures: public Part
{
private:
    float strength;
public:
    Structures(const sf::Vector2f& position,
               CustomTexture* ctextures,
               const PartType& cparttype=PartType::Default,
               const MyTexture& ctexture=MyTexture::Default,
               const float& cstrength=1.0f,
               const sf::Vector2u& canimationMaxSize=sf::Vector2u(1,1),
               const float& canimationTime=1.0f,
               const float& pushBackForce=0.0f);
    ~Structures();
    void Update(float& dtime,sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
    static Structures* PrintStructures(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                         const PartType& cparttype,const MyTexture& ctexture);
    static MyTexture Matchtexture(const PartType& type);
};

#endif // STRUCTURES_H
