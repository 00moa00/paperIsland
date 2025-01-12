#include "all.h"


//----------------------------------------------------------------------
//  BackCoudの揺れ
//----------------------------------------------------------------------
void BGCloud::cloudMove(SpriteManager* sprObj)
{
    
 sprObj->addPosX(-0.1f);


    //端までx移動したら右に移動させる(画像をループさせる)
    if (sprObj->getPosX() <= -sprObj->getTexSizeX())
    {
        //ステージによって画像サイズが異なるため、texSize.xのゲッターを使って判定する
        //ステージ1の場合はtexSize.xが6400なので、pos.xが-6400以下になると+6400に修正する
        sprObj->addPosX(sprObj->getTexSizeX() * 2);
    }


}

BGCloud::BGCloud()
{

    CloudSpeedY = 0.0f;

    // ステージ番号取得
    num = StageSelect::instance()->getNum();

    switch (num)
    {
        case 0:

            sprBackCloud1 = nullptr;
            sprBackCloud2 = nullptr;

            sprBackSky = nullptr;

            break;

    case 1:
        //ステージ1用の画像を用意
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage1_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage1_cloud.png", VECTOR2(6400, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));

        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back1_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));


        break;

    case 2:

        //ステージ2用の画像を用意
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage2_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage2_cloud.png", VECTOR2(4992, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back2_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));

        break;

    case 3:

        //ステージ3用の画像を用意
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage3_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage3_cloud.png", VECTOR2(3200, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back3_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));

        break;

    case 4:

        //ステージ4用の画像を用意
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage4_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage4_cloud.png", VECTOR2(4992, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back4_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));

        break;

    case 5:
        //ステージ5用の画像を用意
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage5_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage5_cloud.png", VECTOR2(4448, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back5_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));


        break;

    }

}



BGCloud::~BGCloud()
{
    //sprBackCloudが存在するときはdeleteする(ステージ1～ステージ4だけnewするため)

    
    if (sprBackCloud1 != nullptr)delete sprBackCloud1;
    if (sprBackCloud2 != nullptr)    delete sprBackCloud2;

    if (sprBackSky != nullptr)    delete sprBackSky;

    

}

void BGCloud::update()
{
    //雲を動かす
    if (sprBackCloud1 != nullptr)
    {
        cloudMove(sprBackCloud1);
        cloudMove(sprBackCloud2);

    }

}

void BGCloud::draw(const VECTOR2 scrollPos)
{

    switch (num)
    {
    case 0:
        break;
    case 1:

        //空の描画
        sprBackSky->draw_cloud(scrollPos);

        //雲の描画
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);



        break;

    case 2:

        //空の描画
        sprBackSky->draw_cloud(scrollPos);

        //雲の描画
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);


        break;


    case 3:

        //空の描画
        sprBackSky->draw_cloud(scrollPos);

        //雲の描画
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);

        break;

    case 4:


        //空の描画
        sprBackSky->draw_cloud(scrollPos);

        //雲の描画
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);


        break;

    case 5:
        //空の描画
        sprBackSky->draw_cloud(scrollPos);

        //雲の描画
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);


        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    }

}

//void BGCloud::clear()
//{
//    //sprBackCloudが存在するときはdeleteする(ステージ1～ステージ4だけnewするため)
//    if (sprBackCloud[0])
//    {
//        delete sprBackCloud[0];
//        delete sprBackCloud[1];
//        //空と木の画像を分けてるのはステージ1～ステージ4だけなので、空の画像の解放もここで処理する
//        delete sprBackSky;
//    }
//}
//
