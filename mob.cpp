#include "mob.h"

Mob::Mob(const sf::Vector2f& position,
         CustomTexture* ctextures,
         const PartType& cparttype,
         const MyTexture& ctexture,
         const sf::Vector2u& canimationMaxSize,
         const float& canimationTime,
         const float& cpushBackForce,
         const float& crange,
         const float& cfollowingSpeed,
         const float& chp,
         Part* ctoFollow):
    Part(position,cparttype,ctextures,ctexture,canimationMaxSize,canimationTime,cpushBackForce),
    range(crange),
    followingSpeed(cfollowingSpeed),
    hp(chp),
    toFollow(ctoFollow)
{
    OriginSet(this->sprite);
}

Mob* Mob::CreateEnemy(const sf::Vector2f& spawnPosition,CustomTexture* textures,const PartType& type, const MyTexture& texture)
{
    return new Mob(
                spawnPosition,
                textures,
                type,
                texture,
                sf::Vector2u(1,1),
                1.0f,
                Mob::GetPushBackForce(),
                Mob::GetRange(),
                Mob::GetFollowSpeed(),
                Mob::GetHp()
                );
}

void Mob::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void Mob::Update(float &dtime, sf::RenderWindow &window)
{
    this->Existing(dtime);

}

float Mob::GetRange()
{
    return CONSTANTS::MOB_RANGE;
}

float Mob::GetHp()
{
    return CONSTANTS::MOB_HP;
}

float Mob::GetFollowSpeed()
{
    return CONSTANTS::MOB_FOLLOW_SPEED;
}

float Mob::GetPushBackForce()
{
    return CONSTANTS::MOB_PUSH_BACK_FORCE;
}

void Mob::switchWhichSide(float& dtime)
{
    switch(whichSide)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    {
        this->sprite.move(-CONSTANTS::MOB_SPEED*dtime*2,0.f);
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::MobMoveLeft));
        break;
    }
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    {
        this->sprite.move(CONSTANTS::MOB_SPEED*dtime*2,0.f);
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::MobMoveRight));
        break;

    }
    case 16:
    case 17:
    {
        this->sprite.move(0.f,-CONSTANTS::MOB_SPEED*dtime*2);
        break;
    }
    case 18:
    case 19:
    {
        this->sprite.move(0.f,CONSTANTS::MOB_SPEED*dtime*2);
        break;

    }
    break;
    }

}

void Mob::Existing(float& dtime)
{
    srand(time(NULL));

    this->totaltime+=dtime;
    losuj=rand()%20;
    this->whichSide=losuj;

    switch(whichSide)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    {
        this->sprite.move(CONSTANTS::MOB_SPEED*dtime,0.f);
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::MobMoveRight));
        break;
    }
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    {
        this->sprite.move(-CONSTANTS::MOB_SPEED*dtime,0.f);
        this->sprite.setTexture(this->textures->GettTexture(MyTexture::MobMoveLeft));
        break;
    }
    case 16:
    case 17:
    {
        this->sprite.move(0.f,CONSTANTS::MOB_SPEED*dtime);
        break;
    }
    case 18:
    case 19:
    {
        this->sprite.move(0.f,-CONSTANTS::MOB_SPEED*dtime);
        break;
    }
    break;
    }
}

Mob::~Mob()
{

}
