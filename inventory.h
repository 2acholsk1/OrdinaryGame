#ifndef INVENTORY_H
#define INVENTORY_H
#include "part.h"

//class Inventory:public Part
//{
//private:
//    int howMuch=0;
//    sf::Text text;

//public:
//    Inventory(const sf::Vector2f& position,
//              const PartType& type,
//              CustomTexture* textures,
//              const MyTexture& texture=MyTexture::Default,
//              const sf::Vector2u& animationMaxSize={1,1},
//              const float& animationTime=1.0f,
//              const float& pushBackForce=0.5f);

//    ~Inventory();
//    static Inventory* PrintInventorySlot(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
//                                         const PartType& cparttype,const MyTexture& ctexture);
//    virtual void Update(float& dtime,sf::RenderWindow& window);
//    virtual void Draw(sf::RenderWindow& window);
//    friend void PrintTExt(sf::Text &Object, int& CharacterSize,std::string& textme,sf::Color& c);
//};
sf::Vector2f operator *(const int& l, sf::Vector2f& hector);
class Inventory
{
private:
    std::vector<sf::Text> statesInv;
    std::vector<int> howMuch;
    sf::Text text;
    sf::Font fontinio;
    sf::Vector2f startTextPosition=sf::Vector2f(-225.f,335.f);
    sf::Vector2f switchingTextX=sf::Vector2f(175.f,0.f);
    sf::Vector2f switchingTextY=sf::Vector2f(0.f,70.f);
    std::vector<sf::Vector2f> StartingPositions;

public:
    Inventory();
    void Draw(sf::RenderWindow& window);
    void Update(float& dtime,sf::RenderWindow& window);
    void UpdatePos(Part* Player);


    ~Inventory()=default;

};

#endif // INVENTORY_H
