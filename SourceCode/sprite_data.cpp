//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

//------< インクルード >----------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< データ >---------------------------------------------------------------


// 2D画像ロードデータ
LoadTexture loadTexture[] = {
    { TEXNO::PLAYER,        L"./Data/Images/PLAYER/player.png",        1U },// プレイヤー
    {TEXNO::PLAYER_OVER,     L"./Data/Images/PLAYER/player_gameover.png",        1U},

    { TEXNO::MAP_TERRAIN,   L"./Data/Maps/chip_terrain1.png",         static_cast<UINT>(BG::LOOP_X * BG::LOOP_Y) }, // マップ地形
    { TEXNO::MAP_TERRAIN_REV,   L"./Data/Maps/chip_terrain2.png",    static_cast<UINT>(BG::LOOP_X * BG::LOOP_Y) }, // マップ地形

    {TEXNO::PAR_BLOCK,     L"./Data/Images/BLOCK/leaf.png", 1U},       //移動ブロック
    {TEXNO::DROP_BLOCK,     L"./Data/Images/BLOCK/block_pink.png", 1U}, //落ちるブロック
    {TEXNO::RUBY_BLOCK,     L"./Data/Images/BLOCK/tu_block.png", 1U},  //うさぎブロック


    { TEXNO::SHOT,         L"./Data/Images/PLAYER/water.png", 1U },   //プレイヤーの弾
    { TEXNO::SHOT1,         L"./Data/Images/PLAYER/water_level.png", 1U },   //プレイヤーの弾(威力小)
    { TEXNO::E_SHOT,         L"./Data/Images/PLAYER/effect.png", 1U },
  
    { TEXNO::SPRITEM,           L"./Data/Maps/ITEM/item.png",       1U },

    { TEXNO::DE_ENEMY,        L"./Data/Images/ENEMY/over_anime.png",       1U },
        { TEXNO::DE_ENEMY2,        L"./Data/Images/ENEMY/over_anime2.png",       1U },

    { TEXNO::ENEMY0,        L"./Data/Images/ENEMY/enemy0.png",       1U },
    { TEXNO::ENEMY1,        L"./Data/Images/ENEMY/enemy1.png",       1U },
    {TEXNO::ENEMY1_SHOT,    L"./Data/Images/ENEMY/enemy1_tama.png", 1U},            //敵1が撃ってくる弾
    { TEXNO::ENEMY5,        L"./Data/Images/ENEMY/enemy5.png",       1U },
    { TEXNO::ENEMY7,        L"./Data/Images/ENEMY/enemy7.png",       1U },
    { TEXNO::ENEMY9,        L"./Data/Images/ENEMY/enemy9.png",       1U },
    { TEXNO::ENEMY10,        L"./Data/Images/ENEMY/enemy10.png",       1U },
    { TEXNO::ENEMY11,        L"./Data/Images/ENEMY/enemy11.png",       1U },

    { TEXNO::WATER_ENEMY,        L"./Data/Images/ENEMY/mini_water.png",       1U },
    { TEXNO::WATER_ENEMY2,        L"./Data/Images/ENEMY/mini_water2.png",       1U },

    {TEXNO::ENEMY_HIT,    L"./Data/Images/ENEMY/hit.png", 1U},

    { -1, nullptr }	// 終了フラグ

};


