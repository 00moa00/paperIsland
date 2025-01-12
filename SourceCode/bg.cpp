//******************************************************************************
//
//
//      BGクラス
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"


//------< using >---------------------------------------------------------------
using namespace GameLib;





//------< TERRAINデータ >---------------
namespace {

    //------< TERRAIN0データ >---------------------------------------------

    int terrain_stage0Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage0.txt"
    };

    //------< TERRAIN1データ >---------------------------------------------

    int terrain_stage1Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage1.txt"
    };

    //------< TERRAIN2データ >---------------------------------------------

    int terrain_stage2Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage2.txt"
    };

    //------< TERRAIN3データ >---------------------------------------------

    int terrain_stage3Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage3.txt"
    };

    //------< TERRAIN4データ >---------------------------------------------

    int terrain_stage4Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage4.txt"
    };

    //------< TERRAINデ5ータ >---------------------------------------------

    int terrain_stage5Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage5.txt"
    };

    //------< TERRAIN6データ >---------------------------------------------

    int terrain_stage6Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage6.txt"
    };

    //------< TERRAIN7データ >---------------------------------------------

    int terrain_stage7Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage7.txt"
    };

    //------< TERRAIN8データ >---------------------------------------------

    int terrain_stage8Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage8.txt"
    };

    //------< TERRAIN9データ >---------------------------------------------

    int terrain_stage9Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage9.txt"
    };

    //------< TERRAIN10データ >---------------------------------------------

    int terrain_stage10Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage10.txt"
    };
}


bool isDebugDraw;

//----------------------------------------------------------------------
//  コンストラクタ
//----------------------------------------------------------------------
BG::BG()
    :scroll(VECTOR2(0, 0))
    , back()
    , terrain()
    , water()
    , player_(nullptr)
    , reverseFlag(false)
    , SCROLL_LIMIT(VECTOR2(0,0))
{
}

//----------------------------------------------------------------------
//  デストラクタ
//----------------------------------------------------------------------
BG::~BG()
{
    clear();

}

//----------------------------------------------------------------------
//  初期設定
//----------------------------------------------------------------------
void BG::init(OBJ2D* player)
{
    StageChipNum = 0;
    player_ = player;

    // BG用データのクリア
    clear();

    // マップデータのロード
    int num = StageSelect::instance()->getNum();

    switch (num)
    {
    case 0:


        if (!loadMapData(terrain_stage0Data, terrain)) assert(!"地形データのロードに失敗");

        break;

    case 1:

        SCROLL_LIMIT.x = 5000;
        SCROLL_LIMIT.y = 180;

        if (!loadMapData(terrain_stage1Data, terrain))assert(!"地形データのロードに失敗");
        break;

    case 2:


        SCROLL_LIMIT.x = 3050;
        SCROLL_LIMIT.y = 645;

        if (!loadMapData(terrain_stage2Data, terrain))assert(!"地形データのロードに失敗");
        break;

    case 3:

        SCROLL_MERGIN_X = 700.f;     // この数値より画面端に近づいたらスクロールする（横）
        SCROLL_MERGIN_Y = 250.f;     // この数値より画面端に近づいたらスクロールする（縦）

        SCROLL_LIMIT.x = 1250;
        SCROLL_LIMIT.y = 3008;

        if (!loadMapData(terrain_stage3Data, terrain))assert(!"地形データのロードに失敗");
        break;

    case 4:


        SCROLL_LIMIT.x = 3050;
        SCROLL_LIMIT.y = 0;

        if (!loadMapData(terrain_stage4Data, terrain))assert(!"地形データのロードに失敗");
        break;

    case 5:

        SCROLL_MERGIN_X = 700.f;     // この数値より画面端に近づいたらスクロールする（横）
        SCROLL_MERGIN_Y = 290.f;     // この数値より画面端に近づいたらスクロールする（縦）
        SCROLL_LIMIT.x = 2500;
        SCROLL_LIMIT.y = 2000;


       if (!loadMapData(terrain_stage5Data, terrain))assert(!"地形データのロードに失敗");
      //  if (!loadMapData(back_stage5Data, back))assert(!"地形データのロードに失敗");
      //  if (!loadMapData(water_stage5Data, water))assert(!"地形データのロードに失敗");

        break;

    case 6:


        SCROLL_LIMIT.x = 668;
        SCROLL_LIMIT.y = 180;

        if (!loadMapData(terrain_stage6Data, terrain))assert(!"地形データのロードに失敗");

        break;

    case 7:


        SCROLL_LIMIT.x = 3000;
        SCROLL_LIMIT.y = 180;


        if (!loadMapData(terrain_stage7Data, terrain))assert(!"地形データのロードに失敗");

        break;

    case 8:


        SCROLL_LIMIT.x = 450;
        SCROLL_LIMIT.y = 2000 ;


        if (!loadMapData(terrain_stage8Data, terrain))assert(!"地形データのロードに失敗");
        break;

    case 9:



        if (!loadMapData(terrain_stage9Data, terrain))assert(!"地形データのロードに失敗");
        break;

    case 10:


        if (!loadMapData(terrain_stage10Data, terrain))assert(!"地形データのロードに失敗");
        break;
    }




    isDebugDraw = false;
}

