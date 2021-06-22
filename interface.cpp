#include "interface.h"

Interface::Interface(const sf::Vector2f& position,
                     const PartType& cparttype,
                     CustomTexture* ctextures,
                     const MyTexture& ctexture,
                     const sf::Vector2u& canimationMaxSize,
                     const float& canimationTime,
                     const float& cpushBackForce
                     ):

                    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce)
{

}


Interface* Interface::PrintInterface(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture)
{
    return new Interface(
                cexistingPosition,
                cparttype,
                ctextures,
                ctexture,
                sf::Vector2u(1,1),
                1.f);
}

Interface::~Interface()
{

}

void Interface::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}



void Interface::Update(float &dtime,sf::RenderWindow& window)
{

    if(this->parttype==PartType::GPSArrow)
    {
        OriginSet(this->sprite);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            this->sprite.setRotation(90.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            this->sprite.setRotation(180.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            this->sprite.setRotation(-90.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            this->sprite.setRotation(0.f);
        }
    }
}

