#include "part.h"
#include <iostream>





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

sf::Vector2f Part::GetPosition()
{
    return this->sprite.getPosition();
}

sf::FloatRect Part::GetSize()
{
    return this->sprite.getGlobalBounds();
}

void Part::UpdatePos(Part *PlaySpri,Part *partSpri)
{
    sf::Vector2f Position=PlaySpri->GetPosition();

    switch(partSpri->GetPartType())
    {
    case PartType::InterfacePart:
    {
        sf::Vector2f where( INTERFACE_POSITION);
        this->sprite.setPosition(Position+where);
        break;

    }
    case PartType::HpBar:
    {
        sf::Vector2f where( HP_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::ExpBar:
    {
        sf::Vector2f where( EXP_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::WaterBar:
    {
        sf::Vector2f where( WATER_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::StarveBar:
    {
        sf::Vector2f where( STARVE_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::GPSArrow:
    {
        sf::Vector2f where( ARROW_MINIMAP_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }

    break;
    }




}

void Part::SetPosition(sf::Vector2f& position)
{
    this->sprite.setPosition(position);
}

Part::~Part()
{

}


