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
                ctexture,
                sf::Vector2u(1,1),
                0.1f);
}

void Player::Update(float& dtime)
{

    int i=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//left
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerML));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerML));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(-CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))//right
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerMR));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerMR));
        this->sprite.move(CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
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

void Player::UpdateBars(float &dtime, float &hp, float &exp, float &starve, float &water)
{

}

