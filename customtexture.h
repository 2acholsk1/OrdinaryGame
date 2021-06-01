#ifndef CUSTOMTEXTURE_H
#define CUSTOMTEXTURE_H

#include <map>

#include <SFML/Graphics.hpp>

enum class MyTexture
{
    Default,
    Grass,
    Stones,
    Mob,
    Item,
    InterfaceDown,
    Tree,
    Structure,
    IronOre,
    GoldenOre,
    CoalOre,
    Player,
    PlayerML,
    PlayerMR,
    PlayerMD,
    PlayerMU,
    HpBar,
    ExpBar,
    StarveBar,
    WaterBar

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
