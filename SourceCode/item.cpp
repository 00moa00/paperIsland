#include "all.h"


namespace
{
    int item_stage0[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
           #include "../Data//Maps/MAP_item_stage0.txt"

    };

    int item_stage1[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_item_stage1.txt"

    };

    int item_stage2[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_item_stage2.txt"

    };

    int item_stage3[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_item_stage3.txt"

    };

    int item_stage4[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_item_stage4.txt"

    };

    int item_stage5[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_item_stage5.txt"
    };

    int item_stage6[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
        #include "../Data//Maps/MAP_item_stage6.txt"
    };


    int item_stage7[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
        #include "../Data//Maps/MAP_item_stage7.txt"
    };



    int item_stage8[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
        #include "../Data//Maps/MAP_item_stage8.txt"
    };



    int item_stage9[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
        #include "../Data//Maps/MAP_item_stage9.txt"
    };



    int item_stage10[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
        #include "../Data//Maps/MAP_item_stage10.txt"
    };



}

void setItem(OBJ2DManager* obj2dManager, BG* bg)
{

    BaseItemBehavior* itemBehavior[] = {
        &itemMove,
        &itemPaper,
        &itemHp,
        &itemWeapon,
        &itemMoveFlag,
    };

    for (int y = 0; y < BG::CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < BG::CHIP_NUM_X; x++)
        {
            int chip = 0;
            int num = StageSelect::instance()->getNum();
            switch (num) {
            case 0: chip = item_stage0[y][x];   break;
            case 1: chip = item_stage1[y][x];   break;
            case 2: chip = item_stage2[y][x];   break;
            case 3: chip = item_stage3[y][x];   break;
            case 4: chip = item_stage4[y][x];   break;
            case 5: chip = item_stage5[y][x];   break;
            case 6: chip = item_stage6[y][x];   break;
            case 7: chip = item_stage7[y][x];   break;
            case 8: chip = item_stage8[y][x];   break;
            case 9: chip = item_stage9[y][x];   break;
            case 10: chip = item_stage10[y][x];   break;


            }

            if (chip < 0) continue;
            assert(chip < ARRAYSIZE(itemBehavior));
            if (!itemBehavior[chip]) continue;

            const VECTOR2 pos = {
                x * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F * 0.5f,
                y * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F * 0.5f,
            };
            OBJ2D* item = new OBJ2D(
                new Renderer,
                new Collider,
                bg,
                nullptr,
                new ItemComponent,
                nullptr
            );
            obj2dManager->add(item, itemBehavior[chip], pos);
        }
    }
}

//==============================================================================
//
//      BaseItemBehavior
//
//==============================================================================

void BaseItemBehavior::move(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    Renderer* renderer = obj->renderer();
    Collider* collider = obj->collider();
    ItemComponent* itemComponent = obj->itemComponent();

    switch (obj->state())
    {
    case 0:
        //////// 初期設定 ////////
        transform->setScale(getParam()->SCALE);
        renderer->setData(getParam()->SPR_ITEM);
        collider->setSize(getParam()->SIZE);
        collider->setJudgeFlag(true);
        collider->setIsDrawHitRect(true);

        // アイテムを揺らす
        itemComponent->setOrgPos(transform->position());
        itemComponent->setAngle(fmodf(transform->position().x, 360.0f));
        collider->calcAttackBox(getParam()->ATTACK_BOX);

        obj->nextState();//state++
        break;
    case 1:
        //////// 通常時 ////////

        // アイテムを揺らす
        transform->setPositionY(itemComponent->orgPos().y + sinf(itemComponent->angle()) * 4);
        collider->calcAttackBox(getParam()->ATTACK_BOX);
        itemComponent->addAngle(ToRadian(6));
        if (itemComponent->angle() > PI)
            itemComponent->addAngle(-2 * PI);

        break;
    }
}

//==============================================================================
//
//      ItemSword
//
//==============================================================================

ItemWeapon::ItemWeapon()
{
    param_.SPR_ITEM = &sprItemWeapon;
    param_.SIZE = { 48,48 };
    param_.ATTACK_BOX = { -48, -48, 48, 48 };
    param_.SCALE = { 1, 1 };
}

