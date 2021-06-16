#include "functions.h"

sf::Vector2f ScallingV2f(const sf::Vector2f& hector, const sf::Vector2f& scala)
{
    return sf::Vector2f(hector.x*scala.x,hector.y*scala.y);
}

void OriginSet(sf::Sprite& sprite)
{
    float midPointToCollisionsX=sprite.getLocalBounds().width/2.f;
    float midPointToCollisionsY=sprite.getLocalBounds().height/2.f;

    sprite.setOrigin(midPointToCollisionsX,midPointToCollisionsY);
}


void PrintTExt(sf::Text &Object, int& CharacterSize,std::string& textme,sf::Color& c)
{
    sf::Font fontino;
    fontino.loadFromFile("fonts/Aspergit Bold.otf");
    Object.setFont(fontino);
    Object.setCharacterSize(CharacterSize);
    Object.setFillColor(c);
    Object.setString(textme);
}
