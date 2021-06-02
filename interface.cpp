#include "interface.h"

Interface::Interface(const sf::Vector2f& position,
                     const PartType& cparttype,
                     CustomTexture* ctextures,
                     const MyTexture& ctexture,
                     const sf::Vector2u& canimationMaxSize,
                     const float& canimationTime,
                     const float& cpushBackForce
                     ):

                    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce)
{

}

void Interface::InitializeInterface()
{
     this->sprite.setTexture(textures->GettTexture(this->texture));
    box.setSize(sf::Vector2f(CONSTANTS::WINDOW_WIDTH,CONSTANTS::WINDOW_HEIGHT/8.f));
}

Interface* Interface::PrintInterface(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture)
{
    return new Interface(
                cexistingPosition,
                cparttype,
                ctextures,
                ctexture,
                sf::Vector2u(1,1),
                1.f);
}

Interface::~Interface()
{

}

void Interface::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void Interface::Update(float &dtime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//left
    {
        this->sprite.move(-CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))//right
    {
        this->sprite.move(CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
    {
        this->sprite.move(0.f,CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
    {
        this->sprite.move(0.f,-CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }
}
