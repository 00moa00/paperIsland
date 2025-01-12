#pragma once

void setEnemy(OBJ2DManager* obj2dManager, BG* bg);
void setTuBlock(OBJ2DManager* obj2dManager, BG* bg);
class BaseEnemyBehavior : public ActorBehavior
{
private:
    void moveY(OBJ2D* obj);
    void moveX(OBJ2D* obj);
    void turn(OBJ2D* obj);
    void moveHp(OBJ2D* ) {};
    virtual void gakeTurn(OBJ2D* obj);
    //virtual OBJ_TYPE getType() = 0;
    OBJ_TYPE attackType() const override { return OBJ_TYPE::PLAYER; }

    bool isAlive(OBJ2D* obj) override;
    bool die_animation(OBJ2D* obj);


    int die_timer;

protected:
    BaseEnemyBehavior() : die_timer(0), timer(0), state(0), state2(0), aliveState(0), oldPosX(0.0f) {}
    void calcAttackBox(OBJ2D* obj) ;

    int timer ;
    int state ;
    int state2;
    int aliveState;
    float oldPosX;

    bool Shotdieflag = false;
    void enemy01ShotAlive(OBJ2D* obj);
};

//虫
class Enemy0Behavior : public BaseEnemyBehavior
{
public:
    Enemy0Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

};

//ひまわり
class SunF_R_Behavior : public BaseEnemyBehavior
{
public:
    SunF_R_Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);

};

//ひまわり2
class SunF_L_Behavior : public BaseEnemyBehavior
{
public:
    SunF_L_Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);

};


//虫
class Enemy9Behavior : public BaseEnemyBehavior
{
public:
    Enemy9Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);
    float oldposY;
    float oldposX;

};




//キノコ
class Enemy10Behavior : public BaseEnemyBehavior
{
public:
    Enemy10Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }
    void moveHp(OBJ2D* obj);
    void moveX(OBJ2D* obj);
    void moveY(OBJ2D*) {}


private:

    //float oldposY;
    //float oldposX;

};


//キノコのとげ
class Enemy11Behavior : public BaseEnemyBehavior
{
public:
    Enemy11Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }

private:
    void moveX(OBJ2D* obj);
    float oldposY;
    float speedY;
    float scrollX;

};

//ひまわり3
class SunF_R2_Behavior : public BaseEnemyBehavior
{
public:
    SunF_R2_Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);

};

//ひまわり4
class SunF_L2_Behavior : public BaseEnemyBehavior
{
public:
    SunF_L2_Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);

};


/////ひまわりの敵の弾/////
//赤
class Enemy01ShotRed :public BaseEnemyBehavior
{
public:
    Enemy01ShotRed();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }

private:
    void moveX(OBJ2D* obj);
    float distanceX;


};
//白
class Enemy01ShotWhite :public BaseEnemyBehavior
{
public:
    Enemy01ShotWhite();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }


private:
    void moveX(OBJ2D* obj);
    float distanceX;


};

//とげ
class Enemy2Behavior : public BaseEnemyBehavior
{
public:
    Enemy2Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override ;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }


};


//movingとげ
class Enemy7Behavior : public BaseEnemyBehavior
{
public:
    Enemy7Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }


private:
    void moveX(OBJ2D* obj);
    float oldposY;
    float oldposX;
    float speedY;

};


//stage8 water
class Stage8WaterBehavior : public BaseEnemyBehavior
{
public:
    Stage8WaterBehavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }

private:
    void moveX(OBJ2D* obj);
   float speedY;
};



//ボス
class Enemy3Behavior : public BaseEnemyBehavior
{
public:
    Enemy3Behavior();
    void hit(OBJ2D* , OBJ2D* ) override { };
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);


    float boss_speed;
};

//water mini
class WaterMini : public BaseEnemyBehavior
{
public:
    WaterMini();
    void hit(OBJ2D* src, OBJ2D* dst) override ;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }

private:
    void moveX(OBJ2D* obj);
    int posY;
};

//ボス
class Enemy3Hitbox : public BaseEnemyBehavior
{
public:
    Enemy3Hitbox();
    void hit(OBJ2D* , OBJ2D* ) override {};
    OBJ_TYPE getType() const override { return OBJ_TYPE::ENEMY; }

private:
    void moveX(OBJ2D* obj);


    float boss_speed;
};


//虫
class Pattern00Behavior : public BaseEnemyBehavior
{
public:
    Pattern00Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }

private:
    void moveX(OBJ2D* obj);

};


//虫
class Pattern01Behavior : public BaseEnemyBehavior
{
public:
    Pattern01Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }


private:
    void moveX(OBJ2D* obj);

};



