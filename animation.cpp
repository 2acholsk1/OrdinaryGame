#include "animation.h"

Animation::Animation(sf::Texture& texture,const sf::Vector2u& canimationMaxSize,const double& canimationTime):
    animationMaxSize(canimationMaxSize),
    elapsed(0.0f),
    currentFrame(0,0)
{
    this->frameSize.width=texture.getSize().x/canimationMaxSize.x;
    this->frameSize.height=texture.getSize().y/canimationMaxSize.y;
    this->animationTime=canimationTime/static_cast<double>(canimationMaxSize.x);
}

Animation::~Animation()
{

}

sf::IntRect Animation::GetFrameIntRect()
{
    return this->frameSize;
}
