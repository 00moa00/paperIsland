//******************************************************************************
//
//
//      BG�N���X
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"


//------< using >---------------------------------------------------------------
using namespace GameLib;





//------< TERRAIN�f�[�^ >---------------
namespace {

    //------< TERRAIN0�f�[�^ >---------------------------------------------

    int terrain_stage0Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage0.txt"
    };

    //------< TERRAIN1�f�[�^ >---------------------------------------------

    int terrain_stage1Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage1.txt"
    };

    //------< TERRAIN2�f�[�^ >---------------------------------------------

    int terrain_stage2Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage2.txt"
    };

    //------< TERRAIN3�f�[�^ >---------------------------------------------

    int terrain_stage3Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage3.txt"
    };

    //------< TERRAIN4�f�[�^ >---------------------------------------------

    int terrain_stage4Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage4.txt"
    };

    //------< TERRAIN�f5�[�^ >---------------------------------------------

    int terrain_stage5Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage5.txt"
    };

    //------< TERRAIN6�f�[�^ >---------------------------------------------

    int terrain_stage6Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage6.txt"
    };

    //------< TERRAIN7�f�[�^ >---------------------------------------------

    int terrain_stage7Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage7.txt"
    };

    //------< TERRAIN8�f�[�^ >---------------------------------------------

    int terrain_stage8Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage8.txt"
    };

    //------< TERRAIN9�f�[�^ >---------------------------------------------

    int terrain_stage9Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage9.txt"
    };

    //------< TERRAIN10�f�[�^ >---------------------------------------------

    int terrain_stage10Data[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_terrain_stage10.txt"
    };
}


bool isDebugDraw;

//----------------------------------------------------------------------
//  �R���X�g���N�^
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
//  �f�X�g���N�^
//----------------------------------------------------------------------
BG::~BG()
{
    clear();

}

