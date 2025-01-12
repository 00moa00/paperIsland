#pragma once
//using namespace GameLib;

class StageTrans
{
private:
   // static StageTrans instance_;

    SpriteManager* sprRight1 = nullptr;
    SpriteManager* sprRight2 = nullptr;
    SpriteManager* sprLeft1 = nullptr;
    SpriteManager* sprLeft2 = nullptr;

    float speedX1;
    float speedX2;

    int timer;
    int state;
    bool StageFlag_;
    bool actorFlag_;

public :
//    static StageTrans* instance() { return &instance_; }

    StageTrans() {
        sprRight1 = new SpriteManager(L"./Data/Images/SCENE/right1.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        sprRight2 = new SpriteManager(L"./Data/Images/SCENE/right2.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        sprLeft1 = new SpriteManager(L"./Data/Images/SCENE/left1.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));
        sprLeft2 = new SpriteManager(L"./Data/Images/SCENE/left2.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));

        StageFlag_ = false;
        actorFlag_ = true;

        speedX1 = 15.0f;
        speedX2 = 9.5f;
        state = 0;
        timer = 0;
    }


    ~StageTrans() {

        delete sprRight1;
        delete sprRight2;
        delete sprLeft1;
        delete sprLeft2;
      

    }
    void init()
    {
    }
    void deinit() {
    }

    void update() {


        switch (state)
        {
        case 0:

            StageFlag_ = false;
            timer = 0;
            sprRight1->addPosX(speedX1);
            sprRight2->addPosX(speedX2);


            sprLeft1->addPosX(-speedX1);
            sprLeft2->addPosX(-speedX2);

            if (sprRight2->getPosX() >= 1910) speedX2 = 0;
            if (sprRight1->getPosX() >= 1910) speedX1 = 0;


            if (speedX1 <= 0 && speedX2 <= 0) {
                state++;
            }
            break;
        case 1:

               
            speedX1 = 21.0f;
            speedX2 = 24.5f;
            break;

        case 2:


            actorFlag_ = false;
           // GameLib::music::play(SOUND::TRANS);

            sprRight1->addPosX(-speedX1);
            sprRight2->addPosX(-speedX2);


            sprLeft1->addPosX(speedX1);
            sprLeft2->addPosX(speedX2);

            if (sprRight1->getPosX() <= 10) speedX1 = 0;
            if (sprRight2->getPosX() <= 10) speedX2 = 0;

            if (speedX1 == 0 && speedX2 == 0) {
              //  timer ++ ;

                //if (timer > 10) {
                    StageFlag_ = true;
                    actorFlag_ = true;
                    state = 0;
                //}
            }
        }

        

    }


    void draw() {

      if(sprRight1)sprRight1->draw();
      if (sprRight2)  sprRight2->draw();
      if (sprLeft1) sprLeft1->draw();
      if (sprLeft2) sprLeft2->draw();
    }

    void setState(int i) {state = i;}
    int getState() { return state; }
    bool getStageFlag() { return StageFlag_; }
    void setActorFlag(bool i) { actorFlag_ = i; }
    bool getActorFlag() { return actorFlag_; }
    
};
