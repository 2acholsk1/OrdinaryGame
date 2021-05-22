#ifndef CUSTOMTEXTURE_H
#define CUSTOMTEXTURE_H

#include <map>

#include <SFML/Graphics.hpp>

enum class MyTexture
{
    Default,
    Player,
    Mob,
    Item,
    InterfacePart,
    Tree,
    Structure,
    Minerals
};


class CustomTexture
{
private:
    std::map<MyTexture,sf::Texture> AllTextures;
public:
    CustomTexture();
    ~CustomTexture();
    void AddTexture(const MyTexture& textureKey,const std::string& filename);
    sf::Texture& GetTexture(const MyTexture& textureKey);
};

#endif // CUSTOMTEXTURE_H