void ItemWeapon::hit(OBJ2D* src, OBJ2D* dst)
{

    GameLib::music::play(SOUND::ITEM);
    //GameLib::music::setVolume(SOUND::ITEM, 1.0f);
    audio_setVolume_SE(SOUND::ITEM, 1.0f);


    switch (dst->behavior()->getType())
    {
    case OBJ_TYPE::PLAYER:
        if (dst->actorComponent())
            //dst->actorComponent()->setHasSword(true);
            PlayerWeapon::instance()->SethasWeapon(true);
        break;
    }
    src->remove();
}

//==============================================================================
//
//      ItemKey
//
//==============================================================================

ItemHp::ItemHp()
{
    param_.SPR_ITEM = &sprItemHp;
    param_.SIZE = { 46,46 };
    param_.ATTACK_BOX = { -46, -46, 46, 46 };
    param_.SCALE = { 1, 1 };
}

void ItemHp::hit(OBJ2D* src, OBJ2D*)
{
    if (HP::instance()->GetHp() < 5) {
        GameLib::music::play(SOUND::ITEM);
        //GameLib::music::setVolume(SOUND::ITEM, 1.0f);
        audio_setVolume_SE(SOUND::ITEM, 1.0f);
        HP::instance()->AddHp();
        src->remove();
    }
}

//==============================================================================
//
//      ItemOrb
//
//==============================================================================

ItemMove::ItemMove()
{
    param_.SPR_ITEM = &sprItemMove;
    param_.SIZE = { 60, 45 };
    param_.ATTACK_BOX = { -60, -45, 60, 45 };
    param_.SCALE = { 1, 1 };
}

void ItemMove::hit(OBJ2D*, OBJ2D*)
{
    //  Renderer* renderer = src->renderer();


    using namespace GameLib;
    switch (StageSelect::instance()->getNum())
    {

    case 0:
        PlayerClear::instance()->SetPlayerClear();
        music::stop(SOUND::PLAYER_WALK);

        Game::instance()->stageTrans()->setState(2);

        //src->setStageM(true);
        break;
    case 1:
        if (!PlayerWeapon::instance()->GethasWeapon())
        {
            break;
        }
    case 2:
    case 3:

    case 4:


    case 5:
    case 6:
    case 7:

    case 8:
        //  renderer->setColor_a(1.0f);
        if (Game::instance()->player()->actorComponent()->isPlayerMove()) {

            music::stop(SOUND::PLAYER_WALK);
            PlayerClear::instance()->SetPlayerClear();
            Game::instance()->stageTrans()->setState(2);
            
            //src->setStageM(true);        
        }



        // case 9:

    }

}

ItemMoveFlag::ItemMoveFlag()
{
    param_.SPR_ITEM = &sprItemMoveFlag;
    param_.SIZE = { 60, 45 };
    param_.ATTACK_BOX = { -60, -45, 60, 45 };
    param_.SCALE = { 1, 1 };
}

void ItemMoveFlag::hit(OBJ2D* src, OBJ2D*)
{
    src->remove();

    Game::instance()->player()->actorComponent()->setPlayerMove(true);

    if (StageSelect::instance()->getNum() == 4)
    {
        music::play(SOUND::STAGE8_WARNING);
        music::stop(MUSIC::GAME);


        music::play(MUSIC::CH1_BOSS, true);
        music::setVolume(MUSIC::CH1_BOSS, 0.0f);

        if (Game::instance()->VolumeSelect(0) == 1) music::fade(MUSIC::CH1_BOSS, 10.0f, 0.2f);
        if (Game::instance()->VolumeSelect(0) == 2) music::fade(MUSIC::CH1_BOSS, 10.0f, 0.5f);
    }
    else
    {
        music::play(SOUND::GET_STAR);
    }

    audio_setVolume_SE(SOUND::STAGE8_WARNING, 1.0f);

}

ItemPaper::ItemPaper()
{

    param_.SPR_ITEM = &sprItemPaper;
    param_.SIZE = { 60, 45 };
    param_.ATTACK_BOX = { -60, -45, 60, 45 };
    param_.SCALE = { 1, 1 };
}

void ItemPaper::hit(OBJ2D*, OBJ2D*)
{
    using namespace input;

    if ((TRG(0) & PAD_START))
    {
        Game::instance()->paper()->setPaperFlag(!Game::instance()->paper()->getPaperFlag());
    }

    //if ((TRG(0) & PAD_START) && Game::instance()->paper()->getPaperFlag())
    //{
    //    Game::instance()->paper()->setPaperFlag(false);
    //}

}