LoadTexture loadTexture_Boss[] = {

 { TEXNO::PLAYER,        L"./Data/Images/PLAYER/player.png",        1U },// プレイヤー
    {TEXNO::PLAYER_OVER,     L"./Data/Images/PLAYER/player_gameover.png",        1U},

    { TEXNO::MAP_TERRAIN,   L"./Data/Maps/chip_terrain1.png",         static_cast<UINT>(BG::LOOP_X * BG::LOOP_Y) }, // マップ地形
    { TEXNO::MAP_TERRAIN_REV,   L"./Data/Maps/chip_terrain2.png",    static_cast<UINT>(BG::LOOP_X * BG::LOOP_Y) }, // マップ地形

    //{TEXNO::PAR_BLOCK,     L"./Data/Images/BLOCK/leaf.png", 1U},       //移動ブロック
    //{TEXNO::DROP_BLOCK,     L"./Data/Images/BLOCK/block_pink.png", 1U}, //落ちるブロック
    //{TEXNO::RUBY_BLOCK,     L"./Data/Images/BLOCK/tu_block.png", 1U},  //うさぎブロック


    { TEXNO::SHOT,         L"./Data/Images/PLAYER/water.png", 1U },   //プレイヤーの弾
    { TEXNO::SHOT1,         L"./Data/Images/PLAYER/water_level.png", 1U },   //プレイヤーの弾(威力小)
    { TEXNO::E_SHOT,         L"./Data/Images/PLAYER/effect.png", 1U },

    { TEXNO::SPRITEM,           L"./Data/Maps/ITEM/item.png",       1U },

    { TEXNO::DE_ENEMY,        L"./Data/Images/ENEMY/over_anime.png",       1U },
       // { TEXNO::DE_ENEMY2,        L"./Data/Images/ENEMY/over_anime2.png",       1U },

    { TEXNO::ENEMY0,        L"./Data/Images/ENEMY/enemy0.png",       1U },
   // { TEXNO::ENEMY1,        L"./Data/Images/ENEMY/enemy1.png",       1U },
   // {TEXNO::ENEMY1_SHOT,    L"./Data/Images/ENEMY/enemy1_tama.png", 1U},            //敵1が撃ってくる弾
   // { TEXNO::ENEMY5,        L"./Data/Images/ENEMY/enemy5.png",       1U },
   // { TEXNO::ENEMY7,        L"./Data/Images/ENEMY/enemy7.png",       1U },
   // { TEXNO::STAGE8_WATER,        L"./Data/Images/ENEMY/stage8_water2.png",       1U },
   // { TEXNO::ENEMY9,        L"./Data/Images/ENEMY/enemy9.png",       1U },
   // { TEXNO::ENEMY10,        L"./Data/Images/ENEMY/enemy10.png",       1U },
   // { TEXNO::ENEMY11,        L"./Data/Images/ENEMY/enemy11.png",       1U },
   //
   // { TEXNO::WATER_ENEMY,        L"./Data/Images/ENEMY/mini_water.png",       1U },
   // { TEXNO::WATER_ENEMY2,        L"./Data/Images/ENEMY/mini_water2.png",       1U },

    {TEXNO::ENEMY_HIT,    L"./Data/Images/ENEMY/hit.png", 1U},
    { TEXNO::BOSS,        L"./Data/Images/ENEMY/boss/boss_anime.png",       1U },

    {TEXNO::STAGE5_PATTERN02,  L"./Data/Images/ENEMY/boss/boss_attack/tama2_anime.png",       1U},
    {TEXNO::STAGE5_PATTERN04,  L"./Data/Images/ENEMY/boss/boss_attack/water.png",       1U},
    {TEXNO::STAGE5_PATTERN05,  L"./Data/Images/ENEMY/boss/boss_attack/tama1_anime.png",       1U},
        { -1, nullptr }	// 終了フラグ

};
//------< マクロ >--------------------------------------------------------------
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // 画像の真ん中が中心
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // 画像の足元が中心
#define SPRITE_BOTTOM_DIE(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/6,(height)+50   }  // 画像の足元が中心

#define SPRITE_BOTTOM_PLAYER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // 画像の足元が中心
#define SPRITE_BOTTOM_ENEMY(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)-30   }  // 画像の足元が中心


//------< プレイヤー >----------------------------------------------------------
//待機
SpriteData sprPlayer_Wait0 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 0, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait1 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 1, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait2 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 2, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait3 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 3, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait4 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 4, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait5 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 5, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait6 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 6, 192 * 0, 170, 192);
SpriteData sprPlayer_Wait7 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 7, 192 * 0, 170, 192);

//上歩き
//SpriteData sprPlayer_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 0, 96, 128);
//SpriteData sprPlayer_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 0, 96, 128);
//SpriteData sprPlayer_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 0, 96, 128);

