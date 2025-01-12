#include "all.h"


//----------------------------------------------------------------------
//  BackCoud�̗h��
//----------------------------------------------------------------------
void BGCloud::cloudMove(SpriteManager* sprObj)
{
    
 sprObj->addPosX(-0.1f);


    //�[�܂�x�ړ�������E�Ɉړ�������(�摜�����[�v������)
    if (sprObj->getPosX() <= -sprObj->getTexSizeX())
    {
        //�X�e�[�W�ɂ���ĉ摜�T�C�Y���قȂ邽�߁AtexSize.x�̃Q�b�^�[���g���Ĕ��肷��
        //�X�e�[�W1�̏ꍇ��texSize.x��6400�Ȃ̂ŁApos.x��-6400�ȉ��ɂȂ��+6400�ɏC������
        sprObj->addPosX(sprObj->getTexSizeX() * 2);
    }


}

BGCloud::BGCloud()
{

    CloudSpeedY = 0.0f;

    // �X�e�[�W�ԍ��擾
    num = StageSelect::instance()->getNum();

    switch (num)
    {
        case 0:

            sprBackCloud1 = nullptr;
            sprBackCloud2 = nullptr;

            sprBackSky = nullptr;

            break;

    case 1:
        //�X�e�[�W1�p�̉摜��p��
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage1_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage1_cloud.png", VECTOR2(6400, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));

        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back1_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));


        break;

    case 2:

        //�X�e�[�W2�p�̉摜��p��
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage2_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage2_cloud.png", VECTOR2(4992, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back2_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));

        break;

    case 3:

        //�X�e�[�W3�p�̉摜��p��
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage3_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage3_cloud.png", VECTOR2(3200, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back3_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));

        break;

    case 4:

        //�X�e�[�W4�p�̉摜��p��
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage4_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage4_cloud.png", VECTOR2(4992, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back4_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));

        break;

    case 5:
        //�X�e�[�W5�p�̉摜��p��
        sprBackCloud1 = new SpriteManager(L"./Data/Maps/BACK/stage5_cloud.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));
        sprBackCloud2 = new SpriteManager(L"./Data/Maps/BACK/stage5_cloud.png", VECTOR2(4448, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));


        sprBackSky = new SpriteManager(L"./Data/Maps/BACK/back5_back.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));


        break;

    }

}



BGCloud::~BGCloud()
{
    //sprBackCloud�����݂���Ƃ���delete����(�X�e�[�W1�`�X�e�[�W4����new���邽��)

    
    if (sprBackCloud1 != nullptr)delete sprBackCloud1;
    if (sprBackCloud2 != nullptr)    delete sprBackCloud2;

    if (sprBackSky != nullptr)    delete sprBackSky;

    

}

void BGCloud::update()
{
    //�_�𓮂���
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

        //��̕`��
        sprBackSky->draw_cloud(scrollPos);

        //�_�̕`��
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);



        break;

    case 2:

        //��̕`��
        sprBackSky->draw_cloud(scrollPos);

        //�_�̕`��
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);


        break;


    case 3:

        //��̕`��
        sprBackSky->draw_cloud(scrollPos);

        //�_�̕`��
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);

        break;

    case 4:


        //��̕`��
        sprBackSky->draw_cloud(scrollPos);

        //�_�̕`��
        sprBackCloud1->draw_cloud(scrollPos);
        sprBackCloud2->draw_cloud(scrollPos);


        break;

    case 5:
        //��̕`��
        sprBackSky->draw_cloud(scrollPos);

        //�_�̕`��
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
//    //sprBackCloud�����݂���Ƃ���delete����(�X�e�[�W1�`�X�e�[�W4����new���邽��)
//    if (sprBackCloud[0])
//    {
//        delete sprBackCloud[0];
//        delete sprBackCloud[1];
//        //��Ɩ؂̉摜�𕪂��Ă�̂̓X�e�[�W1�`�X�e�[�W4�����Ȃ̂ŁA��̉摜�̉���������ŏ�������
//        delete sprBackSky;
//    }
//}
//
