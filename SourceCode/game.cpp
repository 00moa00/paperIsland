//******************************************************************************
//
//
//      ゲーム
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"
#include "game.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
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
//  初期化処理
//--------------------------------------------------------------
void Game::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ

    //セーブデータ読み込み
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

    //UI辺りの初期化
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


    isPaused_ = false;   // ポーズフラグの初期化
    PlayerClear::instance()->init();
    HP::instance()->init();

    //scipt辺り
   BossScript::instance()->init();
   Stage8WaterScript::instance()->init();
   WaterScript::instance()->init();
   if (StageSelect::instance()->getNum() == 9) Ch1boss::instance()->init(); //ch1 boss


   //state
   PlayerJumpState::instance()->init();
   if (StageSelect::instance()->getNum() > 1) PlayerWeapon::instance()->SethasWeapon(true);

   
}

//--------------------------------------------------------------
//  終了処理
//--------------------------------------------------------------
void Game::deinit()
{

    // テクスチャの解放
    texture::releaseAll();

    // 各マネージャの解放
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

    //UI辺りの終了
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


   // 音楽のクリア
   music::clear();

}

//--------------------------------------------------------------
//  更新処理
//--------------------------------------------------------------
void Game::update()
{
    using namespace input;

    //// ステージ移動
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
    if (isOpeKey_) return;              // この時点でポーズ中ならリターン


    if (TRG(0) & PAD_TRG3 && !isPaused_ && !isOpeKey_)
    {
        isOpePad_ = !isOpePad_;
    }
    if (isOpePad_) return;              // この時点でポーズ中ならリターン


    //ポーズ処理
    if (((GetAsyncKeyState(VK_ESCAPE) & 1) || TRG(0) & PAD_SELECT) && !isOpePad_ && !isOpeKey_)
    {
        if (!isPaused_) music::play(SOUND::PAUSE);
        else  music::play(SOUND::PAUSE_CLOSE);

        audio_setVolume_SE(SOUND::PAUSE, 1.0f);
        audio_setVolume_SE(SOUND::PAUSE_CLOSE, 1.0f);

        isPaused_ = !isPaused_;         // 0コンのスタートボタンが押されたらポーズ状態が反転
        menuSelect_ = 0;

    }

    if (isPaused_)
    {
        using namespace input;

        //select
        switch (menuSelect_)
        {
        case 0:             //セーブ
            //ボリュームの初期設定
            isVolume_ = false;

            //上下移動
           // menuMoveSpeed_ += 0.025f;
            menuPosY1_ += menuMoveSpeed_;
            menuPosY2_ = 440.0f;
            menuPosY3_ = 700.0f;

            if (menuPosY1_ < 180.0f || menuPosY1_ >= 195.0f) menuMoveSpeed_ *= -1.0f;


            //遷移
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
                //PostQuitMessage(1); //ゲーム終了
            }
            //上を押したら一番下へ、下を押したら下へ
            if (TRG(0) & PAD_TRG4) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_ = 2;
            }
            if (TRG(0) & PAD_DOWN) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_++;
            }

            break;
        case 1:             //ゲームに戻る
                //上下移動
                //menuMoveSpeed_ += 0.025f;
            menuPosY1_ = 180.0f;
            menuPosY2_ += menuMoveSpeed_;
            menuPosY3_ = 700.0f;

            //if (menuPosY2_ >= 455.0f) menuMoveSpeed_ *= -1.0f;
            if (menuPosY2_ < 440.0f || menuPosY2_ >= 455.0f)  menuMoveSpeed_ *= -1.0f;



            //遷移
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

                //sound設定画面の葉っぱ画像を移動
                switch (voSelect_)
                {
                case 0:         //BGM調整の画像移動
                    soundMenuPosY1_ += soundMenuSpeed_;
                    soundMenuPosY2_ = 650.0f;

                    if (soundMenuPosY1_ <= 175.0f || soundMenuPosY1_ >= 185.0f) soundMenuSpeed_ *= -1.0f;

                    //下キーでSEの調整へ
                    if (TRG(0) & PAD_DOWN && isVolume_) {
                        music::play(SOUND::MENU_SELECT);

                        voSelect_--;
                    }
                    break;

                case 1:          //SE調整の画像移動
                    soundMenuPosY1_ = 180.0f;
                    soundMenuPosY2_ += soundMenuSpeed_;

                    if (soundMenuPosY2_ <= 645.0f || soundMenuPosY2_ >= 655.0f) soundMenuSpeed_ *= -1.0f;

                    //上キーでBGMの調整へ
                    if (TRG(0) & PAD_TRG4 && isVolume_) {
                        music::play(SOUND::MENU_SELECT);

                        voSelect_++;
                    }

                    break;

                }

                //音量調整
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


                //最大値,最小値設定
                if (voSelect_ > 1) voSelect_ = 0;
                if (voSelect_ < 0) voSelect_ = 1;
                if (VolumeSelect_[voSelect_] > 2) VolumeSelect_[voSelect_] = 2;
                if (VolumeSelect_[voSelect_] < 0) VolumeSelect_[voSelect_] = 0;

                //BGM、SEの更新
                audio_update();
            }



            //上を押したら上へ、下を押したら下へ
            if (TRG(0) & PAD_TRG4 && !isVolume_) {
                music::play(SOUND::MENU_SELECT);
                menuSelect_--;
            }
            if (TRG(0) & PAD_DOWN && !isVolume_) {
                music::play(SOUND::MENU_SELECT);

                menuSelect_++;
            }


            break;
        case 2:             //ゲーム終了
                   //上下移動
            //menuMoveSpeed_ += 0.025f;
            menuPosY1_ = 180.0f;
            menuPosY2_ = 440.0f;
            menuPosY3_ += menuMoveSpeed_;

            //if (menuPosY3_ >= 715.0f) menuMoveSpeed_ *= -1.0f;
            if (menuPosY3_ < 700.0f || menuPosY3_ >= 715.0f) menuMoveSpeed_ *= -1.0f;

            //遷移
            if (TRG(0) & PAD_START) PostQuitMessage(1); //ゲーム終了

            //下を押したら一番上へ、上を押したら上へ
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

        return;              // この時点でポーズ中ならリターン
    }

    switch (state_)
    {
    case 0:
        //////// 初期設定 ////////
        timer_ = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理



        //プレイヤーが死んだら体力２で回復させる、ボス戦では５でする
        if (Restart::instance()->GetRestart() == true) {
            if (HP::instance()->GetHp() <= 0 && StageSelect::instance()->getNum() < 9) { HP::instance()->SetHp(2); }
            if (HP::instance()->GetHp() <= 0 && StageSelect::instance()->getNum() == 9){ HP::instance()->SetHp(5); }
            Restart::instance()->SetRestart(false);
        }

        // テクスチャの読み込み

        if (StageSelect::instance()->getNum() != 9) { texture::load(loadTexture); }
        else { texture::load(loadTexture_Boss); }



        //bgm設定
        if (StageSelect::instance()->getNum() > 0 && StageSelect::instance()->getNum() < 5) music::play(MUSIC::GAME, true);
        if (StageSelect::instance()->getNum() > 4 && StageSelect::instance()->getNum() < 9) music::play(MUSIC::SECOND_HALF_GAME, true);
        if (StageSelect::instance()->getNum() == 9) music::play(MUSIC::CH1_BOSS,true);
        music::play(SOUND::TRANS,false);
        music::play(SOUND::STORY,false);

        // OBJ2Dマネージャの初期設定
        obj2dManager()->init();

        setItem(obj2dManager(), bg());
        setBlock(obj2dManager(), bg());
        setEnemy(obj2dManager(), bg());
        if(StageSelect::instance()->getNum() == 1)  setTuBlock(obj2dManager(), bg());


       
        // プレイヤーを追加
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
        // BGの初期設定
        bg()->init(player_);


        //stage6,7,8に上から落ちてくる水玉
        if (StageSelect::instance()->getNum() == 6 || StageSelect::instance()->getNum() == 7 || StageSelect::instance()->getNum() == 8) {
            WaterScript::instance()->setScript(obj2dManager());
        }


        //sprite
        paper()->init();
        stageTrans_->init();

        //Stage8WaterScript::instance()->init();
        audio_update();


        if (StageSelect::instance()->getNum() > 1) PlayerWeapon::instance()->SethasWeapon(true);
        state_++;    // 初期設定処理の終了
        /*fallthrough*/

    case 1:
        //////// 通常時の処理 ////////

        // プレイヤーがいなくなったらタイトルに戻す
        //if (player_ == nullptr)
        //{
        //    changeScene(Title::instance());
        //    break;
        //}



        // オブジェクトの更新
        obj2dManager()->update();

        HP::instance()->updateHP();

        // ↑キーかWキーが押されると裏表が逆転する
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
        //前雲のアニメ処理が終わったら

        if (stageTrans_->getState() == 1) {
            GameLib::music::play(SOUND::STORY, false);
            GameLib::music::play(SOUND::TRANS, false);
        }
        if (stageTrans_->getStageFlag()==true) { 
            
           
            changeScene(GameLoading::instance()); 
        }

        if(StageSelect::instance()->getNum()==4)Midboss::instance()->update();
        //opeGuide_->update();

        //ui辺り
        perClear_->update();
        chapterStar_->update();
        moveFlag_->update();

        stageTrans_->update();

        //ボス戦
        if (StageSelect::instance()->getNum() == 9)Ch1boss::instance()->update();
        if (StageSelect::instance()->getNum() == 9 && Ch1boss::instance()->GetBosshp() > 0) BossScript::instance()->setScript(obj2dManager());

        if (StageSelect::instance()->getNum() == 8 && player()->actorComponent()->getPlayerMove()) { Stage8WaterScript::instance()->setScript(obj2dManager()); }

        //ステージ10からゲームクリア
        if (StageSelect::instance()->getNum() == 10 &&player_->transform()->getPositionX() > 1800) { changeScene(GameClear::instance());}
        

        judge();
        //移動ブロックのスクロールのために、judge関数の後に配置
        bg()->update();   // BGの更新


        timer_++;
        break;
    }


}

