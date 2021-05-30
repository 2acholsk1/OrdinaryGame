#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "part.h"
#include "customtexture.h"
#include "Constants.h"

class Player: public Part
{
private:


public:
    Player(const sf::Vector2f& position,
           CustomTexture* ctextures,
           const PartType& cparttype=PartType::Default,
           const MyTexture& ctexture=MyTexture::Default,
           const sf::Vector2u& canimationMaxSize=sf::Vector2u(1,1),
           const float& canimationTime=1.0f);
    virtual void Draw(sf::RenderWindow &window);
    ~Player();
    static Player* PrintPlayer(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                         const PartType& cparttype,const MyTexture& ctexture);
    void Update(float& dtime);

};

#endif // PLAYER_H
