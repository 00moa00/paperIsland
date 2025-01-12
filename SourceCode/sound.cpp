#include "all.h"


using namespace GameLib;
//--------------------------------------
//  オーディオの初期設定
//--------------------------------------

enum
{
    BGM = 0,
    SE = 1,
};


void audio_init()
{
    // 音楽の読み込み
    music::load(MUSIC::TITLE, L"./Data/Musics/title/03_mitisugara.wav");
    music::load(MUSIC::GAME, L"./Data/Musics/game/08_koubou.wav");
    music::load(MUSIC::LOADING, L"./Data/Musics/loading/botan_b17.wav");
    music::load(MUSIC::CH1_BOSS, L"./Data/Musics/ch1_boss/warning.wav");
    music::load(MUSIC::CLEAR, L"./Data/Musics/game/mezamasi.wav");

    music::load(MUSIC::SECOND_HALF_GAME, L"./Data/Musics/game/densetu.wav");

     //効果音の読み込み
    music::load(SOUND::PLAYER_ATTACK, L"./Data/Sounds/Cartoon_Pop.wav");
    music::load(SOUND::PLAYER_REVERSE, L"./Data/Sounds/OMT004_14S003.wav");

    music::load(SOUND::PLAYER_WALK, L"./Data/Sounds/hito_ta_aru_sp04.wav");

    music::load(SOUND::PLAYER_ATTACK_BOMB, L"./Data/Sounds/ta_ta_warekie02.wav");
    music::load(SOUND::PLAYER_ATTACK_THROW, L"./Data/Sounds/botan_b22.wav");
    music::load(SOUND::PLAYER_JUMP, L"./Data/Sounds/19.wav");
    music::load(SOUND::PLAYER_HIT, L"./Data/Sounds/OMT004_16S003.wav");

    music::load(SOUND::ITEM, L"./Data/Sounds/MP_Water_Droplet.wav");
    music::load(SOUND::STORY, L"./Data/Sounds/pageflip10.wav");
    music::load(SOUND::MENU_SELECT, L"./Data/Sounds/Pause.wav");

    music::load(SOUND::PAUSE, L"./Data/Sounds/pageflip10.wav");
    music::load(SOUND::PAUSE_CLOSE, L"./Data/Sounds/pageflip10.wav");
    music::load(SOUND::STAGE8_WARNING, L"./Data/Sounds/water_warning.wav");
    music::load(SOUND::GET_STAR, L"./Data/Sounds/GetStar.wav");
    music::load(SOUND::TRANS, L"./Data/Sounds/trans.wav");



  //  music::setVolume(MUSIC::TITLE, 0.3f);
  //  music::setVolume(MUSIC::GAME, 0.3f);
  //  music::setVolume(SOUND::PLAYER_ATTACK, 1.0f);
  //  music::setVolume(SOUND::TRANS, 1.0f);



}

//--------------------------------------
//  オーディオの終了処理
//--------------------------------------
void audio_deinit()
{
    // 音楽を全て解放
   // music::clear();
}

void audio_update()
{
#define BGMorSE(x) Game::instance()->VolumeSelect(x)
    //音量
    float volume[] = { 0.0f,0.5f,1.0f };

    ////BGMのボリューム設定
    for (int i = MUSIC::TITLE; i < MUSIC::MUSIC_MAX; i++)
    {
        music::setVolume(i, volume[BGMorSE(BGM)]);
    }
    ////SEのボリューム設定
    for (int i = SOUND::PLAYER_ATTACK; i < SOUND::STAGE8_WARNING; i++)
    {
        music::setVolume(i, volume[BGMorSE(SE)]);
    }
    //music::setVolume(SOUND::PLAYER_WALK, 0.0f);

}

void audio_setVolume_BGM(int EnumName, float volume)
{

    //if (Game::instance()->VolumeSelect(BGM) == 0)Game::instance()->set_outVolume_BGM(false);
    //else Game::instance()->set_outVolume_BGM(true);

    //BGM
    if (Game::instance()->VolumeSelect(BGM) != 0)
    {
        music::setVolume(EnumName, volume);
    }
    else
    {
        music::setVolume(EnumName, 0.0f);
    }
}


void audio_setVolume_SE(int EnumName, float volume)
{

    //if (Game::instance()->VolumeSelect(SE) == 0)Game::instance()->set_outVolume_SE(true);
    //else Game::instance()->set_outVolume_SE(false);

    //SE
    if (Game::instance()->VolumeSelect(SE) != 0)
    {
        music::setVolume(EnumName, volume);

    }
    else
    {
        music::setVolume(EnumName, 0.0f);
    }

}