//右歩き
SpriteData sprPlayer_Right0 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 0, 192 * 1, 170, 192);
SpriteData sprPlayer_Right1 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 1, 192 * 1, 170, 192);
SpriteData sprPlayer_Right2 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 2, 192 * 1, 170, 192);
SpriteData sprPlayer_Right3 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 3, 192 * 1, 170, 192);
SpriteData sprPlayer_Right4 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 4, 192 * 1, 170, 192);
SpriteData sprPlayer_Right5 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 5, 192 * 1, 170, 192);
SpriteData sprPlayer_Right6 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 6, 192 * 1, 170, 192);
SpriteData sprPlayer_Right7 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 7, 192 * 1, 170, 192);
SpriteData sprPlayer_Right8 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 8, 192 * 1, 170, 192);
SpriteData sprPlayer_Right9 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 9, 192 * 1, 170, 192);
SpriteData sprPlayer_Right10 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 10, 192 * 1, 170, 192);
SpriteData sprPlayer_Right11 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 11, 192 * 1, 170, 192);

//下歩き
//SpriteData sprPlayer_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 2, 96, 128);
//SpriteData sprPlayer_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 2, 96, 128);
//SpriteData sprPlayer_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 2, 96, 128);

//左歩き
//SpriteData sprPlayer_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 3, 96, 128);
//SpriteData sprPlayer_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 3, 96, 128);
//SpriteData sprPlayer_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 3, 96, 128);

//ジャンプ
SpriteData sprPlayer_Jump0 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 0, 192 * 2, 170, 192);

//攻撃(作り)
SpriteData sprPlayer_attack_make0 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 0, 192 * 3, 170, 192);
SpriteData sprPlayer_attack_make1 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 1, 192 * 3, 170, 192);
SpriteData sprPlayer_attack_make2 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 2, 192 * 3, 170, 192);
SpriteData sprPlayer_attack_make3 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 3, 192 * 3, 170, 192);
SpriteData sprPlayer_attack_make4 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 4, 192 * 3, 170, 192);

//攻撃(投擲)
SpriteData sprPlayer_attack_throw0 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 0, 192 * 4, 170, 192);
SpriteData sprPlayer_attack_throw1 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 1, 192 * 4, 170, 192);
SpriteData sprPlayer_attack_throw2 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 2, 192 * 4, 170, 192);
SpriteData sprPlayer_attack_throw3 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 3, 192 * 4, 170, 192);
SpriteData sprPlayer_attack_throw4 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 4, 192 * 4, 170, 192);

//プレイヤーの弾
SpriteData sprPlayer_attack_water0 = SPRITE_CENTER(TEXNO::SHOT, 196 * 0, 124 * 0, 196, 124);
SpriteData sprPlayer_attack_water1 = SPRITE_CENTER(TEXNO::SHOT, 196 * 1, 124 * 0, 196, 124);
SpriteData sprPlayer_attack_water2 = SPRITE_CENTER(TEXNO::SHOT, 196 * 2, 124 * 0, 196, 124);
SpriteData sprPlayer_attack_water3 = SPRITE_CENTER(TEXNO::SHOT, 196 * 3, 124 * 0, 196, 124);
SpriteData sprPlayer_attack_water4 = SPRITE_CENTER(TEXNO::SHOT, 196 * 4, 124 * 0, 196, 124);

//プレイヤーの弾(威力小)
SpriteData sprPlayer_attack_water0_l1 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 0, 124 * 0, 196, 124);
SpriteData sprPlayer_attack_water1_l1 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 1, 124 * 0, 196, 124);
SpriteData sprPlayer_attack_water2_l1 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 2, 124 * 0, 196, 124);

//プレイヤーの弾(威力中)
SpriteData sprPlayer_attack_water0_l2 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 0, 124 * 1, 196, 124);
SpriteData sprPlayer_attack_water1_l2 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 1, 124 * 1, 196, 124);
SpriteData sprPlayer_attack_water2_l2 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 2, 124 * 1, 196, 124);

//プレイヤーの弾(威力大)
SpriteData sprPlayer_attack_water0_l3 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 0, 124 * 2, 196, 124);
SpriteData sprPlayer_attack_water1_l3 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 1, 124 * 2, 196, 124);
SpriteData sprPlayer_attack_water2_l3 = SPRITE_CENTER(TEXNO::SHOT1, 196 * 2, 124 * 2, 196, 124);

