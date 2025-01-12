#include "all.h"



Paper::Paper()
{
    num = StageSelect::instance()->getNum();

    switch (num)
    {
    case 0:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper0.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    case 1:
        sprPaper = nullptr;
        break;

    case 2:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper2.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    case 3:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper3.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;
    case 4:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper4.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    case 5:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper5.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    case 6:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper6.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    case  7:
        sprPaper = nullptr;
        break;
    case 8:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper8.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    case 9:
        sprPaper = nullptr;
        break;
    case 10:
        sprPaper = new SpriteManager(L"./Data/images/PAPER/paper10.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        break;

    }

    paperFlag = false;
}


void Paper::init()
{

}

void Paper::draw()
{
    if (sprPaper != nullptr) sprPaper->draw();
}


Paper::~Paper()
{
    if(sprPaper != nullptr) delete sprPaper;

}
