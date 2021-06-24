#ifndef FARMLAND_H
#define FARMLAND_H
#include <SFML/Graphics.hpp>
#include "customtexture.h"
#include "Constants.h"

enum class FieldType
{
    Common,
    Carrot,
    Potato,
    Beet
};


class farmland
{
private:
    CustomTexture* textures;
    sf::Vector2f Position;
    sf::Sprite field;
    FieldType type;
    float ttime;
    int howManyInside;

public:
    farmland(CustomTexture* textures, sf::Vector2f& cPosition);
    void Draw(sf::RenderWindow &window);
    void Update(float& dtime,sf::RenderWindow& window);
    sf::FloatRect GetSize();
    FieldType GetFieldType();
    void Remove();
};

#endif // FARMLAND_H
