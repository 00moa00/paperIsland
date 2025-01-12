//******************************************************************************
//
//
//      �Q�[��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"
#include "game.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Game Game::instance_;
PlayerClear PlayerClear::instance_;
Restart Restart::instance_;
HP HP::instance_;
Midboss Midboss::instance_;
//StageTrans StageTrans::instance_;

//BossScript bossScript;

int          Game::VolumeSelect_[2] = { 2,2 };


Game::~Game()
{

    //ofSavedata.open("playerHpSave.dat", std::ios::in);

    //ofSavedata << player_HP;

    //ofSavedata.close();
}


//----------------- ---------------------------------------------
//  ����������
//--------------------------------------------------------------
void Game::init()
{
    Scene::init();	    // ���N���X��init���Ă�

    //�Z�[�u�f�[�^�ǂݍ���
    if (Title::instance()->GetTitleFlag()) {
        ifSavedata.open("playerHpSave.dat");
        {
            if (ifSavedata) {
                ifSavedata >> playerHpSave;
                HP::instance()->SetHp(playerHpSave);
            }
        }
        ifSavedata.close();

        ifSavedata2.open("stageSave.dat");
        {
            if (ifSavedata2) {
                ifSavedata2 >> stageSave;
                StageSelect::instance()->setStageNum(stageSave);
            }
        }
        ifSavedata2.close();
        Title::instance()->SetTitleFlag(false);

    }

    obj2dManager_   = new OBJ2DManager;
    bg_             = new BG;

    //sprite
    stageTrans_ = new StageTrans;
    bgCloud_ = new BGCloud;
    back_ = new BackSprite;
    water_ = new WaterSprite;
    Story::instance()->init();
    paper_ = new Paper;
    opeGuide_ = new opeGuide;
    if (StageSelect::instance()->getNum() == 8)stage8water_ = new stage8Water;
    if (StageSelect::instance()->getNum() == 4) Midboss::instance()->init();

    //UI�ӂ�̏�����
    //hp_ = new HP;
    perClear_ = new perClear;
    chapterStar_ = new chapterStar;
    moveFlag_ = new MoveFlag;

    sprMenuBack_ = sprite_load(L"./Data/Images/MENU/back.png");
    sprMenuSave_ = sprite_load(L"./Data/Images/MENU/save.png");
    sprMenuSound_ = sprite_load(L"./Data/Images/MENU/sound.png");
    sprMenuExit_ = sprite_load(L"./Data/Images/MENU/end.png");

    sprMenuSound_BACK = sprite_load(L"./Data/Images/MENU/bgm/back2.png");

    sprMenuSound_BGM = sprite_load(L"./Data/Images/MENU/bgm/bgm.png");
    sprMenuSound_SE = sprite_load(L"./Data/Images/MENU/bgm/se.png");


    isPaused_ = false;   // �|�[�Y�t���O�̏�����
    PlayerClear::instance()->init();
    HP::instance()->init();

    //scipt�ӂ�
   BossScript::instance()->init();
   Stage8WaterScript::instance()->init();
   WaterScript::instance()->init();
   if (StageSelect::instance()->getNum() == 9) Ch1boss::instance()->init(); //ch1 boss


   //state
   PlayerJumpState::instance()->init();
   if (StageSelect::instance()->getNum() > 1) PlayerWeapon::instance()->SethasWeapon(true);

   
}

//--------------------------------------------------------------
//  �I������
//--------------------------------------------------------------
void Game::deinit()
{

    // �e�N�X�`���̉��
    texture::releaseAll();

    // �e�}�l�[�W���̉��
    safe_delete(bg_);
    safe_delete(obj2dManager_);

    //sprite
    safe_delete(back_);
    safe_delete(bgCloud_);
    safe_delete(stageTrans_);
    safe_delete(water_);
    Story::instance()->deinit();
    if (StageSelect::instance()->getNum() == 8) safe_delete(stage8water_);
    safe_delete(paper_);
    HP::instance()->deinit();
    safe_delete(opeGuide_);
    if (StageSelect::instance()->getNum() == 4) Midboss::instance()->deinit();

    //UI�ӂ�̏I��
  //  safe_delete(hp_);
    safe_delete(perClear_);
    safe_delete(chapterStar_);
    safe_delete(moveFlag_);

    safe_delete(sprMenuExit_);
    safe_delete(sprMenuBack_);
    safe_delete(sprMenuSave_);
    safe_delete(sprMenuSound_);

    safe_delete(sprMenuSound_BACK);
    safe_delete(sprMenuSound_BGM);
    safe_delete(sprMenuSound_SE);


    //script
    if(StageSelect::instance()->getNum() == 9) Ch1boss::instance()->deinit();
    BossScript::instance()->deinit();
    Stage8WaterScript::instance()->deinit();
    WaterScript::instance()->deinit();


   // ���y�̃N���A
   music::clear();

}

