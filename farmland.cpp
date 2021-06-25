#include "farmland.h"

farmland::farmland(CustomTexture* ctextures, sf::Vector2f& cPosition): Position(cPosition),textures(ctextures)
{
    this->field.setTexture(this->textures->GettTexture(MyTexture::Field));
    this->field.setPosition(this->Position);
    this->field.setScale(0.5f,0.5f);
    srand(time(NULL));
    int los=rand()&3;
    this->howManyInside=los+1;
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
    if(ttime>=TIME_TO_PLANTS_GROW_UP)
    {
        ttime=0;
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



    }
}

sf::FloatRect farmland::GetSize()
{
    return this->field.getGlobalBounds();
}

FieldType farmland::GetFieldType()
{
    return this->type;
}

void farmland::Remove()
{
    if(this->howManyInside<=0)
    {
            this->field.setPosition(sf::Vector2f(-800.f,-800.f));
    }
    else
    {
        this->howManyInside-=1;

    }
}
