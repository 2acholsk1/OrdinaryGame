#include "bars.h"

Bars::Bars(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype,
           const MyTexture& ctexture,
           const sf::Vector2u& canimationMaxSize,
           const float& canimationTime,
           const BarType& cbartype,
           const float& cfilling,
           const float& cmaxFilling,
           const float& cpushBackForce

           ):
Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce),
  type(cbartype),
  filling(cfilling),
  maxFilling(cmaxFilling)
{
    this->sprite.setTextureRect(this->oneBar);
    switch(cbartype)
    {
    case BarType::HpBar:
    {
        infos.emplace_back(cfilling);
        break;
    }
    case BarType::ExpBar:
    {
        infos.emplace_back(cfilling);
        break;
    }
    case BarType::StarveBar:
    {
        infos.emplace_back(cfilling);
        break;
    }
    case BarType::WaterBar:
    {
        infos.emplace_back(cfilling);
        break;
    }
        break;
    }
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

void Bars::Update(float &dtime,sf::RenderWindow& window)
{
     int fill=this->filling*25.f;
     sf::IntRect rect=sf::IntRect(0,fill,250,25);
     this->sprite.setTextureRect(rect);


}


void Bars::UpdateBar(BarType &BT)
{

}

BarType Bars::GetBartType()
{
    return this->type;
}

Bars::~Bars()
{

}
