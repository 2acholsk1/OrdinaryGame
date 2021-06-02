#include "part.h"





Part::Part(const sf::Vector2f& position,
           const PartType& type,
           CustomTexture* ctextures,
           const MyTexture& ctexture,
           const sf::Vector2u& canimationMaxSize,
           const float& canimationTime,
           const float& cpushBackForce
           ):

           sprite(sf::Sprite()),
           parttype(type),
           textures(ctextures),
           texture(ctexture),
           animation(ctextures->GettTexture(ctexture),canimationMaxSize,canimationTime),
           pushBackForce(cpushBackForce)

{
    this->sprite.setPosition(position);
    this->sprite.setTexture(textures->GettTexture(texture));
    this->sprite.setTextureRect(this->animation.GetFrameIntRect());



}

PartType Part::GetPartType()
{
    return this->parttype;
}

Collider Part::GetCollider()
{
    return Collider(this->sprite);
}

float Part::GetPushForce()
{
    return this->pushBackForce;
}

Part::~Part()
{

}


