#include "all.h"
#include <time.h>

using namespace GameLib;


BossScript BossScript::instance_;
Stage8WaterScript Stage8WaterScript::instance_;
WaterScript WaterScript::instance_;


namespace
{   // ※このデータは長いので、Visual Studioの機能で閉じられるようにnamespaceを分けている
    //------< Enemy0のアニメデータ >---------------------------------------------
    //右方向
    AnimeData animeEnemy0_Right[] = {
        { &sprEnemy0_Right0, 10 },
        { &sprEnemy0_Right1, 10 },
        { &sprEnemy0_Right2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //左方向
    AnimeData animeEnemy0_Left[] = {
        { &sprEnemy0_Left0, 10 },
        { &sprEnemy0_Left1, 10 },
        { &sprEnemy0_Left2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //------< Enemy1のアニメデータ >---------------------------------------------

    //右方向
    AnimeData animeEnemy1_Right[] = {
        { &sprEnemy1_Right0, 10 },
        { &sprEnemy1_Right1, 10 },
        { &sprEnemy1_Right2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //右方向
    AnimeData animeEnemy1_Right_INIT[] = {
        { &sprEnemy1_Right0, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //左方向
    AnimeData animeEnemy1_Left[] = {
        { &sprEnemy1_Left0, 10 },
        { &sprEnemy1_Left1, 10 },
        { &sprEnemy1_Left2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //------< ENEMY7のアニメデータ >---------------------------------------------

    AnimeData animeEnemy7[] = {
        { &sprEnemy7, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //------< Enemy9のアニメデータ >---------------------------------------------
 //右方向
    AnimeData animeEnemy9_Right[] = {
        { &sprEnemy9_Right0, 10 },
        { &sprEnemy9_Right1, 10 },
        { &sprEnemy9_Right2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //左方向
    AnimeData animeEnemy9_Left[] = {
        { &sprEnemy9_Left0, 10 },
        { &sprEnemy9_Left1, 10 },
        { &sprEnemy9_Left2, 10 },
        { nullptr, -1 },// 終了フラグ
    };


    //------< stage8 waterのアニメデータ>---------------------------------------------


    //------< Enemy5のアニメデータ >---------------------------------------------

    //右方向
    AnimeData animeEnemy5_Right[] = {
        { &sprEnemy5_Right0, 10 },
        { &sprEnemy5_Right1, 10 },
        { &sprEnemy5_Right2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //左方向
    AnimeData animeEnemy5_Left[] = {
        { &sprEnemy5_Left0, 10 },
        { &sprEnemy5_Left1, 10 },
        { &sprEnemy5_Left2, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    //------< ENEMY1_攻撃のアニメデータ >---------------------------------------------
//白//
    AnimeData animeEnemy1Shot_whitefront[] = {
        {&sprEnemy01_shot1,10},
        {nullptr,-1}
    };
    AnimeData animeEnemy1Shot_whiteback[] = {
        {&sprEnemy01_shot3,10},
        {nullptr,-1}
    };


    //赤//
    AnimeData animeEnemy1Shot_redback[] = {
        {&sprEnemy01_shot2,10},
        {nullptr,-1}
    };
    AnimeData animeEnemy1Shot_redfront[] = {
        {&sprEnemy01_shot4,10},
        {nullptr,-1}
    };
    //------< ENEMY3のアニメデータ >---------------------------------------------

    AnimeData animeBoss_Init[] = {
        { &sprEnemy3_Init, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeBoss_Attack00[] = {
        { &sprEnemy3_Attack00, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeBoss_Attack01[] = {
        { &sprEnemy3_Attack01, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeBoss_Attack02[] = {
        { &sprEnemy3_Attack02, 10 },
        { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeBoss_Attack03[] = {
    { &sprEnemy3_Attack03, 10 },
    { nullptr, -1 },// 終了フラグ
    };


    AnimeData animeBoss_Attack04[] = {
    { &sprEnemy3_Attack04, 10 },
    { nullptr, -1 },// 終了フラグ
    };


    AnimeData animeBoss_Attack05[] = {
    { &sprEnemy3_Attack05, 10 },
    { nullptr, -1 },// 終了フラグ
    };

  

    //------< stage5のアニメデータ >---------------------------------------------

    AnimeData animeStage5_pinkfront[] = {
       { &sprStage5_pinkfront, 10 },
       { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeStage5_blueback[] = {
     { &sprStage5_blueback, 10 },
     { nullptr, -1 },// 終了フラグ
    };


    AnimeData animeStage5_pinkback[] = {
    { &sprStage5_pinkback, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeStage5_bluefront[] = {
    { &sprStage5_bluefront, 10 },
    { nullptr, -1 },// 終了フラグ
    };


    AnimeData animeStage5_water[] = {
    { &sprStage5_water, 10 },
    { nullptr, -1 },// 終了フラグ
    };


    AnimeData animeStage5_bomb[] = {
        { &sprStage5_bomb_0, 10 },
        { &sprStage5_bomb_0, 10 },
        { &sprStage5_bomb_0, 10 },
        { &sprStage5_bomb_1, 10 },
        { &sprStage5_bomb_2, 10 },
        { &sprStage5_bomb_3, 10 },

        { nullptr, -1 },// 終了フラグ
    };

    //------< 敵死亡時のアニメデータ >---------------------------------------------
    AnimeData animeEnemy_die[] = {
    { &sprDe_Enemy0, 10 },
    { &sprDe_Enemy1, 10 },
    { &sprDe_Enemy2, 10 },
    { &sprDe_Enemy3, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    //------< 敵死亡時のアニメデータ >---------------------------------------------
    AnimeData animeEnemy_die2[] = {
    { &sprDe2_Enemy0, 10 },
    { &sprDe2_Enemy1, 10 },
    { &sprDe2_Enemy2, 10 },
    { &sprDe2_Enemy3, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    //------<enemy waterminiのアニメデータ >---------------------------------------------
    AnimeData animeWaterMini[] = {
    { &sprWatermini1, 10 },
    { &sprWatermini2, 10 },
    { &sprWatermini3, 10 },
    { &sprWatermini4, 10 },
    { nullptr, -1 },// 終了フラグ
    };


    //------<enemy waterminiのアニメデータ >---------------------------------------------
    AnimeData animeWaterMini_re[] = {
    { &sprWatermini_re1, 10 },
    { &sprWatermini_re2, 10 },
    { &sprWatermini_re3, 10 },
    { &sprWatermini_re4, 10 },
    { nullptr, -1 },// 終了フラグ
    };



    AnimeData animeRuby1[] = {
    { &spr_rubyblock_0, 10 },
    { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeRuby2[] = {
{ &spr_rubyblock_1, 10 },
{ nullptr, -1 },// 終了フラグ
    };


    AnimeData animeRuby3[] = {
{ &spr_rubyblock_2, 10 },
{ nullptr, -1 },// 終了フラグ
    };

    AnimeData animeMushroomL[] = {
        { &sprEnemy10_0,10},
        { &sprEnemy10_1,10},
        { &sprEnemy10_2,10},
        { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeMushroomR[] = {
    { &sprEnemy10_3,10},
    { &sprEnemy10_4,10},
    { &sprEnemy10_5,10},
    { nullptr, -1 },// 終了フラグ
    };

    AnimeData animeMushroomAttack[] = {
    { &sprEnemy11,10},
    { nullptr, -1 },// 終了フラグ
    };


}
namespace {
    int enemy_stage0[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
      #include "../Data//Maps/MAP_enemy_stage0.txt"
    };

    int enemy_stage1[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_enemy_stage1.txt"
    };

    int enemy_stage2[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_enemy_stage2.txt"
    };

    int enemy_stage3[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
       #include "../Data//Maps/MAP_enemy_stage3.txt"
    };

    int enemy_stage4[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
   #include "../Data//Maps/MAP_enemy_stage4.txt"
    };

    int enemy_stage5[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_enemy_stage5.txt"
    };

    int enemy_stage6[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_enemy_stage6.txt"
    };

    int enemy_stage7[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_enemy_stage7.txt"
    };


    int enemy_stage8[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_enemy_stage8.txt"
    };


    int enemy_stage9[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
    #include "../Data//Maps/MAP_enemy_stage9.txt"
    };

    int enemy_stage10[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
 #include "../Data//Maps/MAP_enemy_stage10.txt"
    };

    int tutorial[BG::CHIP_NUM_Y][BG::CHIP_NUM_X] = {
#include "../Data//Maps/MAP_tu_blook_stage1.txt"
    };


}


void Stage8WaterScript::setScript(OBJ2DManager* obj2dManager)
{

    switch (state)
    {
    case 0:
        music::play(SOUND::STAGE8_WARNING);
        audio_setVolume_SE(SOUND::STAGE8_WARNING, 1.0f);
        state++;
        break;

    case 1:
    { 
        OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

    obj2dManager->add(enemy, &stage8WaterBehavior, VECTOR2(1000, 3008));

    }
        state++;
        break;

    case 2:

        break;
    }
}


void setEnemy(OBJ2DManager* obj2dManager, BG* bg)
{
    BaseEnemyBehavior* enemyBehavior[] = {
        &enemy0Behavior,
        &sunF_R_Behavior,
        &enemy2Behavior,
        &enemy3Behavior,
        &sunF_L_Behavior,
        &sunF_R2_Behavior,
        &sunF_L2_Behavior,
        &enemy7Behavior,
        nullptr,
        &enemy9Behavior,
        &enemy10Behavior,
        &enemy11Behavior,

    };

    for (int y = 0; y < BG::CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < BG::CHIP_NUM_X; x++)
        {

            int chip = -1;
            int num = StageSelect::instance()->getNum();
            switch (num) {

            case 0: chip = enemy_stage0[y][x];  break;
            case 1: chip = enemy_stage1[y][x];  break;
            case 2: chip = enemy_stage2[y][x];  break;
            case 3: chip = enemy_stage3[y][x];  break;
            case 4: chip = enemy_stage4[y][x];  break;
            case 5: chip = enemy_stage5[y][x];  break;
            case 6: chip = enemy_stage6[y][x];  break;
            case 7: chip = enemy_stage7[y][x];  break;
            case 8: chip = enemy_stage8[y][x];  break;
            case 9: chip = enemy_stage9[y][x];  break;
            case 10: chip = enemy_stage10[y][x];  break;


            }

            if (chip < 0) continue;
            assert(chip < ARRAYSIZE(enemyBehavior));
            if (!enemyBehavior[chip]) continue;

            const VECTOR2 pos = {
                x * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F * 0.5f,
                y * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F,
            };
            OBJ2D* enemy = new OBJ2D(
                new Renderer,
                new Collider,
                bg,
                new ActorComponent,
                nullptr,
                nullptr
            );
            obj2dManager->add(enemy, enemyBehavior[chip], pos);
        }
    }

    if (StageSelect::instance()->getNum() == 9)
    {
        OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
        Game::instance()->obj2dManager()->add(enemy, &enemy4Behavior, VECTOR2(975, 900));
    }
}



void setTuBlock(OBJ2DManager* obj2dManager, BG* bg)
{
    BaseEnemyBehavior* enemyBehavior[] = {
        &block1Behavior,
        &block2Behavior,
        &block3Behavior,
        nullptr

    };

    for (int y = 0; y < BG::CHIP_NUM_Y; y++)
    {
        for (int x = 0; x < BG::CHIP_NUM_X; x++)
        {

            int chip = -1;

           chip = tutorial[y][x];


            if (chip < 0) continue;
            assert(chip < ARRAYSIZE(enemyBehavior));
            if (!enemyBehavior[chip]) continue;

            const VECTOR2 pos = {
                x * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F * 0.5f,
                y * BG::CHIP_SIZE_F + BG::CHIP_SIZE_F,
            };
            OBJ2D* enemy = new OBJ2D(
                new Renderer,
                new Collider,
                bg,
                new ActorComponent,
                nullptr,
                nullptr
            );
            obj2dManager->add(enemy, enemyBehavior[chip], pos);
        }
    }

}



void BossScript::setScript(OBJ2DManager* obj2dManager)
{
    //  BaseEnemyBehavior* enemyBehavior[4] = { &pattern00Behavior,&pattern01Behavior,&pattern02Behavior,&pattern03Behavior };

    switch (state)
    {
    case 0:

        state++;
        break;

    case 1:

        timer++;

        //================================
        //      左上、右下から出てくる
        //================================
        {
            if (timer == 160) Ch1boss::instance()->SetAttack00(true);

            if (timer == 250) {
                Ch1boss::instance()->SetAttack00(false);

                for (int i = 0; i < 3; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern00Behavior, VECTOR2(0, 150.0f * (i + 1)));
                }

                for (int i = 3; i < 6; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern01Behavior, VECTOR2(1920.0f, 150.0f * (i + 1)));
                }
            }
        }

        //================================
        //      左上、右下から出てくる
        //================================
        {
            if (timer == 500) Ch1boss::instance()->SetAttack01(true);

            if (timer == 600) {
                Ch1boss::instance()->SetAttack01(false);
                for (int i = 0; i < 3; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern00Behavior, VECTOR2(0, 150.0f * (i + 4)));
                }

                for (int i = 0; i < 3; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern01Behavior, VECTOR2(1920.0f, 150.0f * (i + 1)));
                }
            }
        }

        //================================
        //      花が落ちてくる
        //================================
        {
            if (timer == 900) Ch1boss::instance()->SetAttack02(true);

            if (timer == 1000) {
                // Ch1boss::instance()->SetAttack02(false);
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern02Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }

            if (timer == 1100) {
                // Ch1boss::instance()->SetAttack01(false);
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern03Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }


            if (timer == 1200) {
                // Ch1boss::instance()->SetAttack01(false);
                Ch1boss::instance()->SetAttack02(false);
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern02Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }


            if (timer == 1300) {
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern03Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }
        }

        //================================
        //      お水が上がってくる
        //================================
        {
            if (timer == 1300) Ch1boss::instance()->SetAttack03(true);

            if (timer == 1400) {
                //Ch1boss::instance()->SetAttack03(false);
                OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
                obj2dManager->add(enemy, &pattern04Behavior, VECTOR2(1088 - (544 / 4), (1920)));

            }

            if (timer == 1900) Ch1boss::instance()->SetAttack03(false);
        }

        //================================
        //      花の爆弾 / 下
        //================================
        {
            if (timer == 1900) Ch1boss::instance()->SetAttack05(true);

            if (timer == 1950) {
                OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
                obj2dManager->add(enemy, &pattern05Behavior, VECTOR2(455, 750));
            }


            if (timer == 2000) {

                Ch1boss::instance()->SetAttack05(false);

                OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
                obj2dManager->add(enemy, &pattern05Behavior, VECTOR2(1450, 750));
            }
        }

        //================================
        //      花の爆弾 / 上
        //================================
        {
            if (timer == 2150) Ch1boss::instance()->SetAttack04(true);

            if (timer == 2200) {
                OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
                obj2dManager->add(enemy, &pattern05Behavior, VECTOR2(1600, 420));
            }

            if (timer == 2250) {

                Ch1boss::instance()->SetAttack04(false);

                OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
                obj2dManager->add(enemy, &pattern05Behavior, VECTOR2(320, 420));
            }
        }

        //================================
        //      花が落ちてくる
        //================================
        {
            if (timer == 2500) Ch1boss::instance()->SetAttack02(true);

            if (timer == 2600) {
                // Ch1boss::instance()->SetAttack02(false);
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern02Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }

            if (timer == 2700) {
                // Ch1boss::instance()->SetAttack01(false);
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern03Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }



            if (timer == 2800) {
                // Ch1boss::instance()->SetAttack01(false);
                Ch1boss::instance()->SetAttack02(false);
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern02Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }


            if (timer == 2900) {
                for (int i = 0; i < 12; i++) {
                    OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                    obj2dManager->add(enemy, &pattern03Behavior, VECTOR2(150.0f * (i + 1), 0.0f));
                }
            }



            //================================
            //      左上、右下から出てくる
            //================================
            {
                if (timer == 3000) Ch1boss::instance()->SetAttack00(true);

                if (timer == 3100) {
                    Ch1boss::instance()->SetAttack00(false);

                    for (int i = 0; i < 3; i++) {
                        OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                        obj2dManager->add(enemy, &pattern00Behavior, VECTOR2(0, 150.0f * (i + 1)));
                    }

                    for (int i = 3; i < 6; i++) {
                        OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                        obj2dManager->add(enemy, &pattern01Behavior, VECTOR2(1920.0f, 150.0f * (i + 1)));
                    }
                }
            }

            //================================
            //      左上、右下から出てくる
            //================================
            {
                if (timer == 3500) Ch1boss::instance()->SetAttack01(true);

                if (timer == 3600) {
                    Ch1boss::instance()->SetAttack01(false);
                    for (int i = 0; i < 3; i++) {
                        OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                        obj2dManager->add(enemy, &pattern00Behavior, VECTOR2(0, 150.0f * (i + 4)));
                    }

                    for (int i = 0; i < 3; i++) {
                        OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);

                        obj2dManager->add(enemy, &pattern01Behavior, VECTOR2(1920.0f, 150.0f * (i + 1)));
                    }
                }
            }
        }

        state = 0;
    }

};


void WaterScript::setScript(OBJ2DManager* obj2dManager)
{

   // if (timer == 0) {
        float posY1[8] = { -100.f,-200.f,-300.f,-400.f,-200.f,-300.f,0.f,-100.f };
        float posY2[8] = { -800.f,-900.f,-1000.f,-800.f,-900.f,-1000.f,-600.f,-800.f };
        float posY3[8] = { -1700.f,-1800.f,-2000.f,-1300.f,-1700.f,-2000.f,-1200.f,-1400.f };

        for (int i = 0; i < 600 * 8; i += 600) {
            OBJ2D* enemy = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            obj2dManager->add(enemy, &waterMini, VECTOR2((float)i, posY1[j]));


            OBJ2D* enemy1 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            obj2dManager->add(enemy1, &waterMini, VECTOR2((float)i - 200, posY2[j]));

            if (StageSelect::instance()->getNum() == 8) {
                OBJ2D* enemy2 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
                obj2dManager->add(enemy2, &waterMini, VECTOR2((float)i - 200, posY3[j]));
            }

            j++;
        }
   // }
  //  timer++;
}


void BossScript::update()
{
    timer++;
}

void BaseEnemyBehavior::moveY(OBJ2D* obj)
{
    //calcAttackBox(obj);  //当たり判定用数値更新

    Transform* transform = obj->transform();

    // 速度に加速度を加える
    transform->addSpeedY(getParam()->ACCEL_Y);

    calcAttackBox(obj);  //当たり判定用数値更新


   
    ActorBehavior::moveY(obj);



}

void BaseEnemyBehavior::moveX(OBJ2D* obj)
{
    float dist = 0.0f;
    if (obj->actorComponent()->xFlip())
    {
        // 左向きの場合
        obj->transform()->addSpeedX(-getParam()->ACCEL_X);
        obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);
        dist = -obj->collider()->size().x;
    }
    else
    {
        // 右向きの場合
        obj->transform()->addSpeedX(getParam()->ACCEL_X);
        obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);
        dist = obj->collider()->size().x;
    }

    ActorBehavior::moveX(obj);

    if (obj->actorComponent()->onGround())
    {
        VECTOR2 pos = obj->transform()->position() + VECTOR2(dist, 1);  // 進行方向先端の１ドット下
        if (obj->bg()->getTerrainAttr(pos) == BG::TR_ATTR::TR_NONE)
            obj->actorComponent()->setGakeFlag(true);


        //if (StageSelect::instance()->getNum() == 4 && (obj->transform()->getPositionX() >= 4200 || obj->transform()->getPositionX() <= 3200))
        //{
        //    obj->actorComponent()->setGakeFlag(true);

        //}

    }
    calcAttackBox(obj);  //当たり判定用数値更新


}

void BaseEnemyBehavior::turn(OBJ2D* obj)
{
    if (obj->actorComponent()->kabeFlag())
    {
        // 壁フラグがtrueの場合
        obj->transform()->setSpeedX(0.0f);
        obj->actorComponent()->flip();
        obj->actorComponent()->setKabeFlag(false);
        obj->actorComponent()->setGakeFlag(false);
    }
    else
    {
        // 壁フラグがfalseの場合
        gakeTurn(obj);
    }
}

void BaseEnemyBehavior::gakeTurn(OBJ2D* obj)
{
    if (obj->actorComponent()->gakeFlag())
    {
        obj->transform()->setSpeedX(0.0f);
        obj->actorComponent()->flip();
        obj->actorComponent()->setGakeFlag(false);
    }
}

bool BaseEnemyBehavior::isAlive(OBJ2D* obj)
{
    srand(time(NULL));

    if (obj->actorComponent()->isAlive() == false)
    {


        //if (StageSelect::instance()->getNum() == 1) {

        //    obj->renderer()->addColor_a(-0.03f);
        //    if (obj->renderer()->getColor_a() <= 0.0f) obj->remove();
        //}

         if (die_animation(obj) )
        {
            die_timer = 0;
            obj->remove();
            
            if( StageSelect::instance()->getNum() != 9 && StageSelect::instance()->getNum() != 1){
            int ran = rand()%5; //0~4

            //itemDROP
                if (ran == 0) {
                    OBJ2D* item = Game::instance()->obj2dManager()->add(
                        new OBJ2D(
                            new Renderer,
                            new Collider,
                            obj->bg(),
                            nullptr,
                            new ItemComponent,
                            nullptr
                        ),
                        &itemHp, obj->transform()->position() - VECTOR2(0, 100.0f));
                }
            }
        }

        return false;
    }
    return true;
}


bool BaseEnemyBehavior::die_animation(OBJ2D* obj)
{
    obj->renderer()->setAnimeData(param_.ANIME_HIT);
    if (die_timer > (sizeof(animeEnemy_die) / sizeof(AnimeData)) * 4)
        return true;

    die_timer++;
    return false;
}

void BaseEnemyBehavior::calcAttackBox(OBJ2D* obj)
{
    // 攻撃判定の計算
    obj->collider()->calcAttackBox(
        getParam()->HIT_BOX
    );
}


Enemy0Behavior::Enemy0Behavior()
{
    param_.ANIME_RIGHT = animeEnemy0_Right;
    param_.ANIME_LEFT = animeEnemy0_Left;
    param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -100, 60, 0 };

    param_.ACCEL_X = 0.4f;
    param_.ACCEL_Y = 2.0f;
    param_.SPEED_X_MAX = 1.0f;
    param_.SPEED_Y_MAX = 12.0f;

    param_.HP = 4;
    param_.ENEMY_DAMAGE = 1;
}


void Enemy0Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

    //UNREFERENCED_PARAMETER(dst);
   // Game::instance()->SubHp(1);
}


SunF_R_Behavior::SunF_R_Behavior()
{
    // param_.ANIME_UP = animeEnemy1_Up;
    param_.ANIME_RIGHT = animeEnemy1_Right;

    //.ANIME_DOWN = animeEnemy1_Down;
    param_.ANIME_LEFT = animeEnemy1_Left;
    param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -120, 60, 0 };

    param_.HP = 7;

    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;


}

void SunF_R_Behavior::moveX(OBJ2D* obj)
{

    obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);
    

    switch (state)
    {
    case 0:

        timer++;
        if (timer > 100)
        {
            OBJ2D* enemy1 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy1, &enemy01ShotRed, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));
            timer = 0;
            state = 1;

        }
        //timer = 0;


        break;

    case 1:
        timer++;
        if (timer > 100) {

            OBJ2D* enemy2 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy2, &enemy01ShotWhite, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));

            timer = 0;
            state = 0;
        }

    }
    //debug::setString("timer:%d", timer);
    //debug::setString("state:%d", state);


}

void SunF_R_Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    // UNREFERENCED_PARAMETER(dst);
     //Game::instance()->SubHp();
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);


}

SunF_L_Behavior::SunF_L_Behavior()
{
    // param_.ANIME_UP = animeEnemy1_Up;
    param_.ANIME_RIGHT = animeEnemy1_Right;
    //.ANIME_DOWN = animeEnemy1_Down;
    param_.ANIME_LEFT = animeEnemy1_Left;
    param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -120, 60, 0 };

    param_.HP = 7;
    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;


}

void SunF_L_Behavior::moveX(OBJ2D* obj)
{


    obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);

    switch (state)
    {
    case 0:

        timer++;
        if (timer > 100)
        {
            OBJ2D* enemy1 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy1, &enemy01ShotRed, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));
            timer = 0;
            state = 1;

        }
        //timer = 0;


        break;

    case 1:
        timer++;
        if (timer > 100) {

            OBJ2D* enemy2 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy2, &enemy01ShotWhite, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));

            timer = 0;
            state = 0;
        }

    }
    //debug::setString("timer:%d", timer);
    //debug::setString("state:%d", state);


}

void SunF_L_Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    // UNREFERENCED_PARAMETER(dst);
    //Game::instance()->SubHp();
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}



SunF_R2_Behavior::SunF_R2_Behavior()
{
    // param_.ANIME_UP = animeEnemy1_Up;
    param_.ANIME_RIGHT = animeEnemy5_Right;
    //.ANIME_DOWN = animeEnemy1_Down;
    param_.ANIME_LEFT = animeEnemy5_Left;
    param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -120, 60, 0 };

    param_.HP = 9;

    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;


}

void SunF_R2_Behavior::moveX(OBJ2D* obj)
{

    obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);


    switch (state)
    {
    case 0:

        timer++;
        if (timer > 100)
        {
            OBJ2D* enemy1 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy1, &enemy01ShotRed, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));
            timer = 0;
            state = 1;

        }
        //timer = 0;


        break;

    case 1:
        timer++;
        if (timer > 100) {

            OBJ2D* enemy2 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy2, &enemy01ShotWhite, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));

            timer = 0;
            state = 0;
        }

    }



}

void SunF_R2_Behavior::hit(OBJ2D* src, OBJ2D* dst)
{

    playerHit(src, dst, getParam()->ENEMY_DAMAGE);


}

SunF_L2_Behavior::SunF_L2_Behavior()
{
    param_.ANIME_RIGHT = animeEnemy5_Right;
    param_.ANIME_LEFT = animeEnemy5_Left;
    param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -120, 60, 0 };

    param_.HP = 9;
    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;


}

void SunF_L2_Behavior::moveX(OBJ2D* obj)
{


    obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);

    switch (state)
    {
    case 0:

        timer++;
        if (timer > 100)
        {
            OBJ2D* enemy1 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy1, &enemy01ShotRed, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));
            timer = 0;
            state = 1;

        }
        //timer = 0;


        break;

    case 1:
        timer++;
        if (timer > 100) {

            OBJ2D* enemy2 = new OBJ2D(new Renderer, new Collider, nullptr, new ActorComponent, nullptr, nullptr);
            Game::instance()->obj2dManager()->add(enemy2, &enemy01ShotWhite, VECTOR2(obj->transform()->getPositionX() + 20, obj->transform()->getPositionY() - 40));

            timer = 0;
            state = 0;
        }

    }

}

void SunF_L2_Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);
}



Enemy7Behavior::Enemy7Behavior()
{
    param_.ANIME_RIGHT = animeEnemy7;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -80, -200, 80, -35 };
    param_.ACCEL_Y = 10.0f;
    param_.ACCEL_X = 5.5f;

