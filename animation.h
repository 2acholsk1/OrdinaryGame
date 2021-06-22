#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation
{
private:

    sf::Vector2u currentFrame;
    float totalTime;
    float switchTime;
    sf::IntRect frameSize;
    sf::Vector2u animationMaxSize;


public:
    Animation(sf::Texture& texture,const sf::Vector2u& canimationMaxSize,const float& switchTime);
    virtual ~Animation();
    void Update(int& row,float& deltaTime);
    void Initialize(sf::Texture& texture);
    sf::IntRect GetFrameIntRect();
    void SetAnimationMaxSize(sf::Vector2u& canimationMaxSize);
};

#endif // ANIMATION_H
