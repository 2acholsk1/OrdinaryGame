#include "bars.h"

Bars::Bars(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype,
           const MyTexture& ctexture,
           const sf::Vector2u& canimationMaxSize,
           const float& canimationTime,
           const BarType& cbartype,
           const float& cfilling,
           const float& cmaxFilling
           ):
Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime),
  type(cbartype),
  filling(cfilling),
  maxFilling(cmaxFilling)
{

}

Bars* Bars::PrintBar(const sf::Vector2f& cexistingPosition,
                      CustomTexture* ctextures,
                      const PartType& cparttype,
                      const MyTexture& ctexture,
                      const BarType& cbartype,
                      const float& cfilling)
{
    return new Bars(
                cexistingPosition,
                ctextures,
                cparttype,
                ctexture,
                sf::Vector2u(1,1),
                1.0f,
                cbartype,
                cfilling);
}


void Bars::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void Bars::Update(float &dtime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//left
    {
        this->sprite.move(-CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))//right
    {
        this->sprite.move(CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
    {
        this->sprite.move(0.f,CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
    {
        this->sprite.move(0.f,-CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }


}

void Bars::UpdateBar(BarType &BT)
{
    switch(BT)
    {
    case BarType::HpBar:
    {

    }
    }
}

Bars::~Bars()
{

}