//ゲームオーバー
SpriteData animePlayer_Over0 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 0, 250 * 0, 280, 250);
SpriteData animePlayer_Over1 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 1, 250 * 0, 280, 250);
SpriteData animePlayer_Over2 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 2, 250 * 0, 280, 250);
SpriteData animePlayer_Over3 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 3, 250 * 0, 280, 250);
SpriteData animePlayer_Over4 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 4, 250 * 0, 280, 250);
SpriteData animePlayer_Over5 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 5, 250 * 0, 280, 250);
SpriteData animePlayer_Over6 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 6, 250 * 0, 280, 250);
SpriteData animePlayer_Over7 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 7, 250 * 0, 280, 250);
SpriteData animePlayer_Over8 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 8, 250 * 0, 280, 250);
SpriteData animePlayer_Over9 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 9, 250 * 0, 280, 250);
SpriteData animePlayer_Over10 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 10, 250 * 0, 280, 250);
SpriteData animePlayer_Over11 = SPRITE_BOTTOM(TEXNO::PLAYER_OVER, 280 * 11, 250 * 0, 280, 250);





//被弾
SpriteData sprPlayer_hit0 = SPRITE_BOTTOM_PLAYER(TEXNO::PLAYER, 170 * 0, 192 * 5, 170, 192);


SpriteData sprPlayer_water_e0 = SPRITE_CENTER(TEXNO::E_SHOT, 196 * 0, 160 * 0, 196, 160);
SpriteData sprPlayer_water_e1 = SPRITE_CENTER(TEXNO::E_SHOT, 196 * 1, 160 * 0, 196, 160);

SpriteData sprPlayer_water_e0_l2 = SPRITE_CENTER(TEXNO::E_SHOT, 196 * 0, 160 * 1, 196, 160);
SpriteData sprPlayer_water_e1_l2 = SPRITE_CENTER(TEXNO::E_SHOT, 196 * 1, 160 * 1, 196, 160);

SpriteData sprPlayer_water_e0_l3 = SPRITE_CENTER(TEXNO::E_SHOT, 196 * 0, 160 * 2, 196, 160);
SpriteData sprPlayer_water_e1_l3 = SPRITE_CENTER(TEXNO::E_SHOT, 196 * 1, 160 * 2, 196, 160);

//------< アイテム >-------------------------------------------------------------
SpriteData sprItemWeapon = SPRITE_CENTER(TEXNO::SPRITEM, 125 * 4, 120 * 0, 125, 120);
SpriteData sprItemMove = SPRITE_CENTER(TEXNO::SPRITEM, 125 * 0, 120 * 0, 125, 120);
SpriteData sprItemHp = SPRITE_CENTER(TEXNO::SPRITEM, 125 * 1, 120 * 0, 125, 120);
SpriteData sprItemMoveFlag = SPRITE_CENTER(TEXNO::SPRITEM, 125 * 2, 120 * 0, 125, 120);
SpriteData sprItemPaper = SPRITE_CENTER(TEXNO::SPRITEM, 125 * 3, 120 * 0, 125, 120);

//------< 敵 >------------------------------------------------------------------

//================================
//      敵 hit
//================================
SpriteData sprEnemyHit = SPRITE_CENTER(TEXNO::ENEMY_HIT, 120 * 0, 60 * 0, 120, 60);
SpriteData sprEnemyHit2 = SPRITE_CENTER(TEXNO::ENEMY_HIT, 120 * 1, 60 * 0, 120, 60);
SpriteData sprEnemyHit3 = SPRITE_CENTER(TEXNO::ENEMY_HIT, 120 * 2, 60 * 0, 120, 60);

//================================
//      敵 死亡アニメ
//================================
SpriteData sprDe_Enemy0 = SPRITE_BOTTOM(TEXNO::DE_ENEMY, 160 * 0, 0, 160, 160);
SpriteData sprDe_Enemy1 = SPRITE_BOTTOM(TEXNO::DE_ENEMY, 160 * 1, 0, 160, 160);
SpriteData sprDe_Enemy2 = SPRITE_BOTTOM(TEXNO::DE_ENEMY, 160 * 2, 0, 160, 160);
SpriteData sprDe_Enemy3 = SPRITE_BOTTOM(TEXNO::DE_ENEMY, 160 * 3, 0, 160, 160);


