#pragma once

class SpriteManager
{
private:
    GameLib::Sprite* data_;

    VECTOR2 pos_;
    VECTOR2 scale_;
    VECTOR2 texpos_;
    VECTOR2 texsize_;
    float angle_;
    VECTOR4 color_;

public:
    SpriteManager(const wchar_t* filepath, VECTOR2 pos, VECTOR2 scale, VECTOR2 texpos, VECTOR2 texsize);
    ~SpriteManager();

    void update();
    void draw();
    void draw_cloud(const VECTOR2 scrollPos);

    void release();

    //sub
    void subTexsizeX(float a) { texsize_.x -= a; }
    void subAlphaA(float a) { color_.w -= a; }

    //setter
    void setScale(VECTOR2 a) { scale_ = a; }
    void setAlphaA(float a) { color_.w = a; }
    void setTexPosX(float a) { texpos_.x = a; }
    void setTexPosY(float a) { texpos_.y = a; }
    void setPosY(float a) { pos_.y = a; }
    void setPosX(float a) { pos_.x = a; }

    //getter
    float getPosX() { return pos_.x; }
    float getPosY() { return pos_.y; }
    float getTexSizeX() { return texsize_.x; }
    float getAlpha() { return color_.w; }

    //add
    void addPosX(float a) { pos_.x += a; }
    void addPosY(float a) { pos_.y += a; }
    void addAlpha(float a) { color_.w += a; }

};