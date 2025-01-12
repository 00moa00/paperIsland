//******************************************************************************
//
//
//      �v���C���[�N���X
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

PlayerWeapon PlayerWeapon::instance_;
PlayerJumpState PlayerJumpState::instance_;
//------< using >---------------------------------------------------------------
using namespace GameLib;

//******************************************************************************
//
//      �v���C���[�ړ�����
//
//******************************************************************************

//------< �v���C���[�̃A�j���f�[�^ >----------------------------------------------
namespace
{   // �����̃f�[�^�͒����̂ŁAVisual Studio�̋@�\�ŕ�����悤��namespace�𕪂��Ă���

    //------< �v���C���[�̃A�j���f�[�^ >------------------------------------------
    //�ҋ@
    AnimeData animePlayer_Wait[] = {
        { &sprPlayer_Wait0, 10 },
        { &sprPlayer_Wait1, 10 },
        { &sprPlayer_Wait2, 10 },
        { &sprPlayer_Wait3, 10 },
        { &sprPlayer_Wait4, 10 },
        { &sprPlayer_Wait5, 10 },
        { &sprPlayer_Wait6, 10 },
        { &sprPlayer_Wait7, 10 },
        { nullptr, -1 },// �I���t���O
    };


    //�����
    //AnimeData animePlayer_Up[] = {
    //    { &sprPlayer_Up0, 10 },
    //    { &sprPlayer_Up1, 10 },
    //    { &sprPlayer_Up2, 10 },
    //    { &sprPlayer_Up1, 10 },
    //    { nullptr, -1 },// �I���t���O
    //};
    //�E���� //0~11
    AnimeData animePlayer_Right[] = {
        { &sprPlayer_Right0, 10 },
        { &sprPlayer_Right1, 10 },
        { &sprPlayer_Right2, 10 },
        { &sprPlayer_Right3, 10 },
        { &sprPlayer_Right4, 10 },
        { &sprPlayer_Right5, 10 },
        { &sprPlayer_Right6, 10 },
        { &sprPlayer_Right7, 10 },
        { nullptr, -1 },// �I���t���O
    };
    //������
    //AnimeData animePlayer_Down[] = {
    //    { &sprPlayer_Down0, 10 },
    //    { &sprPlayer_Down1, 10 },
    //    { &sprPlayer_Down2, 10 },
    //    { &sprPlayer_Down1, 10 },
    //    { nullptr, -1 },// �I���t���O
    //};
    //�W�����v
    AnimeData animePlayer_Jump[] = {
        { &sprPlayer_Jump0, 100},
        { &sprPlayer_Jump0, 100 },
        { &sprPlayer_Jump0, 100 },
        { &sprPlayer_Jump0, 100 },
        { &sprPlayer_Jump0, 100 },

        { nullptr, -1 },// �I���t���O
    };

    //�U��(���)
    AnimeData animePlayer_Attack_Make[] = {
       { &sprPlayer_attack_make0, 5 },
       { &sprPlayer_attack_make1, 5 },
       { &sprPlayer_attack_make2, 50 },
       { &sprPlayer_attack_make0, 10 },
       { &sprPlayer_attack_make2, 50 },
       { &sprPlayer_attack_make0, 10 },
       { &sprPlayer_attack_make2, 300 },

      // { &sprPlayer_attack_make3, 5 },
       //{ &sprPlayer_attack_make4, 5 },
       //{ &sprPlayer_Wait0, 10 },
       //{ &sprPlayer_Wait0, 10 },

       //{ &sprPlayer_Wait0, 10 },

       { nullptr, -1 },// �I���t���O
    };

    //�U��(����)
    AnimeData animePlayer_Attack_Throw[] = {
      { &sprPlayer_attack_make3, 5 },

      { &sprPlayer_attack_throw0, 5 },
      { &sprPlayer_attack_throw1, 5 },
      { &sprPlayer_attack_throw2, 5 },
      { &sprPlayer_attack_throw3, 5 },
      { &sprPlayer_attack_throw4, 5 },
      { &sprPlayer_Wait0, 10 },
       { &sprPlayer_Wait0, 10 },
       { &sprPlayer_Wait0, 10 },
      { nullptr, -1 },// �I���t���O
    };