    param_.HP = 8;
    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;
    oldposX = 0;
    oldposY = 0;
    speedY = 50;
}

void Enemy7Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

void Enemy7Behavior::moveX(OBJ2D* obj)
{
    if (StageSelect::instance()->getNum() == 7) {

        oldposY = 1200;

        if (!Game::instance()->bg()->getReverseFlag()) state = 2;
        if (Game::instance()->bg()->getReverseFlag()) state = 1;

        switch (state)
        {
        case 0:

            break;

        case 1:
            if (obj->transform()->getPositionY() < oldposY - 550)         obj->transform()->addPositionY(.0f);
            else          obj->transform()->addPositionY(-getParam()->ACCEL_Y);


            break;

        case 2:
            if (obj->transform()->getPositionY() > oldposY)         obj->transform()->addPositionY(.0f);
            else          obj->transform()->addPositionY(getParam()->ACCEL_Y);

            break;

        }
    }


    if (StageSelect::instance()->getNum() == 6) {


        // oldposY = 1200;

        if (!Game::instance()->bg()->getReverseFlag()) state = 2;
        if (Game::instance()->bg()->getReverseFlag()) state = 1;

        switch (state)
        {
        case 0:

            break;

        case 1:
            if (obj->transform()->getPositionX() < 300.0f)         obj->transform()->addPositionX(.0f);
            else          obj->transform()->addPositionX(-getParam()->ACCEL_X);


            break;

        case 2:
            if (obj->transform()->getPositionX() > 2200.0f)         obj->transform()->addPositionX(.0f);
            else          obj->transform()->addPositionX(getParam()->ACCEL_X);

            break;

        }

    }
}




