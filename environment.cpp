#include "environment.h"


//GRASS  TREE   STONES   IRON ORE    COAL ORE    GOLDEN ORE

environment::environment(const sf::Vector2f& position,
                         CustomTexture* ctextures,
                         const PartType& cparttype,
                         const IncludedItem& cincludedItem,
                         const MyTexture& ctexture,
                         const float& cstrength,
                         const sf::Vector2u& canimationMaxSize,
                         const float& canimationTime
                         ):

                        Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime),
                        strength(cstrength),
                        includedItem(cincludedItem)
{
    OriginSet(this->sprite);
}


environment* environment::PrintEnvironment(const sf::Vector2f& existingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture)
{
    return new environment(
                existingPosition,
                ctextures,
                cparttype,
                environment::GetIncludedItem(cparttype),
                ctexture,
                1.0f,
                sf::Vector2u(1,1),
                1.0f);
}

IncludedItem environment::GetIncludedItem(const PartType& parttype)
{
    switch(parttype)
    {
    case PartType::Default:
        return IncludedItem::Default;
    case PartType::Tree:
        return IncludedItem::Wood;
    case PartType::Stone:
        return IncludedItem::SmallStones;
    case PartType::IronOre:
        return IncludedItem::Iron;
    case PartType::CoalOre:
        return IncludedItem::Coal;
    case PartType::GoldenOre:
        return IncludedItem::Gold;
    }
}



void environment::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}


environment::~environment()
{

}

void environment::Update(float& dtime)
{

}
