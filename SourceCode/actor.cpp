#include "all.h"
using namespace GameLib;

void ActorBehavior::move(OBJ2D* obj)
{
    obj->renderer()->setAnimeData(nullptr);

    switch (obj->state())
    {
    case 0: {
        //////// �����ݒ� ////////
        // �A�j���̏����ݒ�
        obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);

        obj->transform()->setScale(getParam()->SCALE);
        const VECTOR2 size = {
            getParam()->SIZE.x * getParam()->SCALE.x,
            getParam()->SIZE.y * getParam()->SCALE.y,
        };
        obj->collider()->setSize(size);
        obj->collider()->setJudgeFlag(true);
        obj->collider()->setIsDrawHitRect(true);

        obj->actorComponent()->setHp(getParam()->HP);

        obj->nextState();//state_++
        break;
    }

    case 1:
        //////// �ʏ펞 ////////

        if (isAlive(obj) == false)
            break;

        moveY(obj);
        moveX(obj);
        jump(obj);
        hashigo(obj);
        areaCheck(obj);
        turn(obj);
        attack(obj);
        moveHp(obj);
        break;
    }

    obj->collider()->calcHitBox(getParam()->HIT_BOX);

    // �A�j���[�V�����X�V
    if (obj->renderer()->animeData())
        obj->renderer()->animeUpdate();
}

void ActorBehavior::moveY(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    BG* bg = obj->bg();
    ActorComponent* actorComp = obj->actorComponent();
    Collider* collider = obj->collider();

    // Y�����̍R�͂̌v�Z
   // transform->addSpeedY(bg->calcResistance(obj, transform->speed().y));

    // �ő呬�x����
    transform->setSpeedY(clamp(transform->speed().y, -getParam()->SPEED_Y_MAX, getParam()->SPEED_Y_MAX));


    //�ړ��u���b�N�̏�ɏ���Ă���ꍇ�A�ړ��u���b�N�̃X�s�[�h�ɍ��킹�ăv���C���[�̃|�W�V�������ς��
    //if (actorComp->IdoBlockFlagUp())
    //{
       // transform->setPositionY(Game::instance()->moveBlock()->getPosition());

    //}

    // �ʒu�X�V
    float oldY = transform->position().y;           // �ړ��O�̈ʒu��ێ�
    transform->addPositionY(transform->speed().y);
    float deltaY = transform->position().y - oldY;  // �ړ���̈ʒu����ړ��O�̈ʒu������

    actorComp->setOnGround(false);

    // �������̂����蔻��
    if (deltaY > 0)
    {
        if (bg->isFloor(transform->position().x, (transform->position().y), (collider->size().x) / 2) || actorComp->BlockFlagDo())
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
            actorComp->setJumpTimer(0);
        }
    }

    //game.cpp�ɂ�update(),juge()�̏��Ԃŏ��������Bjuge()�̎���flag�����邩���L��if��ʂ�Ƃ��ɂ͔���ɂ����BlocFlagDo�̐��l�����肵�Ă���
    //���t���[�����l�͕ς��̂Ŕ��肪�I���Ƃ�����x���Z�b�g����B���肪�I���O�Ƀ��Z�b�g����Ƃ����Ɠ������l�Ŕ��肳���̂Ń_��
    actorComp->set_BlockFlagDo(false);
    actorComp->set_BlockFlagUp(false);
    actorComp->set_IdoBlockFlagUp(false);

}