Enemy9Behavior::Enemy9Behavior()
{
    param_.ANIME_RIGHT = animeEnemy9_Right;
    param_.ANIME_LEFT = animeEnemy9_Left;
    param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -100, 60, 0 };


    param_.HP = 8;
    param_.ENEMY_DAMAGE = 1;

    oldposX = 0;
    oldposY = 0;

    state = 0;
    state2 = 0;
}

 
void Enemy9Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

void Enemy9Behavior::moveX(OBJ2D* obj)
{
    
    Transform* transform = obj->transform();    
    if (StageSelect::instance()->getNum() == 7) {

        switch (state2)
        {
        case 0:


            oldposX = transform->getPositionX();
            oldposY = transform->getPositionY();

            state2++;
            break;

        case 1:
            obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);
            transform->addPositionY(1.0f);
            if (transform->getPositionY() > oldposY + 50) {
                oldposY = transform->getPositionY();
                state2++;
            }

            break;

        case 2:
            obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);
            transform->addPositionY(-1.0f);

            if (transform->getPositionY() < oldposY - 50) {
                state2 = 0;
            }
        }
    }
}



////ひまわりのshot////
//赤
Enemy01ShotRed::Enemy01ShotRed()
{
    param_.SIZE = VECTOR2(50, 50);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -18,-40,18,0 };

    param_.HP = 1;
    param_.ACCEL_X = 9.0f;
    param_.ENEMY_DAMAGE = 1;


    state = 0;
    timer = 0;
    distanceX = 0;
    Shotdieflag = false;


}

