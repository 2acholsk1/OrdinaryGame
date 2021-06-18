#include "environment.h"


//GRASS  TREE   STONES   IRON ORE    COAL ORE    GOLDEN ORE

environment::environment(const sf::Vector2f& position,
                         CustomTexture* ctextures,
                         const PartType& cparttype,
                         const IncludedItem& cincludedItem,
                         const MyTexture& ctexture,
                         const float& cstrength,
                         const sf::Vector2u& canimationMaxSize,
                         const float& canimationTime,
                         const float& cpushBackForce

                         ):

                        Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce),
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
                environment::Matchtexture(cparttype)
                );

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

void environment::Update(float& dtime,sf::RenderWindow& window)
{

}

PartType environment::RandomPartEnv()
{
    srand(time(NULL));
    int los=rand()%5;
    switch(los)
    {
    case 0:
    {
        return PartType::Tree;
        break;
    }
    case 1:
    {
        return PartType::Stone;
        break;
    }
    case 2:
    {
        return PartType::IronOre;
        break;
    }
    case 3:
    {
        return PartType::GoldenOre;
        break;
    }
    case 4:
    {
        return PartType::CoalOre;
        break;
    }
        break;
    }
}

MyTexture environment::Matchtexture(const PartType& type)
{

    switch(type)
    {
    case PartType::Tree:
    {
        return MyTexture::Tree;
        break;
    }
    case PartType::Stone:
    {
        return MyTexture::Stones;
        break;
    }
    case PartType::IronOre:
    {
        return MyTexture::IronOre;
        break;
    }
    case PartType::GoldenOre:
    {
        return MyTexture::GoldenOre;
        break;
    }
    case PartType::CoalOre:
    {
        return MyTexture::CoalOre;
        break;
    }
        break;
    }
}
