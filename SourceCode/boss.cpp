#include "all.h"

Ch1boss Ch1boss::instance_;


void Ch1boss::init()
{
    sprHp_frame = new SpriteManager(L"./Data/Images/ENEMY/boss/hp_bar/hp_frame.png", VECTOR2(640, 980), VECTOR2(1,1), VECTOR2(0,0), VECTOR2(700,40));
    sprHp_graph = new SpriteManager(L"./Data/Images/ENEMY/boss/hp_bar/hp_graph.png", VECTOR2(640, 980), VECTOR2(1,1), VECTOR2(0,0), VECTOR2(700,40));
    sprHP_base = new SpriteManager(L"./Data/Images/ENEMY/boss/hp_bar/hp_base.png",  VECTOR2(640, 980), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(700, 40));
    sprAppear = new SpriteManager(L"./Data/Images/ENEMY/boss/appear.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    
    right_up = new SpriteManager(L"./Data/Images/ENEMY/boss/end/right_up.png", VECTOR2(1920, -1920), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    right_down = new SpriteManager(L"./Data/Images/ENEMY/boss/end/right_down.png", VECTOR2(1920, 1920), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));

    left_up = new SpriteManager(L"./Data/Images/ENEMY/boss/end/left_up.png", VECTOR2(-1920, -1920), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    left_down = new SpriteManager(L"./Data/Images/ENEMY/boss/end/left_down.png", VECTOR2(-1920, 1920), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));

    sprHP_base->setAlphaA(0.5f);

    bossHp = 700.f;
    next_timer = 0;
    appear_timer = 0;

    speedX_Up1 = 18.0f;
    speedY_Up1 = 18.0f;
    speedX_Up2 = 17.0f;
    speedY_Up2 = 17.0f;

    speedX_Down1 = 17.0f;
    speedY_Down1 = 17.0f;
    speedX_Down2 = 18.0f;
    speedY_Down2 = 18.0f;

    end_timer = 0;
}

void Ch1boss::update()
{
    using namespace GameLib;
    //debug::setString("bossHp:%f", bossHp);
   // sprHp_graph->subTexsizeY(7);


    //ボスが死んだら待機後、次のステージにいく
    if (next_timer > 600) { 
        Game::instance()->changeScene(GameLoading::instance()); 
    }


    appear_timer++;
    if (bossHp <= 0) {
        PlayerWeapon::instance()->setShotFlag(true);

        end_update();
        next_timer++;
    }
   // debug::setString("end_timer:%d", end_timer);

}

void Ch1boss::draw()
{
    if((appear_timer & 0x10)&&appear_timer < 150)sprAppear->draw();

    sprHP_base->draw();
    sprHp_graph->draw();
    sprHp_frame->draw();
}

void Ch1boss::deinit()
{
    delete sprHp_frame;
    delete sprHp_graph;
    delete sprHP_base;

    delete sprAppear;

    delete right_up;
    delete right_down;
    delete left_up;
    delete left_down;

}

void Ch1boss::end_update()
{
    music::fade(MUSIC::CH1_BOSS, 3.0f, 0.0f);


    right_up->addPosX(-speedX_Up1);
    right_up->addPosY(+speedY_Up1);

    right_down->addPosX(-speedX_Down1);
    right_down->addPosY(-speedY_Down1);

    left_up->addPosX(+speedX_Up2);
    left_up->addPosY(+speedY_Up2);

    left_down->addPosX(+speedX_Down2);
    left_down->addPosY(-speedY_Down2);


    switch (end_state)
    {
    case 0:   
        if (right_up->getPosX() < 17.f) speedX_Up1 = 0.0f;
        if (right_up->getPosY() > -17.f)speedY_Up1 = 0.0f;

        if (right_down->getPosX() < 15.f) speedX_Down1 = 0.0f;
        if (right_down->getPosY() < 15.f)speedY_Down1 = 0.0f;

        if (left_up->getPosX() > 17.f) speedX_Up2 = 0.0f;
        if (left_up->getPosY() > -17.f)speedY_Up2 = 0.0f;

        if (left_down->getPosX() > -15.f) speedX_Down2 = 0.0f;
        if (left_down->getPosY() < 15.f)speedY_Down2 = 0.0f;  


        if (speedX_Up1 == 0.0f && speedY_Up1 == 0.0f && speedX_Down1 == 0.0f && speedY_Down1 == 0.0f && speedX_Up2 == 0.0f && speedY_Up2 == 0.0f && speedX_Down2 == 0.0f && speedY_Down2 == 0.0f) end_state++;

        break;

    case 1:
        end_timer++;

        if (end_timer > 100) {
            right_up->subAlphaA(0.01f);
            right_down->subAlphaA(0.01f); 
            left_up->subAlphaA(0.01f);
            left_down->subAlphaA(0.01f);

            BossisAlive = false;
        }

    }




}

void Ch1boss::end_draw()
{
    right_up->draw();
    right_down->draw();


    left_up->draw();
    left_down->draw();

}

void Ch1boss::SupBosshp(int i)
{
    bossHp -= i*5.0f;
    sprHp_graph->subTexsizeX(i*5.0f);
}
