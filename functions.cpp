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


void PrintTExt(sf::Text &Object, int& CharacterSize,std::string& textme,sf::Color& c,sf::Vector2f& Position)
{
    sf::Font fontino;
    fontino.loadFromFile("fonts/Aspergit Bold.otf");
    Object.setFont(fontino);
    Object.setCharacterSize(CharacterSize);
    Object.setFillColor(c);
    Object.setPosition(Position);
    Object.setString(textme);
}

float CountDistance(const sf::Vector2f& vector_uno, const sf::Vector2f& vector_dos)
{
    float x_d = vector_uno.x - vector_dos.x;
    float y_d = vector_uno.y - vector_dos.y;

    return std::sqrt(x_d * x_d + y_d * y_d);
}

void DrawBel(CustomTexture* ctextures,sf::RenderWindow& window)
{
    sf::Vector2f size=sf::Vector2f(100.f,10.f);
    sf::RectangleShape shape(size);
    shape.setPosition(1000.f,200.f);
    shape.setTexture(&ctextures->GettTexture(MyTexture::Bel));
    window.draw(shape);
}
