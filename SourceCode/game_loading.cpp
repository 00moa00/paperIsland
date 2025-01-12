#include "all.h"

GameLoading GameLoading::instance_;


GameLoading::GameLoading()
{
 

}

void GameLoading::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ

    Drawflag = true;
    sprGameloading = new SpriteManager(L"./Data/Images/SCENE/loading.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
    sprLoadingBook = new SpriteManager(L"./Data/Images/SCENE/LoadingBook.png", VECTOR2(820, 750), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(220, 200));
    sprNotice = new SpriteManager(L"./Data/Images/SCENE/loading_notice.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
    sprWarning = new SpriteManager(L"./Data/Images/SCENE/loadingWarning.png", VECTOR2(0, 980), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 84));
}

void GameLoading::update()
{
    if (GetAsyncKeyState(VK_ESCAPE) & 1) PostQuitMessage(1);



    switch (state)
    {
    case 0:

        
        using namespace GameLib;
        music::play(MUSIC::LOADING);
        audio_setVolume_BGM(MUSIC::LOADING, 1.0f);
        Drawflag = true;


        timer = 0;
        state++;
        break;

    case 1:
        

        //体力が 1 以上の時次のステージに移動(=体力が0だったら死んだステージからリスタート) 
        if (HP::instance()->GetHp() >= 1)  StageSelect::instance()->addNum();
       
        state++;
    case 2:

        if (StageSelect::instance()->getNum() > 0) {
            GameLib::clear(VECTOR4(1, 1, 1, 1));
        }
        state++;
        break;
    case 3:
        timer++;
        bookTimer = timer / 10;
        sprLoadingBook->setTexPosX(bookTimer * 220.0f);

        if (timer >= 150) sprLoadingBook->setTexPosX((bookTimer - 1) * 220.0f);

        if (timer > 150) {
            state = 0;
            timer = 0;
            Drawflag = false;
            PlayerClear::instance()->init();
            changeScene(Game::instance());


        }


    }

    using namespace GameLib;

}

void GameLoading::draw()
{
    //using namespace GameLib;
    if (Drawflag) {
        sprGameloading->draw();
        sprLoadingBook->draw();
        sprNotice->draw();
        sprWarning->draw();
    }

}

void GameLoading::deinit()
{
    timer = 0;
    state = 0;
    delete sprGameloading;
    delete sprLoadingBook;
    delete sprNotice;
    delete sprWarning;


}


GameLoading::~GameLoading()
{

}
