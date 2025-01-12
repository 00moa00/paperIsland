#pragma once

//******************************************************************************
//
//
//      OBJ2Dクラス
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include <list>
#include "../GameLib/vector.h"
#include "../GameLib/obj2d_data.h"

// 前方宣言
class OBJ2D;

//==============================================================================

enum class OBJ_TYPE {
    PLAYER,
    ITEM,
    BLOCK,
    ENEMY,
    NO_ATTACK_ENEMY,
    WEAPON,
    BOSS,
    NONE,
    RUBY,
    MAX
};

// 移動アルゴリズムクラス（抽象クラス）
class Behavior
{
public:
    virtual void move(OBJ2D* obj) = 0;
    virtual OBJ_TYPE getType() const = 0;
    virtual OBJ_TYPE attackType() const = 0;
    virtual void hit(OBJ2D* src, OBJ2D* dst) = 0;
};

// 消去アルゴリズムクラス（抽象クラス）
class Eraser
{
public:
    virtual void erase(OBJ2D* obj) = 0;
};

//==============================================================================

//==============================================================================
//
//      OBJ2Dクラス
//
//==============================================================================

//----------------------------------------------------------------------
//  Component
//----------------------------------------------------------------------
class Component
{
private:
    OBJ2D* parent_;
public:
    Component()
        :parent_(nullptr) {}
    virtual void draw(const VECTOR2&) {}

    OBJ2D* parent() const { return parent_; }
    void setParent(OBJ2D* parent) { parent_ = parent; }
};

//----------------------------------------------------------------------
//  Transform
//----------------------------------------------------------------------
class Transform : public Component
{
private:
    VECTOR2 position_ = {};
    VECTOR2 scale_ = {};
    float rotation_ = 0;
    VECTOR2 speed_ = {};


public:
    Transform()
        :position_()
        , scale_(VECTOR2(1, 1))
        , rotation_(0.0f)
        , speed_() {}
        
    // getter
    const VECTOR2& position() const { return position_; }
    const VECTOR2& scale() const { return scale_; }
    const float rotation() const { return rotation_; }
    const VECTOR2& speed() const { return speed_; }

    const float& scaleX()const { return scale_.x; }
    const float& scaleY()const { return scale_.y; }

    // setter
    void setPosition(const VECTOR2& position) { position_ = position; }
    void setPositionX(float x) { position_.x = x; }
    void setPositionY(float y) { position_.y = y; }
    void addPositionX(float x) { position_.x += x; }
    void addPositionY(float y) { position_.y += y; }
    void setScale(const VECTOR2& s) { scale_ = s; }
    void setRotation(float r) { rotation_ = r; }
    void setSpeed(const VECTOR2& s) { speed_ = s; }
    void setSpeedX(float x) { speed_.x = x; }
    void setSpeedY(float y) { speed_.y = y; }
    void addSpeedX(float x) { speed_.x += x; }
    void addSpeedY(float y) { speed_.y += y; }


    //getter
    float getSpeedY() { return speed_.y; }
    float getPositionY() { return position_.y; }
    float getPositionX() { return position_.x; }
    //void setFlip(bool b) {scale_.x = b ? -scale_.x : scale_.x;}
    void FlipX(const bool b) { scale_.x = b ? -1.0f : 1; }
    bool getScaleX() { return scale_.x; }

    void update() { position_ += speed_; }
    void rotate(float r) { rotation_ += r; }
};

//----------------------------------------------------------------------
//  Renderer
//----------------------------------------------------------------------
class Renderer : public Component
{
private:
    GameLib::SpriteData* data_ = nullptr;
    VECTOR4 color_ = {}; 
    GameLib::Anime anime_ = {};
    GameLib::AnimeData* animeData_ = nullptr;
public:
    Renderer()
        :data_(nullptr)
        , color_(VECTOR4(1, 1, 1, 1))
        , anime_()
        , animeData_(nullptr) {}
    void draw(const VECTOR2& scrollPos);
    bool animeUpdate();

