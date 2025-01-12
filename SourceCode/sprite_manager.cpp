#include "all.h"

using namespace GameLib;

SpriteManager::SpriteManager(const wchar_t* filepath, VECTOR2 pos, VECTOR2 scale, VECTOR2 texpos, VECTOR2 texsize)
{
    // initialize(filepath,pos, scale);
    data_ = sprite_load(filepath);
    pos_ = pos;
    scale_ = scale;
    texpos_ = texpos;
    texsize_ = texsize;
    angle_ = 0;
    color_ = { 1,1,1,1 };
}

SpriteManager::~SpriteManager()
{
    release();
}


void SpriteManager::update()
{
    // subTexsizeY();
}

void SpriteManager::draw_cloud(const VECTOR2 scrollPos)
{
    sprite_render(
        data_,
        pos_.x - scrollPos.x, pos_.y - scrollPos.y,
        scale_.x, scale_.y,
        texpos_.x, texpos_.y,
        texsize_.x, texsize_.y,
        0, 0,
        0,
        color_.x, color_.y, color_.z, color_.w
    );
}

void SpriteManager::draw()
{

    sprite_render(
        data_,
        pos_.x , pos_.y,
        scale_.x, scale_.y,
        texpos_.x, texpos_.y,
        texsize_.x, texsize_.y,
        0, 0,
        0,
        color_.x, color_.y, color_.z, color_.w
    );
}

void SpriteManager::release()
{
    safe_delete(data_);
    pos_ = {};
    scale_ = {};
}




