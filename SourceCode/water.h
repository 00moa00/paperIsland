#pragma once

using namespace GameLib;
class stage8Water
{
protected:
    struct Param
    {
        GameLib::Sprite* spr;
        VECTOR2 pos;
        VECTOR2 scale;

        VECTOR2 texpos;
        VECTOR2 texsize;
        VECTOR2 texscale;

        VECTOR4 cloer;
        float angle;
    }param_ = {};

    float speedY;

    const Param* getParam() { return &param_; }

public:

    stage8Water() {
        param_.spr = sprite_load(L"./Data/Images/ENEMY/stage8_water2.png");

        chapterStar::getStageChapter = 0;

        param_.pos = { 0,2900 };
        param_.scale = { 1.0f, 1.0f };
        param_.texpos = { 1,1 };
        param_.texscale = { 1,1 };
        param_.texsize = { 2400,2061 };
        param_.angle = 0.0f;
        param_.cloer = { 1,1,1,1 };

        speedY = 1.5f;
    }

    ~stage8Water() {
       safe_delete(param_.spr);
       param_.pos = { 0,1000 };

    }
    void update() {
        param_.pos.y -= speedY;

        if (param_.pos.y < 3008-2061) { speedY = 0; }

    }

    void draw(const VECTOR2& scrollPos) {

        GameLib::sprite_render(
            param_.spr,
            param_.pos.x-scrollPos.x, param_.pos.y - scrollPos.y,
            param_.scale.x, param_.scale.y,
            param_.texpos.x, param_.texpos.y,
            param_.texsize.x, param_.texsize.y,
            0, 0,
            param_.angle,
            param_.cloer.x, param_.cloer.y, param_.cloer.z, param_.cloer.w,
            true);
    }

};



class WaterSprite
{
private:
       SpriteManager* sprWater = nullptr;

public:
    WaterSprite() {


        switch (StageSelect::instance()->getNum())
        {
        case 1:
            sprWater = nullptr;
            break;
        case 2:
            sprWater = nullptr;
            break;
        case 3:
            sprWater = nullptr;
            break;
        case 4:
            sprWater = nullptr;
            break;
        case 5:
            sprWater = new SpriteManager(L"./Data/Maps/BACK/back5_water.png", VECTOR2(4448-2511, 3008-140), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(2511, 140));
            break;
        case 6:
            sprWater = new SpriteManager(L"./Data/Maps/BACK/back6_water.png", VECTOR2(0, 1280-132), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(2592, 132));
            break;

        case 7:
            sprWater = new SpriteManager(L"./Data/Maps/BACK/back7_water.png", VECTOR2(0, 1280-156), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(4992, 156));
            break;

        case 9:
            sprWater = nullptr;
            break;
        case 10:
            sprWater = nullptr;
        }


    }

    ~WaterSprite() {
        if (sprWater != nullptr) delete sprWater;
    }

    void draw(const VECTOR2 scrollPos) {
        if (sprWater != nullptr) sprWater->draw_cloud(scrollPos);
    }


};