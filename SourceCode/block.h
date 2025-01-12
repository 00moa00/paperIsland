#pragma once

//******************************************************************************
//
//
//      block.h
//
//
//******************************************************************************

void setBlock(OBJ2DManager* obj2dManager, BG* bg);

//==============================================================================
//
//      BaseBlockBehavior
//
//==============================================================================

class BaseBlockBehavior : public Behavior
{
protected:
    struct Param {
        GameLib::SpriteData* SPR_BLOCK=nullptr;
        VECTOR2 SIZE = {};
        VECTOR2 SPEED = {};
        GameLib::fRECT ATTACK_BOX = {};
        VECTOR2 SCALE = { 1, 1 };
    } param_;

protected:
    const Param* getParam() const { return &param_; }
    void setParam_speed(VECTOR2 n) { param_.SPEED = n; }
    float stageLimitPosRight = 0;
    float stageLimitPosLeft = 0;
    float stageLimitPosUp = 0;
    float stageLimitPosDown = 0;


private:
    void move(OBJ2D* obj);
    virtual void moveX(OBJ2D* ) {};
    virtual void moveY(OBJ2D* ) {};
    virtual void update(OBJ2D* ) = 0;        // 位置に速度を足す
    virtual void calcAttackBox(OBJ2D* ) = 0; // 攻撃用あたり領域の計算
    virtual void areaCheck(OBJ2D*) {};

    OBJ_TYPE getType() const override { return OBJ_TYPE::BLOCK; }
    OBJ_TYPE attackType() const override { return OBJ_TYPE::PLAYER; }

};

//==============================================================================
//
//      BlockPar  平行横移動するブロック
//
//==============================================================================

class BlockPar_YO : public BaseBlockBehavior
{
public:
    BlockPar_YO();
    void update(OBJ2D* obj) override;
    void calcAttackBox(OBJ2D* obj) override;
    void hit(OBJ2D* src, OBJ2D* dst) override;
    void moveX(OBJ2D* obj) override;
    void areaCheck(OBJ2D* obj) override;
};

EXTERN BlockPar_YO      blockpar_YO;

class BlockPar_UP : public BaseBlockBehavior
{
public:
    BlockPar_UP();
    void update(OBJ2D* obj) override;
    void calcAttackBox(OBJ2D* obj) override;
    void hit(OBJ2D* src, OBJ2D* dst) override;
    void moveY(OBJ2D* obj) override;
    void areaCheck(OBJ2D* obj) override;

};

EXTERN BlockPar_UP      blockpar_UP;



class BlockEraser : public Eraser
{
private:
    void erase(OBJ2D* obj) override;
};
EXTERN BlockEraser blockEraser;


class DropBlock : public BaseBlockBehavior
{
private:
    VECTOR4 color;

public:
    DropBlock();
    void update(OBJ2D* obj) override;
    void calcAttackBox(OBJ2D* obj) override;
    void hit(OBJ2D* src, OBJ2D* dst) override;
    void moveY(OBJ2D* obj) override;
};

EXTERN DropBlock dropBlock;

