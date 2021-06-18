#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
#include <math.h>

class Collider
{
private:
    sf::Sprite& MainSprite;


public:
    Collider(sf::Sprite& sprite);
    ~Collider();

    bool CheckCollision(Collider& other,float& pushForce);
    void Move(sf::Vector2f& direction);
};

#endif // COLLIDER_H
