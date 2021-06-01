#include "collider.h"

Collider::Collider(sf::RectangleShape& body):
MainBody(body)
{

}

bool Collider::CheckCollision(Collider &other, Player& some)
{
    sf::Vector2f otherPosition=other.GetBodyPosition();
    sf::Vector2f otherHalfPosition=other.GetBodyHalfSize();

    sf::Vector2f thisPosition=GetBodyPosition();
    sf::Vector2f thisHalfPosition=GetBodyHalfSize();

    float deltaX=otherPosition.x-thisPosition.x;
    float deltaY=otherPosition.y-thisPosition.y;
    float intersectX=abs(deltaX)-(otherHalfPosition.x+thisHalfPosition.x);
    float intersectY=abs(deltaY)-(otherHalfPosition.y+thisHalfPosition.y);

    if( intersectX<0.0f && intersectY<0.0f )
    {
        switch(some.GetPartType())
        {
            case PartType::CoalOre:
            {

            }
            case PartType::GoldenOre:
            {

            }
            case PartType::IronOre:
            {

            }
            case PartType::Stone:
            {
                some.isMove=0;
            }
        }

        return true;
    }

}