//----------------------------------------------------------------------
//  �����ݒ�
//----------------------------------------------------------------------
void BG::init(OBJ2D* player)
{
    StageChipNum = 0;
    player_ = player;

    // BG�p�f�[�^�̃N���A
    clear();

    // �}�b�v�f�[�^�̃��[�h
    int num = StageSelect::instance()->getNum();

    switch (num)
    {
    case 0:


        if (!loadMapData(terrain_stage0Data, terrain)) assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");

        break;

    case 1:

        SCROLL_LIMIT.x = 5000;
        SCROLL_LIMIT.y = 180;

        if (!loadMapData(terrain_stage1Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;

    case 2:


        SCROLL_LIMIT.x = 3050;
        SCROLL_LIMIT.y = 645;

        if (!loadMapData(terrain_stage2Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;

    case 3:

        SCROLL_MERGIN_X = 700.f;     // ���̐��l����ʒ[�ɋ߂Â�����X�N���[������i���j
        SCROLL_MERGIN_Y = 250.f;     // ���̐��l����ʒ[�ɋ߂Â�����X�N���[������i�c�j

        SCROLL_LIMIT.x = 1250;
        SCROLL_LIMIT.y = 3008;

        if (!loadMapData(terrain_stage3Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;

    case 4:


        SCROLL_LIMIT.x = 3050;
        SCROLL_LIMIT.y = 0;

        if (!loadMapData(terrain_stage4Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;

    case 5:

        SCROLL_MERGIN_X = 700.f;     // ���̐��l����ʒ[�ɋ߂Â�����X�N���[������i���j
        SCROLL_MERGIN_Y = 290.f;     // ���̐��l����ʒ[�ɋ߂Â�����X�N���[������i�c�j
        SCROLL_LIMIT.x = 2500;
        SCROLL_LIMIT.y = 2000;


       if (!loadMapData(terrain_stage5Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
      //  if (!loadMapData(back_stage5Data, back))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
      //  if (!loadMapData(water_stage5Data, water))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");

        break;

    case 6:


        SCROLL_LIMIT.x = 668;
        SCROLL_LIMIT.y = 180;

        if (!loadMapData(terrain_stage6Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");

        break;

    case 7:


        SCROLL_LIMIT.x = 3000;
        SCROLL_LIMIT.y = 180;


        if (!loadMapData(terrain_stage7Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");

        break;

    case 8:


        SCROLL_LIMIT.x = 450;
        SCROLL_LIMIT.y = 2000 ;


        if (!loadMapData(terrain_stage8Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;

    case 9:



        if (!loadMapData(terrain_stage9Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;

    case 10:


        if (!loadMapData(terrain_stage10Data, terrain))assert(!"�n�`�f�[�^�̃��[�h�Ɏ��s");
        break;
    }




    isDebugDraw = false;
}

//----------------------------------------------------------------------
//  �����o�ϐ��̃N���A
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

    scroll = {};                                // �X�N���[�����W�i��ʍ���̈ʒu�̃��[���h���W�j
}


//----------------------------------------------------------------------
//  �}�b�v�f�[�^�̃��[�h�i���j
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
//  �X�V����
//----------------------------------------------------------------------
void BG::update()
{    
    if(!(StageSelect::instance()->getNum() == 0 )||
        !(StageSelect::instance()->getNum() == 9)||
        !(StageSelect::instance()->getNum() == 10))
        
        scrollMap();

}


//----------------------------------------------------------------------
//  �}�b�v�̃X�N���[��
//----------------------------------------------------------------------
void BG::scrollMap()
{


    Transform* transform = player_->transform();
    Collider* collision = player_->collider();

    // �X�N���[������
    // �E�����̃X�N���[������
    if (scroll.x < transform->position().x + collision->size().x - CLIENT_W + SCROLL_MERGIN_X) {
        if (scroll.x < SCROLL_LIMIT.x)  scroll.x = transform->position().x + collision->size().x - CLIENT_W + SCROLL_MERGIN_X;
    }

    // �������̃X�N���[������
    if (scroll.x > transform->position().x - collision->size().x - SCROLL_MERGIN_X) 
      scroll.x = transform->position().x - collision->size().x - SCROLL_MERGIN_X;
   

    // �������̃X�N���[������

    if (scroll.y < transform->position().y - CLIENT_H + SCROLL_MERGIN_Y) {

        if(scroll.y < SCROLL_LIMIT.y) scroll.y = transform->position().y - CLIENT_H + SCROLL_MERGIN_Y;
    }

    // ������̃X�N���[������
    if (scroll.y > transform->position().y - collision->size().y - SCROLL_MERGIN_Y) {
        scroll.y = transform->position().y - collision->size().y - SCROLL_MERGIN_Y;
    }

    // �G���A�����i�E�j
    if (scroll.x > WIDTH - CLIENT_W)
        scroll.x = WIDTH - CLIENT_W;

    // �G���A�����i���j
    if (scroll.x < 0)
        scroll.x = 0;

    // �G���A�����i���j
    if (scroll.y > HEIGHT - CLIENT_H)
        scroll.y = HEIGHT - CLIENT_H;

    // �G���A�����i��j
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
//  �w�i�`��
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  �n�`�`��
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
//  BG�f�[�^�`��
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
                my >= CHIP_NUM_Y || my < 0) continue;   // �Y�����͈̔̓`�F�b�N

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
//      �����蔻��
//
//******************************************************************************

//----------------------------------------------------------------------
//  �w�肵�����W�̃}�b�v�`�b�v�̎�ނ��擾����
//----------------------------------------------------------------------
int BG::getData(int map[][CHIP_NUM_X], const VECTOR2& pos)
{
    int divX = static_cast<int>(pos.x) / CHIP_SIZE;      // x�����̃C���f�b�N�X
    int divY = static_cast<int>(pos.y) / CHIP_SIZE;      // y�����̃C���f�b�N�X

    if (divX < 0 || divX >= CHIP_NUM_X ||
        divY < 0 || divY >= CHIP_NUM_Y)
        return -1;

    return map[divY][divX];
}

//----------------------------------------------------------------------
//  �w�肵�����W�̒n�`�̑������擾����
//----------------------------------------------------------------------
BG::TR_ATTR BG::getTerrainAttr(const VECTOR2& pos)
{
    // �C���f�b�N�X�擾�i1�����z��ŏ����j
    int index = getData(terrain, pos);
    if (index < 0) return TR_ATTR::TR_NONE;
    assert(index < CHIP_NUM_PER_LINE* CHIP_LINE_NUM);

    if (reverseFlag) return terrainAttrReverse[index];      //���ɐ؂�ւ���Ă���Ƃ��́A���̒n�`������Ԃ�

    return terrainAttr[index];
}

//----------------------------------------------------------------------
//  �w�肵��y���W���A�}�b�v�`�b�v�̏㑤4����1�ɂ��邩�ǂ�����Ԃ�
//----------------------------------------------------------------------
bool BG::isUpperQuater(float y)
{
    return static_cast<int>(y) % CHIP_SIZE < CHIP_SIZE / 2;
}

//----------------------------------------------------------------------
//  �������Ɍ����āA�w�肵�����W���ǂł��邩�ǂ���
//----------------------------------------------------------------------
bool BG::isHitDown(float x, float y)
{
    switch (getTerrainAttr(VECTOR2(x, y)))                  // �n�`�̑������擾����
    {
    case TR_ATTR::ALL_BLOCK:    return true;                // �S�ĕǂ̒n�`�ł�����

    case TR_ATTR::UPPER_BLOCK:  return isUpperQuater(y);    // �㑤�S���̂P���n�`�ŁA��S���̂P�Ɋ܂܂�邩

        break;
    }
    return false;   // �n�`�ł͂Ȃ������ꍇ
}

//----------------------------------------------------------------------
//  �S�ĕǂ̃u���b�N���ǂ���
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
//  �������ւ̂����蔻��
//----------------------------------------------------------------------
bool BG::isFloor(float x, float y, float width)
{
    for (; width > 0; width -= CHIP_SIZE)       // width��CHIP_SIZE�����炵�Ă���
    {
        const float left = x - width;
        const float right = x + width;

        // �G���A�`�F�b�N
        if (left < 0)       continue;
        if (right >= WIDTH) continue;

        if (isHitDown(left, y))  return true;   // ���[����
        if (isHitDown(right, y)) return true;   // �E�[����
    }
    return isHitDown(x, y);                     // �Ō�ɐ^�񒆂Ŕ���
}

//----------------------------------------------------------------------
//  �������ɂ������Ă���ꍇ�̕␳����
//----------------------------------------------------------------------
void BG::mapHoseiDown(OBJ2D* obj)
{
    Transform* transform = obj->transform();

    float y = transform->position().y;
    transform->addPositionY(-(fmodf(y, CHIP_SIZE_F) + ADJUST_Y));
    transform->setSpeedY(std::min(transform->speed().y, 0.0f));
}

//----------------------------------------------------------------------
//  �V��ɂ������Ă��邩
//----------------------------------------------------------------------
bool BG::isCeiling(float x, float y, float width)
{
    for (; width > 0; width -= CHIP_SIZE)
    {
        const float left    = x - width;
        const float right   = x + width;

        // �G���A�`�F�b�N
        if (left < 0)       continue;
        if (right >= WIDTH) continue;

        if (isHitAll(left, y))  return true;
        if (isHitAll(right, y)) return true;
    }
    return isHitAll(x, y);
}

//----------------------------------------------------------------------
//  ������ɂ������Ă���ꍇ�̕␳����
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
//  ���̕ǂɂ������Ă��邩
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
//  �E�����ɂ������Ă���ꍇ�̕␳����
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
//  �������ɂ������Ă���ꍇ�̕␳����
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
//  ���̈ʒu�ő��x�ɑ΂���R�͂��v�Z����
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
////  �w�肵���n�_�̔w�i�̑������擾
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
////  �w�i�̑����ɉ�������R��Ԃ�
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
////  OBJ2D�������ɂ��邩�ǂ���
////----------------------------------------------------------------------
//bool BG::isInWater(const OBJ2D* obj)
//{
//    Transform* transform = obj->transform();
//    return (getBackAttr(transform->position()) == BG_ATTR::WATER);
//}
