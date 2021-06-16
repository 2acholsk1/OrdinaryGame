#ifndef INVENTORY_H
#define INVENTORY_H
#include "part.h"

class Inventory:public Part
{
private:
    int howMuch=0;
    sf::Text text;

public:
    Inventory(const sf::Vector2f& position,
              const PartType& type,
              CustomTexture* textures,
              const MyTexture& texture=MyTexture::Default,
              const sf::Vector2u& animationMaxSize={1,1},
              const float& animationTime=1.0f,
              const float& pushBackForce=0.5f);

    ~Inventory();
    static Inventory* PrintInventorySlot(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                         const PartType& cparttype,const MyTexture& ctexture);
    virtual void Update(float& dtime,sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);
    friend void PrintTExt(sf::Text &Object, int& CharacterSize,std::string& textme,sf::Color& c);
};

#endif // INVENTORY_H
