//******************************************************************************
//
//
//      タイトル
//
//
//******************************************************************************

//------< インクルード >----------------------------------------------------------
#include "all.h"
#include<filesystem>
//------< using >---------------------------------------------------------------
using namespace GameLib;

Title Title::instance_;

Title::~Title()
{
}

void Title::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ

    sprTitle_front = new SpriteManager(L"./Data/Images/SCENE/title_front.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    sprTitle_back = new SpriteManager(L"./Data/Images/SCENE/title_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    sprTitle_move1 = new SpriteManager(L"./Data/Images/SCENE/title_move1.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    sprTitle_move2 = new SpriteManager(L"./Data/Images/SCENE/title_move2.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    sprTitle_start = new SpriteManager(L"./Data/Images/SCENE/start.png", VECTOR2(960, 600), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(297, 208));
    sprTitle_reset =  new SpriteManager(L"./Data/Images/SCENE/reset.png", VECTOR2(1470, 600), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(297, 208));
    sprTitle_exit = new SpriteManager(L"./Data/Images/SCENE/exit.png", VECTOR2(1180, 780), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(296, 211));
    sprTitle_notice = new SpriteManager(L"./Data/Images/SCENE/title_notice.png", VECTOR2(1328, 1024), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(592, 56));


    sprTitle_yes = new SpriteManager(L"./Data/Images/SCENE/resetYes.png", VECTOR2(358, 285), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1191, 517));
    sprTitle_no = new SpriteManager(L"./Data/Images/SCENE/resetNo.png", VECTOR2(358, 285), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1191, 517));



    move1_speedY = 0.18f;
    move2_speedY = -0.2f;

    moveSpeedY = 0.5f;


    select = 0;

    yesFlag = false;
    noFlag = false;

    selectMove = true;
    popUpState = 0;
}

//--------------------------------------------------------------
//  更新処理
//--------------------------------------------------------------
void Title::update()
{

    
    switch (state)
    {
    case 0 :

        music::play(MUSIC::TITLE,true);
        state++;

    case 1:
        using namespace input;

        sprTitle_move1->addPosY(move1_speedY);
        sprTitle_move2->addPosY(move2_speedY);

        if (sprTitle_move1->getPosY() >= 20.0f || sprTitle_move1->getPosY() < 0.0f) move1_speedY *= -1;
        if(sprTitle_move2->getPosY() < -10.0f || sprTitle_move2->getPosY() >= 0.0f) move2_speedY *= -1;

        //if (move1_speedY > 1.0f) move1_speedY *= -1.0f;
        //if (move2_speedY < -0.6f) move2_speedY *= -1.0f;

        if (!yesFlag || !noFlag) { selectMove = true; }


        if (GetAsyncKeyState(VK_ESCAPE) & 1) PostQuitMessage(1);
 

        //select
        switch (select)
        {
        case 0:
            //start
            //移動させる

            sprTitle_start->addPosY(moveSpeedY);
            sprTitle_reset->setPosY(600);
            sprTitle_exit->setPosY(780);


            if (sprTitle_start->getPosY() < 590.0f || sprTitle_start->getPosY() >= 610.0f) moveSpeedY *= -1.0f;


            if (TRG(0) & PAD_START) {
                music::play(SOUND::MENU_SELECT);

                //changeScene(StageSelect::instance());// ゲームシーンに切り替え
               //changeScene(GameLoading::instance());// ゲームシーンに切り替え
                titleFlag = true;

                changeScene(Game::instance());// ゲームシーンに切り替え
            }



            if (selectMove) {
                if (TRG(0) & PAD_LEFT) {
                    music::play(SOUND::MENU_SELECT);

                    select = 2;
                }
                if (TRG(0) & PAD_RIGHT) {
                    music::play(SOUND::MENU_SELECT);

                    select++;
                }
            }

            break;
        case 1:

            //reset
            //移動させる
            sprTitle_reset->addPosY(moveSpeedY);
            sprTitle_start->setPosY(600);
            sprTitle_exit->setPosY(780);



            if (sprTitle_reset->getPosY() < 590.0f || sprTitle_reset->getPosY() >= 610.0f) moveSpeedY *= -1.0f;

            if (TRG(0) & PAD_START) {
                popUpState = 0;
                select = 4;
            }



            if (selectMove) {
                if (TRG(0) & PAD_LEFT) {
                    music::play(SOUND::MENU_SELECT);

                    select--;
                }
                if (TRG(0) & PAD_RIGHT) {
                    music::play(SOUND::MENU_SELECT);

                    select++;
                }
            }
            break;

        case 2:

            //exit
            //移動させる
            sprTitle_exit->addPosY(moveSpeedY);
            sprTitle_start->setPosY(600);
            sprTitle_reset->setPosY(600);

            if (sprTitle_exit->getPosY() < 770.0f || sprTitle_exit->getPosY() >= 790.0f) moveSpeedY *= -1.0f;




            if (TRG(0) & PAD_START) {
                PostQuitMessage(1); //ゲーム終了
            }

            if (selectMove) {

                if (TRG(0) & PAD_RIGHT) {
                                    music::play(SOUND::MENU_SELECT);

                    select = 0;
                }
                if (TRG(0) & PAD_LEFT) {
                    music::play(SOUND::MENU_SELECT);

                    select--;
                }

            }

            break;

        case 4:
           popUp();


        }
       
    }


    //debug::setString("select num:%d", select);

}

