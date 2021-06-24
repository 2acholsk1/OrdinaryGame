#ifndef INVENTORY_H
#define INVENTORY_H
#include "part.h"
#include "farmland.h"


sf::Vector2f operator *(const int& l, sf::Vector2f& hector);
class Inventory
{
private:
    std::vector<sf::Text> statesInv;
    std::vector<int> howMuch;
    sf::Text text;
    sf::Font fontinio;
    sf::Vector2f startTextPosition=sf::Vector2f(-225.f,335.f);
    sf::Vector2f startItemInderlinedPosition=sf::Vector2f(300.f,400.f);
    sf::Vector2f switchingTextX=sf::Vector2f(175.f,0.f);
    sf::Vector2f switchingTextY=sf::Vector2f(0.f,70.f);
    sf::Vector2f switchingItemX=sf::Vector2f(60.f,0.f);
    std::vector<sf::Vector2f> StartingPositions;
    std::vector<sf::RectangleShape> underlinedItems;
    int ItemInUse=0;

public:
    Inventory();
    ~Inventory()=default;
    void Draw(sf::RenderWindow& window);
    void Update(float& dtime,sf::RenderWindow& window);
    void UpdatePos(Part* Player);
    void AddingItem(PartType& type);
    void AddingItem(FieldType& type);
    bool Eating(FieldType& type);
    bool Building(PartType& type);
    int GetItemInUse();


};

#endif // INVENTORY_H
