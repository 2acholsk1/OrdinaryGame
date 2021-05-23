#include "environment.h"
#include <SFML/Graphics.hpp>

environment::environment(sf::Vector2f& position,
                         CustomTexture* ctextures,
                         const MyTexture& ctexture,
                         const PartType& cparttype,
                         const sf::Vector2u& canimationMaxSize,
                         const double& canimationTime,
                         const EnvPart& cenvpart,
                         int& cstrength):

                        Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime),
                        envpart(cenvpart),
                        strength(cstrength)
{

}

environment::~environment()
{

}
