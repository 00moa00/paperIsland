#pragma once
#define SHOT_ATTACK 1


class BaseShotBehavior : public Behavior
{

protected:

    struct Param {
        GameLib::AnimeData* SPR_WATER;     // �X�v���C�g
        GameLib::AnimeData* SPR_WATER_l1;     // �X�v���C�g
        GameLib::AnimeData* SPR_WATER_l2;     // �X�v���C�g
        GameLib::AnimeData* SPR_WATER_l3;     // �X�v���C�g
        Eraser* ERASER;         // �C���C�T�[�i�폜�p�̃A���S���Y���j
        float                   SPEED_X;        // �������̑��x
        int                     B_TIMER;        //��������܂ł̃^�C�}�[
        VECTOR2                 SCALE;          // �X�P�[��
        GameLib::fRECT          ATTACK_BOX;     // �U���p������̈�
    } param_ = {};

    int b_timer = 0;  //��������܂ł̃^�C�}�[
    int timer = 0;
    int atacck = 0;  //�U����
    int b_animeNum = 0;

protected:
    const Param* getParam() { return &param_; }
    void setParamBTimer(int b) { param_.B_TIMER = b; }

    bool awaFlag = false;  //�A���G�ƐڐG�������ǂ������肷��悤
    bool BombFlag = false;

    bool level1 = false;
    bool level2 = false;
    bool level3 = false;


private:
    void move(OBJ2D* obj) override;
    virtual void update(OBJ2D* obj) = 0;        // �ʒu�ɑ��x�𑫂�
    virtual void calcAttackBox(OBJ2D* obj) = 0; // �U���p������̈�̌v�Z
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
    // void occurrence(OBJ2D* obj);  //shot�����p����
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