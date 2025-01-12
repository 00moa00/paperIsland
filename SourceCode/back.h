#pragma once

class BackSprite
{
public:
    SpriteManager* back = nullptr;
    
    BackSprite()
    {
        switch (StageSelect::instance()->getNum())
        {
        case 0:
            back = new SpriteManager(L"./Data/Maps/BACK/back0.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
            break;

        case 1:
            back = new SpriteManager(L"./Data/Maps/BACK/back1.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(6400, 1280));
            break;

        case 2:
            back = new SpriteManager(L"./Data/Maps/BACK/back2.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1760));
            break;

        case 3:
            back = new SpriteManager(L"./Data/Maps/BACK/back3.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(3200, 3008));
            break;

        case 4:
            back = new SpriteManager(L"./Data/Maps/BACK/back4.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1088));
            break;

        case 5:
            back = new SpriteManager(L"./Data/Maps/BACK/back5.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4448, 3008));
            break;

        case 6:
            back = new SpriteManager(L"./Data/Maps/BACK/back6.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(2592, 1280));
            break;

        case 7:
            back = new SpriteManager(L"./Data/Maps/BACK/back7.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 1280));
            break;

        case 8:
            back = new SpriteManager(L"./Data/Maps/BACK/back8.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(2400, 3088));
            break;

        case 9:
            back = new SpriteManager(L"./Data/Maps/BACK/back9.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
            break;

        case 10:
            back = new SpriteManager(L"./Data/Maps/BACK/back10.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
            break;
        }


    }

    void draw(const VECTOR2 scrollPos) {
        if (back != nullptr) back->draw_cloud(scrollPos);
    }

    ~BackSprite() {
        if (back != nullptr) delete back;
    }
    

};
