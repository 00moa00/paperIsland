#include "all.h"


namespace
{
    int block_stage2[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
  #include "../Data/Maps/BLOCK/MAP_leaf_stage2.txt"
    };

    int block_stage3[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data/Maps/BLOCK/MAP_leaf_stage3.txt"
    };

    int block_stage4[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
#include "../Data/Maps/BLOCK/MAP_leaf_stage4.txt"
    };


    int block_stage5[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
#include "../Data/Maps/BLOCK/MAP_leaf_stage5.txt"
    };


    int block_stage6[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
#include "../Data/Maps/BLOCK/MAP_leaf_stage6.txt"
    };


    int block_stage7[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
#include "../Data/Maps/BLOCK/MAP_leaf_stage7.txt"
    };



    int block_stage8[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
#include "../Data/Maps/BLOCK/MAP_leaf_stage8.txt"
    };
}
void setBlock(OBJ2DManager* obj2dManager, BG* bg)
{

    BaseBlockBehavior* blockbehavior[] =
    {
        &blockpar_YO,
        &blockpar_UP,
        &dropBlock,
        &dropBlock,
        nullptr,
    };

    for (int y = 0; y < BG::CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < BG::CHIP_NUM_X; x++)
        {

            int chip = -1;
            int num = StageSelect::instance()->getNum();
            switch (num) {

                //case 0: chip = block_stage0[y][x];  break;
                //case 1: chip = block_stage1[y][x];  break;
            case 2: chip = block_stage2[y][x];  break;
            case 3: chip = block_stage3[y][x];  break;
            case 4: chip = block_stage4[y][x];  break;
            case 5: chip = block_stage5[y][x];  break;
            case 6: chip = block_stage6[y][x];  break;
            case 7: chip = block_stage7[y][x];  break;
            case 8: chip = block_stage8[y][x];  break;

            }

            if (chip < 0) continue;
            assert(chip < ARRAYSIZE(blockbehavior));
            if (!blockbehavior[chip]) continue;

            const VECTOR2 pos = {
                x * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F * 0.5f,
                y * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F,
            };
            OBJ2D* block = new OBJ2D(
                new Renderer,
                new Collider,
                bg,
                new ActorComponent,
                nullptr,
                nullptr
            );
            obj2dManager->add(block, blockbehavior[chip], pos);
        }
    }

}




void BaseBlockBehavior::move(OBJ2D* obj)
{
    switch (obj->state())
    {
    case 0:
        //////// �����ݒ� ////////
        obj->transform()->setScale(getParam()->SCALE);
        obj->renderer()->setData(getParam()->SPR_BLOCK);
        obj->collider()->setSize(getParam()->SIZE);
        obj->collider()->setJudgeFlag(true);      // �����蔻����s��
        obj->collider()->setIsDrawHitRect(true);  // �����蔻��̗̈��`�悷��i�f�o�b�O�p�j


        obj->actorComponent()->setOnGround(false);

        obj->transform()->setSpeedY(1.0f);        // �O�̂���

        obj->nextState();//state++
        /*fallthrough*/

    case 1:

        //////// �ʏ펞 ////////
        update(obj);    // ����̈ʒu�X�V
        calcAttackBox(obj);  //�����蔻��p���l�X�V
        areaCheck(obj);

        break;


    }
}



void BlockEraser::erase(OBJ2D* obj)
{
    const VECTOR2* scrollPos = &obj->bg()->getScrollPos();
    const VECTOR2* size = &obj->collider()->size();
    const VECTOR2* pos = &obj->transform()->position();

    const float leftLimit = scrollPos->x - size->x;
    const float rightLimit = scrollPos->x + BG::CLIENT_W + size->x;
    const float topLimit = scrollPos->y - size->y;
    const float bottomLimit = scrollPos->y + BG::CLIENT_H + size->y;

    if (pos->x < leftLimit ||
        pos->x > rightLimit ||
        pos->y < topLimit ||
        pos->y > bottomLimit)
    {
        obj->remove();
    }
}

BlockPar_YO::BlockPar_YO()
{
    param_.SIZE = { 150 * param_.SCALE.x, 130 * param_.SCALE.y };
    param_.ATTACK_BOX = { -80, -15, 80, 55 };
    param_.SPEED = { 4.0f, 0.0f };
    param_.SPR_BLOCK = &spr_parblock;

}

void BlockPar_YO::update(OBJ2D* obj)
{
    moveX(obj);
}

void BlockPar_YO::calcAttackBox(OBJ2D* obj)
{
    // �U������̌v�Z
    obj->collider()->calcAttackBox(
        getParam()->ATTACK_BOX
    );
}

