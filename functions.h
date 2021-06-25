#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "customtexture.h"

sf::Vector2f ScallingV2f(const sf::Vector2f& hector, const sf::Vector2f& scala);
void OriginSet(sf::Sprite& sprite);
void PrintTExt(sf::Text &Object, int CharacterSize,std::string textme,sf::Color c,sf::Vector2f& Position);
float CountDistance(const sf::Vector2f& vec_a, const sf::Vector2f& vec_b);
void DrawBel(CustomTexture* ctextures,sf::RenderWindow& window);


#endif // FUNCTIONS_H
