#ifndef INTERFACE_H
#define INTERFACE_H
#include "part.h"






class Interface: public Part
{

public:
    Interface(const sf::Vector2f& position,
              const PartType& type,
              CustomTexture* textures,
              const MyTexture& texture=MyTexture::Default,
              const sf::Vector2u& animationMaxSize={1,1},
              const float& animationTime=1.0f,
              const float& pushBackForce=0.5f
              );
    ~Interface();
    static Interface* PrintInterface(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture);
    void InitializeInterface();
    virtual void Update(float& dtime,sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);


private:
    sf::RectangleShape box;



};

#endif // INTERFACE_H
