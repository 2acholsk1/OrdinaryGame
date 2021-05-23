#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "part.h"

enum class EnvParts
{
    Default,
    Tree,
    Stone,
    IronOre,
    CoalOre,
    GoldenOre,
    CooperOre
};


class environment: public Part
{
protected:
    EnvPart envpart;
public:
    environment(sf::Vector2f& position,
                CustomTexture* ctextures,
                const MyTexture& ctexture,
                const PartType& cparttype,
                const sf::Vector2u& canimationMaxSize,
                const double& canimationTime);
    ~environment();
};

#endif // ENVIRONMENT_H
