#include "inventory.h"

Inventory::Inventory()
{

    this->fontinio.loadFromFile("fonts/Ace Records.ttf");
    for(int i=0;i<8;i++)
    {
        howMuch.emplace_back(0);
    }
    for(int i=0;i<8;i++)
    {
        if(i==4)
        {
            this->startTextPosition+=switchingTextY;
        }
        this->text.setString("0");
        this->text.setCharacterSize(20);
        this->text.setFillColor(sf::Color::White);
        this->text.setFont(this->fontinio);


        if(i>3)
        {
            this->text.setPosition(this->startTextPosition+((i-4)*switchingTextX));
        }
        else
        {
            this->text.setPosition(this->startTextPosition+(i*switchingTextX));
        }

        this->StartingPositions.emplace_back(this->text.getPosition());
        this->statesInv.emplace_back(this->text);
    }

    for(int i=0;i<4;i++)
    {
        sf::RectangleShape under;
        under.setSize(sf::Vector2f(50.f,10.f));
        under.setFillColor(sf::Color::Transparent);
        under.setPosition(this->startItemInderlinedPosition+((i+1)*switchingItemX));
        underlinedItems.emplace_back(under);
        this->StartingPositions.emplace_back(under.getPosition());

    }


}

sf::Vector2f operator*(const int& l, sf::Vector2f& hector)
{
    sf::Vector2f out;
    out.x+=hector.x*l;

    return out;
}

void Inventory::Draw(sf::RenderWindow& window)
{
    for(auto &i:statesInv)
    {
        window.draw(i);
    }
    for(auto& a:underlinedItems)
    {
        window.draw(a);
    }
}


void Inventory::UpdatePos(Part* Player)
{
    sf::Vector2f Position=Player->GetPosition();
    int j=0;
    for(auto &i:statesInv)
    {
        i.setPosition(Position+this->StartingPositions[j]);
        j++;
    }
    for(auto& i:underlinedItems)
    {
        i.setPosition(Position+this->StartingPositions[j]);
        j++;
    }
}

void Inventory::Update(float &dtime, sf::RenderWindow &window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->underlinedItems[0].setFillColor(sf::Color::Green);
        this->underlinedItems[1].setFillColor(sf::Color::Transparent);
        this->underlinedItems[2].setFillColor(sf::Color::Transparent);
        this->underlinedItems[3].setFillColor(sf::Color::Transparent);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        this->underlinedItems[0].setFillColor(sf::Color::Transparent);
        this->underlinedItems[1].setFillColor(sf::Color::Green);
        this->underlinedItems[2].setFillColor(sf::Color::Transparent);
        this->underlinedItems[3].setFillColor(sf::Color::Transparent);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        this->underlinedItems[0].setFillColor(sf::Color::Transparent);
        this->underlinedItems[1].setFillColor(sf::Color::Transparent);
        this->underlinedItems[2].setFillColor(sf::Color::Green);
        this->underlinedItems[3].setFillColor(sf::Color::Transparent);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        this->underlinedItems[0].setFillColor(sf::Color::Transparent);
        this->underlinedItems[1].setFillColor(sf::Color::Transparent);
        this->underlinedItems[2].setFillColor(sf::Color::Transparent);
        this->underlinedItems[3].setFillColor(sf::Color::Green);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->underlinedItems[0].setFillColor(sf::Color::Transparent);
        this->underlinedItems[1].setFillColor(sf::Color::Transparent);
        this->underlinedItems[2].setFillColor(sf::Color::Transparent);
        this->underlinedItems[3].setFillColor(sf::Color::Transparent);
    }
}








































//Inventory::Inventory(const sf::Vector2f& position,
//                     const PartType& cparttype,
//                     CustomTexture* ctextures,
//                     const MyTexture& ctexture,
//                     const sf::Vector2u& canimationMaxSize,
//                     const float& canimationTime,
//                     const float& cpushBackForce
//                     ):

//                    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce)
//{

////   PrintTExt(text,200,"dupa",sf::Color::Black);
//}

//Inventory::~Inventory()
//{

//}

//void Inventory::Draw(sf::RenderWindow &window)
//{
//    window.draw(this->sprite);
//    window.draw(this->text);

//}

//void Inventory::Update(float &dtime, sf::RenderWindow &window)
//{

//    PartType type=this->GetPartType();
//    sf::Vector2f Position=this->GetPosition();
//    switch(type)
//    {
//    case PartType::Slot1:
//    {
//        sf::Vector2f where(-1000.f,-500.f);
//        //this->text.setPosition(Position+where);

//        break;
//    }
//    case PartType::Slot2:
//    {
//        sf::Vector2f where(5.f,5.f);
//        //this->text.setPosition(Position+where);

//        break;
//    }
//        break;
//    }

//}

//Inventory* Inventory::PrintInventorySlot(const sf::Vector2f &cexistingPosition, CustomTexture *ctextures,
//                                         const PartType &cparttype, const MyTexture &ctexture)
//{
//    return new Inventory(
//                cexistingPosition,
//                cparttype,
//                ctextures,
//                ctexture,
//                sf::Vector2u(1,1),
//                1.f);
//}