//----------------------------------------------------------------------
//  メンバ変数のクリア
//----------------------------------------------------------------------
void BG::clear()
{
    for (int y = 0; y < CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            terrain[y][x] = -1;
        }
    }

    for (int y = 0; y < CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            back[y][x] = -1;
        }
    }

    for (int y = 0; y < CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            water[y][x] = -1;
        }
    }
    StageChipNum = 0;

    scroll = {};                                // スクロール座標（画面左上の位置のワールド座標）
}


//----------------------------------------------------------------------
//  マップデータのロード（仮）
//----------------------------------------------------------------------
bool BG::loadMapData(const int data[][CHIP_NUM_X], int map[][CHIP_NUM_X])
{


        for (int y = 0; y < BG::CHIP_NUM_Y; y++)
        {
            for (int x = 0; x < BG::CHIP_NUM_X; x++)
            {
                map[y][x] = data[y][x];
            }
        }

    
    return true;

}

//----------------------------------------------------------------------
//  更新処理
//----------------------------------------------------------------------
void BG::update()
{    
    if(!(StageSelect::instance()->getNum() == 0 )||
        !(StageSelect::instance()->getNum() == 9)||
        !(StageSelect::instance()->getNum() == 10))
        
        scrollMap();

}


//----------------------------------------------------------------------
//  マップのスクロール
//----------------------------------------------------------------------
void BG::scrollMap()
{


    Transform* transform = player_->transform();
    Collider* collision = player_->collider();

    // スクロール処理
    // 右方向のスクロール処理
    if (scroll.x < transform->position().x + collision->size().x - CLIENT_W + SCROLL_MERGIN_X) {
        if (scroll.x < SCROLL_LIMIT.x)  scroll.x = transform->position().x + collision->size().x - CLIENT_W + SCROLL_MERGIN_X;
    }

    // 左方向のスクロール処理
    if (scroll.x > transform->position().x - collision->size().x - SCROLL_MERGIN_X) 
      scroll.x = transform->position().x - collision->size().x - SCROLL_MERGIN_X;
   

    // 下方向のスクロール処理

    if (scroll.y < transform->position().y - CLIENT_H + SCROLL_MERGIN_Y) {

        if(scroll.y < SCROLL_LIMIT.y) scroll.y = transform->position().y - CLIENT_H + SCROLL_MERGIN_Y;
    }

    // 上方向のスクロール処理
    if (scroll.y > transform->position().y - collision->size().y - SCROLL_MERGIN_Y) {
        scroll.y = transform->position().y - collision->size().y - SCROLL_MERGIN_Y;
    }

    // エリア制限（右）
    if (scroll.x > WIDTH - CLIENT_W)
        scroll.x = WIDTH - CLIENT_W;

    // エリア制限（左）
    if (scroll.x < 0)
        scroll.x = 0;

    // エリア制限（下）
    if (scroll.y > HEIGHT - CLIENT_H)
        scroll.y = HEIGHT - CLIENT_H;

    // エリア制限（上）
    if (scroll.y < 0)
        scroll.y = 0;

    using namespace input;
    if (TRG(0) & PAD_TRG2)
    {
        isDebugDraw = !isDebugDraw;
    }

    //debug::setString("scroll.x:%f", scroll.x);
    //debug::setString("scroll.y:%f", scroll.y);

}

//----------------------------------------------------------------------
//  背景描画
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  地形描画
//----------------------------------------------------------------------
void BG::drawTerrain()
{
    draw(TEXNO::MAP_TERRAIN, terrain);
}

void BG::drawTerrainRev()
{
    draw(TEXNO::MAP_TERRAIN_REV, terrain);
}



