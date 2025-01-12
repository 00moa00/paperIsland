#include "all.h"
using namespace GameLib;

void ActorBehavior::move(OBJ2D* obj)
{
    obj->renderer()->setAnimeData(nullptr);

    switch (obj->state())
    {
    case 0: {
        //////// 初期設定 ////////
        // アニメの初期設定
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
        //////// 通常時 ////////

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

    // アニメーション更新
    if (obj->renderer()->animeData())
        obj->renderer()->animeUpdate();
}

void ActorBehavior::moveY(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    BG* bg = obj->bg();
    ActorComponent* actorComp = obj->actorComponent();
    Collider* collider = obj->collider();

    // Y方向の抗力の計算
   // transform->addSpeedY(bg->calcResistance(obj, transform->speed().y));

    // 最大速度制限
    transform->setSpeedY(clamp(transform->speed().y, -getParam()->SPEED_Y_MAX, getParam()->SPEED_Y_MAX));


    //移動ブロックの上に乗っている場合、移動ブロックのスピードに合わせてプレイヤーのポジションも変わる
    //if (actorComp->IdoBlockFlagUp())
    //{
       // transform->setPositionY(Game::instance()->moveBlock()->getPosition());

    //}

    // 位置更新
    float oldY = transform->position().y;           // 移動前の位置を保持
    transform->addPositionY(transform->speed().y);
    float deltaY = transform->position().y - oldY;  // 移動後の位置から移動前の位置を引く

    actorComp->setOnGround(false);

    // 下方向のあたり判定
    if (deltaY > 0)
    {
        if (bg->isFloor(transform->position().x, (transform->position().y), (collider->size().x) / 2) || actorComp->BlockFlagDo())
        {
            // 床にあたっていたら
            bg->mapHoseiDown(obj);    //  下方向の補正処理
            actorComp->setOnGround(true);   // 地面フラグ

        }
    }

    // 上方向のあたり判定
    if (deltaY < 0)
    {
        if (bg->isCeiling(transform->position().x, transform->position().y - (collider->size().y), collider->size().x))
        {
            // 天井にあたっていたら
            bg->mapHoseiUp(obj);
            actorComp->setJumpTimer(0);
        }
    }

    //game.cppにてupdate(),juge()の順番で処理される。juge()の時にflagが入るから上記のifを通るときには判定によってBlocFlagDoの数値が決定している
    //毎フレーム数値は変わるので判定が終わるともう一度リセットする。判定が終わる前にリセットするとずっと同じ数値で判定されるのでダメ
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

    // X方向の抗力の計算
   // transform->addSpeedX(bg->calcResistance(obj, transform->speed().x));

    // 最大速度チェック
    if (transform->speed().x > getParam()->SPEED_X_MAX)
        transform->setSpeedX(getParam()->SPEED_X_MAX);
    if (transform->speed().x < -getParam()->SPEED_X_MAX)
        transform->setSpeedX(-getParam()->SPEED_X_MAX);

    //移動ブロックの上に乗っている場合、移動ブロックのスピードに合わせてプレイヤーのポジションも変わる
    //if (actorComp->IdoBlockFlag())
    //{
    //    float idoBlock_speed = (Game::instance()->bg()->getReverseFlag()) ? 4.0f : -4.0f;
    //    transform->addPositionX(idoBlock_speed);
    //}

    // X方向移動
    float oldX = transform->position().x;
    transform->addPositionX(transform->speed().x);
    float deltaX = transform->position().x - oldX;

    //bool kabeFlag = false;  // 壁フラグをfalseにしておく（プレイヤーでは使用しない）

    // 右方向あたり判定
    if (deltaX > 0)
    {
        if (bg->isWall(transform->position().x + collider->size().x,
            transform->position().y, collider->size().y) || actorComp->BlockFlagRight())
        {
            bg->mapHoseiRight(obj);     // 右方向の補正処理
            obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;                    // 壁フラグをtrueにしておく
        }
    }

    // 左方向あたり判定
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

    const float LIMIT = 512.0f; // 世界の下端からこの数値分落ちたら消す
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

    if (dst->actorComponent()->hitTimer() >= 120)//無敵時間
    {
    dst->actorComponent()->setHitAnimeTimer(18);    //アニメ表示時間を1秒に設定
        if (dst->transform()->position().x > src->transform()->position().x)
        {
            dst->transform()->addSpeedX(knockBack.x);     //ノックバックの値
            dst->transform()->addSpeedY(knockBack.y);    //ノックバックの値

        }
        else
        {
            dst->transform()->addSpeedX(-knockBack.x);    //ノックバックの値
            dst->transform()->addSpeedY(knockBack.y);    //ノックバックの値
        }
        dst->actorComponent()->setHitTimer(0);

        HP::instance()->SubHp(damage);

        GameLib::music::play(SOUND::PLAYER_HIT);
        audio_setVolume_SE(SOUND::PLAYER_HIT, 1.0f);
        dst->actorComponent()->setIsHitAnime(true);

    }
}
