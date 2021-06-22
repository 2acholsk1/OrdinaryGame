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

void Player::AnimationUp(float &dtime)
{
    int i=0;
    this->animation.Update(i,dtime);
}

void Player::Update(float& dtime,sf::RenderWindow& window)
{
    this->acceleration=CONSTANTS::PLAYER_MOVING_SPEED/dtime;
    this->ShowPosition();
    int i=0;
    sf::Vector2u animMaxS=sf::Vector2u(2,1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//left
    {
        this->MovingLeft=true;
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerML));
        this->animation.SetAnimationMaxSize(animMaxS);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerML));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(-CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))//right
    {
        this->MovingLeft=false;
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerMR));
        this->animation.SetAnimationMaxSize(animMaxS);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerMR));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(CONSTANTS::PLAYER_MOVING_SPEED*dtime,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerMD));
        this->animation.SetAnimationMaxSize(animMaxS);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerMD));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(0.f,CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
    {
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerMU));
        this->animation.SetAnimationMaxSize(animMaxS);
        this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerMU));
        this->animation.Update(i,dtime);
        sprite.setTextureRect(animation.GetFrameIntRect());
        this->sprite.move(0.f,-CONSTANTS::PLAYER_MOVING_SPEED*dtime);
    }

    if(this->MovingLeft)
    {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
         {
            this->lastItemInUse=4;
             this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerSwordL));
            this->animation.SetAnimationMaxSize(animMaxS);
             this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerSwordL));
             this->animation.Update(i,dtime);
             sprite.setTextureRect(animation.GetFrameIntRect());

         }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            this->lastItemInUse=3;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerPickaxeL));
            this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerPickaxeL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            this->lastItemInUse=2;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerAxeL));
            this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerAxeL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            this->lastItemInUse=1;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerShovelL));
            this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerShovelL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        {
            this->lastItemInUse=8;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerSwordR));
        this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerSwordR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            this->lastItemInUse=7;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerPickaxeR));
            this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerPickaxeR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            this->lastItemInUse=6;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerAxeR));
            this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerAxeR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            this->lastItemInUse=5;
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerShovelR));
            this->animation.SetAnimationMaxSize(animMaxS);
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerShovelR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());

        }
    }



   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
   {
       this->lastItemInUse=0;
       this->animation.SetAnimationMaxSize(animMaxS);
       this->animation.Initialize(this->textures->GettTexture(MyTexture::Player));
       this->sprite.setTexture(this->textures->GettTexture(MyTexture::Player));
       sprite.setTextureRect(animation.GetFrameIntRect());
   }

    this->IsMoving();
    if(isMove==0)
    {
        switch(this->lastItemInUse)
        {
        case 0:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::Player));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::Player));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 1:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerShovelL));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerShovelL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 5:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerShovelR));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerShovelR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 2:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerAxeL));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerAxeL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 6:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerAxeR));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerAxeR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 3:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerPickaxeL));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerPickaxeL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 7:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerPickaxeR));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerPickaxeR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 4:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerSwordL));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerSwordL));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
        case 8:
        {
            this->animation.Initialize(this->textures->GettTexture(MyTexture::PlayerSwordR));
            this->sprite.setTexture(this->textures->GettTexture(MyTexture::PlayerSwordR));
            this->animation.Update(i,dtime);
            sprite.setTextureRect(animation.GetFrameIntRect());
            break;
        }
            break;
        }


    }
    lastPosition=currentPosition;

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

bool Player::InRange(sf::RenderWindow& window)
{
    sf::Vector2i MousePosition=sf::Mouse::getPosition(window);
    if((MousePosition.x>CONSTANTS::PLAYER_MIDDLE_POSITION.x-this->range)&&
            (MousePosition.x<CONSTANTS::PLAYER_MIDDLE_POSITION.x+this->range)&&
            (MousePosition.y>CONSTANTS::PLAYER_MIDDLE_POSITION.y-this->range)&&
            (MousePosition.y<CONSTANTS::PLAYER_MIDDLE_POSITION.y+this->range))
    {
        return true;
    }
    return false;
}

sf::Vector2f Player::GetCurrentPosition()
{
    return this->currentPosition;
}

sf::FloatRect Player::GetGlobalBounds()
{
    return this->sprite.getGlobalBounds();
}

bool Player::MLeft()
{
    return this->MovingLeft;
}
bool Player::IMove()
{
    return this->isMove;
}
