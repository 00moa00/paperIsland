#pragma once

class ActorBehavior : public Behavior
{
protected:
    struct Param {
        // アニメーション
        GameLib::AnimeData* ANIME_UP;
        GameLib::AnimeData* ANIME_RIGHT;
        GameLib::AnimeData* ANIME_DOWN;
        GameLib::AnimeData* ANIME_LEFT;
        GameLib::AnimeData* ANIME_WAIT;
        GameLib::AnimeData* ANIME_JUMP;

        GameLib::AnimeData* ANIME_ATTACK_MAKE;
        GameLib::AnimeData* ANIME_ATTACK_THROW;

        GameLib::AnimeData* ANIME_HIT;
        GameLib::AnimeData* ANIME_OVER;


        // サイズ
        VECTOR2 SIZE;
        VECTOR2 SCALE;
        GameLib::fRECT HIT_BOX;

        // 速度関連のパラメータ
        float ACCEL_X;
        float ACCEL_Y;
        float SPEED_X_MAX;
        float SPEED_Y_MAX;
        float JUMP_POWER_Y;
        int ENEMY_DAMAGE;
        int HP;

    }param_ = {};

protected:
    const Param* getParam() const { return &param_; }
    void setParamHitBox(GameLib::fRECT n) { param_.HIT_BOX = n; }

    void playerHit(OBJ2D*, OBJ2D*, int damage);
    virtual void moveY(OBJ2D* obj);
    virtual void moveX(OBJ2D* obj);
    virtual void moveHp(OBJ2D* obj) = 0;
private:
    void move(OBJ2D* obj) override;
    virtual void jump(OBJ2D*) {}
    virtual void hashigo(OBJ2D*) {}
    void areaCheck(OBJ2D* obj);
    virtual void turn(OBJ2D*) {}
    // virtual void hit(OBJ2D* src, OBJ2D* dst) = 0;

    virtual void attack(OBJ2D*) {}
    virtual bool isAlive(OBJ2D*) = 0;

};
