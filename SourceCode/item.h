#pragma once

//******************************************************************************
//
//
//      item.h
//
//
//******************************************************************************

void setItem(OBJ2DManager* obj2dManager, BG* bg);

//==============================================================================
//
//      BaseItemBehavior
//
//==============================================================================

class BaseItemBehavior : public Behavior
{
protected:
    struct Param {
        GameLib::SpriteData* SPR_ITEM = nullptr;
        VECTOR2 SIZE = {};
        GameLib::fRECT ATTACK_BOX = {};
        VECTOR2 SCALE = { 1, 1 };
    } param_;

protected:
    const Param* getParam() const { return &param_; }
private:
    void move(OBJ2D* obj) override;

    OBJ_TYPE getType() const override { return OBJ_TYPE::ITEM; }
    OBJ_TYPE attackType() const override { return OBJ_TYPE::PLAYER; }
};

//==============================================================================
//
//      ItemSword
//
//==============================================================================

class ItemWeapon : public BaseItemBehavior
{
public:
    ItemWeapon();
    void hit(OBJ2D* src, OBJ2D* dst) override;
};

//==============================================================================
//
//      ItemKey
//
//==============================================================================

class ItemHp : public BaseItemBehavior
{
public:
    ItemHp();
    void hit(OBJ2D* src, OBJ2D* ) override;
};

//==============================================================================
//
//      ItemMove
//
//==============================================================================

class ItemMove : public BaseItemBehavior
{
public:
    ItemMove();
    void hit(OBJ2D* , OBJ2D* ) override;
};

//==============================================================================
//
//      ItemMoveflag
//
//==============================================================================

class ItemMoveFlag : public BaseItemBehavior
{
public:
    ItemMoveFlag();
    void hit(OBJ2D* src, OBJ2D* ) override;
};


//==============================================================================
//
//      ItemPaper
//
//==============================================================================

class ItemPaper : public BaseItemBehavior
{
public:
    ItemPaper();
    void hit(OBJ2D* , OBJ2D* ) override;
};


EXTERN ItemWeapon    itemWeapon;
EXTERN ItemHp        itemHp;
EXTERN ItemMove      itemMove;
EXTERN ItemMoveFlag  itemMoveFlag;

EXTERN ItemPaper  itemPaper;