void Enemy01ShotRed::moveX(OBJ2D* obj)
{

    Renderer* renderer = obj->renderer();
    Transform* transform = obj->transform();

    renderer->setAnimeData(getParam()->ANIME_RIGHT);


    switch (state)
    {
    case 0:
        distanceX = obj->transform()->getPositionX();
        
        state = StageSelect::instance()->getNum();
        break;

    case 3:

        //アニメ設定
        if (Game::instance()->bg()->getReverseFlag() == false)obj->renderer()->setAnimeData(animeEnemy1Shot_redfront);
        else obj->renderer()->setAnimeData(animeEnemy1Shot_redback);


        //移動設定
        if (obj->transform()->getPositionY() > 1400 && StageSelect::instance()->getNum() == 3) {
            obj->transform()->setPositionX((obj->transform()->getPositionX() - getParam()->ACCEL_X));
        }

        if (obj->transform()->getPositionY() < 1400 && StageSelect::instance()->getNum() == 3) {

            obj->transform()->setPositionX((obj->transform()->getPositionX() + getParam()->ACCEL_X));

            transform->FlipX(true);
            obj->actorComponent()->setXFlip(true);
        }

        //remove作業
        if ((obj->transform()->getPositionY() > 1400 && (obj->transform()->getPositionX() < (distanceX + 480))) ||
            ((obj->transform()->getPositionY() < 1400) && (obj->transform()->getPositionX() > distanceX + 460)))
        {

            obj->remove();
        }


        if (StageSelect::instance()->getNum() == 6) {
            transform->FlipX(false);
            obj->actorComponent()->setXFlip(false);

            state = 0;
        }

        break;


    case 6:
        //ステージ6用

        //アニメ設定
        if (Game::instance()->bg()->getReverseFlag() == false)obj->renderer()->setAnimeData(animeEnemy1Shot_redfront);
        else obj->renderer()->setAnimeData(animeEnemy1Shot_redback);


        //移動設定
        obj->transform()->setPositionX((obj->transform()->getPositionX() - getParam()->ACCEL_X));



        if ((obj->transform()->getPositionX() < (distanceX - 400))) obj->remove();

        if (StageSelect::instance()->getNum() == 7) {
            state = 0;
        }

        break;

    case 7:
        //ステージ6用

        //アニメ設定
        if (Game::instance()->bg()->getReverseFlag() == false)obj->renderer()->setAnimeData(animeEnemy1Shot_redfront);
        else obj->renderer()->setAnimeData(animeEnemy1Shot_redback);


        //transform->FlipX(true);
        //obj->actorComponent()->setXFlip(true);

        //移動設定
        obj->transform()->setPositionX((obj->transform()->getPositionX() - getParam()->ACCEL_X));

        if ((obj->transform()->getPositionX() < (distanceX - 600))) obj->remove();


        break;

    }

}

