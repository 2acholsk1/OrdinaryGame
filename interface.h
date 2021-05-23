#ifndef INTERFACE_H
#define INTERFACE_H
#include <SFML/Graphics.hpp>
#include "part.h"
#include "bars.h"
#include "inventory.h"




class Interface: public Part
{

public:
    Interface(const sf::Vector2f& position,
              const PartType& type,
              CustomTexture* textures,
              const MyTexture& texture=MyTexture::Default,
              const sf::Vector2u& animationMaxSize={1,1},
              const float& animationTime=1.0f);


    Bars HP_bar;
    Bars MANA_bar;
    Bars STARVE_bar;
    Bars WATER_bar;
    Bars EXP_bar;
    Inventory slot_1;
    Inventory slot_2;
    Inventory slot_3;
    Inventory slot_4;
};

#endif // INTERFACE_H
