#include "all.h"

GameClear GameClear::instance_;
using namespace GameLib;

void GameClear::init()
{
    sprGameclear = new SpriteManager(L"./Data/Images/SCENE/clear.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1080));
}

void GameClear::update()
{
    switch (state_)
    {
    case 0:
        using namespace input;
        music::play(MUSIC::CLEAR, true);
        state_++;
    case 1:
        if (TRG(0) & PAD_START || GetAsyncKeyState(VK_ESCAPE) & 1) {
            PostQuitMessage(1);
        }

    }


}

void GameClear::draw()
{
    sprGameclear->draw();
}

void GameClear::deinit()
{
    delete sprGameclear;
}
