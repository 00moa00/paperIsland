#pragma once


//******************************************************************************
//
//
//      audio.h
//
//
//******************************************************************************

//------< ’è” >----------------------------------------------------------------

// XWB‚ÌŽí—Þ
//#define XWB_SYSTEM          0
//#define XWB_STAGE1          1

//// SYSTEM‚ÌŒø‰Ê‰¹
//#define XWB_SYSTEM_KATI     0
//#define XWB_SYSTEM_START    1
//
//// STAGE1‚ÌŒø‰Ê‰¹
//#define XWB_STAGE1_COIN     0
//#define XWB_STAGE1_JUMP     1
//#define XWB_STAGE1_SHOT     2
//#define XWB_STAGE1_MISSILE  3
//#define XWB_STAGE1_LASER    4
//#define XWB_STAGE1_BOMB     5


enum MUSIC
{
    TITLE = 0,
    GAME,
    LOADING,
    CH1_BOSS,
    CLEAR,
    SECOND_HALF_GAME,

    MUSIC_MAX,
};

enum SOUND
{
    SOUND_START = MUSIC_MAX,

    PLAYER_ATTACK = SOUND_START,
    PLAYER_REVERSE,
    PLAYER_WALK,
    PLAYER_ATTACK_THROW,
    PLAYER_ATTACK_BOMB,
    PLAYER_JUMP,
    PLAYER_HIT,
    ITEM,
    STORY,
    PAUSE,
    PAUSE_CLOSE,
    STAGE8_WARNING,
    GET_STAR,
    TRANS,

    SOUND_MAX,
    MENU_SELECT
};


//------< ŠÖ” >----------------------------------------------------------------
void audio_init();
void audio_deinit();

void audio_update();

void audio_setVolume_BGM(int EnumName, float volume);
void audio_setVolume_SE(int EnumName, float volume);