//================================
//      敵 死亡アニメ
//================================
SpriteData sprDe2_Enemy0 = SPRITE_BOTTOM_DIE(TEXNO::DE_ENEMY2, 256 * 0, 0, 256, 256);
SpriteData sprDe2_Enemy1 = SPRITE_BOTTOM_DIE(TEXNO::DE_ENEMY2, 256 * 1, 0, 256, 256);
SpriteData sprDe2_Enemy2 = SPRITE_BOTTOM_DIE(TEXNO::DE_ENEMY2, 256 * 2, 0, 256, 256);
SpriteData sprDe2_Enemy3 = SPRITE_BOTTOM_DIE(TEXNO::DE_ENEMY2, 256 * 3, 0, 256, 256);


//================================
//      敵0
//================================


//右歩き
SpriteData sprEnemy0_Right0 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 0, 153 * 1, 194, 153);
SpriteData sprEnemy0_Right1 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 1, 153 * 1, 194, 153);
SpriteData sprEnemy0_Right2 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 2, 153 * 1, 194, 153);

//下歩き
//SpriteData sprEnemy0_Down0 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 0, 153 * 0, 194, 153);
//SpriteData sprEnemy0_Down1 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 1, 153 * 0, 194, 153);
//SpriteData sprEnemy0_Down2 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 2, 153 * 0, 194, 153);
//左歩き
SpriteData sprEnemy0_Left0 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 0, 153 * 0, 194, 153);
SpriteData sprEnemy0_Left1 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 1, 153 * 0, 194, 153);
SpriteData sprEnemy0_Left2 = SPRITE_BOTTOM(TEXNO::ENEMY0, 194 * 2, 153 * 0, 194, 153);
//================================
//      敵1
//================================

//上歩き
//SpriteData sprEnemy1_Up0 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 0, 153 * 0, 194, 153);
//SpriteData sprEnemy1_Up1 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 1, 153 * 0, 194, 153);
//SpriteData sprEnemy1_Up2 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 2, 153 * 0, 194, 153);

//右歩き
SpriteData sprEnemy1_Right0 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 0, 153 * 1, 194, 153);
SpriteData sprEnemy1_Right1 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 1, 153 * 1, 194, 153);
SpriteData sprEnemy1_Right2 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 2, 153 * 1, 194, 153);

//下歩き
//SpriteData sprEnemy1_Down0 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 0, 153 * 0, 194, 153);
//SpriteData sprEnemy1_Down1 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 1, 153 * 0, 194, 153);
//SpriteData sprEnemy1_Down2 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 2, 153 * 0, 194, 153);
//左歩き
SpriteData sprEnemy1_Left0 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 0, 153 * 0, 194, 153);
SpriteData sprEnemy1_Left1 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 1, 153 * 0, 194, 153);
SpriteData sprEnemy1_Left2 = SPRITE_BOTTOM(TEXNO::ENEMY1, 194 * 2, 153 * 0, 194, 153);


//================================
//      敵5
//================================



//右歩き
SpriteData sprEnemy5_Right0 = SPRITE_BOTTOM(TEXNO::ENEMY5, 194 * 0, 153 * 1, 194, 153);
SpriteData sprEnemy5_Right1 = SPRITE_BOTTOM(TEXNO::ENEMY5, 194 * 1, 153 * 1, 194, 153);
SpriteData sprEnemy5_Right2 = SPRITE_BOTTOM(TEXNO::ENEMY5, 194 * 2, 153 * 1, 194, 153);


//左歩き
SpriteData sprEnemy5_Left0 = SPRITE_BOTTOM(TEXNO::ENEMY5, 194 * 0, 153 * 0, 194, 153);
SpriteData sprEnemy5_Left1 = SPRITE_BOTTOM(TEXNO::ENEMY5, 194 * 1, 153 * 0, 194, 153);
SpriteData sprEnemy5_Left2 = SPRITE_BOTTOM(TEXNO::ENEMY5, 194 * 2, 153 * 0, 194, 153);

