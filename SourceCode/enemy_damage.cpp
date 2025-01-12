#include "all.h"

void BaseEnemyDamage::move(OBJ2D* obj)
{

    Transform* transform = obj->transform();
    Renderer* renderer = obj->renderer();
    Collider* collider = obj->collider();
    ItemComponent* itemComponent = obj->itemComponent();

    switch (obj->state())
    {
    case 0:
        //////// ‰ŠúÝ’è ////////
        oldPosX = transform->getPositionX();
        oldPosY = transform->getPositionY();

        transform->setScale(getParam()->SCALE);
        renderer->setData(getParam()->SPR_DAMAGE);
        collider->setSize(getParam()->SIZE);
        collider->setJudgeFlag(true);
        collider->setIsDrawHitRect(true);

        itemComponent->setOrgPos(transform->position());
        itemComponent->setAngle(fmodf(transform->position().x, 360.0f));
        collider->calcAttackBox(getParam()->ATTACK_BOX);

        obj->nextState();//state++
        break;
    case 1:
        //////// ’ÊíŽž ////////

        transform->addPositionY(-1.0f);
        transform->addPositionX(0.1f);

        if (transform->getPositionY() < oldPosY - 25) obj->nextState();
        break;

    case 2:
        obj->remove();

        //transform->setPositionY(itemComponent->orgPos().y + sinf(itemComponent->angle()) * 4);
        //collider->calcAttackBox(getParam()->ATTACK_BOX);
        //itemComponent->addAngle(ToRadian(6));
        //if (itemComponent->angle() > PI)
        //    itemComponent->addAngle(-2 * PI);

        break;
    }

}

EnemyDamagelevel1::EnemyDamagelevel1()
{
    param_.SPR_DAMAGE = &sprEnemyHit;
    //param_.SIZE = { 48,48 };
   // param_.ATTACK_BOX = { -48, -48, 48, 48 };
    param_.SCALE = { 1, 1 };
}

EnemyDamagelevel2::EnemyDamagelevel2()
{
    param_.SPR_DAMAGE = &sprEnemyHit2;
    //param_.SIZE = { 48,48 };
   // param_.ATTACK_BOX = { -48, -48, 48, 48 };
    param_.SCALE = { 1, 1 };
}

EnemyDamagelevel3::EnemyDamagelevel3()
{

    param_.SPR_DAMAGE = &sprEnemyHit3;
    //param_.SIZE = { 48,48 };
   // param_.ATTACK_BOX = { -48, -48, 48, 48 };
    param_.SCALE = { 1, 1 };
}
