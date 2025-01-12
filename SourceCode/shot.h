#pragma once
#define SHOT_ATTACK 1


class BaseShotBehavior : public Behavior
{

protected:

    struct Param {
        GameLib::AnimeData* SPR_WATER;     // スプライト
        GameLib::AnimeData* SPR_WATER_l1;     // スプライト
        GameLib::AnimeData* SPR_WATER_l2;     // スプライト
        GameLib::AnimeData* SPR_WATER_l3;     // スプライト
        Eraser* ERASER;         // イレイサー（削除用のアルゴリズム）
        float                   SPEED_X;        // 横方向の速度
        int                     B_TIMER;        //爆発するまでのタイマー
        VECTOR2                 SCALE;          // スケール
        GameLib::fRECT          ATTACK_BOX;     // 攻撃用あたり領域
    } param_ = {};

    int b_timer = 0;  //爆発するまでのタイマー
    int timer = 0;
    int atacck = 0;  //攻撃力
    int b_animeNum = 0;

protected:
    const Param* getParam() { return &param_; }
    void setParamBTimer(int b) { param_.B_TIMER = b; }

    bool awaFlag = false;  //泡が敵と接触したかどうか判定するよう
    bool BombFlag = false;

    bool level1 = false;
    bool level2 = false;
    bool level3 = false;


private:
    void move(OBJ2D* obj) override;
    virtual void update(OBJ2D* obj) = 0;        // 位置に速度を足す
    virtual void calcAttackBox(OBJ2D* obj) = 0; // 攻撃用あたり領域の計算
    OBJ_TYPE getType() const override { return OBJ_TYPE::WEAPON; }
    OBJ_TYPE attackType() const override { return OBJ_TYPE::ENEMY; }

};


class ShotBehavior : public BaseShotBehavior
{
public:
    ShotBehavior();

private:
    int oldBombTimer = 0;
    int outBombTimer_Throw = 0;
    int outBombTimer_Make = 0;
    int b_state = 0;

private:
    // void occurrence(OBJ2D* obj);  //shot発生用処理
    void update(OBJ2D* obj) override;
    void calcAttackBox(OBJ2D* obj) override;
    void hit(OBJ2D* src, OBJ2D* dst) override;
    void moveX(OBJ2D* obj);
    void moveY(OBJ2D* obj);
    bool b_anime(OBJ2D* obj);
    bool GetAwaflag() { return awaFlag; }
};
EXTERN ShotBehavior shotBehavior;

class ShotEraser : public Eraser
{
private:
    void erase(OBJ2D* obj) override;
};
EXTERN ShotEraser shotEraser;