    AnimeData animePlayer_Hit[] = {
     { &sprPlayer_hit0, 10 },
     { nullptr, -1 },// �I���t���O
    };

    //gameover
    AnimeData animePlayer_Over[] = {
      { &animePlayer_Over0, 10 },
      { &animePlayer_Over1, 10 },
      { &animePlayer_Over2, 10 },
      { &animePlayer_Over3, 10 },
      { &animePlayer_Over4, 10 },
      { &animePlayer_Over5, 10 },
      { &animePlayer_Over6, 10 },
      { &animePlayer_Over7, 10 },
      { &animePlayer_Over8, 10 },
      { &animePlayer_Over9, 10 },
      { &animePlayer_Over10, 10 },
      { &animePlayer_Over11, 10 },
      { &animePlayer_Over11, 40 },
      { &animePlayer_Over11, 40 },
      { &animePlayer_Over11, 40 },
      { &animePlayer_Over11, 40 },
      { &animePlayer_Over11, 40 },
      { &animePlayer_Over11, 40 },
      { &animePlayer_Over11, 40 },


      { nullptr, -1 },// �I���t���O
    };

}

//******************************************************************************
//
//      BasePlayerBehavior
//
//******************************************************************************

void BasePlayerBehavior::moveX(OBJ2D* obj)
{
// Collider* collider = obj->collider();
Transform* transform = obj->transform();
Renderer* renderer = obj->renderer();
ActorComponent* actor = obj->actorComponent();


        //stage�̐؂�ւ��̎��Ɉړ�����
    if (!Game::instance()->stageTrans()->getActorFlag()) {

       // renderer->setAnimeData(getParam()->ANIME_WAIT);
        transform->setSpeedX(1.6f);
        transform->addSpeedX(getParam()->ACCEL_X);
        renderer->setAnimeData(getParam()->ANIME_RIGHT);
        transform->FlipX(false);
        obj->actorComponent()->setXFlip(false);

        PlayerWeapon::instance()->SethasWeapon(false);
        PlayerJumpState::instance()->SetPlayerJump(false);

        ActorBehavior::moveX(obj);
        return;


    }


    if (!attackflag && Game::instance()->stageTrans()->getActorFlag()) // �U�����I���܂ł͓����Ȃ�
    {
        renderer->setAnimeData(getParam()->ANIME_WAIT);

        // ���E���͂̎��o��
        using namespace input;

        //�X�e�[�W�U�̌㔼�̓L�[���͂��󂯕t���Ȃ�
        if (StageSelect::instance()->getNum() == 10 && transform->getPositionX() > 1000)
        {
            //�ړ���A�j���͉E���s�ŌŒ�
            transform->setSpeedX(1.6f);
            transform->addSpeedX(getParam()->ACCEL_X);
            renderer->setAnimeData(getParam()->ANIME_RIGHT);
            transform->FlipX(false);
            obj->actorComponent()->setXFlip(false);

            //�����W�����v�̃A�N�V����������
            PlayerWeapon::instance()->SethasWeapon(false);
            PlayerJumpState::instance()->SetPlayerJump(false);

            ActorBehavior::moveX(obj);
            return;

        }

        int input = STATE(0) & (PAD_LEFT | PAD_RIGHT);
        if (getPadState(0)->leftX < -0.3f)
            input = PAD_LEFT;
        if (getPadState(0)->leftX > 0.3f)
            input = PAD_RIGHT;
        switch (input)
        {
        case PAD_LEFT:  // ��������������Ă���ꍇ
            if (!actor->WalkFlag() && actor->onGround()) {

                music::play(SOUND::PLAYER_WALK, true);
                actor->setWalkFlag(true);
            }
            transform->addSpeedX(-getParam()->ACCEL_X);
            renderer->setAnimeData(getParam()->ANIME_RIGHT);
            transform->FlipX(true);

            obj->actorComponent()->setXFlip(true);
            Game::instance()->paper()->setPaperFlag(false);
            break;


        case PAD_RIGHT: // �E������������Ă���ꍇ    
            if (!actor->WalkFlag() && actor->onGround()) {
                music::play(SOUND::PLAYER_WALK, true);
                actor->setWalkFlag(true);
            }

            transform->addSpeedX(getParam()->ACCEL_X);
            renderer->setAnimeData(getParam()->ANIME_RIGHT);
            transform->FlipX(false);

            obj->actorComponent()->setXFlip(false);
            Game::instance()->paper()->setPaperFlag(false);
            break;


        default:        // �ǂ����������Ă��Ȃ������E����Ă���ꍇ
            //renderer->setAnimeData(getParam()->ANIME_RIGHT);
            //music::stop(SOUND::PLAYER_WALK);
            if (actor->WalkFlag() || !actor->onGround()) {
                music::stop(SOUND::PLAYER_WALK);
                actor->setWalkFlag(false);
            }


            if (transform->speed().x > 0)
            {
                transform->addSpeedX(-getParam()->ACCEL_X / 2);
                if (transform->speed().x < 0) transform->setSpeedX(0.0f);
            }
            if (transform->speed().x < 0)
            {
                transform->addSpeedX(getParam()->ACCEL_X / 2);
                if (transform->speed().x > 0) transform->setSpeedX(0.0f);
            }
            break;
        }

        //debug::setString("player hasSword:%d", obj->actorComponent()->hasSword());
        //debug::setString("player posX:%f", obj->transform()->getPositionX());

        ActorBehavior::moveX(obj);
    }









    if (actor->onGround() || !attackflag) {
        //music::setVolume(SOUND::PLAYER_WALK, 0.2f);
        audio_setVolume_SE(SOUND::PLAYER_WALK, 0.2f);

    }
    if (!actor->onGround() || attackflag) {
        //music::setVolume(SOUND::PLAYER_WALK, 0.0f);
        audio_setVolume_SE(SOUND::PLAYER_WALK, 0.0f);
    }

    music::setPitch(SOUND::PLAYER_WALK, 0.5f);
   
}



