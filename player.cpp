#include "player.h"

Player::Player(const sf::Vector2f& position,
               CustomTexture* ctextures,
               const PartType& cparttype,
               const MyTexture& ctexture,
               const sf::Vector2u& canimationMaxSize,
               const float& canimationTime,
               const float& cpushBackForce
               ):
    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce)
{
    this->sprite.setTexture(ctextures->GettTexture(this->texture));
    OriginSet(this->sprite);
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
                sf::Vector2u(2,1),
                0.1f);
}

void Player::Update(float& dtime,sf::RenderWindow& window)
{
    this->acceleration=CONSTANTS::PLAYER_MOVING_SPEED/dtime;
    this->ShowPosition();
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
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerMD));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerMD));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(0.f,CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerMU));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerMU));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(0.f,-CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::C))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerShovelL));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerShovelL));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::C))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerShovelR));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerShovelR));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::V))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerSwordL));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerSwordL));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::V))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerSwordR));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerSwordR));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::X))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerPickaxeL));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerPickaxeL));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::X))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerPickaxeR));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerPickaxeR));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Z))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerAxeL));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerAxeL));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Z))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerAxeR));
        this->animation.animationMaxSize=sf::Vector2u(2,1);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerAxeR));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());

    }

    this->IsMoving();
    if(isMove==0)
    {
        this->animation.Initialize(this->textures->GettTexture(MyTexture::Player));
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::Player));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
    }
    lastPosition=currentPosition;
}

void Player::UpdateBars(float &dtime, float &hp, float &exp, float &starve, float &water)
{

}


void Player::ShowPosition()
{
    this->currentPosition=sprite.getPosition();
}

void Player::IsMoving()
{
    float disx=fabsf(currentPosition.x-lastPosition.x);
    float disy=fabsf(currentPosition.y-lastPosition.y);
    float out=sqrtf(powf(disx,2.f)+powf(disy,2.f));
    if(out==0)
    {
        isMove= false;
    }
    else
    {
        isMove= true;
    }
}
