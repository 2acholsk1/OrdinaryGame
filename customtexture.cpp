#include "customtexture.h"

CustomTexture::CustomTexture()
{

}

CustomTexture::~CustomTexture()
{

}

void CustomTexture::AddTexture(const MyTexture& textureKey,const std::string& filename)
{
    if(this->Textures.find(textureKey)!=this->Textures.end())
    {
        throw std::invalid_argument("Element already existed");
    }

    sf::Texture UnosTexturos;

    if(!UnosTexturos.loadFromFile(filename))
    {
        throw std::invalid_argument("File no open");
    }

    this->Textures.insert(std::pair<MyTexture,sf::Texture>(textureKey,UnosTexturos));
}

sf::Texture& CustomTexture::GettTexture(const MyTexture& textureKey)
{
    if(this->Textures.find(textureKey)==this->Textures.end())
    {
        throw std::out_of_range("Can't find it");
    }

    return this->Textures.at(textureKey);
}



