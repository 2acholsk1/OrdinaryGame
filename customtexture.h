#ifndef CUSTOMTEXTURE_H
#define CUSTOMTEXTURE_H

#include <map>

#include <SFML/Graphics.hpp>

enum class MyTexture
{
    Default,
    Grass,
    Stones,
    Player,
    Mob,
    Item,
    InterfacePart,
    Tree,
    Structure,
    IronOre,
    GoldenOre,
    CoalOre
};


class CustomTexture
{
private:
    std::map<MyTexture,sf::Texture> Textures;
public:
    CustomTexture();
    ~CustomTexture();
    void AddTexture(const MyTexture& textureKey,const std::string& filename);
    sf::Texture& GettTexture(const MyTexture& textureKey);
};

#endif // CUSTOMTEXTURE_H