void ActorBehavior::moveX(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    BG* bg = obj->bg();
    ActorComponent* actorComp = obj->actorComponent();
    Collider* collider = obj->collider();

    // X�����̍R�͂̌v�Z
   // transform->addSpeedX(bg->calcResistance(obj, transform->speed().x));

    // �ő呬�x�`�F�b�N
    if (transform->speed().x > getParam()->SPEED_X_MAX)
        transform->setSpeedX(getParam()->SPEED_X_MAX);
    if (transform->speed().x < -getParam()->SPEED_X_MAX)
        transform->setSpeedX(-getParam()->SPEED_X_MAX);

    //�ړ��u���b�N�̏�ɏ���Ă���ꍇ�A�ړ��u���b�N�̃X�s�[�h�ɍ��킹�ăv���C���[�̃|�W�V�������ς��
    //if (actorComp->IdoBlockFlag())
    //{
    //    float idoBlock_speed = (Game::instance()->bg()->getReverseFlag()) ? 4.0f : -4.0f;
    //    transform->addPositionX(idoBlock_speed);
    //}

    // X�����ړ�
    float oldX = transform->position().x;
    transform->addPositionX(transform->speed().x);
    float deltaX = transform->position().x - oldX;

    //bool kabeFlag = false;  // �ǃt���O��false�ɂ��Ă����i�v���C���[�ł͎g�p���Ȃ��j

    // �E���������蔻��
    if (deltaX > 0)
    {
        if (bg->isWall(transform->position().x + collider->size().x,
            transform->position().y, collider->size().y) || actorComp->BlockFlagRight())
        {
            bg->mapHoseiRight(obj);     // �E�����̕␳����
            obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;                    // �ǃt���O��true�ɂ��Ă���
        }
    }

    // �����������蔻��
    if (deltaX < 0)
    {
        if (bg->isWall(transform->position().x - collider->size().x,
            transform->position().y, collider->size().y) || actorComp->BlockFlagLeft())
        {
            bg->mapHoseiLeft(obj);
            obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;
        }
    }

    actorComp->set_BlockFlagRight(false);
    actorComp->set_BlockFlagLeft(false);
    actorComp->set_IdoBlockFlag(false);
}

void ActorBehavior::areaCheck(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    Collider* collider = obj->collider();

    const float LIMIT = 512.0f; // ���E�̉��[���炱�̐��l�������������
    if (transform->position().y > Game::instance()->bg()->HEIGHT + LIMIT)
    {
        obj->remove();
        return;
    }

    if (transform->position().x < 0 + collider->size().x)
    {
        transform->setPositionX(collider->size().x);
        transform->setSpeedX(0.0f);

        obj->actorComponent()->setKabeFlag(true);
    }
    if (transform->position().x > Game::instance()->bg()->WIDTH - collider->size().x)
    {
        transform->setPositionX(Game::instance()->bg()->WIDTH - collider->size().x);
        transform->setSpeedX(0.0f);

        obj->actorComponent()->setKabeFlag(true);
    }
}



void ActorBehavior::playerHit(OBJ2D* src, OBJ2D* dst, int damage)
{


    //dst->actorComponent()->addHitTimer();
    if (HP::instance()->GetHp() <= 0 || Restart::instance()->GetRestart()) return;

    VECTOR2 knockBack = { 20.0f,-30.5f };

    if (dst->actorComponent()->hitTimer() >= 120)//���G����
    {
    dst->actorComponent()->setHitAnimeTimer(18);    //�A�j���\�����Ԃ�1�b�ɐݒ�
        if (dst->transform()->position().x > src->transform()->position().x)
        {
            dst->transform()->addSpeedX(knockBack.x);     //�m�b�N�o�b�N�̒l
            dst->transform()->addSpeedY(knockBack.y);    //�m�b�N�o�b�N�̒l

        }
        else
        {
            dst->transform()->addSpeedX(-knockBack.x);    //�m�b�N�o�b�N�̒l
            dst->transform()->addSpeedY(knockBack.y);    //�m�b�N�o�b�N�̒l
        }
        dst->actorComponent()->setHitTimer(0);

        HP::instance()->SubHp(damage);

        GameLib::music::play(SOUND::PLAYER_HIT);
        audio_setVolume_SE(SOUND::PLAYER_HIT, 1.0f);
        dst->actorComponent()->setIsHitAnime(true);

    }
}
