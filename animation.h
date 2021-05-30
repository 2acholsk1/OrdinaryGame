#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation
{
private:
    sf::Vector2u animationMaxSize;
    sf::Vector2u currentFrame;
    float animationTime;
    float elapsedT;
    sf::IntRect frameSize;

public:
    Animation(sf::Texture& texture,const sf::Vector2u& canimationMaxSize,const float& canimationTime);
    virtual ~Animation();

    sf::IntRect GetFrameIntRect();
};

#endif // ANIMATION_H
