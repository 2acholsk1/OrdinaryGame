#include "player.h"

Player::Player(const sf::Vector2f& position,
               CustomTexture* ctextures,
               const PartType& cparttype,
               const MyTexture& ctexture,
               const sf::Vector2u& canimationMaxSize,
               const float& canimationTime
               ):
    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime)
{
    this->sprite.setTexture(ctextures->GettTexture(this->texture));
}


void Player::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

Player::~Player()
{

}

Player* Player::PrintPlayer(const sf::Vector2f& cexistingPosition,CustomTexture* ctextures,
                                     const PartType& cparttype,const MyTexture& ctexture)
{
    return new Player(
                cexistingPosition,
                ctextures,
                cparttype,
                ctexture);
}

void Player::Update(float& dtime)
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
