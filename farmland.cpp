#include "farmland.h"

farmland::farmland(CustomTexture* ctextures, sf::Vector2f& cPosition): Position(cPosition),textures(ctextures)
{
    this->field.setTexture(this->textures->GettTexture(MyTexture::Field));
    this->field.setPosition(this->Position);
    this->field.setScale(0.5f,0.5f);
    srand(time(NULL));
    int los=rand()&3;
    switch(los)
    {
        case 0:
    {
        this->type=FieldType::Beet;
        break;
    }
    case 1:
    {
        this->type=FieldType::Carrot;
        break;
    }
    case 2:
    {
        this->type=FieldType::Potato;
        break;
    }
        break;
    }
}

void farmland::Draw(sf::RenderWindow &window)
{
    window.draw(this->field);
}

void farmland::Update(float &dtime, sf::RenderWindow &window)
{
    this->ttime+=dtime;
    if(ttime>=3.f)
    {
        switch(this->type)
        {
        case FieldType::Beet:
        {
            this->field.setTexture(this->textures->GettTexture(MyTexture::BeetField));
            break;
        }
        case FieldType::Carrot:
        {
            this->field.setTexture(this->textures->GettTexture(MyTexture::CarrotField));
            break;
        }
        case FieldType::Potato:
        {
            this->field.setTexture(this->textures->GettTexture(MyTexture::PotatoField));
            break;
        }
            break;
        }


        ttime=0;
    }
}