//----------------------------------------------------------------------
//  BGデータ描画
//----------------------------------------------------------------------
void BG::draw(int texNo, int map[][CHIP_NUM_X])
{
    const int DIV_X = static_cast<int>(scroll.x) / CHIP_SIZE; // division x
    const int DIV_Y = static_cast<int>(scroll.y) / CHIP_SIZE; // division y
    const int REM_X = static_cast<int>(scroll.x) % CHIP_SIZE; // remainder x
    const int REM_Y = static_cast<int>(scroll.y) % CHIP_SIZE; // remainder y

    texture::begin(texNo);
    for (int y = 0; y < LOOP_Y; y++)
    {
        for (int x = 0; x < LOOP_X; x++)
        {
            const int mx = DIV_X + x;
            const int my = DIV_Y + y;
            if (mx >= CHIP_NUM_X || mx < 0 ||
                my >= CHIP_NUM_Y || my < 0) continue;   // 添え字の範囲チェック

            int chip = map[my][mx];
            if (-1 == chip) continue;

            texture::draw(texNo,
                x * CHIP_SIZE_F - REM_X, y * CHIP_SIZE_F - REM_Y,
                1, 1,
                chip % CHIP_NUM_PER_LINE * CHIP_SIZE_F,
                chip / CHIP_NUM_PER_LINE * CHIP_SIZE_F,
                CHIP_SIZE_F, CHIP_SIZE_F
                );
        }
    }
    texture::end(texNo);
}



//******************************************************************************
//
//      あたり判定
//
//******************************************************************************

//----------------------------------------------------------------------
//  指定した座標のマップチップの種類を取得する
//----------------------------------------------------------------------
int BG::getData(int map[][CHIP_NUM_X], const VECTOR2& pos)
{
    int divX = static_cast<int>(pos.x) / CHIP_SIZE;      // x方向のインデックス
    int divY = static_cast<int>(pos.y) / CHIP_SIZE;      // y方向のインデックス

    if (divX < 0 || divX >= CHIP_NUM_X ||
        divY < 0 || divY >= CHIP_NUM_Y)
        return -1;

    return map[divY][divX];
}

//----------------------------------------------------------------------
//  指定した座標の地形の属性を取得する
//----------------------------------------------------------------------
BG::TR_ATTR BG::getTerrainAttr(const VECTOR2& pos)
{
    // インデックス取得（1次元配列で処理）
    int index = getData(terrain, pos);
    if (index < 0) return TR_ATTR::TR_NONE;
    assert(index < CHIP_NUM_PER_LINE* CHIP_LINE_NUM);

    if (reverseFlag) return terrainAttrReverse[index];      //裏に切り替わっているときは、裏の地形属性を返す

    return terrainAttr[index];
}

//----------------------------------------------------------------------
//  指定したy座標が、マップチップの上側4分の1にあるかどうかを返す
//----------------------------------------------------------------------
bool BG::isUpperQuater(float y)
{
    return static_cast<int>(y) % CHIP_SIZE < CHIP_SIZE / 2;
}

//----------------------------------------------------------------------
//  下方向に向けて、指定した座標が壁であるかどうか
//----------------------------------------------------------------------
bool BG::isHitDown(float x, float y)
{
    switch (getTerrainAttr(VECTOR2(x, y)))                  // 地形の属性を取得する
    {
    case TR_ATTR::ALL_BLOCK:    return true;                // 全て壁の地形であった

    case TR_ATTR::UPPER_BLOCK:  return isUpperQuater(y);    // 上側４分の１が地形で、上４分の１に含まれるか

        break;
    }
    return false;   // 地形ではなかった場合
}

//----------------------------------------------------------------------
//  全て壁のブロックかどうか
//----------------------------------------------------------------------
bool BG::isHitAll(float x, float y)
{
    //return (getTerrainAttr(VECTOR2(x, y)) == (TR_ATTR::ALL_BLOCK|| TR_ATTR::B_BLOCK1));


    if ((getTerrainAttr(VECTOR2(x, y)) == TR_ATTR::ALL_BLOCK) ) {

        return true;
    }


    return false;
}

//----------------------------------------------------------------------
//  床方向へのあたり判定
//----------------------------------------------------------------------
bool BG::isFloor(float x, float y, float width)
{
    for (; width > 0; width -= CHIP_SIZE)       // widthをCHIP_SIZE分減らしていく
    {
        const float left = x - width;
        const float right = x + width;

        // エリアチェック
        if (left < 0)       continue;
        if (right >= WIDTH) continue;

        if (isHitDown(left, y))  return true;   // 左端から
        if (isHitDown(right, y)) return true;   // 右端から
    }
    return isHitDown(x, y);                     // 最後に真ん中で判定
}