//================================
//      敵7
//================================


SpriteData sprEnemy7 = SPRITE_BOTTOM(TEXNO::ENEMY7, 249 * 0, 237 * 0, 249, 237);

//================================
//      敵9
//================================


//右歩き
SpriteData sprEnemy9_Right0 = SPRITE_BOTTOM(TEXNO::ENEMY9, 194 * 0, 153 * 1, 194, 153);
SpriteData sprEnemy9_Right1 = SPRITE_BOTTOM(TEXNO::ENEMY9, 194 * 1, 153 * 1, 194, 153);
SpriteData sprEnemy9_Right2 = SPRITE_BOTTOM(TEXNO::ENEMY9, 194 * 2, 153 * 1, 194, 153);


SpriteData sprEnemy9_Left0 = SPRITE_BOTTOM(TEXNO::ENEMY9, 194 * 0, 153 * 0, 194, 153);
SpriteData sprEnemy9_Left1 = SPRITE_BOTTOM(TEXNO::ENEMY9, 194 * 1, 153 * 0, 194, 153);
SpriteData sprEnemy9_Left2 = SPRITE_BOTTOM(TEXNO::ENEMY9, 194 * 2, 153 * 0, 194, 153);



//================================
//    敵1, 9の攻撃弾
//================================
SpriteData sprEnemy01_shot1 = SPRITE_BOTTOM(TEXNO::ENEMY1_SHOT, 50 * 0, 50 * 0, 50, 50);           //左上
SpriteData sprEnemy01_shot2 = SPRITE_BOTTOM(TEXNO::ENEMY1_SHOT, 50 * 1, 50 * 0, 50, 50);           //右上
SpriteData sprEnemy01_shot3 = SPRITE_BOTTOM(TEXNO::ENEMY1_SHOT, 50 * 0, 50 * 1, 50, 50);           //左下
SpriteData sprEnemy01_shot4 = SPRITE_BOTTOM(TEXNO::ENEMY1_SHOT, 50 * 1, 50 * 1, 50, 50);           //右下


//================================
//      10
//================================


SpriteData sprEnemy10_0 = SPRITE_BOTTOM_ENEMY(TEXNO::ENEMY10, 445 * 0, 413 * 0, 445, 413);
SpriteData sprEnemy10_1 = SPRITE_BOTTOM_ENEMY(TEXNO::ENEMY10, 445 * 1, 413 * 0, 445, 413);
SpriteData sprEnemy10_2 = SPRITE_BOTTOM_ENEMY(TEXNO::ENEMY10, 445 * 2, 413 * 0, 445, 413);


SpriteData sprEnemy10_3 = SPRITE_BOTTOM_ENEMY(TEXNO::ENEMY10, 445 * 0, 413 * 1, 445, 413);
SpriteData sprEnemy10_4 = SPRITE_BOTTOM_ENEMY(TEXNO::ENEMY10, 445 * 1, 413 * 1, 445, 413);
SpriteData sprEnemy10_5 = SPRITE_BOTTOM_ENEMY(TEXNO::ENEMY10, 445 * 2, 413 * 1, 445, 413);


//================================
//      11
//================================


SpriteData sprEnemy11 = SPRITE_BOTTOM(TEXNO::ENEMY11, 1500 * 0, 237 * 0, 1500, 237);

//================================
//      water
//================================




//================================
//      watermini
//================================


SpriteData sprWatermini1 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY, 68 * 0, 68 * 0, 68, 68);
SpriteData sprWatermini2 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY, 68 * 1, 68 * 0, 68, 68);
SpriteData sprWatermini3 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY, 68 * 2, 68 * 0, 68, 68);
SpriteData sprWatermini4 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY, 68 * 3, 68 * 0, 68, 68);



//================================
//      watermini2
//================================