void BlockPar_YO::hit(OBJ2D* src, OBJ2D* dst)
{
    if (dst->actorComponent()->BlockFlagLeft() && !dst->actorComponent()->BlockFlagUp())
    {
        Game::instance()->bg()->mapHoseiRight(src);
        setParam_speed(VECTOR2(0.0f, 0.0f));
    }

    if (dst->actorComponent()->BlockFlagRight() && !dst->actorComponent()->BlockFlagUp())
    {
        Game::instance()->bg()->mapHoseiLeft(src);
        setParam_speed(VECTOR2(0.0f, 0.0f));
    }

    //�����v���C���[�A�G���ړ��u���b�N�̏�ɏ���Ă����true�ɂ���
    if (!src->actorComponent()->kabeFlag() && dst->actorComponent()->jumpTimer() <= 0)
    {
        if (dst->actorComponent()->BlockFlagDo()) dst->actorComponent()->set_IdoBlockFlag(true);

    }


    //�����v���C���[�A�G���ړ��u���b�N�̏�ɏ���Ă����true�ɂ���
   // if (dst->actorComponent()->BlockFlagDo() && dst->actorComponent()->jumpTimer() <= 0)
   // {
   //     if (dst->actorComponent()->BlockFlagDo()) dst->actorComponent()->set_IdoBlockFlag(true);
   //    // if (Game::instance()->bg()->getReverseFlag() && src->actorComponent()->kabeFlag()/*&& Game::instance()->bg()->getScrollY() < 650*/ && Game::instance()->bg()->getScrollY() < Game::instance()->bg()->getSCROLLLIMIT().y) Game::instance()->bg()->addScrollY(1.2f);
   //    // if (!Game::instance()->bg()->getReverseFlag() &&src->actorComponent()->kabeFlag()) Game::instance()->bg()->addScrollY(-1.2f);
   //    
   //    // dst->transform()->addPositionX(4.0f);
   //
   // }

    if (dst->actorComponent()->IdoBlockFlag()) {

        if (src->actorComponent()->kabeFlag()) return;

        float idoBlock_speed = (Game::instance()->bg()->getReverseFlag()) ? 4.0f : -4.0f;
        dst->transform()->addPositionX(idoBlock_speed);
    }




    dst->actorComponent()->setOnGround(true);
}

void BlockPar_YO::moveX(OBJ2D* obj)
{
    Transform* t = obj->transform();
    BG* bg = obj->bg();
    Collider* collider = obj->collider();

    obj->actorComponent()->setKabeFlag(false);


    // X�����ړ�
    float oldX = t->position().x;
    (Game::instance()->bg()->getReverseFlag()) ? t->addPositionX(getParam()->SPEED.x) : t->addPositionX(-getParam()->SPEED.x);
    float deltaX = t->position().x - oldX;


    // �E���������蔻��
    if (deltaX > 0)
    {
        if ((bg->isWall(t->position().x + collider->size().x,
            t->position().y, collider->size().y)))
        {
            bg->mapHoseiRight(obj);     // �E�����̕␳����
            obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;                    // �ǃt���O��true�ɂ��Ă���
        }
    }

    // �����������蔻��
    if (deltaX < 0)
    {
        if ((bg->isWall(t->position().x - collider->size().x,
            t->position().y, collider->size().y)))
        {
            bg->mapHoseiLeft(obj);
            obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;
        }
    }


    if (getParam()->SPEED.x <= 0.0f) setParam_speed(VECTOR2(1.0f, 0.0f));
}

void BlockPar_YO::areaCheck(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    Collider* collider = obj->collider();


    //�X�e�[�W���Ƃɐ�����ݒ肷��
    switch (StageSelect::instance()->getNum())
    {

        //case 0:
        //case 1:
        //case 2:
    case 3:

        stageLimitPosRight = 2400;
        stageLimitPosLeft = 800;

        break;

    case 4:

        stageLimitPosRight = 2600;
        stageLimitPosLeft = 1600;
        break;

    case 5:

        stageLimitPosRight = 3000;
        stageLimitPosLeft = 2100;
        break;


    case 6:

        stageLimitPosRight = 1360;
        stageLimitPosLeft = 710;
        break;
        // case 7:
    case 8:
        stageLimitPosRight = 600;
        stageLimitPosLeft = collider->size().x;
        break;
    default:

        stageLimitPosRight = BG::WIDTH - (collider->size().x);
        stageLimitPosLeft = collider->size().x;
        break;
    }


    //if (transform->position().y > stageLimitPosDown)
    //{
    //    transform->setPositionY(stageLimitPosDown);
    //    transform->setSpeedY(0.0f);

    //    obj->actorComponent()->setKabeFlag(true);
    //}




    //if (transform->position().y < stageLimitPosUp)
    //{
    //    transform->setPositionY(stageLimitPosUp);
    //    transform->setSpeedY(0.0f);

    //    obj->actorComponent()->setKabeFlag(true);
    //}


    if (transform->position().x < stageLimitPosLeft)
    {
        transform->setPositionX(stageLimitPosLeft);
        transform->setSpeedX(0.0f);

        obj->actorComponent()->setKabeFlag(true);
    }
    if (transform->position().x /*> BG::WIDTH - collider->size().x || transform->position().x */ > stageLimitPosRight)
    {
        transform->setPositionX(/*BG::WIDTH - collider->size().x*/stageLimitPosRight);
        transform->setSpeedX(0.0f);

        obj->actorComponent()->setKabeFlag(true);
    }


}