//----------------------------------------------------------------------
//  下方向にあたっている場合の補正処理
//----------------------------------------------------------------------
void BG::mapHoseiDown(OBJ2D* obj)
{
    Transform* transform = obj->transform();

    float y = transform->position().y;
    transform->addPositionY(-(fmodf(y, CHIP_SIZE_F) + ADJUST_Y));
    transform->setSpeedY(std::min(transform->speed().y, 0.0f));
}

//----------------------------------------------------------------------
//  天井にあたっているか
//----------------------------------------------------------------------
bool BG::isCeiling(float x, float y, float width)
{
    for (; width > 0; width -= CHIP_SIZE)
    {
        const float left    = x - width;
        const float right   = x + width;

        // エリアチェック
        if (left < 0)       continue;
        if (right >= WIDTH) continue;

        if (isHitAll(left, y))  return true;
        if (isHitAll(right, y)) return true;
    }
    return isHitAll(x, y);
}

//----------------------------------------------------------------------
//  上方向にあたっている場合の補正処理
//----------------------------------------------------------------------
void BG::mapHoseiUp(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    Collider* collider = obj->collider();

    float y = transform->position().y - collider->size().y;
    transform->addPositionY(CHIP_SIZE_F - fmodf(y, CHIP_SIZE_F));
    transform->setSpeedY(std::max(transform->speed().y, 0.0f));
}

//----------------------------------------------------------------------
//  横の壁にあたっているか
//----------------------------------------------------------------------
bool BG::isWall(float x, float y, float height)
{
    for (; height > 0; height -= CHIP_SIZE)
    {
        const float yPos = y - height;
        if (yPos < 0)      continue;
        if (yPos > HEIGHT) continue;

        if (isHitAll(x, yPos))
            return true;
    }

    return isHitAll(x, y);
}

//----------------------------------------------------------------------
//  右方向にあたっている場合の補正処理
//----------------------------------------------------------------------
void BG::mapHoseiRight(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    Collider* collider = obj->collider();

    float x = transform->position().x + collider->size().x;
    transform->addPositionX(-(fmodf(x, CHIP_SIZE) + ADJUST_X));
    transform->setSpeedX(0.0f);
}

//----------------------------------------------------------------------
//  左方向にあたっている場合の補正処理
//----------------------------------------------------------------------
void BG::mapHoseiLeft(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    Collider* collider = obj->collider();

    float x = transform->position().x - collider->size().x;
    transform->addPositionX(CHIP_SIZE_F - fmodf(x, CHIP_SIZE_F) + ADJUST_X);
    transform->setSpeedX(0.0f);
}

//----------------------------------------------------------------------
//  その位置で速度に対する抗力を計算する
//----------------------------------------------------------------------
//float BG::calcResistance(const OBJ2D* obj, float speed)
//{
//    Transform* transform = obj->transform();
//    Collider* collider = obj->collider();
//    return getTeikou(
//        getBackAttr(VECTOR2(transform->position().x, transform->position().y - collider->size().y * 0.5f)), 
//        speed);
//}
//
////----------------------------------------------------------------------
////  指定した地点の背景の属性を取得
////----------------------------------------------------------------------
//BG::BG_ATTR BG::getBackAttr(const VECTOR2& pos)
//{
//    int index = getData(back, pos);
//    if (index < 0) return BG_ATTR::BG_NONE;
//    assert(index < CHIP_NUM_PER_LINE* CHIP_LINE_NUM);
//    return bgAttr[index];
//}
//
////----------------------------------------------------------------------
////  背景の属性に応じた抵抗を返す
////----------------------------------------------------------------------
//float BG::getTeikou(BG_ATTR attr, float speed)
//{
//    switch (attr)
//    {
//    case BG_ATTR::WATER:
//        return speed / -4.0f;
//
//    default:
//        break;
//    }
//    return 0.0f;
//}
//
////----------------------------------------------------------------------
////  OBJ2Dが水中にいるかどうか
////----------------------------------------------------------------------
//bool BG::isInWater(const OBJ2D* obj)
//{
//    Transform* transform = obj->transform();
//    return (getBackAttr(transform->position()) == BG_ATTR::WATER);
//}
