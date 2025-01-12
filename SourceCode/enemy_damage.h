#pragma once
class BaseEnemyDamage : public Behavior
{
protected:
    struct Param {
        GameLib::SpriteData* SPR_DAMAGE= nullptr;
        VECTOR2 SIZE = {};
        GameLib::fRECT ATTACK_BOX = {};
        VECTOR2 SCALE = { 1, 1 };
    } param_;

protected:
    const Param* getParam() const { return &param_; }

    float oldPosY = .0f;
    float oldPosX = .0f;

private:
    void move(OBJ2D* obj) override;

    OBJ_TYPE getType() const override { return OBJ_TYPE::NONE; }
    OBJ_TYPE attackType() const override { return OBJ_TYPE::NONE; }

    void hit(OBJ2D* , OBJ2D* ) override {};

};



class EnemyDamagelevel1 : public BaseEnemyDamage
{
public:
    EnemyDamagelevel1();

};


class EnemyDamagelevel2 : public BaseEnemyDamage
{
public:
    EnemyDamagelevel2();

};


class EnemyDamagelevel3 : public BaseEnemyDamage
{
public:
    EnemyDamagelevel3();

};


EXTERN EnemyDamagelevel1 enemyDamagelevel1;
EXTERN EnemyDamagelevel2 enemyDamagelevel2; 
EXTERN EnemyDamagelevel3 enemyDamagelevel3;