BlockPar_UP::BlockPar_UP()
{
    param_.SIZE = { 100 * param_.SCALE.x, 160 * param_.SCALE.y };
    param_.ATTACK_BOX = { -80, -45, 80, 45 };
    param_.SPEED = { 0.0f, 4.0f };
    param_.SPR_BLOCK = &spr_parblock;

}

void BlockPar_UP::update(OBJ2D* obj)
{
    moveY(obj);
}

void BlockPar_UP::calcAttackBox(OBJ2D* obj)
{
    // �U������̌v�Z
    obj->collider()->calcAttackBox(
        getParam()->ATTACK_BOX
    );
}

void BlockPar_UP::hit(OBJ2D* src, OBJ2D* dst)
{
    if (dst->actorComponent()->BlockFlagLeft() || dst->actorComponent()->BlockFlagRight())
    {
        src->transform()->setSpeedY(0.0f);
    }

    //�����v���C���[�A�G���ړ��u���b�N�̏�ɏ���Ă����true�ɂ���
    if (dst->actorComponent()->BlockFlagDo() && dst->actorComponent()->jumpTimer() <= 0)
    {
        if (dst->actorComponent()->BlockFlagDo()) dst->actorComponent()->set_IdoBlockFlagUp(true);
        // if (Game::instance()->bg()->getReverseFlag() && src->actorComponent()->kabeFlag()/*&& Game::instance()->bg()->getScrollY() < 650*/ && Game::instance()->bg()->getScrollY() < Game::instance()->bg()->getSCROLLLIMIT().y) Game::instance()->bg()->addScrollY(1.2f);
        // if (!Game::instance()->bg()->getReverseFlag() &&src->actorComponent()->kabeFlag()) Game::instance()->bg()->addScrollY(-1.2f);
        dst->transform()->setPositionY(src->transform()->getPositionY());

    }


    dst->actorComponent()->setOnGround(true);


}

void BlockPar_UP::moveY(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    BG* bg = obj->bg();
    ActorComponent* actorComp = obj->actorComponent();
    Collider* collider = obj->collider();

    // �ʒu�X�V
    float oldY = transform->position().y;           // �ړ��O�̈ʒu��ێ�
    (Game::instance()->bg()->getReverseFlag()) ? transform->addPositionY(getParam()->SPEED.y) : transform->addPositionY(-getParam()->SPEED.y);
    float deltaY = transform->position().y - oldY;  // �ړ���̈ʒu����ړ��O�̈ʒu������

    actorComp->setOnGround(false);

    // �������̂����蔻��
    if (deltaY > 0)
    {
        if (bg->isFloor(transform->position().x, (transform->position().y), (collider->size().x) / 2))
        {
            // ���ɂ������Ă�����
            bg->mapHoseiDown(obj);    //  �������̕␳����
            actorComp->setOnGround(true);   // �n�ʃt���O

        }
    }

    // ������̂����蔻��
    if (deltaY < 0)
    {
        if (bg->isCeiling(transform->position().x, transform->position().y - (collider->size().y), collider->size().x))
        {
            // �V��ɂ������Ă�����
            bg->mapHoseiUp(obj);
        }
    }

    if (getParam()->SPEED.y <= 0.0f) setParam_speed(VECTOR2(0.0f, 1.0f));
    //actorComp->set_IdoBlockFlagUp(false);


}

