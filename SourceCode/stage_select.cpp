//インクルード
#include "all.h"

//using
using namespace GameLib;

StageSelect StageSelect::instance_;


void StageSelect::init() {
}

void StageSelect::update()
{

    using namespace input;
    numUpdate();


   // if (TRG(0) & PAD_START)     changeScene(Game::instance());

}

//--------------------------------------------------------------
//  描画処理
//--------------------------------------------------------------
void StageSelect::draw()
{
    GameLib::clear(VECTOR4(1, 1, 1, 1));

    GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

    debug::setString("stage:%d", stage_num);

}


void StageSelect::numUpdate() {

    using namespace input;


    if (TRG(0) & PAD_RIGHT) addNum();
    if (TRG(0) & PAD_LEFT)subNum();


}


void StageSelect::addNum() {

    if (stage_num + 1 < STAGE_NUM_MAX) stage_num += 1;

}

void StageSelect::subNum() {
    if (stage_num > 0) stage_num--;
}