//--------------------------------------------------------------
//  �X�V����
//--------------------------------------------------------------
void Game::update()
{
    using namespace input;

    //// �X�e�[�W�ړ�
    //if ((STATE(0) & PAD_SELECT) &&    
    //    (TRG(0) & PAD_START))           
    //{
    //   music::play(SOUND::MENU_SELECT);
    //
    //    changeScene(GameLoading::instance()); //
    //
    //}

    if (isOpePad_ || isOpeKey_ || isPaused_)
    {
        music::pause(SOUND::PLAYER_WALK);


    }
    else {
        music::resume(SOUND::PLAYER_WALK);


    }
    

    if (isOpePad_ || isOpeKey_) {

        if ((TRG(0) & PAD_SELECT) || (TRG(0) & PAD_LEFT) || (TRG(0) & PAD_RIGHT) || (TRG(0) & PAD_UP) || (TRG(0) & PAD_SPACE) || (GetAsyncKeyState(VK_ESCAPE) & 1))
        {

            isOpeKey_ = false;
            isOpePad_ = false;
        }
    }


    if ((GetAsyncKeyState('1') & 1) && !isPaused_ && !isOpePad_)
    {
        isOpeKey_ = !isOpeKey_;
    }
    if (isOpeKey_) return;              // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��


    if (TRG(0) & PAD_TRG3 && !isPaused_ && !isOpeKey_)
    {
        isOpePad_ = !isOpePad_;
    }
    if (isOpePad_) return;              // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��


    //�|�[�Y����
    if (((GetAsyncKeyState(VK_ESCAPE) & 1) || TRG(0) & PAD_SELECT) && !isOpePad_ && !isOpeKey_)
    {
        if (!isPaused_) music::play(SOUND::PAUSE);
        else  music::play(SOUND::PAUSE_CLOSE);

        audio_setVolume_SE(SOUND::PAUSE, 1.0f);
        audio_setVolume_SE(SOUND::PAUSE_CLOSE, 1.0f);

        isPaused_ = !isPaused_;         // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
        menuSelect_ = 0;

    }

    if (isPaused_)
    {
        using namespace input;

        //select
        switch (menuSelect_)
        {
        case 0:             //�Z�[�u
            //�{�����[���̏����ݒ�
            isVolume_ = false;

            //�㉺�ړ�
           // menuMoveSpeed_ += 0.025f;
            menuPosY1_ += menuMoveSpeed_;
            menuPosY2_ = 440.0f;
            menuPosY3_ = 700.0f;

            if (menuPosY1_ < 180.0f || menuPosY1_ >= 195.0f) menuMoveSpeed_ *= -1.0f;


            //�J��
            if (TRG(0) & PAD_START) {

                music::play(SOUND::MENU_SELECT);

                playerHpSave = HP::instance()->GetHp();
                ofSavedata.open("playerHpSave.dat", std::ios::in);

                ofSavedata << playerHpSave;

                ofSavedata.close();


                stageSave = StageSelect::instance()->getNum();
                ofSavedata2.open("stageSave.dat", std::ios::in);

                ofSavedata2 << stageSave;

                ofSavedata2.close();
                isPaused_ = false;
                //PostQuitMessage(1); //�Q�[���I��
            }
            //������������ԉ��ցA�����������牺��
            if (TRG(0) & PAD_TRG4) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_ = 2;
            }
            if (TRG(0) & PAD_DOWN) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_++;
            }

            break;
        case 1:             //�Q�[���ɖ߂�
                //�㉺�ړ�
                //menuMoveSpeed_ += 0.025f;
            menuPosY1_ = 180.0f;
            menuPosY2_ += menuMoveSpeed_;
            menuPosY3_ = 700.0f;

            //if (menuPosY2_ >= 455.0f) menuMoveSpeed_ *= -1.0f;
            if (menuPosY2_ < 440.0f || menuPosY2_ >= 455.0f)  menuMoveSpeed_ *= -1.0f;



            //�J��
            if (TRG(0) & PAD_START)
            {
                isVolume_ = true;
                music::play(SOUND::MENU_SELECT);

            }

            if (((GetAsyncKeyState(VK_ESCAPE) & 1) || TRG(0) & PAD_SELECT) && !isOpePad_ && !isOpeKey_)
            {

                isVolume_ = false;
                menuSelect_ = 0;
                break;
            }

            if (isVolume_)
            {

                //sound�ݒ��ʂ̗t���ω摜���ړ�
                switch (voSelect_)
                {
                case 0:         //BGM�����̉摜�ړ�
                    soundMenuPosY1_ += soundMenuSpeed_;
                    soundMenuPosY2_ = 650.0f;

                    if (soundMenuPosY1_ <= 175.0f || soundMenuPosY1_ >= 185.0f) soundMenuSpeed_ *= -1.0f;

                    //���L�[��SE�̒�����
                    if (TRG(0) & PAD_DOWN && isVolume_) {
                        music::play(SOUND::MENU_SELECT);

                        voSelect_--;
                    }
                    break;

                case 1:          //SE�����̉摜�ړ�
                    soundMenuPosY1_ = 180.0f;
                    soundMenuPosY2_ += soundMenuSpeed_;

                    if (soundMenuPosY2_ <= 645.0f || soundMenuPosY2_ >= 655.0f) soundMenuSpeed_ *= -1.0f;

                    //��L�[��BGM�̒�����
                    if (TRG(0) & PAD_TRG4 && isVolume_) {
                        music::play(SOUND::MENU_SELECT);

                        voSelect_++;
                    }

                    break;

                }

                //���ʒ���
                if (TRG(0) & PAD_LEFT && isVolume_) {
                    music::play(SOUND::MENU_SELECT);

                    VolumeSelect_[voSelect_]--;
                }
                if (TRG(0) & PAD_RIGHT && isVolume_) {
                    music::play(SOUND::MENU_SELECT);

                    VolumeSelect_[voSelect_]++;
                }

                if ((TRG(0) & PAD_RIGHT) && isVolume_ && voSelect_ == 1) {
                    music::play(SOUND::MENU_SELECT);

                    VolumeSelect_[voSelect_] += 2;
                }
                if ((TRG(0) & PAD_LEFT) && isVolume_ && voSelect_ == 1) {
                    music::play(SOUND::MENU_SELECT);

                    VolumeSelect_[voSelect_] -= 2;
                }


                //�ő�l,�ŏ��l�ݒ�
                if (voSelect_ > 1) voSelect_ = 0;
                if (voSelect_ < 0) voSelect_ = 1;
                if (VolumeSelect_[voSelect_] > 2) VolumeSelect_[voSelect_] = 2;
                if (VolumeSelect_[voSelect_] < 0) VolumeSelect_[voSelect_] = 0;

                //BGM�ASE�̍X�V
                audio_update();
            }



            //������������ցA�����������牺��
            if (TRG(0) & PAD_TRG4 && !isVolume_) {
                music::play(SOUND::MENU_SELECT);
                menuSelect_--;
            }
            if (TRG(0) & PAD_DOWN && !isVolume_) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_++;
            }


            break;
        case 2:             //�Q�[���I��
                   //�㉺�ړ�
            //menuMoveSpeed_ += 0.025f;
            menuPosY1_ = 180.0f;
            menuPosY2_ = 440.0f;
            menuPosY3_ += menuMoveSpeed_;

            //if (menuPosY3_ >= 715.0f) menuMoveSpeed_ *= -1.0f;
            if (menuPosY3_ < 700.0f || menuPosY3_ >= 715.0f) menuMoveSpeed_ *= -1.0f;

            //�J��
            if (TRG(0) & PAD_START) PostQuitMessage(1); //�Q�[���I��

            //�������������ԏ�ցA�������������
            if (TRG(0) & PAD_TRG4) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_--;
            }
            if (TRG(0) & PAD_DOWN) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_ = 0;
            }

            break;
        }

        return;              // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��
    }

    switch (state_)
    {
    case 0:
        //////// �����ݒ� ////////
        timer_ = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����



        //�v���C���[�����񂾂�̗͂Q�ŉ񕜂�����A�{�X��ł͂T�ł���
        if (Restart::instance()->GetRestart() == true) {
            if (HP::instance()->GetHp() <= 0 && StageSelect::instance()->getNum() < 9) { HP::instance()->SetHp(2); }
            if (HP::instance()->GetHp() <= 0 && StageSelect::instance()->getNum() == 9){ HP::instance()->SetHp(5); }
            Restart::instance()->SetRestart(false);
        }

        // �e�N�X�`���̓ǂݍ���

        if (StageSelect::instance()->getNum() != 9) { texture::load(loadTexture); }
        else { texture::load(loadTexture_Boss); }



        //bgm�ݒ�
        if (StageSelect::instance()->getNum() > 0 && StageSelect::instance()->getNum() < 5) music::play(MUSIC::GAME, true);
        if (StageSelect::instance()->getNum() > 4 && StageSelect::instance()->getNum() < 9) music::play(MUSIC::SECOND_HALF_GAME, true);
        if (StageSelect::instance()->getNum() == 9) music::play(MUSIC::CH1_BOSS,true);
        music::play(SOUND::TRANS,false);
        music::play(SOUND::STORY,false);

        // OBJ2D�}�l�[�W���̏����ݒ�
        obj2dManager()->init();

        setItem(obj2dManager(), bg());
        setBlock(obj2dManager(), bg());
        setEnemy(obj2dManager(), bg());
        if(StageSelect::instance()->getNum() == 1)  setTuBlock(obj2dManager(), bg());


       
        // �v���C���[��ǉ�
        player_ = obj2dManager()->add(
            new OBJ2D(
                new Renderer, 
                new Collider, 
                bg(), 
                new ActorComponent, 
                nullptr, 
                nullptr
            ), 
            &walkPlayerBehavior, VECTOR2(160, 160));


        if (StageSelect::instance()->getNum() == 3) player_->transform()->setPosition(VECTOR2(160, 1570));
        if (StageSelect::instance()->getNum() == 8) player_->transform()->setPosition(VECTOR2(160, 2600));
        //if (StageSelect::instance()->getNum() == 8) player_->transform()->setPosition(VECTOR2(1000, 0));
        // BG�̏����ݒ�
        bg()->init(player_);


        //stage6,7,8�ɏォ�痎���Ă��鐅��
        if (StageSelect::instance()->getNum() == 6 || StageSelect::instance()->getNum() == 7 || StageSelect::instance()->getNum() == 8) {
            WaterScript::instance()->setScript(obj2dManager());
        }


        //sprite
        paper()->init();
        stageTrans_->init();

        //Stage8WaterScript::instance()->init();
        audio_update();


        if (StageSelect::instance()->getNum() > 1) PlayerWeapon::instance()->SethasWeapon(true);
        state_++;    // �����ݒ菈���̏I��
        /*fallthrough*/

    case 1:
        //////// �ʏ펞�̏��� ////////

        // �v���C���[�����Ȃ��Ȃ�����^�C�g���ɖ߂�
        //if (player_ == nullptr)
        //{
        //    changeScene(Title::instance());
        //    break;
        //}



        // �I�u�W�F�N�g�̍X�V
        obj2dManager()->update();

        HP::instance()->updateHP();

        // ���L�[��W�L�[���������Ɨ��\���t�]����
        if (TRG(0) & PAD_SPACE)
        {
            music::play(SOUND::PLAYER_REVERSE);
            audio_setVolume_SE(SOUND::PLAYER_REVERSE, 0.3f);
            bg()->setReverseFlag(!bg()->getReverseFlag());
        }

        //hp
        //player_hp()->update();
        //player_hp()->setHp(player_HP);

        //sprite
        bgCloud()->update();
        Story::instance()->update();
        if (StageSelect::instance()->getNum() == 8&& (Game::instance()->player()->actorComponent()->getPlayerMove())) { stage8water_->update(); }
        //�O�_�̃A�j���������I�������

        if (stageTrans_->getState() == 1) {
            GameLib::music::play(SOUND::STORY, false);
            GameLib::music::play(SOUND::TRANS, false);
        }
        if (stageTrans_->getStageFlag()==true) { 
            
           
            changeScene(GameLoading::instance()); 
        }

        if(StageSelect::instance()->getNum()==4)Midboss::instance()->update();
        //opeGuide_->update();

        //ui�ӂ�
        perClear_->update();
        chapterStar_->update();
        moveFlag_->update();

        stageTrans_->update();

        //�{�X��
        if (StageSelect::instance()->getNum() == 9)Ch1boss::instance()->update();
        if (StageSelect::instance()->getNum() == 9 && Ch1boss::instance()->GetBosshp() > 0) BossScript::instance()->setScript(obj2dManager());

        if (StageSelect::instance()->getNum() == 8 && player()->actorComponent()->getPlayerMove()) { Stage8WaterScript::instance()->setScript(obj2dManager()); }

        //�X�e�[�W10����Q�[���N���A
        if (StageSelect::instance()->getNum() == 10 &&player_->transform()->getPositionX() > 1800) { changeScene(GameClear::instance());}
        

        judge();
        //�ړ��u���b�N�̃X�N���[���̂��߂ɁAjudge�֐��̌�ɔz�u
        bg()->update();   // BG�̍X�V


        timer_++;
        break;
    }


}

