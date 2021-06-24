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
     int fill=this->filling;
     sf::IntRect rect=sf::IntRect(0,fill*25,250,25);
     this->sprite.setTextureRect(rect);
     if((fill>100)&&(this->GetBartType()==BarType::ExpBar))
     {
         this->filling=0.f;
         fill=0;
     }
     this->totalTime+=dtime;
     if((totalTime>CONSTANTS::TIME_TO_STARVE_AND_THIRST)&&(this->type==BarType::StarveBar||this->type==BarType::WaterBar))
     {
         totalTime=0.f;
         this->ChangeFilling(CONSTANTS::STARVE_OR_THIRST);
     }


}


void Bars::UpdateBar(BarType &BT)
{

}

BarType Bars::GetBartType()
{
    return this->type;
}

void Bars::ChangeFilling(const float& howMuch)
{
    this->filling+=howMuch;
}

float Bars::GetFilling()
{
    return this->filling;
}

Bars::~Bars()
{

}