    GameLib::AnimeData* animeData() const { return animeData_; }

    void setData(GameLib::SpriteData* d) { data_ = d; }
    void setColor(const VECTOR4& c) { color_ = c; }
    void setColor_a(float a) { color_.w = a; }

    void addColor_a(const float a) { color_.w += a; }
    float getColor_a() { return color_.w; }

    void setAnimeData(GameLib::AnimeData* adata) { animeData_ = adata; }
};

//----------------------------------------------------------------------
//  Collider
//----------------------------------------------------------------------
class Collider : public Component
{
private:
    VECTOR2 size_ = {};
    GameLib::fRECT hitBox_;
    GameLib::fRECT attackBox_;
    bool judgeFlag_;
    bool isDrawHitRect_;
public:
    Collider()
        :size_()
        , hitBox_()
        , attackBox_()
        , judgeFlag_(false)
        , isDrawHitRect_(false) {}
    void draw(const VECTOR2& scrollPos) override;
    void calcHitBox(const GameLib::fRECT& rc);
    void calcAttackBox(const GameLib::fRECT& rc);
    void hit_b(OBJ2D* obj);
    void hit_r(OBJ2D* obj);
    bool hitCheck(Collider* coll);
    bool hitCheck(OBJ2D* obj);

    const VECTOR2& size() const { return size_; }
    bool judgeFlag() const { return judgeFlag_; }

    void setSize(const VECTOR2& s) { size_ = s; }
    void setJudgeFlag(bool b) { judgeFlag_ = b; }
    void setIsDrawHitRect(bool b) { isDrawHitRect_ = b; }
};

//----------------------------------------------------------------------
//  ActorComponent
//----------------------------------------------------------------------
class ActorComponent : public Component
{
private:
    int jumpTimer_;
    int attackTimer_;
    int hitTimer_;
    int hp_;
    float alpha_;

    bool onGround_;
    bool kabeFlag_;
    bool gakeFlag_;
    bool xFlip_;
    bool hasSword_;
    bool k_Animation_;
    bool blockFlagDo_;  //プレイヤーor敵がブロックの上におるか判定用
    bool blockFlagUp_;  //プレイヤーor敵がブロックの下におるか判定用
    bool blockFlagRight_;  //プレイヤーor敵がブロックの横におるか判定用
    bool blockFlagLeft_;  //プレイヤーor敵がブロックの横におるか判定用
    bool IdoblockFlag_;  //プレイヤーが移動ブロックに乗っている
    bool IdoblockFlagUp_;  //プレイヤーが移動ブロックに乗っている

    bool isJump_;
    bool walkFlag_;
    bool PlayerHitFlag_;
    bool playerMove_;

    bool isHitAnime_;
    int hitAnimeTimer_;

    bool DropBlockFlag_;


public:
    ActorComponent()
        :jumpTimer_(0)
        , attackTimer_(0)
        , hitTimer_(0)
        , hp_(1)
        , alpha_(1.0f)

        , onGround_(false)
        , kabeFlag_(false)
        , gakeFlag_(false)
        , xFlip_(false)
        , hasSword_(false)
        , k_Animation_(false)
        , blockFlagDo_(false)
        , blockFlagUp_(false)
        , blockFlagRight_(false)
        , blockFlagLeft_(false)
        , IdoblockFlag_(false)
        , IdoblockFlagUp_(false)
        , walkFlag_(false)
        , PlayerHitFlag_(false)
        , isJump_(false)
        , playerMove_(false)
        , isHitAnime_(false)
        , hitAnimeTimer_(0)
        , DropBlockFlag_(false)

    {}


    // getter
    int jumpTimer() const { return jumpTimer_; }
    int hitTimer()const { return hitTimer_; }
    int attackTimer() const { return attackTimer_; }
    int hp() const { return hp_; }
    float alpha() { return alpha_; }

