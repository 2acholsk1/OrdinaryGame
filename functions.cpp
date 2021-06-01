#include "functions.h"

sf::Vector2f Placement(sf::RenderWindow& window)
{
    sf::Vector2f onMapPosition=CONSTANTS::PLAYER_MIDDLE_POSITION;
}

void OriginSet(sf::Sprite& sprite)
{
    float midPointToCollisionsX=sprite.getLocalBounds().width/2.f;
    float midPointToCollisionsY=sprite.getLocalBounds().height/2.f;

    sprite.setOrigin(midPointToCollisionsX,midPointToCollisionsY);
}