void Enemy01ShotRed::hit(OBJ2D* src, OBJ2D* dst)
{
    if (!(Game::instance()->bg()->getReverseFlag())) {

        playerHit(src, dst, getParam()->ENEMY_DAMAGE);

    }

}

void BaseEnemyBehavior::enemy01ShotAlive(OBJ2D* obj)
{
    if (Shotdieflag == true)
    {
        obj->renderer()->setColor({ 0,0,0,0 });
        param_.ENEMY_DAMAGE = 0;
    }
    else {
        obj->renderer()->setColor({ 1,1,1,1 });
        param_.ENEMY_DAMAGE = 1;
    }

}

//白

Enemy01ShotWhite::Enemy01ShotWhite()
{
    param_.SIZE = VECTOR2(50, 50);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -18,-40,18,0 };
    param_.HP = 1;
    param_.ACCEL_X = 9.0f;
    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;
    distanceX = 0;
    Shotdieflag = false;

}

void Enemy01ShotWhite::hit(OBJ2D* src, OBJ2D* dst)
{

    if ((Game::instance()->bg()->getReverseFlag())) {

        playerHit(src, dst, getParam()->ENEMY_DAMAGE);

    }


}

void Enemy01ShotWhite::moveX(OBJ2D* obj)
{

    Renderer* renderer = obj->renderer();
    Transform* transform = obj->transform();
    renderer->setAnimeData(getParam()->ANIME_RIGHT);


    switch (state)
    {
    case 0:
        distanceX = obj->transform()->getPositionX();


        state = StageSelect::instance()->getNum();
        break;

    case 3:

        //アニメ設定
        if (Game::instance()->bg()->getReverseFlag() == false)obj->renderer()->setAnimeData(animeEnemy1Shot_whiteback);
        else obj->renderer()->setAnimeData(animeEnemy1Shot_whitefront);


        //移動設定
        if (obj->transform()->getPositionY() > 1400 && StageSelect::instance()->getNum() == 3) 
        
        {
            obj->transform()->setPositionX((obj->transform()->getPositionX() - getParam()->ACCEL_X));
        }

        if (obj->transform()->getPositionY() < 1400 && StageSelect::instance()->getNum() == 3) {

            obj->transform()->setPositionX((obj->transform()->getPositionX() + getParam()->ACCEL_X));

            transform->FlipX(true);
            obj->actorComponent()->setXFlip(true);
        }

        //remove作業
        if ((obj->transform()->getPositionY() > 1400 && (obj->transform()->getPositionX() < (distanceX + 480))) ||
            ((obj->transform()->getPositionY() < 1400) && (obj->transform()->getPositionX() > distanceX + 460)))
        {
            obj->remove();
        }


        if (StageSelect::instance()->getNum() == 6) {
            transform->FlipX(false);
            obj->actorComponent()->setXFlip(false);

            state = 0;
        }

        break;


    case 6:

        //ステージ6用

        //アニメ設定
        if (Game::instance()->bg()->getReverseFlag() == false)obj->renderer()->setAnimeData(animeEnemy1Shot_whiteback);
        else obj->renderer()->setAnimeData(animeEnemy1Shot_whitefront);


        obj->transform()->setPositionX((obj->transform()->getPositionX() - getParam()->ACCEL_X));


        if ((obj->transform()->getPositionX() < (distanceX - 400))) obj->remove();

        if (StageSelect::instance()->getNum() == 7) {
            state = 0;
        }
        break;


    case 7:

        //ステージ7用

        //アニメ設定
        if (Game::instance()->bg()->getReverseFlag() == false)obj->renderer()->setAnimeData(animeEnemy1Shot_whiteback);
        else obj->renderer()->setAnimeData(animeEnemy1Shot_whitefront);


        obj->transform()->setPositionX((obj->transform()->getPositionX() - getParam()->ACCEL_X));


        if ((obj->transform()->getPositionX() < (distanceX - 700))) obj->remove();

        break;
    }


}


