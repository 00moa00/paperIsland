#pragma once


enum STORY 
{
    ST0_1 = 0,
    ST0_2,
    ST0_3,
    ST0_4,

    ST1_1,

    ST10_1,
    ST10_2,
    ST10_3,
    ST10_4,
    NONE
};

class Story 
{

private:
    static Story instance_;

    Story();
    ~Story();


    SpriteManager* sprST0_story1 = nullptr;
    SpriteManager* sprST0_story2 = nullptr;
    SpriteManager* sprST0_story3 = nullptr;
    SpriteManager* sprST0_story4 = nullptr;

    SpriteManager* sprST1_story1 = nullptr;

    SpriteManager* sprST10_story1 = nullptr;
    SpriteManager* sprST10_story2 = nullptr;
    SpriteManager* sprST10_story3 = nullptr;
    SpriteManager* sprST10_story4 = nullptr;

public:
    static Story* instance() { return &instance_; }

    void init();
    void update();
    void draw();

    int state;
    int sound_state;
    bool sound;
    void deinit();


};