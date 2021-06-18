#include "collider.h"

Collider::Collider(sf::Sprite& sprite):
MainSprite(sprite)
{

}
Collider::~Collider()
{

}

void Collider::Move(sf::Vector2f &direction)
{
    this->MainSprite.move(direction);
}

bool Collider::CheckCollision(Collider &other,float& pushForce)
{
    sf::Vector2f thisPosition=this->MainSprite.getPosition();
    sf::Vector2f otherPosition=other.MainSprite.getPosition();

    sf::FloatRect thisRect=this->MainSprite.getGlobalBounds();
    sf::FloatRect otherRect=other.MainSprite.getGlobalBounds();

    sf::Vector2f thisHalfPosition(thisRect.width/2.f,thisRect.height/2.f);
    sf::Vector2f otherHalfPosition(otherRect.width/2.f,otherRect.height/2.f);

    float deltaX=thisPosition.x-otherPosition.x;
    float deltaY=thisPosition.y-otherPosition.y;
    float intersectX=abs(deltaX)-(otherHalfPosition.x+thisHalfPosition.x);
    float intersectY=abs(deltaY)-(otherHalfPosition.y+thisHalfPosition.y);

    bool IsThatTrueOrNot=intersectX<0.0f && intersectY<0.0f;

    if(IsThatTrueOrNot)
    {
        pushForce=std::min(std::max(pushForce,0.0f),1.0f);             //clamping

        sf::Vector2f thisMoveDirection(0.0f,0.0f);
        sf::Vector2f otherMoveDirection(0.0f,0.0f);

        if(intersectX>intersectY)
        {
            if(deltaX>0.0f)
            {
                thisMoveDirection.x=intersectX*(1.0f-pushForce);
                otherMoveDirection.x=-intersectX*pushForce;
            }
            else
            {
                thisMoveDirection.x=-intersectX*(1.0f-pushForce);
                otherMoveDirection.x=intersectX*pushForce;
            }
        }
        else
        {
            if(deltaY>0.0f)
            {
                thisMoveDirection.y=intersectY*(1.0f-pushForce);
                otherMoveDirection.y=-intersectY*pushForce;
            }
            else
            {
                thisMoveDirection.y=-intersectY*(1.0f-pushForce);
                otherMoveDirection.y=intersectY*pushForce;
            }
        }
        this->Move(thisMoveDirection);
        this->Move(otherMoveDirection);
        return true;
    }
    return false;

}

