#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "part.h"
#include "customtexture.h"

class Player: public Part
{
private:
    sf::Sprite sprite;


public:
    Player(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype,
           const MyTexture& ctexture,
           const sf::Vector2u& canimationMaxSize,
           const float& canimationTime);
    void SetupPlayer(CustomTexture* ctextures);
};

#endif // PLAYER_H
