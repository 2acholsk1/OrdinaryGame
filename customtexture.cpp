#include "customtexture.h"

CustomTexture::CustomTexture()
{

}

CustomTexture::~CustomTexture()
{

}

void CustomTexture::AddTexture(const MyTexture& textureKey,const std::string& filename)
{
    if(this->textures.find(textureKey)!=this->textures.end())
    {
        throw std::invalid_argument("Element already existed");
    }

    sf::Texture UnosTexturos;

    if(!UnosTexturos.loadFromFile(filename))
    {
        throw std::invalid_argument("File no open");
    }

    this->textures.insert(std::pair<MyTexture,sf::Texture>(textureKey,UnosTexturos));
}

sf::Texture& CustomTexture::GetTexture(const MyTexture& textureKey)
{
    if(this->textures.find(textureKey)==this->textures.end())
    {
        throw std::out_of_range("Can't find it");
    }

    return this->textures.at(textureKey);
}


