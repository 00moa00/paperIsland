//#pragma once
//
//void setRuby(OBJ2DManager* obj2dManager, BG* bg);
//
//class BaseRubyBehavior : public ActorBehavior
//{
//private:
//    void moveY(OBJ2D* obj) {};
//    void moveX(OBJ2D* obj) {};
//    virtual OBJ_TYPE getType() = 0;   //何故か継承先でオーバーライド扱いされない
//    OBJ_TYPE attackType() const override { return OBJ_TYPE::PLAYER; }
//
//    void calcAttackBox(OBJ2D* obj);
//    bool isAlive(OBJ2D* obj) override;
//    bool die_animation(OBJ2D* obj);
//
//
//    int die_timer;
//
//protected:
//    BaseRubyBehavior() : die_timer(0), timer(0), state(0), state2(0) {}
//
//    int timer;
//    int state;
//    int state2;
//
//    bool Shotdieflag = false;
//};
//
//class RUBYBLOCK : public BaseRubyBehavior
//{
//private:
//    GameLib::SpriteData* spr_ruby;
//public:
//    RUBYBLOCK();
//    void hit(OBJ2D* src, OBJ2D* dst) override;
//    OBJ_TYPE getType() const override { return OBJ_TYPE::BLOCK; }
//};
//
//EXTERN RUBYBLOCK ruby_block;