#ifndef PART_H
#define PART_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "animation.h"
#include "customtexture.h"
#include "functions.h"
#include "collider.h"
#include <vector>

#define WINDOW_WIDTH 1600.f
#define WINDOW_HEIGHT 900.f
#define PLAYER_MIDDLE_POSITION sf::Vector2f(WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f)
#define PLAYER_MOVING_SPEED 300.f

#define DEFAULT_INTERFACE_PART_START_POSITION (WINDOW_WIDTH/2.f,WINDOW_HEIGHT/2.f)
#define INTERFACE_POSITION sf::Vector2f(-1000,WINDOW_HEIGHT*6.f/7.f-450)
#define HP_BAR_POSITION sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+10-450)
#define EXP_BAR_POSITION sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+40-450)
#define STARVE_BAR_POSITION sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+70-450)
#define WATER_BAR_POSITION sf::Vector2f(-700,WINDOW_HEIGHT*6.f/7.f+100-450)
#define ARROW_MINIMAP_POSITION sf::Vector2f(WINDOW_WIDTH*6.f/7.f-710.f,WINDOW_HEIGHT*6.f/7.f-400)
#define INSTRUCTION_START_POSITION sf::Vector2f(-5600.f,-5200.f)
#define INSTRUCTION_POSITION sf::Vector2f(-600.f,-400.f)
#define GAME_OVER_POSITION sf::Vector2f(WINDOW_WIDTH/2.f-1125.f,WINDOW_HEIGHT*0.75f-1000.f)
#define TOTAL_POINTS_POSITION sf::Vector2f(WINDOW_WIDTH/2.f-1000.f,WINDOW_HEIGHT*0.6f-700.f)
#define POINTS_POSITION sf::Vector2f(WINDOW_WIDTH/2.f-900.f,WINDOW_HEIGHT*0.45f-450.f)
#define PRESS_X_POSITION sf::Vector2f(WINDOW_WIDTH/2.f-1000.f,WINDOW_HEIGHT*0.2f)



enum class PartType
{
    Default,
    Player,
    Mob,
    Item,
    InterfacePart,
    Structure,
    Tree,
    Stone,
    Lake,
    Instruction,
    IronOre,
    CoalOre,
    GoldenOre,
    CooperOre,
    HpBar,
    ExpBar,
    StarveBar,
    WaterBar,
    GPSArrow,
    WoodenFence,
    Cobble,
    Boards

};

class Part
{
protected:
    sf::Sprite sprite;
    PartType parttype;
    CustomTexture* textures;
    MyTexture texture;
    Animation animation;
    float pushBackForce;



public:
    Part(const sf::Vector2f& position,
         const PartType& type,
         CustomTexture* textures,
         const MyTexture& texture=MyTexture::Default,
         const sf::Vector2u& animationMaxSize={1,1},
         const float& animationTime=1.0f,
         const float& pushBackForce=0.5f);

    virtual ~Part();
    virtual void Draw(sf::RenderWindow& window)=0;
    virtual void Update(float& dtime,sf::RenderWindow& window)=0;
    void UpdatePos(Part* PlaySpri,Part *partSpri);
    friend void OriginSet(sf::Sprite& sprite);
    PartType GetPartType();
    Collider GetCollider();
    float GetPushForce();
    sf::Vector2f GetPosition();
    sf::FloatRect GetSize();
    void SetPosition(sf::Vector2f& position);




};

#endif // PART_H
