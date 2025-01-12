#pragma once
#define HP_MAX 6

class UI
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

    const Param* getParam() { return &param_; }

public:
    virtual void update() = 0;
    virtual void draw() = 0;
};

class HP
{
private:
    static HP instance_;

public:
    static HP* instance() { return &instance_; }

    SpriteManager* sprHP;

    int playerHP;//HP�\���Ɏg�p

    HP();
    ~HP();
    void init();
    void deinit();
    void updateHP();
    void drawHP()  ;

   // void setHp(int a) { playerHP = a; }
   // int getHp() { return playerHP; }

    void SubHp(int a) { if (playerHP > 0)playerHP -= a; if (playerHP < 0) playerHP = 0; }
    void AddHp() { if (playerHP < HP_MAX - 1)playerHP++; }
    void SetHp(int a) { playerHP = a; }
    int GetHp() { return playerHP; }
};

//���[�^�[
class perClear : public UI
{
public:
    static int getStageClear;         //�X�e�[�W�ԍ��p

    perClear();
    ~perClear();
    void update()   override;
    void draw()     override;

};

//�`���v�^�[�̐�
class chapterStar : public UI
{
public:
    static int getStageChapter;         //�X�e�[�W�ԍ��p

    chapterStar();
    ~chapterStar();
    void update()   override;
    void draw()     override;


};


class MoveFlag : public UI
{
public:

    MoveFlag();
    ~MoveFlag();
    void update()   override;
    void draw()     override;
};


//TODO
class opeGuide : public UI
{
private:

    GameLib::Sprite* sprManager[2];
    int sprNo;

    //�L�[�{�[�h���R���g���[���[�̔��ʃt���O�@
    //false:�L�[�{�[�h true:�R���g���[���[
    bool InputFlag;

public:

    opeGuide();
    ~opeGuide();

    void update()   override{};
    void draw()     override{};
    void drawKeypad();
    void drawXBox();

    //static opeGuide* instance() { return &instance_; }

    //bool getIsPaused() { return isPaused_; }
    //void setIsPaused(bool b) { isPaused_ = b; }

    bool getInputFlag() const { return InputFlag; }
    void setInputFlag(bool b) { InputFlag = b; }

    void InputFlag_false() { InputFlag = false; }
    void InputFlag_true() { InputFlag = true; }


};