    bool onGround() const { return onGround_; }
    bool hasSword() const { return hasSword_; }
    bool kabeFlag() const { return kabeFlag_; }
    bool gakeFlag() const { return gakeFlag_; }
    bool xFlip() const { return xFlip_; }
    bool K_Animationflag() const { return k_Animation_; }
    bool IdoBlockFlag() const { return IdoblockFlag_; }
    bool IdoBlockFlagUp() const { return IdoblockFlagUp_; }

    bool BlockFlagDo() const { return blockFlagDo_; }
    bool BlockFlagUp() const { return blockFlagUp_; }
    bool BlockFlagRight() const { return blockFlagRight_; }
    bool BlockFlagLeft() const { return blockFlagLeft_; }
    bool WalkFlag() { return walkFlag_; }
    bool PlayerHitFlag() { return PlayerHitFlag_; }
    bool isJump() {return isJump_; }
    bool isPlayerMove() { return playerMove_; }
    bool isHitAnime() { return isHitAnime_; }
    int hitAnimeTimer() { return hitAnimeTimer_; }
    bool DropBlockFlag() { return DropBlockFlag_; }

    // setter
    void setJumpTimer(int j) { jumpTimer_ = j; }
    void addJumpTimer(int a) { jumpTimer_ += a; }
   // void addAttackTimer(int a) { attackTimer_ += a; }
    void setAttackTimer(int a) { attackTimer_ = a; }
    void subAttackTimer(int a) { attackTimer_ = std::max(attackTimer_ - a, 0); }
    void setHitTimer(int a) { hitTimer_ = a; }
    void subHitTimer(int a) { hitTimer_ = std::max(hitTimer_ - a, 0); }
    void addHitTimer() { hitTimer_++; }
    void setHp(int h) { hp_ = h; }
    void addHp(int h) { hp_ += h; }
    void subHp(int h) { hp_ -= h; hp_ = std::max(hp_, 0); }
    void setOnGround(bool b) { onGround_ = b; }
    void setHasSword(bool b) { hasSword_ = b; }
    void setKabeFlag(bool b) { kabeFlag_ = b; }
    void setGakeFlag(bool b) { gakeFlag_ = b; }
    void setXFlip(bool b) { xFlip_ = b; }//攻撃の方向　true:左　false:右
    void set_Animation(bool s) { k_Animation_ = s; }  //カエルアニメーション用flagセット関数
    void setAlive(int a) { hp_ = a; }
    void set_IdoBlockFlag(bool b) { IdoblockFlag_ = b; }
    void set_IdoBlockFlagUp(bool b) { IdoblockFlagUp_ = b; }

    void set_BlockFlagDo(bool b) { blockFlagDo_ = b; }  //プレイヤーor敵がブロックの上におるか判定する
    void set_BlockFlagUp(bool b) { blockFlagUp_ = b; }
    void set_BlockFlagRight(bool b) { blockFlagRight_ = b; }
    void set_BlockFlagLeft(bool b) { blockFlagLeft_ = b; }

    void setWalkFlag(bool b) { walkFlag_ = b; }
    void setPlayerHit(bool b) { PlayerHitFlag_ = b; }
    void setIsJump(bool b) { isJump_ = b; }

    void set_DropBlockFlag(bool b) { DropBlockFlag_ = b; }

    void flip() { xFlip_ = !xFlip_; }
    bool isAlive() const { return hp_ > 0; }
    void setPlayerMove(bool b) { playerMove_ = b; }
    bool getPlayerMove() { return playerMove_; }

    void setIsHitAnime(bool b) { isHitAnime_ = b; }
    void setHitAnimeTimer(int i) { hitAnimeTimer_ = i; }
    void decHitAnimeTimer() { hitAnimeTimer_--; }

    void addAlpha(float i) { alpha_ += i; }

    void setAlpha(float i) { alpha_ = i; }

};

