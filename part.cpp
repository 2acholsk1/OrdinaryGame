#include "part.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>




Part::Part(const sf::Vector2f& position,
           const PartType& type,
           CustomTexture* ctextures,
           const MyTexture& ctexture,
           const sf::Vector2u& canimationMaxSize,
           const float& canimationTime):

           sprite(sf::Sprite()),
           parttype(type),
           textures(ctextures),
           texture(ctexture),
           animation(ctextures->GettTexture(ctexture),canimationMaxSize,canimationTime)

{
    this->sprite.setPosition(position);
    this->sprite.setTexture(textures->GettTexture(texture));
    this->sprite.setTextureRect(this->animation.GetFrameIntRect());

}

Part::~Part()
{

}