//--------------------------------------------------------------
//  �`�揈��
//--------------------------------------------------------------
void Game::draw()
{
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    bgCloud()->draw(bg()->getScrollPos());

    backSprite()->draw(bg()->getScrollPos());
    water_->draw(bg()->getScrollPos());

    // �n�`�`��͕\���ŕ���
    if (bg()->getReverseFlag()) bg()->drawTerrainRev();
    else             bg()->drawTerrain();       // �\�n�`�̕`��


    // �I�u�W�F�N�g�̕`��
    obj2dManager()->draw(bg()->getScrollPos());
    //stage8
    if (StageSelect::instance()->getNum() == 8) { stage8water_->draw(bg()->getScrollPos()); }
    //�v���C���[��UI
    if(StageSelect::instance()->getNum() > 0 && StageSelect::instance()->getNum() < 10)HP::instance()->drawHP();

    //ui
    if (StageSelect::instance()->getNum() > 0 && StageSelect::instance()->getNum() < 10) {
        perClear_->draw();
        chapterStar_->draw();
        moveFlag_->draw();
    } 
         
     //�{�X
    if (StageSelect::instance()->getNum() == 4) Midboss::instance()->draw(bg()->getScrollPos());
    if (StageSelect::instance()->getNum() == 9)Ch1boss::instance()->draw();
    if (StageSelect::instance()->getNum() == 9)Ch1boss::instance()->end_draw();

    //�X�g�[���[
    Story::instance()->draw();


    if(paper()->getPaperFlag()) paper()->draw();

    stageTrans_->draw();

    //�|�[�Y���̕`��
    if (isPaused_ && !isVolume_)// ���̎��_�Ń|�[�Y���Ȃ�摜��`��
    {
        sprite_render(sprMenuBack_, 0, 0);
        sprite_render(sprMenuSave_, 803.4f, menuPosY1_);
        sprite_render(sprMenuSound_, 803.4f, menuPosY2_);
        sprite_render(sprMenuExit_, 803.4f, menuPosY3_);
    }

    if (isVolume_ && isPaused_)
    {
        int voX[] = { 500,850,1200 };

        sprite_render(sprMenuBack_, 0, 0);

        sprite_render(sprMenuSound_BACK, 0, 0);
        sprite_render(sprMenuSound_BGM, voX[VolumeSelect_[0]], soundMenuPosY1_);
        sprite_render(sprMenuSound_SE, voX[VolumeSelect_[1]], soundMenuPosY2_);
    }

   // debug::setString("stage:%d", StageSelect::instance()->getNum());

    if (isOpeKey_) opeGuide_->drawKeypad();
    if (isOpePad_) opeGuide_->drawXBox();

}



