#include "part.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>




Part::Part(sf::Vector2f& position,
           const PartType& type,
           CustomTexture* ctextures,
           const MyTexture& ctexture):
           sprite(sf::Sprite()),
           parttype(type),
           textures(ctextures),
           texture(ctexture)


{
    this->sprite.setPosition(position);
    this->sprite.setTexture(textures->GetTexture(texture));

}

Part::~Part()
{

}


