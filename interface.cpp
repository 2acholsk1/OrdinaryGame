#include "interface.h"

Interface::Interface(const sf::Vector2f& position,
                     const PartType& cparttype,
                     CustomTexture* ctextures,
                     const MyTexture& ctexture,
                     const sf::Vector2u& canimationMaxSize,
                     const float& canimationTime):

                    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime)
{

}