bool BasePlayerBehavior::isAlive(OBJ2D* obj)
{
    UNREFERENCED_PARAMETER(obj);

    Renderer* renderer = obj->renderer();
    ActorComponent* actorComponent = obj->actorComponent();

    //int oldHp = Game::instance()->GetHp();

    actorComponent->addHitTimer();

    if (animeTimer > 140)//���Z�b�g
    {
        animeTimer = 0;
        //Game::instace()-> changeScene(GameLoading::instance());//gameover�Ɉڍs
        renderer->setAnimeData(getParam()->ANIME_WAIT);

        attackflag = false;
        oldAttackTimer = 0;
        outAttackTimer_Throw = 0;
        outAttackTimer_Make = 0;
        make_ani = false;

        //obj->renderer()->setColor_a(0.0f);

        //hp�Z�[�u�̂���
        Restart::instance()->SetRestart(true);

        //�O�_�̃A�j��state
        Game::instance()->stageTrans()->setState(2);
        //Game::instance()->restart();


    }

    if (HP::instance()->GetHp() <= 0)
    {
        animeTimer++;
        music::stop(SOUND::PLAYER_WALK);
        renderer->setAnimeData(getParam()->ANIME_OVER);
        Game::instance()->player()->actorComponent()->setPlayerMove(false);

        return false;
    }
    else return true;    // ����
}

//******************************************************************************
//
//      WalkPlayerBehavior
//
//******************************************************************************

