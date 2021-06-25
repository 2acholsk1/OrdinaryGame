#ifndef MOUSECONTROL_H
#define MOUSECONTROL_H
#include<SFML/Graphics.hpp>
#include <sstream>

#define GRID_SIZE_F 100.f
#define GRID_SIZE_U static_cast<unsigned>(GRID_SIZE_F)

void PrintPosition(sf::RenderWindow& window);
void MouseControl(sf::RenderWindow& window);

#endif // MOUSECONTROL_H
