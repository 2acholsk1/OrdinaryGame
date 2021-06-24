#include "structures.h"

Structures::Structures(const sf::Vector2f& position,
                       CustomTexture* ctextures,
                       const PartType& cparttype,
                       const MyTexture& ctexture,
                       const float& cstrength,
                       const sf::Vector2u& canimationMaxSize,
                       const float& canimationTime,
                       const float& cpushBackForce
                       ):
                      Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce),
                      strength(cstrength)

{
    this->sprite.setScale(0.6f,0.6f);
    OriginSet(this->sprite);
}
void Structures::Update(float &dtime, sf::RenderWindow &window)
{

}

void Structures::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

Structures* Structures::PrintStructures(const sf::Vector2f& existingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture)
{
    return new Structures(
               existingPosition,
                ctextures,
                cparttype,
                Structures::Matchtexture(cparttype)
                );

}

MyTexture Structures::Matchtexture(const PartType &type)
{
    switch(type)
    {
    case PartType::WoodenFence:
    {
        return MyTexture::WoodenFence;
        break;
    }
    case PartType::Cobble:
    {
        return MyTexture::Cobble;
        break;
    }
    case PartType::Boards:
    {
        return MyTexture::Boards;
        break;
    }
        break;
    }
}


Structures::~Structures()
{

}