WalkPlayerBehavior::WalkPlayerBehavior() {
    // �A�j���[�V����
    param_.ANIME_WAIT = animePlayer_Wait;
    //param_.ANIME_UP     = animePlayer_Up;
    param_.ANIME_RIGHT = animePlayer_Right;
    //param_.ANIME_DOWN   = animePlayer_Down;
    //param_.ANIME_LEFT   = animePlayer_Left;
    param_.ANIME_HIT = animePlayer_Hit;

    param_.ANIME_ATTACK_MAKE = animePlayer_Attack_Make;
    param_.ANIME_ATTACK_THROW = animePlayer_Attack_Throw;

    param_.ANIME_OVER = animePlayer_Over;


    param_.SIZE = VECTOR2(45 / 2, 172);
    param_.SCALE = VECTOR2(1, 1);
    //param_.HIT_BOX = { -20, -104, 20, -20 };
    param_.HIT_BOX = { -45, -172, 45, 0 };


    // ���x�֘A�̃p�����[�^
    param_.ACCEL_X = 1.0f;
    param_.ACCEL_Y = 1.0f;
    param_.SPEED_X_MAX = 5.0f;
    param_.SPEED_Y_MAX = 16.0f;
    param_.JUMP_POWER_Y = -20;

    attackflag = false;
    oldAttackTimer = 0;
    outAttackTimer_Throw = 0;
    outAttackTimer_Make = 0;
    make_ani = false;

    //param_.HP = 5;

}
void WalkPlayerBehavior::moveY(OBJ2D* obj)
{
    param_.ANIME_JUMP = animePlayer_Jump;

    Transform* transform = obj->transform();

    // ���x�ɉ����x��������
    transform->addSpeedY(getParam()->ACCEL_Y);

    ActorBehavior::moveY(obj);
}

void WalkPlayerBehavior::jump(OBJ2D* obj)
{
    Transform* transform = obj->transform();
    ActorComponent* actorComp = obj->actorComponent();
    Renderer* renderer = obj->renderer();

    //BG* bg = obj->bg();



    // �v���C���[��onground�ł͂Ȃ��ꍇ�̃A�j���[�V�����ݒ�
    if (!actorComp->onGround())
    {
        renderer->setAnimeData(getParam()->ANIME_JUMP);
    }

    // �W�����v�`�F�b�N
    using namespace input;


    if (Game::instance()->stageTrans()->getActorFlag()) {
        //if (TRG(0) & PAD_SPACE)
        if (TRG(0) & PAD_UP)
        {
            Game::instance()->paper()->setPaperFlag(false);

            // music::setVolume(SOUND::PLAYER_WALK,0.0f);

            if (actorComp->onGround() && PlayerJumpState::instance()->GetPlayerJump())
            {
                music::play(SOUND::PLAYER_JUMP);
                audio_setVolume_SE(SOUND::PLAYER_JUMP, 1.0f);

                actorComp->setJumpTimer(13);
            }
        }

        // actorComp->setIsJump(false);

     // �W�����v��
        if (actorComp->jumpTimer() > 0)
        {
            //if (STATE(0) & PAD_SPACE)
            if (STATE(0) & PAD_UP)
            {   // PAD_TRG1��������Ă���ꍇ
              //  actorComp->setIsJump(true);

                renderer->setAnimeData(getParam()->ANIME_JUMP);
                transform->setSpeedY(getParam()->JUMP_POWER_Y);
                actorComp->addJumpTimer(-1);

            }
            else
            {   // PAD_TRG1��������Ă��Ȃ��ꍇ

                actorComp->setJumpTimer(0);

            }
        }
    }
    hitAnime(obj);


}