//--------------------------------------------------------------
//  �����蔻��
//--------------------------------------------------------------
void Game::judge()
{
    for (auto& src : *obj2dManager()->getList())
    {
        if (!src->behavior()) continue;
        if (!src->collider()->judgeFlag()) continue;

        for (auto& dst : *obj2dManager()->getList())
        {
            if (src->behavior() == nullptr) break;

            if (src == dst) continue;       // �������g�͂Ƃ΂�
            if (!dst->behavior()) continue;
            if (!dst->collider()->judgeFlag()) continue;


            // src�̍U���^�C�v��dst�̃^�C�v����v����Ȃ�^��������src��WEAPON�^�C�v�ł���dst��RUBY�Ȃ�^
            if (!(src->behavior()->attackType() != dst->behavior()->getType()) ||
                (dst->behavior()->getType() == OBJ_TYPE::RUBY) && (src->behavior()->getType() == OBJ_TYPE::WEAPON))
            {

                switch (src->behavior()->getType())
                {
                case OBJ_TYPE::BLOCK:
                    // �����蔻����s��
                    if (src->collider()->hitCheck(dst))
                    {
                        // ���������ꍇ�̏���
                        src->collider()->hit_b(dst);
                        src->behavior()->hit(src, dst);
                    }

                    break;

                case OBJ_TYPE::RUBY:
                    // �����蔻����s��
                    if (src->collider()->hitCheck(dst))
                    {
                        // ���������ꍇ�̏���
                       // src->collider()->hit_r(dst);
                        src->behavior()->hit(src, dst);
                    }

                    break;



                default:

                    // �����蔻����s��
                    if (src->collider()->hitCheck(dst))
                    {
                        // ���������ꍇ�̏���
                        src->behavior()->hit(src, dst);
                    }

                    break;
                }
            }

            if (src->getStageM() == true) {

                changeScene(GameLoading::instance()); // �^�C�g���V�[���ɐ؂�ւ���
            }
        }
    }
}

//******************************************************************************
