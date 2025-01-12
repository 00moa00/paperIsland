#pragma once

//******************************************************************************
//
//
//      Player.h
//
//
//******************************************************************************

//==============================================================================
//
//      移動アルゴリズム
//
//==============================================================================
//void playerHit(OBJ2D*, OBJ2D*, int damage);

class BasePlayerBehavior : public ActorBehavior
{
private:
    // BasePlayerBehavior() { animeTimer = 0; attackflag = false; }

    void moveX(OBJ2D* obj) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::PLAYER; }
    OBJ_TYPE attackType() const override { return OBJ_TYPE::ENEMY; }
    void hit(OBJ2D*, OBJ2D*) override {};
    bool isAlive(OBJ2D* obj) override;
    void moveHp(OBJ2D* ) {};

    int animeTimer = 0;
    int dieTimer = 0;

protected:
    bool attackflag = false;
    int oldAttackTimer = 0;
    int outAttackTimer_Throw = 0;
    int outAttackTimer_Make = 0;
    bool make_ani = false;

};

class WalkPlayerBehavior : public BasePlayerBehavior
{
private:

public:
    WalkPlayerBehavior();
    void K_Animation(OBJ2D* obj);
    void hitAnime(OBJ2D* obj);


private:
    void moveY(OBJ2D* obj) override;
    void jump(OBJ2D* obj) override;
    void attack(OBJ2D* obj) override;
};

EXTERN WalkPlayerBehavior walkPlayerBehavior;


//==============================================================================
//
//      消去アルゴリズム
//
//==============================================================================

// 消去アルゴリズム
class ErasePlayer : public Eraser
{
    void erase(OBJ2D* obj);
};

// 消去アルゴリズムの実体
//EXTERN ErasePlayer      erasePlayer;