void WalkPlayerBehavior::attack(OBJ2D* obj)
{
    Renderer* renderer = obj->renderer();
    //�e�̔������������߂�ϐ�
    VECTOR2 flip = obj->transform()->scaleX() > 0.0f ? VECTOR2(-0.5, 0.5f) : VECTOR2(-0.5f, 0.5f);
    using namespace input;

    //C�L�[�ɂĒe����
    if (TRG(0) & PAD_TRG2 &&
        obj->actorComponent()->attackTimer() <= 0 &&
        PlayerWeapon::instance()->GethasWeapon() && Game::instance()->stageTrans()->getActorFlag() 
        && !PlayerWeapon::instance()->getShotFlag())
    {
        Game::instance()->paper()->setPaperFlag(false);

        music::play(SOUND::PLAYER_ATTACK);
        audio_setVolume_SE(SOUND::PLAYER_ATTACK, 1.0f);

        attackflag = true;

        //�U���̃��[�V�����Ɏg�p
        oldAttackTimer = 0;
        oldAttackTimer = obj->timer();
        outAttackTimer_Throw = oldAttackTimer + 25;

        const VECTOR2 pos = obj->transform()->position() + VECTOR2(70.0f, -50.0f);

        
            OBJ2D* shuriken = Game::instance()->obj2dManager()->add(
                new OBJ2D(
                    new Renderer,
                    new Collider,
                    obj->bg(),
                    new ActorComponent,
                    nullptr,
                    new WeaponComponent
                ),
                &shotBehavior, pos);
            shuriken->weaponComponent()->setOwner(obj);
            make_ani = true;
        

        obj->actorComponent()->setAttackTimer(25);  //�J�G���̃A�j���[�V�������o�O��Ȃ��悤�ɑҋ@���Ԃ�݂���
    }

    //�A���Ƃ��p�̃A�j���[�V����if��
    if (make_ani && !obj->actorComponent()->K_Animationflag())
        renderer->setAnimeData(getParam()->ANIME_ATTACK_MAKE); //�U��(����)

    //�J�G�����A���΂��A�j���[�V�����pif��
    if (obj->actorComponent()->K_Animationflag())
    {
        K_Animation(obj);
        make_ani = false;
    }

}

void WalkPlayerBehavior::K_Animation(OBJ2D* obj)
{


    Renderer* renderer = obj->renderer();

    //�U�����[�V�����Ɏg�p(timer)
    oldAttackTimer++;


    obj->actorComponent()->subAttackTimer(1);


    if (oldAttackTimer < outAttackTimer_Throw)
    {

        renderer->setAnimeData(getParam()->ANIME_ATTACK_THROW); //�U��(����)
    }
    else if (oldAttackTimer >= outAttackTimer_Throw)
    {
        obj->actorComponent()->set_Animation(false);
        attackflag = false;

    }
}


void WalkPlayerBehavior::hitAnime(OBJ2D* obj)
{
    Renderer* renderer = obj->renderer();
    ActorComponent* actor = obj->actorComponent();

    if (actor->isHitAnime())
    {
        //PlayerHit�֐��Őݒ肵�����Ԃ���f�N�������g����0�ɂȂ�܂ł̂������A��e�A�j���[�V������\������
        if (actor->hitAnimeTimer() > 0)
        {
            renderer->setAnimeData(getParam()->ANIME_HIT);
        }
        actor->decHitAnimeTimer();          //��e�A�j���^�C�}�[�̃f�N�������g

    }
    if (actor->isHitAnime() && actor->hitAnimeTimer() <= 0) actor->setIsHitAnime(false);
    if (actor->hitAnimeTimer() < -10) actor->setHitAnimeTimer(0);   //��e�A�j���^�C�}�[�̃��Z�b�g


}

//--------------------------------------------------------------
//  ����
//--------------------------------------------------------------
void ErasePlayer::erase(OBJ2D* obj)
{
    obj->setBehavior(nullptr);
}



//void playerHit(OBJ2D* src, OBJ2D* dst, int damage)
//{
//
//    //dst->actorComponent()->addHitTimer();
//    if (Game::instance()->GetHp() <= 0) return;
//
//    VECTOR2 knockBack = { 20.0f,-30.5f };
//
//    if (dst->actorComponent()->hitTimer() >= 120)//���G����
//    {
//
//        if (dst->transform()->position().x > src->transform()->position().x)
//        {
//            dst->transform()->addSpeedX(knockBack.x);     //�m�b�N�o�b�N�̒l
//            dst->transform()->addSpeedY(knockBack.y);    //�m�b�N�o�b�N�̒l
//        }
//        else
//        {
//            dst->transform()->addSpeedX(-knockBack.x);    //�m�b�N�o�b�N�̒l
//            dst->transform()->addSpeedY(knockBack.y);    //�m�b�N�o�b�N�̒l
//
//        }
//        dst->actorComponent()->setHitTimer(0);
//
//       Game::instance()->SubHp(damage);
//        GameLib::music::play(SOUND::PLAYER_HIT);
//
//    }
//
//   
//}