//----------------------------------------------------------------------
//  ItemComponent
//----------------------------------------------------------------------
class ItemComponent : public Component
{
private:
    VECTOR2 orgPos_;    // 最初に出現した位置を保持しておく
    float angle_;       // サインカーブなどで揺らす場合などのための汎用の変数（自由に使ってよい）
public:
    ItemComponent()
        :orgPos_()
        , angle_(0) {}

    float angle() const { return angle_; }
    const VECTOR2& orgPos() const { return orgPos_; }

    void setOrgPos(const VECTOR2& pos) { orgPos_ = pos; }
    void setAngle(float a) { angle_ = a; }
    void addAngle(float a) { angle_ += a; }
};


//----------------------------------------------------------------------
//  WeaponComponent
//----------------------------------------------------------------------
class WeaponComponent : public Component
{
private:
    OBJ2D* owner_;  // この武器の持ち主
    bool xFlip_;    // true … 左向き / false … 右向き
public:
    WeaponComponent()
        :owner_(nullptr)
        , xFlip_(false) {}

    // getter
    OBJ2D* owner() const { return owner_; }
    bool xFlip() const { return xFlip_; }

    // setter
    void setOwner(OBJ2D* o) { owner_ = o; }
    void setXFlip(bool b) { xFlip_ = b; }

    // 武器の持ち主のxFlip_を武器に設定する
    void copyOwnerXFlip();
};

//----------------------------------------------------------------------
//  OBJ2D
//----------------------------------------------------------------------
class BG;
class OBJ2D
{
private:
    // 基本的なメンバ
    int         state_;
    int         timer_;
    Behavior*   behavior_;
    Eraser*     eraser_;
    bool stageMove_;

    BG* bg_;

    // 各コンポーネント
    Transform* transform_;
    Renderer* renderer_;
    Collider* collider_;
    ActorComponent* actorComponent_;
    ItemComponent* itemComponent_;
    WeaponComponent* weaponComponent_;

public:
    // メンバ関数
    OBJ2D(Renderer* renderer,
        Collider* collider,
        BG* bg,
        ActorComponent* actorComponent,
        ItemComponent* itemComponent, 
        WeaponComponent* weaponComponent
    );
    ~OBJ2D();
    void move();    // 移動

    // コンポーネントのゲッター
    Transform* transform() const { return transform_; }
    Renderer* renderer() const { return renderer_; }
    Collider* collider() const { return collider_; }
    ActorComponent* actorComponent() const { return actorComponent_; }
    ItemComponent* itemComponent() const { return itemComponent_; }
    WeaponComponent* weaponComponent() const { return weaponComponent_; }

    // getter
    int state() const { return state_; }
    int timer() const { return timer_; }
    Behavior* behavior() const { return behavior_; }
    BG* bg() const { return bg_; }
    bool getStageM(){ return stageMove_; }

    // setter
    void setState(int s) { state_ = s; }
    void setBehavior(Behavior* behavior) { behavior_ = behavior; }
    void setEraser(Eraser* eraser) { eraser_ = eraser; }
    void setTimer(int a) { timer_ = a; }
    void addTimer(int a) { timer_ += a; }


    void SetState(int a) { state_ = a; }
    void nextState() { state_++; }
    void remove() { setBehavior(nullptr); }
    void setStageM(bool b) { stageMove_ = b; }
};

//==============================================================================

// OBJ2DManagerクラス
class OBJ2DManager
{
private:
    VECTOR2* scrollPos_;
protected:
    std::list<OBJ2D*> objList_;
public:
    // デストラクタ
    ~OBJ2DManager();
    OBJ2DManager() : timer(0), state(0) {};
    void setScrollPos(VECTOR2* s) { scrollPos_ = s; }

    void init();    // 初期化
    void update();  // 更新
    void draw(const VECTOR2&);    // 描画

    OBJ2D* add(OBJ2D* obj, Behavior* behavior, const VECTOR2& pos);
    std::list<OBJ2D*>* getList() { return &objList_; }

    int timer;
    int state;
};

//******************************************************************************
