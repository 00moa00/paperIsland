#pragma once


#include <fstream>
//******************************************************************************
//
//
//      ゲームシーン
//
//
//******************************************************************************

//==============================================================================
//
//      Gameクラス
//
//==============================================================================

#define STAGE_NUM_MAX 11

class Game : public Scene
{
private:
    OBJ2DManager*       obj2dManager_;
    BG*                 bg_;
    OBJ2D*              player_;
    static Game         instance_;

    bool                isPaused_;
    bool                isOpeKey_;//操作説明
    bool                isOpePad_;//操作説明

    bool                isVolume_;

    int                 voSelect_;//0:BGM,1:SE
    static int          VolumeSelect_[2];

    int                 menuSelect_;
    float               menuPosY1_;
    float               menuPosY2_;
    float               menuPosY3_;
    float               menuMoveSpeed_;

    float               soundMenuPosY1_;
    float               soundMenuPosY2_;
    float               soundMenuSpeed_;

    GameLib::Sprite* sprMenuBack_ = nullptr;
    GameLib::Sprite* sprMenuSave_ = nullptr;
    GameLib::Sprite* sprMenuSound_ = nullptr;
    GameLib::Sprite* sprMenuExit_ = nullptr;

    GameLib::Sprite* sprMenuSound_BACK = nullptr;
    GameLib::Sprite* sprMenuSound_BGM = nullptr;
    GameLib::Sprite* sprMenuSound_SE = nullptr;


    BGCloud* bgCloud_;
    BackSprite* back_;
    stage8Water* stage8water_;
    WaterSprite* water_;
    StageTrans* stageTrans_;
    perClear* perClear_;
    chapterStar* chapterStar_;
    Paper* paper_;
    MoveFlag* moveFlag_;
    opeGuide* opeGuide_;

    std::ofstream ofSavedata; //書き込み用
    std::ifstream ifSavedata; //読み込み用


    std::ofstream ofSavedata2; //書き込み用
    std::ifstream ifSavedata2; //読み込み用

    int playerHpSave = 0;
    int stageSave = 0;

public:
    static Game* instance()         { return &instance_; }

    OBJ2DManager* obj2dManager()    { return obj2dManager_; }
    BG* bg()                        { return bg_; }
    BGCloud* bgCloud() { return bgCloud_; }
    BackSprite* backSprite() { return back_; }
    StageTrans* stageTrans() { return stageTrans_; }
    WaterSprite* waterSprite() { return water_; }

    Paper* paper() { return paper_; }

    int VolumeSelect(int i)const { return VolumeSelect_[i]; }

    void init() override;
    void deinit() override;
    void update() override;
    void draw() override;


    OBJ2D* player() const { return player_; }
    void setPlayer(OBJ2D* p) { player_ = p; }
    //bool getReverseFlag() { return reverseFlag; }
    void reState() { state_ = 0; }//ゲームオーバーで使用
    
    //restart用
    bool restart() { changeScene(GameLoading::instance()); return true; }

private:
    Game()
        :obj2dManager_(nullptr)
        , bg_(nullptr)
        , isPaused_(false)
        , isOpeKey_(false)
        , isOpePad_(false)
        , sprMenuBack_(nullptr)
        , sprMenuSave_(nullptr)
        , sprMenuSound_(nullptr)
        , sprMenuExit_(nullptr)
        , water_(nullptr)
        , menuSelect_(0)
        , menuPosY1_(180.0f)
        , menuPosY2_(440.0f)
        , menuPosY3_(700.0f)
        , menuMoveSpeed_(0.5f)
        , soundMenuPosY1_(180)
        , soundMenuPosY2_(650)
        , soundMenuSpeed_(0.4f)
        , player_(nullptr)
        , perClear_(nullptr)
        , chapterStar_(nullptr)
        , stage8water_(nullptr)
        , opeGuide_(nullptr)
        , bgCloud_(nullptr)
        , paper_(nullptr)
        , moveFlag_(nullptr)
        , stageTrans_(nullptr)
        , back_(nullptr)
    {
        ofSavedata.open("playerHpSave.dat", std::ios::in);

        //なかったら作る
        if (!ofSavedata)
        {
            playerHpSave = 4;
            ofSavedata.open("playerHpSave.dat");
            //default 
            ofSavedata << playerHpSave;
        }
        ofSavedata.close();


        ofSavedata2.open("stageSave.dat", std::ios::in);

        //なかったら作る
        if (!ofSavedata2)
        {
            stageSave = 0;
            ofSavedata2.open("stageSave.dat");
            //default 
            ofSavedata2 << stageSave;
        }
        ofSavedata2.close();
    }


    Game(const Game&) = delete; // = delete コピーコンストラクタが存在しないことを明示

    ~Game();
    void judge();
    void Puase();
};

//******************************************************************************

