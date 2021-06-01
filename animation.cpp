#include "animation.h"

Animation::Animation(sf::Texture& texture,const sf::Vector2u& canimationMaxSize,const float& cswitchTime):
    animationMaxSize(canimationMaxSize),
    totalTime(0.0f),
    currentFrame(0,0),
    switchTime(cswitchTime)
{
    this->Initialize(texture);
}

void Animation::Initialize(sf::Texture& texture)
{
    this->frameSize.width=texture.getSize().x/animationMaxSize.x;
    this->frameSize.height=texture.getSize().y/animationMaxSize.y;
}

Animation::~Animation()
{

}

sf::IntRect Animation::GetFrameIntRect()
{
    return this->frameSize;
}
 void Animation::Update(int &row, float &deltaTime)
 {
     this->currentFrame.y=row;
     this->totalTime+=deltaTime;

     if(this->totalTime>=this->switchTime)
     {
         this->totalTime-=switchTime;
         this->currentFrame.x++;
         if(this->currentFrame.x>=this->animationMaxSize.x)
         {
             this->currentFrame.x=0;
         }
     }
     this->frameSize.left=currentFrame.x*frameSize.width;
     this->frameSize.top=currentFrame.y*frameSize.height;
 }