void BlockPar_UP::areaCheck(OBJ2D* obj)
{

    Transform* transform = obj->transform();
    //�X�e�[�W���Ƃɐ�����ݒ肷��
    switch (StageSelect::instance()->getNum())
    {

        //case 0:
        //case 1:
    case 2:

        stageLimitPosUp = 500;
        stageLimitPosDown = 1400;

        break;
    case 3:

        stageLimitPosUp = 600;
        stageLimitPosDown = 1000;

        break;

        //case 4:

        //    stageLimitPosRight = 2100;
        //    stageLimitPosLeft = 1600;
        //    break;

    case 5:

        stageLimitPosUp = 1950;
        stageLimitPosDown = 2800;
        break;

        //    //case 6:
        //   // case 7:
    case 8:
        stageLimitPosUp = 500;
        stageLimitPosDown = 1400;
        break;
        /*default:

            stageLimitPosRight = BG::WIDTH - (collider->size().x);
            stageLimitPosLeft = collider->size().x;
            break;*/
    }


    if (transform->position().y > stageLimitPosDown)
    {
        transform->setPositionY(stageLimitPosDown);
        transform->setSpeedY(0.0f);

        obj->actorComponent()->setKabeFlag(true);
    }




    if (transform->position().y < stageLimitPosUp)
    {
        transform->setPositionY(stageLimitPosUp);
        transform->setSpeedY(0.0f);

        obj->actorComponent()->setKabeFlag(true);
    }



}


//������u���b�N
DropBlock::DropBlock()
{
    param_.SIZE = { 256 * param_.SCALE.x, 160 * param_.SCALE.y };
    param_.ATTACK_BOX = { -120, -45, 110, 45 };
    param_.SPEED = { 0.0f, 3.0f };
    param_.SPR_BLOCK = &spr_dropblock;

    color = { 1.0f,1.0f,1.0f,1.0f };

}

void DropBlock::update(OBJ2D* obj)
{
    //��x�U�ꂽ�ꍇ�@�^�C�}�[��+�ɂ���
    if (obj->actorComponent()->DropBlockFlag())obj->actorComponent()->addHitTimer();
    //else obj->actorComponent()->setHitTimer(0);

    //�F�̌����ݒ�

    if (obj->actorComponent()->hitTimer() >= 60 * 5)
    {
        obj->actorComponent()->setAlpha(1.0f);
        obj->actorComponent()->set_DropBlockFlag(false);
        obj->actorComponent()->setHitTimer(0);

    }
    else if (obj->actorComponent()->hitTimer() >= 60 * 3)
    {

        obj->transform()->addPositionY(-getParam()->SPEED.y);


    }
    else if (obj->actorComponent()->hitTimer() >= 60)
    {
        if (obj->actorComponent()->hitTimer() / 20 % 2)obj->actorComponent()->addAlpha(-0.02f);
        moveY(obj);
    }


    if (obj->actorComponent()->alpha() <= 0.9f)
    {
        obj->actorComponent()->setPlayerHit(true);
    }
    else if (obj->actorComponent()->alpha() == 1.0f)
    {
        obj->actorComponent()->setPlayerHit(false);
    }

    color = { 1.0f,1.0f,1.0f,obj->actorComponent()->alpha() };
    obj->renderer()->setColor(color);
}

void DropBlock::calcAttackBox(OBJ2D* obj)
{
    // �U������̌v�Z
    //TODO
    if (!obj->actorComponent()->PlayerHitFlag())
    {
        obj->collider()->calcAttackBox(
            getParam()->ATTACK_BOX
        );

    }

}
//TODO
void DropBlock::hit(OBJ2D* src, OBJ2D* dst)
{


    if (dst->actorComponent()->BlockFlagLeft() || dst->actorComponent()->BlockFlagRight())
    {
        src->transform()->setSpeedY(0.0f);
    }
    
    //�����v���C���[�A�G���ړ��u���b�N�̏�ɏ���Ă����true�ɂ���
    if (dst->actorComponent()->BlockFlagDo() && dst->actorComponent()->jumpTimer() <= 0)
    {
        if (dst->actorComponent()->BlockFlagDo()) dst->actorComponent()->set_IdoBlockFlagUp(true);
        dst->transform()->setPositionY(src->transform()->getPositionY() - 20);
    }


    dst->actorComponent()->setOnGround(true);
    if (dst->transform()->getPositionY() <= src->transform()->getPositionY())
    {
        src->actorComponent()->set_DropBlockFlag(true);
    }
}

void DropBlock::moveY(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    // BG* bg = obj->bg();
    ActorComponent* actorComp = obj->actorComponent();

    // �ʒu�X�V
   // float oldY = transform->position().y;           // �ړ��O�̈ʒu��ێ�
    transform->addPositionY(getParam()->SPEED.y);
    // float deltaY = transform->position().y - oldY;  // �ړ���̈ʒu����ړ��O�̈ʒu������

    actorComp->setOnGround(false);



    if (getParam()->SPEED.y <= 0.0f) setParam_speed(VECTOR2(0.0f, 1.0f));

}

