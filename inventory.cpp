#include "inventory.h"

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