Enemy2Behavior::Enemy2Behavior()
{
    param_.SIZE = VECTOR2(1300, 110);

    //param_.SCALE = VECTOR2(10, 10);

    param_.HIT_BOX = { -1350, -110, 1350, 0 };

    param_.HP = 10;
    param_.ENEMY_DAMAGE = 2;

}

void Enemy2Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    //UNREFERENCED_PARAMETER(dst);
    //Game::instance()->SubHp(1);
    //Game::instance()->SubHp(1);

    if (StageSelect::instance()->getNum() < 5) { param_.ENEMY_DAMAGE = 5; }
    else { param_.ENEMY_DAMAGE = 2; }
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

Stage8WaterBehavior::Stage8WaterBehavior()
{
    //param_.SIZE = VECTOR2(2400 / 2, 500);
    //param_.SCALE = VECTOR2(1, 1);

    //param_.HIT_BOX = { -2400, 2061, 2400, 50 };

    //param_.HP = 100;
    //param_.ENEMY_DAMAGE = 1;
    //state = 0;
    //speedY = 0.0f;


    param_.HIT_BOX = { -2400, -50, 2400, 0 };

    param_.HP = 100;
    speedY = 0.0f;
    state = 0;
    param_.ENEMY_DAMAGE = 2;
}

void Stage8WaterBehavior::hit(OBJ2D* src, OBJ2D* dst)
{    
    //Game::instance()->SubHp(1);

    playerHit(src, dst, getParam()->ENEMY_DAMAGE);
    debug::setString("end_timer:%d", state);


}

void Stage8WaterBehavior::moveX(OBJ2D* obj)
{
   // obj->renderer()->setAnimeData(animeSt8_water);

    if (Restart::instance()->GetRestart()) {
        setParamHitBox(GameLib::fRECT{ 0, 0, 0, 0 });
        speedY = 0;
        state = 0;
    }

 
    switch (state)
    {
    case 0:

        speedY = 0;
        obj->transform()->setPosition(VECTOR2(1000, 3008));
        
        if (Game::instance()->player()->actorComponent()->getPlayerMove())state++;

        //if (PlayerClear::instance()->GetPlayerClear()) state++;
        break;
    case 1:
        speedY += 1.5f;
        //obj->transform()->addPositionY(-1.0f);
        setParamHitBox(GameLib::fRECT{ -2400, -50 - speedY, 2400, 0 });

        if(getParam()->HIT_BOX.top < -2061) { state=2; }

        break;

    case 2:
        setParamHitBox(GameLib::fRECT{ -2400, -2061, 2400, 0 });

        speedY = 0;
        break;

   // case 3:


    }


}


Enemy3Behavior::Enemy3Behavior()
{
    param_.ANIME_RIGHT = animeBoss_Init;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -320, -800, 320, -200 };

    param_.ACCEL_X = 0;
    param_.ACCEL_Y = 1;
    param_.SPEED_X_MAX = 0;
    param_.SPEED_Y_MAX = 0;

    param_.HP = 10000; 

    state = 0;
    timer = 0;
    boss_speed = 0.1f;


}

void Enemy3Behavior::moveX(OBJ2D* obj)
{

    //Renderer* renderer = obj->renderer();

    //揺らす
    switch (state)
    {

    case 0:


        state++;


        break;
    case 1:

        obj->transform()->setPositionY((obj->transform()->getPositionY() + boss_speed));

        if (obj->transform()->getPositionY() > 950) state++;

        break;
    case 2:
        obj->transform()->setPositionY((obj->transform()->getPositionY() - boss_speed));

        if (obj->transform()->getPositionY() < 940) state = 1;

    }

    if (Ch1boss::instance()->GetAttack00() == true)    obj->renderer()->setAnimeData(animeBoss_Attack00);
    else if (Ch1boss::instance()->GetAttack01() == true)    obj->renderer()->setAnimeData(animeBoss_Attack01);
    else if (Ch1boss::instance()->GetAttack02() == true)    obj->renderer()->setAnimeData(animeBoss_Attack02);
    else if (Ch1boss::instance()->GetAttack03() == true)    obj->renderer()->setAnimeData(animeBoss_Attack03);
    else if (Ch1boss::instance()->GetAttack04() == true)    obj->renderer()->setAnimeData(animeBoss_Attack04);
    else if (Ch1boss::instance()->GetAttack05() == true)    obj->renderer()->setAnimeData(animeBoss_Attack05);

    else { obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT); }


   // if (Ch1boss::instance()->GetBosshp() < 0) {



       // Ch1boss::instance()->setBossAlive();

        if (!Ch1boss::instance()->getBossAlive()) {
            obj->renderer()->addColor_a(-0.01f);
            if (obj->renderer()->getColor_a() <= 0) {
                obj->actorComponent()->setAlive(0);
            }
        }
    //}

}

