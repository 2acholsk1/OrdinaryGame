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

void Part::UpdatePos(Part *PlaySpri,Part *partSpri)
{
    sf::Vector2f Position=PlaySpri->GetPosition();

    switch(partSpri->GetPartType())
    {
    case PartType::InterfacePart:
    {
        sf::Vector2f where(CONSTANTS::INTERFACE_POSITION);
        this->sprite.setPosition(Position+where);
        break;

    }
    case PartType::HpBar:
    {
        sf::Vector2f where(CONSTANTS::HP_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::ExpBar:
    {
        sf::Vector2f where(CONSTANTS::EXP_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::WaterBar:
    {
        sf::Vector2f where(CONSTANTS::WATER_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::StarveBar:
    {
        sf::Vector2f where(CONSTANTS::STARVE_BAR_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
    case PartType::GPSArrow:
    {
        sf::Vector2f where(CONSTANTS::ARROW_MINIMAP_POSITION);
        this->sprite.setPosition(Position+where);
        break;
    }
//    case PartType::Slot1:
//    {
//        sf::Vector2f where(CONSTANTS::SLOT_1_POSITION);
//        this->sprite.setPosition(Position+where);
//        break;
//    }
//    case PartType::Slot2:
//    {
//        sf::Vector2f where(CONSTANTS::SLOT_2_POSITION);
//        this->sprite.setPosition(Position+where);
//        break;
//    }
//    case PartType::Slot3:
//    {
//        sf::Vector2f where(CONSTANTS::SLOT_3_POSITION);
//        this->sprite.setPosition(Position+where);
//        break;
//    }
//    case PartType::Slot4:
//    {
//        sf::Vector2f where(CONSTANTS::SLOT_4_POSITION);
//        this->sprite.setPosition(Position+where);
//        break;
//    }
//    case PartType::Slot5:
//    {
//        sf::Vector2f where(CONSTANTS::SLOT_5_POSITION);
//        this->sprite.setPosition(Position+where);
//        break;
//    }
    break;
    }

//    std::cout<<"x where:"<<where.x<<std::endl;
//    std::cout<<"y where:"<<where.y<<std::endl;

//    std::cout<<"x Position:"<<Position.x<<std::endl;
//    std::cout<<"y Position:"<<Position.y<<std::endl;




}

Part::~Part()
{

}


