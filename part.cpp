#include "part.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

enum class PartTypes
{
    Player,
    Mob,
    Item,
    InterfacePart,
    Tree,
    Structure,
    Minerals

};


Part::Part()
{
    sf::Sprite sprite;
    PartTypes parttype;

}


