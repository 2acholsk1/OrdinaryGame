#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SFML/Graphics.hpp>
#include "Constants.h"

sf::Vector2f ScallingV2f(const sf::Vector2f& hector, const sf::Vector2f& scala);
void OriginSet(sf::Sprite& sprite);
void PrintTExt(sf::Text &Object, int CharacterSize,std::string textme,sf::Color c);


#endif // FUNCTIONS_H
