#ifndef FARMLAND_H
#define FARMLAND_H
#include <SFML/Graphics.hpp>
#include "customtexture.h"

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

public:
    farmland(CustomTexture* textures, sf::Vector2f& cPosition);
    void Draw(sf::RenderWindow &window);
    void Update(float& dtime,sf::RenderWindow& window);
};

#endif // FARMLAND_H