Enemy3Hitbox::Enemy3Hitbox()
{

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -100, -200, 80, 0 };

    param_.ACCEL_X = 0;
    param_.ACCEL_Y = 1;
    param_.SPEED_X_MAX = 0;
    param_.SPEED_Y_MAX = 0;

    param_.HP = 10000; //7?

    state = 0;
    timer = 0;
    boss_speed = 0.1f;
}

void Enemy3Hitbox::moveX(OBJ2D* obj)
{


    //揺らす
    switch (state)
    {
    case 0:
        obj->transform()->setPositionY((obj->transform()->getPositionY() + boss_speed));

        if (obj->transform()->getPositionY() > 950) state++;

        break;
    case 1:
        obj->transform()->setPositionY((obj->transform()->getPositionY() - boss_speed));

        if (obj->transform()->getPositionY() < 940) state = 0;

    }


    if (Ch1boss::instance()->GetBosshp() < 0) {
        obj->actorComponent()->setAlive(0);

    }

}


Pattern00Behavior::Pattern00Behavior()
{

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -100, 60, 0 };

    param_.HP = 100;
    param_.ENEMY_DAMAGE = 1;
    param_.ANIME_HIT = animeEnemy_die;


}

void Pattern00Behavior::moveX(OBJ2D* obj)
{

    if (Ch1boss::instance()->GetBosshp() <= 0)         obj->actorComponent()->setAlive(0);


    obj->renderer()->setAnimeData(animeEnemy0_Right);

    obj->transform()->setPositionX((obj->transform()->getPositionX() + 3.5f));

    if (obj->transform()->getPositionX() > 2000) obj->remove();


}

void Pattern00Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    //UNREFERENCED_PARAMETER(dst);
   // Game::instance()->SubHp();
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

Pattern01Behavior::Pattern01Behavior()
{

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -60, -100, 60, 0 };

    param_.HP = 100;
    param_.ENEMY_DAMAGE = 1;
    param_.ANIME_HIT = animeEnemy_die;


}

void Pattern01Behavior::moveX(OBJ2D* obj)
{
    if (Ch1boss::instance()->GetBosshp() <= 0)         obj->actorComponent()->setAlive(0);

    obj->renderer()->setAnimeData(animeEnemy0_Left);

    obj->transform()->setPositionX((obj->transform()->getPositionX() - 3.5f));

    if (obj->transform()->getPositionX() < 30) obj->remove();


}

void Pattern01Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    // UNREFERENCED_PARAMETER(dst);
     //Game::instance()->SubHp();
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);


}


Pattern02Behavior::Pattern02Behavior()
{

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -40, -90,40 , -10 };

    param_.HP = 100;
    param_.ENEMY_DAMAGE = 1;
    param_.ANIME_HIT = animeEnemy_die;


}

void Pattern02Behavior::moveX(OBJ2D* obj)
{
    if (Ch1boss::instance()->GetBosshp() <= 0)         obj->actorComponent()->setAlive(0);


    if (Game::instance()->bg()->getReverseFlag() == false) {


        obj->renderer()->setAnimeData(animeStage5_pinkfront);

        obj->transform()->setPositionY((obj->transform()->getPositionY() + 2.0f));


    }

    else {
        obj->renderer()->setAnimeData(animeStage5_pinkback);

        obj->transform()->setPositionY((obj->transform()->getPositionY() + 2.0f));
    }

    if (obj->transform()->getPositionY() > 1920) obj->remove();

}

void Pattern02Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    //UNREFERENCED_PARAMETER(dst);
    if (!(Game::instance()->bg()->getReverseFlag())) {
        //src->remove();
       // Game::instance()->SubHp();
        playerHit(src, dst, getParam()->ENEMY_DAMAGE);

    }

}

Pattern03Behavior::Pattern03Behavior()
{

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -40, -90,40 , -10 };

    param_.HP = 100;
    param_.ENEMY_DAMAGE = 1;
    param_.ANIME_HIT = animeEnemy_die;

}

void Pattern03Behavior::moveX(OBJ2D* obj)
{
    if (Ch1boss::instance()->GetBosshp() <= 0)         obj->actorComponent()->setAlive(0);


    if (Game::instance()->bg()->getReverseFlag() == false) {


        obj->renderer()->setAnimeData(animeStage5_blueback);

        obj->transform()->setPositionY((obj->transform()->getPositionY() + 2.0f));


    }

    else {
        obj->renderer()->setAnimeData(animeStage5_bluefront);

        obj->transform()->setPositionY((obj->transform()->getPositionY() + 2.0f));
    }

    if (obj->transform()->getPositionY() > 1920) obj->remove();

}

void Pattern03Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    // UNREFERENCED_PARAMETER(dst);
    if ((Game::instance()->bg()->getReverseFlag())) {
        //  Game::instance()->SubHp();
        playerHit(src, dst, getParam()->ENEMY_DAMAGE);

    }

}

Pattern04Behavior::Pattern04Behavior()
{
    //param_.SIZE = VECTOR2();
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -1920, -192, 1920, 0 };

    param_.HP = 100;
    speedY = 1.0f;
    param_.ENEMY_DAMAGE = 1;
    state = 0;

}


void Pattern04Behavior::moveX(OBJ2D* obj)
{
    if (Ch1boss::instance()->GetBosshp() <= 0)         obj->remove();

    if (Restart::instance()->GetRestart()) {
        //obj->remove();
        //speedY = 0;
        state = 0;
        timer = 0;
        speedY = 1.0f;
       obj->transform()->setPosition( VECTOR2(1088 - (544 / 4), (1920)));

    }

    obj->renderer()->setAnimeData(animeStage5_water);


    switch (state) {

    case 0:


        obj->transform()->setPositionY(obj->transform()->getPositionY() - speedY);

        //上がって来たら止まる。
        if (obj->transform()->getPositionY() < 1088) { speedY = 0;   state++; }

        break;
    case 1:
        timer++;

        if (timer > 1300) {
            speedY = 1.5f;
            obj->transform()->setPositionY(obj->transform()->getPositionY() + speedY);

            if (obj->transform()->getPositionY() > 1088 + 192) {
                obj->remove();
                timer = 0;
                state = 0;
            }

        }
    }

    // if (obj->transform()->getPositionX() < 30) obj->remove();
}

void Pattern04Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

    //UNREFERENCED_PARAMETER(dst);
   // Game::instance()->SubHp();

}

Pattern05Behavior::Pattern05Behavior()
{
    param_.ANIME_RIGHT = animeStage5_bomb;

    param_.SIZE = VECTOR2(48 / 2, 128 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -120, -260, 120, -35 };


    param_.HP = 10;
    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;
}