//--------------------------------------------------------------
//  描画処理
//--------------------------------------------------------------
void Title::draw()
{


    //タイトルイメージ
    GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

    font::textOut(4, "Push Start Button", { 0, 0 }, { 2, 2 }, { 0, 0, 1, 1 });
    

    // タイトル表示
   
    sprTitle_back->draw();
    sprTitle_move1->draw();
    sprTitle_move2->draw();
    sprTitle_front->draw();
    sprTitle_start->draw();
    sprTitle_exit->draw();
    sprTitle_reset->draw();

    sprTitle_notice->draw();
    
    if (yesFlag) sprTitle_yes->draw();
    if (noFlag) sprTitle_no->draw();

}

void Title::deinit()
{
    delete sprTitle_front;
    delete sprTitle_back;
    delete sprTitle_move1;
    delete sprTitle_move2;
    delete sprTitle_start;
    delete sprTitle_exit;
    delete sprTitle_reset;

    delete sprTitle_yes;
    delete sprTitle_no;

    delete sprTitle_notice;
}

void Title::popUp()
{
    using namespace input;


    switch (popUpState)
    {
    case 0:

        yesFlag = true;

        if ((TRG(0) & PAD_START) && yesFlag ) {
            music::play(SOUND::MENU_SELECT);

            std::filesystem::path p("./stageSave.dat");
            std::filesystem::remove(p);

            std::filesystem::path p2("./playerHpSave.dat");
            std::filesystem::remove(p2);
            selectMove = true;
            select = 1;
            yesFlag = false;
        }

        if ((TRG(0) & PAD_RIGHT)|| (TRG(0) & PAD_LEFT)) {
            music::play(SOUND::MENU_SELECT);

            yesFlag = false;
            noFlag = true;

            popUpState++;
        }
        break;
    case 1:

       // noFlag = true;

        if ((TRG(0) & PAD_START) && noFlag) {
            music::play(SOUND::MENU_SELECT);

            noFlag = false;
            selectMove = true;

            select = 1;

        }

        if ((TRG(0) & PAD_LEFT)|| (TRG(0) & PAD_RIGHT)) {
            music::play(SOUND::MENU_SELECT);

            yesFlag = true;
            noFlag = false;

            popUpState--;
        }
    break;

    }


    //if (TRG(0) & PAD_RIGHT && !selectMove && !yesFlag) {
    //    selectMove = true;
    //    yesFlag = false;
    //    noFlag = true;
    //    if (TRG(0) & PAD_START) {
    //        noFlag = false;
    //        selectMove = true;
    //    }
    //    //PostQuitMessage(1); //ゲーム終了
    //}

    //if (selectMove) {

    //    if (TRG(0) & PAD_RIGHT) select++;
    //    if (TRG(0) & PAD_LEFT) select--;

    //}
}

//******************************************************************************