//上からピンク色の花が落ちてくる。
class Pattern02Behavior : public BaseEnemyBehavior
{
public:
    Pattern02Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }


private:
    void moveX(OBJ2D* obj);

};


//上からブール色の花が落ちてくる。
class Pattern03Behavior : public BaseEnemyBehavior
{
public:
    Pattern03Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }

private:
    void moveX(OBJ2D* obj);

};


//下からお水が上がってくる
class Pattern04Behavior : public BaseEnemyBehavior
{
public:
    Pattern04Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }



private:
    void moveX(OBJ2D* obj);
    float speedY = 0.0f;
};

class Pattern05Behavior : public BaseEnemyBehavior
{
public:
    Pattern05Behavior();
    void hit(OBJ2D* src, OBJ2D* dst) override ;
    OBJ_TYPE getType() const override { return OBJ_TYPE::NO_ATTACK_ENEMY; }


private:
    void moveX(OBJ2D* obj);

};




class BossScript
{
private:
    static BossScript instance_;

public:
    static BossScript* instance() { return &instance_; }
    void setScript(OBJ2DManager* obj2dManager);

    void update();
    int Gettimer() { return timer; }
    void init() { timer = 0; state = 0;; }
    void deinit() { timer = 0; state = 0; }
    int timer = 0;
    int state = 0;
};



class Stage8WaterScript
{
private:
    static Stage8WaterScript instance_;


public:
    static Stage8WaterScript* instance() { return &instance_; }
    void setScript(OBJ2DManager* obj2dManager);

    void update() { timer++; }
    int Gettimer() { return timer; }
    void init() { timer = 0; state = 0; }
    void deinit() { timer = 0; state = 0; }
    int timer = 0;
    int state = 0;
};



class WaterScript
{
private:
    static WaterScript instance_;

public:
    static WaterScript* instance() { return &instance_; }
    void setScript(OBJ2DManager* obj2dManager);

    void update() { timer++; }
    int Gettimer() { return timer; }
    void init() { timer = 0; state = 0; j= 0; }
    void deinit() { timer = 0; state = 0; j = 0; }
    int timer = 0;
    int state = 0;
    int j = 0;
};




//ウサギ
class Block1Behavior : public BaseEnemyBehavior
{
public:
    Block1Behavior();
    void hit(OBJ2D* , OBJ2D* ) override {};
    OBJ_TYPE getType() const override { return OBJ_TYPE::RUBY; }

private:
    void moveX(OBJ2D* ) {};
};


class Block2Behavior : public BaseEnemyBehavior
{
public:
    Block2Behavior();
    void hit(OBJ2D* , OBJ2D*) override {};
    OBJ_TYPE getType() const override { return OBJ_TYPE::RUBY; }

private:
    void moveX(OBJ2D* ) {};
};



class Block3Behavior : public BaseEnemyBehavior
{
public:
    Block3Behavior();
    void hit(OBJ2D*, OBJ2D* ) override {};
    OBJ_TYPE getType() const override { return OBJ_TYPE::RUBY; }

private:
    void moveX(OBJ2D* ) {};
};


EXTERN Block1Behavior block1Behavior;
EXTERN Block2Behavior block2Behavior;
EXTERN Block3Behavior block3Behavior;

EXTERN Enemy10Behavior enemy10Behavior;
EXTERN Enemy11Behavior enemy11Behavior;

EXTERN Enemy0Behavior enemy0Behavior;
EXTERN SunF_R_Behavior sunF_R_Behavior;
EXTERN SunF_L_Behavior sunF_L_Behavior;
EXTERN Enemy7Behavior enemy7Behavior;
EXTERN Stage8WaterBehavior stage8WaterBehavior;


EXTERN Enemy9Behavior enemy9Behavior;
EXTERN SunF_R2_Behavior sunF_R2_Behavior;
EXTERN SunF_L2_Behavior sunF_L2_Behavior;


EXTERN Enemy2Behavior enemy2Behavior;
EXTERN Enemy3Behavior enemy3Behavior;
EXTERN WaterMini waterMini;


EXTERN Enemy01ShotRed enemy01ShotRed;
EXTERN Enemy01ShotWhite enemy01ShotWhite;


EXTERN Enemy3Hitbox enemy4Behavior;


EXTERN Pattern00Behavior pattern00Behavior;
EXTERN Pattern01Behavior pattern01Behavior;
EXTERN Pattern02Behavior pattern02Behavior;
EXTERN Pattern03Behavior pattern03Behavior;
EXTERN Pattern04Behavior pattern04Behavior;
EXTERN Pattern05Behavior pattern05Behavior;