void Pattern05Behavior::moveX(OBJ2D* obj)
{

    if (Ch1boss::instance()->GetBosshp() <= 0)         obj->remove();


    obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);

    switch (state) {

    case 0: state++;
        break;
    case 1:
        timer++;

        if (timer > 28) {
            obj->remove();
            timer = 0;
        }
        state = 0;
    }

}

void Pattern05Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    //UNREFERENCED_PARAMETER(dst);
   // Game::instance()->SubHp();
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

WaterMini::WaterMini()
{
    param_.ANIME_RIGHT = animeWaterMini;
    param_.ANIME_LEFT = animeWaterMini_re;

    param_.SIZE = VECTOR2(68 / 2, 68);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -25, -40, 25, -10 };


    param_.HP = 10;
    param_.ENEMY_DAMAGE = 1;

    state = 0;
    timer = 0;
    posY = 0;
}

void WaterMini::hit(OBJ2D*src, OBJ2D*dst)
{
    if(!Game::instance()->bg()->getReverseFlag()) playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}


void WaterMini::moveX(OBJ2D* obj)
{

    if(!Game::instance()->bg()->getReverseFlag())     obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);
    else obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);

    obj->transform()->addPositionY(1.0f);


    switch (StageSelect::instance()->getNum())
    {

    case 6: posY = 1280; break;
    case 7: posY = 1280; break;
    case 8: posY = 3006; break;
    break;
    }


    if (obj->transform()->getPositionY() > posY ) { obj->transform()->setPositionY(-obj->collider()->size().y); };

}




Block1Behavior::Block1Behavior()
{
    param_.ANIME_RIGHT = animeRuby1;
    param_.ANIME_HIT = animeEnemy_die2;

    param_.SIZE = VECTOR2(40/2, 400);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -10, -150, 10, 150 };


    param_.HP = 1;
    param_.ENEMY_DAMAGE = 0;
}


Block2Behavior::Block2Behavior()
{
    param_.ANIME_RIGHT = animeRuby2;    
    param_.ANIME_HIT = animeEnemy_die2;
    param_.SIZE = VECTOR2(40 / 2, 400);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -10, -150, 10, 150 };


    param_.HP = 3;
    param_.ENEMY_DAMAGE = 0;
}



Block3Behavior::Block3Behavior()
{
    param_.ANIME_RIGHT = animeRuby3;
    param_.ANIME_HIT = animeEnemy_die2;

    param_.SIZE = VECTOR2(40 / 2, 400);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -10, -150, 10, 150 };


    param_.HP = 6;
    param_.ENEMY_DAMAGE = 0;
}

Enemy10Behavior::Enemy10Behavior()
{
    param_.ANIME_RIGHT = animeMushroomR;
    param_.ANIME_LEFT = animeMushroomL;

    param_.ANIME_HIT = animeEnemy_die2;

    param_.SIZE = VECTOR2(150 , 100);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -120, -250, 120, 200 };


    param_.ACCEL_X = 3.0f;
    param_.ACCEL_Y = 2.0f;
    param_.SPEED_X_MAX = 5.0f;
    param_.SPEED_Y_MAX = 12.0f;

    param_.HP = 500;
    param_.ENEMY_DAMAGE = 1;
    state = 0;
    timer = 0;
}

void Enemy10Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

void Enemy10Behavior::moveHp(OBJ2D* obj)
{
   Midboss::instance()->setPositionX(obj->transform()->getPositionX()-150);
   Midboss::instance()->setPositionY(obj->transform()->getPositionY()-450);
   
   if (Midboss::instance()->GetBosshp() <= 10)
   {
       obj->actorComponent()->setAlive(0);
       if(Game::instance()->VolumeSelect(0) >= 1) music::fade(MUSIC::CH1_BOSS, 6.0f, 0.0f);
       state = 0;
       timer = 0;
   }
}

void Enemy10Behavior::moveX(OBJ2D* obj)
{
    calcAttackBox(obj);  //当たり判定用数値更新

    if (Restart::instance()->GetRestart()) {
        obj->transform()->setPositionX(4200);
        state = 0;
        timer = 0;
    }

    switch (state)
    {
    case 0:
    obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);
        obj->transform()->setPositionX(4200);

        if (Game::instance()->player()->actorComponent()->isPlayerMove()) {
            timer++;
                if (timer > 100) {
                    state++;
                }

            }
        break;

    case 1:     //右から左に動く
        obj->renderer()->setAnimeData(getParam()->ANIME_LEFT);

        obj->transform()->addPositionX(-getParam()->ACCEL_X);

    if (obj->transform()->getPositionX() < 1800)
    {
        state ++;
    }
    break;

    case 2:     //左から右に動く

        obj->renderer()->setAnimeData(getParam()->ANIME_RIGHT);
        obj->transform()->addPositionX(getParam()->ACCEL_X);

        if (obj->transform()->getPositionX() > 2800)
        {
            state=1;
        }

        break;
    }
}




Enemy11Behavior::Enemy11Behavior()
{
    param_.ANIME_RIGHT = animeMushroomAttack;
   // param_.ANIME_HIT = animeEnemy_die;

    param_.SIZE = VECTOR2(1000 / 2, 220 - 16);
    param_.SCALE = VECTOR2(1, 1);

    param_.HIT_BOX = { -680, -220, 680, -35 };

    param_.ACCEL_X = 4.0f;
    param_.ACCEL_Y = 3.0f;
    param_.SPEED_X_MAX = 0.0f;
    param_.SPEED_Y_MAX = 0.0f;

    param_.HP = 100;
    param_.ENEMY_DAMAGE = 1;
    state = 0;
    timer = 0;
    speedY = 0;
    scrollX = 30;
    oldposY = 0;
}

void Enemy11Behavior::hit(OBJ2D* src, OBJ2D* dst)
{
    playerHit(src, dst, getParam()->ENEMY_DAMAGE);

}

void Enemy11Behavior::moveX(OBJ2D* obj)
{


    if (Restart::instance()->GetRestart()) {
        speedY = 0;
        state = 0;
        timer = 0;
        scrollX = 30;

        //obj->transform()->setPositionY(100.0f);
       // Game::instance()->player()->actorComponent()->setPlayerMove(false);
        music::stop(SOUND::STAGE8_WARNING);
    }

    switch (state)
    {
    case 0:

       obj->transform()->setPositionY(100.0f);
        if (Game::instance()->player()->actorComponent()->isPlayerMove()) {
            Game::instance()->bg()->addScrollX(10.0f);
            scrollX -= 0.3f;
            

            if (scrollX <= 0) {

                state = 1;
                
            }
        }

        break;
    case 1:
        speedY = 1.0f;
        obj->transform()->addPositionY(speedY);
        if (obj->transform()->getPositionY() >= 1000) state++;

        break;
    case 3:

        obj->transform()->setPositionY(1000);

        break;


    }

    if (Midboss::instance()->GetBosshp() <= 10){

        obj->renderer()->addColor_a(-0.1f);
        if (obj->renderer()->getColor_a() <= 0) {
            speedY = 0;
            state = 0;
            timer = 0;
            scrollX = 30;
            obj->remove();

        }
    }

}