SpriteData sprWatermini_re1 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY2, 68 * 0, 68 * 0, 68, 68);
SpriteData sprWatermini_re2 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY2, 68 * 1, 68 * 0, 68, 68);
SpriteData sprWatermini_re3 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY2, 68 * 2, 68 * 0, 68, 68);
SpriteData sprWatermini_re4 = SPRITE_BOTTOM(TEXNO::WATER_ENEMY2, 68 * 3, 68 * 0, 68, 68);

//================================
//      敵3 // BOSS
//================================

SpriteData sprEnemy3_Init = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 6, 893 * 0, 900, 893);

SpriteData sprEnemy3_Attack00 = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 1, 893 * 0, 900, 893);
SpriteData sprEnemy3_Attack01 = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 2, 893 * 0, 900, 893);
SpriteData sprEnemy3_Attack02 = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 0, 893 * 0, 900, 893);
SpriteData sprEnemy3_Attack03 = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 3, 893 * 0, 900, 893);
SpriteData sprEnemy3_Attack04 = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 4, 893 * 0, 900, 893);
SpriteData sprEnemy3_Attack05 = SPRITE_BOTTOM(TEXNO::BOSS, 900 * 5, 893 * 0, 900, 893);





//================================
//      STAGE_PATTERN02,03
//================================
SpriteData sprStage5_pinkfront = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN02, 106 * 0, 110 * 0, 106, 110);
SpriteData sprStage5_blueback = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN02, 106 * 1, 110 * 0, 106, 110);
SpriteData sprStage5_pinkback = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN02, 106 * 0, 110 * 1, 106, 110);
SpriteData sprStage5_bluefront = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN02, 106 * 1, 110 * 1, 106, 110);



//================================
//      STAGE_PATTERN04
//================================
SpriteData sprStage5_water = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN04, 1920 * 0, 192 * 0, 1920, 192);


//================================
//      STAGE_PATTERN05
//================================
SpriteData sprStage5_bomb_0 = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN05, 422 * 0, 344 * 0, 422, 344);
SpriteData sprStage5_bomb_1 = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN05, 422 * 1, 344 * 0, 422, 344);
SpriteData sprStage5_bomb_2 = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN05, 422 * 2, 344 * 0, 422, 344);
SpriteData sprStage5_bomb_3 = SPRITE_BOTTOM(TEXNO::STAGE5_PATTERN05, 422 * 3, 344 * 0, 422, 344);


//================================
//      BLOCKS
//================================

//par_block(平行移動)
SpriteData spr_parblock = SPRITE_CENTER(TEXNO::PAR_BLOCK, 256 * 0, 160 * 0, 256, 160);
SpriteData spr_dropblock = SPRITE_CENTER(TEXNO::DROP_BLOCK, 256 * 0, 160 * 0, 256, 160);


//うさぎブロック
SpriteData spr_rubyblock_0 = SPRITE_BOTTOM(TEXNO::RUBY_BLOCK, 421 * 0, 460 * 0, 421, 460);
SpriteData spr_rubyblock_1 = SPRITE_BOTTOM(TEXNO::RUBY_BLOCK, 421 * 1, 460 * 0, 421, 460);
SpriteData spr_rubyblock_2 = SPRITE_BOTTOM(TEXNO::RUBY_BLOCK, 421 * 2, 460 * 0, 421, 460);



//------< 武器 >----------------------------------------------------------------
SpriteData sprWeapon_Sword = SPRITE_BOTTOM(TEXNO::WEAPON, 128 * 0, 0, 128, 128);
//SpriteData sprWeapon_Katana = SPRITE_BOTTOM(TEXNO::WEAPON, 128 * 1, 0, 128, 128);
//SpriteData sprWeapon_Axe = SPRITE_BOTTOM(TEXNO::WEAPON, 128 * 2, 0, 128, 128);
//SpriteData sprWeapon_Spear = SPRITE_BOTTOM(TEXNO::WEAPON, 128 * 3, 0, 128, 128);
SpriteData sprWeapon_Shuriken = SPRITE_CENTER(TEXNO::WEAPON, 128 * 4, 0, 128, 128);

//------------------------------------------------------------------------------



#undef SPRITE_CENTER
#undef SPRITE_BOTTOM

//******************************************************************************

