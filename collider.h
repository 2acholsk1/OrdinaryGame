#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include "player.h"

class Collider
{
private:
    sf::RectangleShape& MainBody;


public:
    Collider(sf::RectangleShape& body);
    ~Collider();

    bool CheckCollision(Collider& other,Player& some);
    sf::Vector2f GetBodyPosition(){return MainBody.getPosition();}
    sf::Vector2f GetBodyHalfSize(){return MainBody.getSize()/2.0f;}
};

#endif // COLLIDER_H
