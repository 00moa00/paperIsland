#include "all.h"

//using
using namespace GameLib;

namespace
{   // ※このデータは長いので、Visual Studioの機能で閉じられるようにnamespaceを分けている

    //------< プレイヤーの弾>------------------------------------------
    //待機
    AnimeData animePlayer_Water[] = {
        { &sprPlayer_attack_water0, 5 },
        { &sprPlayer_attack_water1, 5 },
        { &sprPlayer_attack_water2, 5 },
        { &sprPlayer_attack_water3, 5 },
        { &sprPlayer_attack_water4, 5 },
        { nullptr, -1 },// 終了フラグ
    };

    AnimeData animePlayer_Waterl1[] = {
    { &sprPlayer_attack_water0_l1, 10 },
    { &sprPlayer_attack_water1_l1, 10 },
    { &sprPlayer_attack_water2_l1, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    AnimeData animePlayer_Waterl2[] = {
    { &sprPlayer_attack_water0_l2, 10 },
    { &sprPlayer_attack_water1_l2, 10 },
    { &sprPlayer_attack_water2_l2, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    AnimeData animePlayer_Waterl3[] = {
    { &sprPlayer_attack_water0_l3, 10 },
    { &sprPlayer_attack_water1_l3, 10 },
    { &sprPlayer_attack_water2_l3, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeWater_e[][3] = {
        {
        {&sprPlayer_water_e0, 5},
        {&sprPlayer_water_e1, 5},
        {nullptr, -1}//終了フラグ
        },

        {
        {&sprPlayer_water_e0_l2, 5},
        {&sprPlayer_water_e1_l2, 5},
        {nullptr, -1}//終了フラグ
        },

        {
        {&sprPlayer_water_e0_l3, 5},
        {&sprPlayer_water_e1_l3, 5},
        {nullptr, -1}//終了フラグ
        },

    };


}

void BaseShotBehavior::move(OBJ2D* obj)
{
    using namespace input;

    Transform* tp = Game::instance()->player()->transform();

    obj->collider()->setSize(VECTOR2(40, 50));

    switch (obj->state())
    {
    case 0:
        //////// 初期設定 ////////
        //obj->renderer()->setData(getParam()->SPR_WATER);
        PlayerWeapon::instance()->setShotFlag(true);
        awaFlag = true;  //泡が生成されたらtrue
        BombFlag = false;
        b_animeNum = 0;
        level1 = true;
        level2 = false;
        level3 = false;

        obj->renderer()->setAnimeData(getParam()->SPR_WATER);
        obj->transform()->setScale((tp->scaleX() < 0.0f) ? VECTOR2(-getParam()->SCALE.x, getParam()->SCALE.y) : getParam()->SCALE);
        //obj->setEraser(getParam()->ERASER);
        obj->collider()->setJudgeFlag(true);      // あたり判定を行う
        obj->collider()->setIsDrawHitRect(true);  // あたり判定の領域を描画する（デバッグ用）
        b_timer = 0;  //爆発までの時間(小:10 中:5 大:0)この数値からカウントアップで数えていくから小さい数字の方が生きる時間が長い
        atacck = 1;    //shotの攻撃力

        obj->actorComponent()->setOnGround(true);

        obj->transform()->setSpeedY(0.0f);        // 念のため
        obj->setTimer(0);


        obj->nextState();//state++
        /*fallthrough*/

    case 1:
        //////// 生成時 ////////
        //弾生成中にプレイヤーの座標を反映する

        music::play(SOUND::PLAYER_ATTACK_THROW);
        audio_setVolume_SE(SOUND::PLAYER_ATTACK_THROW, 0.3f);

        obj->transform()->setPosition((tp->scaleX() < 0.0f) ? VECTOR2(-100.0f, -50.0f) + tp->position() : VECTOR2(70.0f, -50.0f) + tp->position());
        // アニメーション更新
        if (obj->renderer()->animeData())
        {

            if (obj->renderer()->animeUpdate())
            {
                if (!(STATE(0) & PAD_TRG2))
                {
                    //下記の関数にtrueが入る事によりプレイヤーのカエルが泡を飛ばすアニメーションとなる
                    Game::instance()->player()->actorComponent()->set_Animation(true);

                    //生成アニメーション終了時に泡の飛ぶ向きを決める
                    // 左右の向き、速度を設定（プレイヤーにもxFlip_の設定が必要）
                    obj->weaponComponent()->copyOwnerXFlip();   // 武器の持ち主のxFlip_を武器に設定する
                    obj->transform()->setSpeedX(
                        obj->weaponComponent()->xFlip()
                        ? -getParam()->SPEED_X : getParam()->SPEED_X);

                    //泡が飛ぶ動きの処理へ移行
                    obj->nextState();//state++
                }


            }
        }

        if (obj->timer() > 30 && obj->timer() < 50)
        {
            obj->renderer()->setAnimeData(getParam()->SPR_WATER_l1);
            level2 = false;
            level3 = false;
            b_animeNum = 0;
        }

        if (obj->timer() > 50 && obj->timer() < 90)
        {
            obj->renderer()->setAnimeData(getParam()->SPR_WATER_l2);
            atacck = 3;
            b_timer = 5;

            level1 = false;
            level2 = true;
            level3 = false;
            b_animeNum = 1;

        }

        else if (obj->timer() > 90)
        {
            obj->renderer()->setAnimeData(getParam()->SPR_WATER_l3);
            atacck = 6;
            b_timer = 10;

            level1 = false;
            level2 = false;
            level3 = true;
            b_animeNum = 2;

        }
        break;

    case 2:

        //////// 通常時 ////////
        update(obj);    // 武器の位置更新
        calcAttackBox(obj);  //当たり判定用数値更新

        break;

    case 3:
        //泡消滅時
        PlayerWeapon::instance()->setShotFlag(false);

        obj->remove();
        // setParamBTimer(25);
        BombFlag = false;
        break;


    }
}

ShotBehavior::ShotBehavior()
{
    param_.SPR_WATER = animePlayer_Water;
    param_.SPR_WATER_l1 = animePlayer_Waterl1;
    param_.SPR_WATER_l2 = animePlayer_Waterl2;
    param_.SPR_WATER_l3 = animePlayer_Waterl3;
    param_.ERASER = &shotEraser;
    param_.SPEED_X = 35.0f;

    param_.B_TIMER = 34;  //秒数
    param_.SCALE = { 1.0f, 1.0f };
    param_.ATTACK_BOX = { -24, -24, 24, -24 };
    b_state = 0;
    awaFlag = true;  //泡が生成されたらtrue
    timer = 0;
}


void ShotBehavior::update(OBJ2D* obj)
{

    if (b_timer / 1 >= getParam()->B_TIMER || GetAwaflag() == false) //爆発処理へ移行
    {
        if (b_anime(obj)) obj->nextState();  //trueが帰ってきたら実行

    }

    else
    {


        moveY(obj);

       if(obj->actorComponent()->onGround()) moveX(obj);
    }


    b_timer++;


}

void ShotBehavior::calcAttackBox(OBJ2D* obj)
{
    // 攻撃判定の計算
    obj->collider()->calcAttackBox(
        getParam()->ATTACK_BOX
    );
}

void ShotBehavior::hit(OBJ2D* src, OBJ2D* dst)
{

    awaFlag = false; //泡が消滅した

        //knockBack処理
        VECTOR2 knockBack = { 25.0f,-7.5f };
        if (dst->transform()->position().x > src->transform()->position().x)
        {
            dst->transform()->addSpeedX(knockBack.x);     //ノックバックの値
            dst->transform()->addSpeedY(knockBack.y);    //ノックバックの値

        }
        else
        {
            dst->transform()->addSpeedX(-knockBack.x);    //ノックバックの値
            dst->transform()->addSpeedY(knockBack.y);    //ノックバックの値

        };


    if (!BombFlag)
    {
        float posX = 0;
        float posY = 0;

        if (StageSelect::instance()->getNum() != 9 && ((StageSelect::instance()->getNum() != 4))) {

            if (StageSelect::instance()->getNum() == 1) {
                 posX = 85;
                 posY = -100;
            }

            if (level1) {
                OBJ2D* damage = Game::instance()->obj2dManager()->add(
                    new OBJ2D(
                        new Renderer,
                        new Collider,
                        dst->bg(),
                        nullptr,
                        new ItemComponent,
                        nullptr
                    ),
                    &enemyDamagelevel1, dst->transform()->position() + VECTOR2(50+posX, -100.0f + posY));
            }

            if (level2) {
                OBJ2D* damage = Game::instance()->obj2dManager()->add(
                    new OBJ2D(
                        new Renderer,
                        new Collider,
                        dst->bg(),
                        nullptr,
                        new ItemComponent,
                        nullptr
                    ),
                    &enemyDamagelevel2, dst->transform()->position() + VECTOR2(50 + posX, -100.0f + posY));
            }

            if (level3) {
                OBJ2D* damage = Game::instance()->obj2dManager()->add(
                    new OBJ2D(
                        new Renderer,
                        new Collider,
                        dst->bg(),
                        nullptr,
                        new ItemComponent,
                        nullptr
                    ),
                    &enemyDamagelevel3, dst->transform()->position() + VECTOR2(50 + posX, -100.0f + posY));
            }
        }

        if (dst->behavior()->getType() != OBJ_TYPE::RUBY)
        {
            dst->actorComponent()->subHp(atacck);
        }
        //うさぎブロックを壊す用の処理
        else
        {
            if (dst->actorComponent() != nullptr)
                dst->actorComponent()->addHp(-atacck);
        }


        if (StageSelect::instance()->getNum() == 9) {
            Ch1boss::instance()->SupBosshp(atacck);
        }

        if (StageSelect::instance()->getNum() == 4 ) {
            Midboss::instance()->SupBosshp(atacck);
        }
    }


    // EnemyDamage* damage = Game::instance()->enemyDamage()->init({ dst->transform()->getPositionX(), dst->transform()->getPositionY() }, { 1,1 });


}

void ShotBehavior::moveX(OBJ2D* obj)
{
    //obj->transform()->update(obj);

    Transform* transform = obj->transform();
    BG* bg = obj->bg();
    Collider* collider = obj->collider();


    // X方向移動
    float oldX = transform->position().x;
    transform->addPositionX(transform->speed().x);
    float deltaX = transform->position().x - oldX;

    //bool kabeFlag = false;  // 壁フラグをfalseにしておく（プレイヤーでは使用しない）

    // 右方向あたり判定
    if (deltaX > 0)
    {
        if (bg->isWall(transform->position().x + collider->size().x,
            transform->position().y, collider->size().y))
        {
            bg->mapHoseiRight(obj);     // 右方向の補正処理
            //obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;                    // 壁フラグをtrueにしておく
        }

    }

    // 左方向あたり判定
    if (deltaX < 0)
    {
        if (bg->isWall(transform->position().x - collider->size().x,
            transform->position().y, collider->size().y))
        {
            bg->mapHoseiLeft(obj);
            //obj->actorComponent()->setKabeFlag(true);
            //kabeFlag = true;
        }
    }
}

void ShotBehavior::moveY(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    BG* bg = obj->bg();
    ActorComponent* actorComp = obj->actorComponent();
    Collider* collider = obj->collider();


    // 最大速度制限
    transform->setSpeedY(clamp(transform->speed().y, -50.0f, 50.0f));

    actorComp->setOnGround(true);


    //床に当たっていない
    if (!bg->isFloor(transform->position().x, transform->position().y + 50, collider->size().x))
    {
        obj->actorComponent()->setOnGround(false);
        transform->addPositionX(obj->weaponComponent()->xFlip()
            ? -4.0f : 4.0f);
        actorComp->setOnGround(false);

        transform->addPositionY(12.0f);
    }

    // if (actorComp->onGround() == false) { transform->addSpeedX(+ 5.0); }
}

bool ShotBehavior::b_anime(OBJ2D* obj)
{
    Renderer* renderer = obj->renderer();

    switch (b_state)
    {
    case 0:
        BombFlag = true;
        music::play(SOUND::PLAYER_ATTACK_BOMB);
        audio_setVolume_SE(SOUND::PLAYER_ATTACK_BOMB, 1.0f);


        oldBombTimer = 0;
        oldBombTimer = obj->timer();
        outBombTimer_Throw = oldBombTimer + 5;
        b_state++;

        //fallthrouh//

    case 1:
        if (oldBombTimer < outBombTimer_Throw)
        {
            renderer->setAnimeData(animeWater_e[b_animeNum]); //泡が消滅のアニメーション
            renderer->animeUpdate();

            // renderer->addColor_a(-0.01f);
        }

        else
        {
            //泡の消滅処理
            b_state = 0;
            //awaFlag = true;
            return true;
        }
        oldBombTimer++;

        break;


    }

    return false;

}

void ShotEraser::erase(OBJ2D* obj)
{
    const VECTOR2* scrollPos = &obj->bg()->getScrollPos();
    const VECTOR2* size = &obj->collider()->size();
    const VECTOR2* pos = &obj->transform()->position();

    const float leftLimit = scrollPos->x - size->x;
    const float rightLimit = scrollPos->x + Game::instance()->bg()->CLIENT_W + size->x;
    const float topLimit = scrollPos->y - size->y;
    const float bottomLimit = scrollPos->y + Game::instance()->bg()->CLIENT_H + size->y;

    if (pos->x < leftLimit ||
        pos->x > rightLimit ||
        pos->y < topLimit ||
        pos->y > bottomLimit)
    {
        obj->remove();
    }
}
