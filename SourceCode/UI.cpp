
//include
#include "all.h"

//using
using namespace GameLib;

//int HP::UIgetHP;
int perClear::getStageClear;
int chapterStar::getStageChapter;

HP::HP()
{

    playerHP = 4;
    sprHP = nullptr;
}

HP::~HP()
{
}

void HP::init()
{

    sprHP = new SpriteManager(L"./Data/Images/UI/player_hp.png", VECTOR2(20, 30), VECTOR2(1, 1), VECTOR2(1, 1), VECTOR2(478, 87));
}

void HP::deinit()
{
    delete sprHP;
}

void HP::updateHP()
{

    sprHP->setTexPosY(87.0f * playerHP);


}


void HP::drawHP()
{

    sprHP->draw();
}

perClear::perClear()
{

    param_.spr = sprite_load(L"./Data/Images/UI/perClear.png");

    perClear::getStageClear = 0;

    param_.pos = { 1420,10 };
    param_.scale = { 1,1 };
    param_.texpos = { 1,1 };
    param_.texscale = { 1,1 };
    param_.texsize = { 480,130 };
    param_.angle = 0.0f;
    param_.cloer = { 1,1,1,1 };
}

perClear::~perClear()
{
    safe_delete(param_.spr);
}

void perClear::update()
{
    getStageClear = StageSelect::instance()->getNum();      //ステージ番号の取得

    int drawMeterRange = (getStageClear % 4);       //ステージ番号を5で割った余り分の目盛りを表示させる
    param_.texpos.y = 130.0f * drawMeterRange;

    if (getStageClear == 4 || getStageClear == 8)  param_.texpos.y = 130.0f * 4;           //4で割り切れて0になってしまうので別途記述
    if (getStageClear == 9)  param_.texpos.y = 130.0f * 5;                                //ボス戦のステージ番号は別途記述
    if (getStageClear == 11) param_.texpos.y = 130.0f * 0;                                  //エピローグは0番と同じ扱い(チャプター2ができたらこっちに切り替える)
    //if (getStageClear == 6) param_.texpos.y = 130.0f * 0;                                 //エピローグは0番と同じ扱い


}

void perClear::draw()
{
    sprite_render(
        param_.spr,
        param_.pos.x, param_.pos.y,
        param_.scale.x, param_.scale.y,
        param_.texpos.x, param_.texpos.y,
        param_.texsize.x, param_.texsize.y,
        0, 0,
        param_.angle,
        param_.cloer.x, param_.cloer.y, param_.cloer.z, param_.cloer.w,
        true);

}






chapterStar::chapterStar()
{
    param_.spr = sprite_load(L"./Data/Images/UI/chapterStar.png");

    chapterStar::getStageChapter = 0;

    param_.pos = { 1425,120 };
    param_.scale = { 1.0f, 1.0f };
    param_.texpos = { 1,1 };
    param_.texscale = { 1,1 };
    param_.texsize = { 480,130 };
    param_.angle = 0.0f;
    param_.cloer = { 1,1,1,1 };

}

chapterStar::~chapterStar()
{
    safe_delete(param_.spr);
}

void chapterStar::update()
{
    //getStageChapter = StageSelect::instance()->getNum() / 5;      //チャプター番号の取得

    if (StageSelect::instance()->getNum() < 5) getStageChapter = 0;
    if (StageSelect::instance()->getNum() > 4 && StageSelect::instance()->getNum() < 9) getStageChapter = 1;
    if (StageSelect::instance()->getNum() == 9) getStageChapter = 2;


    param_.texpos.y = 130.0f * getStageChapter;                 //チャプターに対応した画像位置に設定する

}

void chapterStar::draw()
{
    sprite_render(
        param_.spr,
        param_.pos.x, param_.pos.y,
        param_.scale.x, param_.scale.y,
        param_.texpos.x, param_.texpos.y,
        param_.texsize.x, param_.texsize.y,
        0, 0,
        param_.angle,
        param_.cloer.x, param_.cloer.y, param_.cloer.z, param_.cloer.w,
        true);
}

MoveFlag::MoveFlag()
{
    param_.spr = sprite_load(L"./Data/Images/UI/moveFlag_UI.png");


    param_.pos = { 20,130 };
    param_.scale = { 1.0f, 1.0f };
    param_.texpos = { 0,0 };
    param_.texscale = { 1,1 };
    param_.texsize = { 107,102 };
    param_.angle = 0.0f;
    param_.cloer = { 1,1,1,1 };
}


void MoveFlag::update()
{
    if (Game::instance()->player()->actorComponent()->isPlayerMove()) {
        param_.texpos.y = 102;
    }
    else {
        param_.texpos.y = 0;
    }
}

void MoveFlag::draw()
{
    sprite_render(
        param_.spr,
        param_.pos.x, param_.pos.y,
        param_.scale.x, param_.scale.y,
        param_.texpos.x, param_.texpos.y,
        param_.texsize.x, param_.texsize.y,
        0, 0,
        param_.angle,
        param_.cloer.x, param_.cloer.y, param_.cloer.z, param_.cloer.w,
        true);
}


MoveFlag::~MoveFlag()
{
    safe_delete(param_.spr);

}

//TODO
opeGuide::opeGuide()
{
    sprManager[0] = sprite_load(L"./Data/Images/UI/keyboard.png");
    sprManager[1] = sprite_load(L"./Data/Images/UI/xbox.png");

    param_.spr = {};

    param_.pos = { 0.0f,0.0f };
    param_.scale = { 1.0f, 1.0f };
    param_.texpos = { 0,0 };
    param_.texscale = { 1,1 };
    param_.texsize = { 1920,1088 };
    param_.angle = 0.0f;
    param_.cloer = { 1,1,1,1 };

    InputFlag = false;
    sprNo = 0;
}


opeGuide::~opeGuide()
{
    safe_delete(sprManager[0]);
    safe_delete(sprManager[1]);
    //safe_delete(param_.spr);
}


void opeGuide::drawKeypad()
{
    sprite_render(
        sprManager[0],
        param_.pos.x, param_.pos.y,
        param_.scale.x, param_.scale.y,
        param_.texpos.x, param_.texpos.y,
        param_.texsize.x, param_.texsize.y,
        0, 0,
        param_.angle,
        param_.cloer.x, param_.cloer.y, param_.cloer.z, param_.cloer.w,
        true);
}

void opeGuide::drawXBox()
{
    sprite_render(
        sprManager[1],
        param_.pos.x, param_.pos.y,
        param_.scale.x, param_.scale.y,
        param_.texpos.x, param_.texpos.y,
        param_.texsize.x, param_.texsize.y,
        0, 0,
        param_.angle,
        param_.cloer.x, param_.cloer.y, param_.cloer.z, param_.cloer.w,
        true);

}