//--------------------------------------------------------------
//  描画処理
//--------------------------------------------------------------
void Game::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    bgCloud()->draw(bg()->getScrollPos());

    backSprite()->draw(bg()->getScrollPos());
    water_->draw(bg()->getScrollPos());

    // 地形描画は表裏で分岐
    if (bg()->getReverseFlag()) bg()->drawTerrainRev();
    else             bg()->drawTerrain();       // 表地形の描画


    // オブジェクトの描画
    obj2dManager()->draw(bg()->getScrollPos());
    //stage8
    if (StageSelect::instance()->getNum() == 8) { stage8water_->draw(bg()->getScrollPos()); }
    //プレイヤーのUI
    if(StageSelect::instance()->getNum() > 0 && StageSelect::instance()->getNum() < 10)HP::instance()->drawHP();

    //ui
    if (StageSelect::instance()->getNum() > 0 && StageSelect::instance()->getNum() < 10) {
        perClear_->draw();
        chapterStar_->draw();
        moveFlag_->draw();
    } 
         
     //ボス
    if (StageSelect::instance()->getNum() == 4) Midboss::instance()->draw(bg()->getScrollPos());
    if (StageSelect::instance()->getNum() == 9)Ch1boss::instance()->draw();
    if (StageSelect::instance()->getNum() == 9)Ch1boss::instance()->end_draw();

    //ストーリー
    Story::instance()->draw();


    if(paper()->getPaperFlag()) paper()->draw();

    stageTrans_->draw();

    //ポーズ中の描画
    if (isPaused_ && !isVolume_)// この時点でポーズ中なら画像を描画
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
//  あたり判定
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

            if (src == dst) continue;       // 自分自身はとばす
            if (!dst->behavior()) continue;
            if (!dst->collider()->judgeFlag()) continue;


            // srcの攻撃タイプとdstのタイプが一致するなら真もしくはsrcがWEAPONタイプでかつdstがRUBYなら真
            if (!(src->behavior()->attackType() != dst->behavior()->getType()) ||
                (dst->behavior()->getType() == OBJ_TYPE::RUBY) && (src->behavior()->getType() == OBJ_TYPE::WEAPON))
            {

                switch (src->behavior()->getType())
                {
                case OBJ_TYPE::BLOCK:
                    // あたり判定を行う
                    if (src->collider()->hitCheck(dst))
                    {
                        // あたった場合の処理
                        src->collider()->hit_b(dst);
                        src->behavior()->hit(src, dst);
                    }

                    break;

                case OBJ_TYPE::RUBY:
                    // あたり判定を行う
                    if (src->collider()->hitCheck(dst))
                    {
                        // あたった場合の処理
                       // src->collider()->hit_r(dst);
                        src->behavior()->hit(src, dst);
                    }

                    break;



                default:

                    // あたり判定を行う
                    if (src->collider()->hitCheck(dst))
                    {
                        // あたった場合の処理
                        src->behavior()->hit(src, dst);
                    }

                    break;
                }
            }

            if (src->getStageM() == true) {

                changeScene(GameLoading::instance()); // タイトルシーンに切り替える
            }
        }
    }
}

//******************************************************************************
