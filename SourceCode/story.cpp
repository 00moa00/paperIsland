#include "all.h"

Story Story::instance_;
using namespace GameLib;

Story::Story()
{
    sprST0_story1 = nullptr;
    sprST0_story2 = nullptr;
    sprST0_story3 = nullptr;
    sprST0_story4 = nullptr;

    sprST1_story1 = nullptr;

    sprST10_story1 = nullptr;
    sprST10_story2 = nullptr;
    sprST10_story3 = nullptr;
    sprST10_story4 = nullptr;

    state = 0;
    sound = 0;
    sound_state = 0;
}

Story::~Story()
{


}

void Story::init()
{
    sprST0_story1 = new SpriteManager(L"./Data/Images/STORY/stage0_1.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprST0_story2 = new SpriteManager(L"./Data/Images/STORY/stage0_2.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprST0_story3 = new SpriteManager(L"./Data/Images/STORY/stage0_3.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprST0_story4 = new SpriteManager(L"./Data/Images/STORY/stage0_4.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
   
    sprST1_story1 = new SpriteManager(L"./Data/Images/STORY/stage1_1.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));

    sprST10_story1 = new SpriteManager(L"./Data/Images/STORY/stage6_1.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprST10_story2 = new SpriteManager(L"./Data/Images/STORY/stage6_2.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprST10_story3 = new SpriteManager(L"./Data/Images/STORY/stage6_3.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprST10_story4 = new SpriteManager(L"./Data/Images/STORY/stage6_4.png", VECTOR2(-50, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));

}

void Story::update()
{

    if (StageSelect::instance()->getNum() == 1) state = STORY::ST1_1;
    if (StageSelect::instance()->getNum() > 2 && StageSelect::instance()->getNum() <10) state = STORY::ST10_1;

    switch (state)
    {
    case STORY::ST0_1 :
        //指定された位置に行ったら次のスクリプトを出す
        if (Game::instance()->player()->transform()->getPositionX() > 500 &&
            StageSelect::instance()->getNum() == 0) {
            sound_state=1;
            state++;
        }
        break;

    case STORY::ST0_2 :
        if (Game::instance()->player()->transform()->getPositionX() > 900 &&
            StageSelect::instance()->getNum() == 0) {

            sound_state = 1;
            state++;
        }

        break;

    case STORY::ST0_3:
        if (Game::instance()->player()->transform()->getPositionX() > 1300 &&
            StageSelect::instance()->getNum() == 0) {

            sound_state = 1;
            state++;
        }

        break;

    case STORY::ST0_4:
        if (StageSelect::instance()->getNum() == 1) {

            sound_state = 1;
            state++;
        }

        break;

    case STORY::ST1_1:
        if (StageSelect::instance()->getNum() > 1) {
            state++;
        }

        break;


    case STORY::ST10_1:

        if (Game::instance()->player()->transform()->getPositionX() > 500 &&
            StageSelect::instance()->getNum() == 10) {

            sound_state = 1;
            state++;
        }
        break;

    case STORY::ST10_2:

        if (Game::instance()->player()->transform()->getPositionX() > 1000 &&
            StageSelect::instance()->getNum() == 10) {

            sound_state = 1;
            state++;
        }
        break;

    case STORY::ST10_3:

        if (Game::instance()->player()->transform()->getPositionX() > 1400 &&
            StageSelect::instance()->getNum() == 10) {

            sound_state = 1;
            state++;
        }
        break;

    case STORY::ST10_4:

        if (Game::instance()->player()->transform()->getPositionX() > 1600 &&
            StageSelect::instance()->getNum() == 10) {

           // sound_state = 1;
            //state++;
        }

        break;
    }


    switch (sound_state)
    {
    case STORY::ST0_1 :
    case STORY::ST0_2:
    case STORY::ST0_3:
    case STORY::ST0_4:
    case STORY::ST1_1:
    case STORY::ST10_1:
    case STORY::ST10_2:
    case STORY::ST10_3:
    case STORY::ST10_4:
        music::play(SOUND::STORY);
        sound_state = STORY::NONE;
    case STORY::NONE:
        break;
    }



}

void Story::draw()
{
    if(state == STORY::ST0_1 && StageSelect::instance()->getNum() == 0)sprST0_story1->draw();
    if(state == STORY::ST0_2 && StageSelect::instance()->getNum() == 0)sprST0_story2->draw();
    if(state == STORY::ST0_3 && StageSelect::instance()->getNum() == 0)sprST0_story3->draw();
    if(state == STORY::ST0_4 && StageSelect::instance()->getNum() == 0)sprST0_story4->draw();
                 
  /*  if(state == STORY::ST1_1 && Game::instance()->player()->transform()->getPositionX() < 500 &&StageSelect::instance()->getNum() == 1)
        sprST1_story1->draw();
                 
    if(state == STORY::ST10_1 && StageSelect::instance()->getNum() == 10) 
        sprST10_story1->draw();*/

    if(state == STORY::ST10_2&& StageSelect::instance()->getNum() == 10)sprST10_story2->draw();
    if(state == STORY::ST10_3&& StageSelect::instance()->getNum() == 10)sprST10_story3->draw();
    if(state == STORY::ST10_4&& StageSelect::instance()->getNum() == 10)sprST10_story4->draw();
}

void Story::deinit()
{

    delete sprST0_story1;
    delete sprST0_story2;
    delete sprST0_story3;
    delete sprST0_story4;

    delete sprST1_story1;

    delete sprST10_story1;
    delete sprST10_story2;
    delete sprST10_story3;
    delete sprST10_story4;
}
