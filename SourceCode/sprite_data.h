#pragma once

//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

#include "../GameLib/texture.h"

// ÉâÉxÉãíËã`
enum TEXNO
{
    // ÉQÅ[ÉÄ
    PLAYER,
    PLAYER_OVER,

    MAP_TERRAIN,
    MAP_TERRAIN_REV,

    PAR_BLOCK,
    DROP_BLOCK,
    RUBY_BLOCK,

    SHOT,

    SHOT1,
    E_SHOT,


    SPRITEM,
    WEAPON,

    ENEMY0,
    ENEMY1,
    ENEMY1_SHOT,

    ENEMY5,
    ENEMY7,
    ENEMY9,
    WATER_ENEMY,
    WATER_ENEMY2,
    ENEMY10,
    ENEMY11,

    ENEMY_HIT,

    DE_ENEMY,
    DE_ENEMY2,

    STAGE5_PATTERN02,
    STAGE5_PATTERN04,
    STAGE5_PATTERN05,
    BOSS,



};
extern GameLib::LoadTexture loadTexture_Boss[];
extern GameLib::LoadTexture loadTexture[];

//------< ÉvÉåÉCÉÑÅ[ >----------------------------------------------------------
//ë“ã@
extern GameLib::SpriteData sprPlayer_Wait0;
extern GameLib::SpriteData sprPlayer_Wait1;
extern GameLib::SpriteData sprPlayer_Wait2;
extern GameLib::SpriteData sprPlayer_Wait3;
extern GameLib::SpriteData sprPlayer_Wait4;
extern GameLib::SpriteData sprPlayer_Wait5;
extern GameLib::SpriteData sprPlayer_Wait6;
extern GameLib::SpriteData sprPlayer_Wait7;



//è„ï‡Ç´
//extern GameLib::SpriteData sprPlayer_Up0;
//extern GameLib::SpriteData sprPlayer_Up1;
//extern GameLib::SpriteData sprPlayer_Up2;

//âEï‡Ç´
extern GameLib::SpriteData sprPlayer_Right0;
extern GameLib::SpriteData sprPlayer_Right1;
extern GameLib::SpriteData sprPlayer_Right2;
extern GameLib::SpriteData sprPlayer_Right3;
extern GameLib::SpriteData sprPlayer_Right4;
extern GameLib::SpriteData sprPlayer_Right5;
extern GameLib::SpriteData sprPlayer_Right6;
extern GameLib::SpriteData sprPlayer_Right7;
extern GameLib::SpriteData sprPlayer_Right8;
extern GameLib::SpriteData sprPlayer_Right9;
extern GameLib::SpriteData sprPlayer_Right10;
extern GameLib::SpriteData sprPlayer_Right11;


//ÉWÉÉÉìÉv
extern GameLib::SpriteData sprPlayer_Jump0;

//çUåÇ(çÏÇË)
extern GameLib::SpriteData sprPlayer_attack_make0;
extern GameLib::SpriteData sprPlayer_attack_make1;
extern GameLib::SpriteData sprPlayer_attack_make2;
extern GameLib::SpriteData sprPlayer_attack_make3;
extern GameLib::SpriteData sprPlayer_attack_make4;

//çUåÇ(ìäù±)
extern GameLib::SpriteData sprPlayer_attack_throw0;
extern GameLib::SpriteData sprPlayer_attack_throw1;
extern GameLib::SpriteData sprPlayer_attack_throw2;
extern GameLib::SpriteData sprPlayer_attack_throw3;
extern GameLib::SpriteData sprPlayer_attack_throw4;

//ÉvÉåÉCÉÑÅ[ÇÃíe
extern GameLib::SpriteData sprPlayer_attack_water0;
extern GameLib::SpriteData sprPlayer_attack_water1;
extern GameLib::SpriteData sprPlayer_attack_water2;
extern GameLib::SpriteData sprPlayer_attack_water3;
extern GameLib::SpriteData sprPlayer_attack_water4;

extern GameLib::SpriteData sprPlayer_attack_water0_l1;
extern GameLib::SpriteData sprPlayer_attack_water1_l1;
extern GameLib::SpriteData sprPlayer_attack_water2_l1;

extern GameLib::SpriteData sprPlayer_attack_water0_l2;
extern GameLib::SpriteData sprPlayer_attack_water1_l2;
extern GameLib::SpriteData sprPlayer_attack_water2_l2;

extern GameLib::SpriteData sprPlayer_attack_water0_l3;
extern GameLib::SpriteData sprPlayer_attack_water1_l3;
extern GameLib::SpriteData sprPlayer_attack_water2_l3;

extern GameLib::SpriteData sprPlayer_water_e0;
extern GameLib::SpriteData sprPlayer_water_e1;

extern GameLib::SpriteData sprPlayer_water_e0_l2;
extern GameLib::SpriteData sprPlayer_water_e1_l2;

extern GameLib::SpriteData sprPlayer_water_e0_l3;
extern GameLib::SpriteData sprPlayer_water_e1_l3;

//îÌíe
extern GameLib::SpriteData sprPlayer_hit0;

//ÉQÅ[ÉÄÉIÅ[ÉoÅ[
extern GameLib::SpriteData animePlayer_Over0;
extern GameLib::SpriteData animePlayer_Over1;
extern GameLib::SpriteData animePlayer_Over2;
extern GameLib::SpriteData animePlayer_Over3;
extern GameLib::SpriteData animePlayer_Over4;
extern GameLib::SpriteData animePlayer_Over5;
extern GameLib::SpriteData animePlayer_Over6;
extern GameLib::SpriteData animePlayer_Over7;
extern GameLib::SpriteData animePlayer_Over8;
extern GameLib::SpriteData animePlayer_Over9;
extern GameLib::SpriteData animePlayer_Over10;
extern GameLib::SpriteData animePlayer_Over11;



//------< ÉAÉCÉeÉÄ >-------------------------------------------------------------
extern GameLib::SpriteData sprItemWeapon;
extern GameLib::SpriteData sprItemHp;
extern GameLib::SpriteData sprItemMove;
extern GameLib::SpriteData sprItemMoveFlag;
extern GameLib::SpriteData sprItemPaper;


//------< ìG >------------------------------------------------------------------

//================================
//      ìG hit
//================================
extern GameLib::SpriteData sprEnemyHit;
extern GameLib::SpriteData sprEnemyHit2;
extern GameLib::SpriteData sprEnemyHit3;


//================================
//      ìG éÄñSÉAÉjÉÅ
//================================

extern GameLib::SpriteData sprDe_Enemy0;
extern GameLib::SpriteData sprDe_Enemy1;
extern GameLib::SpriteData sprDe_Enemy2;
extern GameLib::SpriteData sprDe_Enemy3;

//================================
//      ìG éÄñSÉAÉjÉÅ
//================================

extern GameLib::SpriteData sprDe2_Enemy0;
extern GameLib::SpriteData sprDe2_Enemy1;
extern GameLib::SpriteData sprDe2_Enemy2;
extern GameLib::SpriteData sprDe2_Enemy3;

//================================
//      ìG0
//================================

//âEï‡Ç´
extern GameLib::SpriteData sprEnemy0_Right0;
extern GameLib::SpriteData sprEnemy0_Right1;
extern GameLib::SpriteData sprEnemy0_Right2;


//ç∂ï‡Ç´
extern GameLib::SpriteData sprEnemy0_Left0;
extern GameLib::SpriteData sprEnemy0_Left1;
extern GameLib::SpriteData sprEnemy0_Left2;

//================================
//      ìG1
//================================

//è„ï‡Ç´
//extern GameLib::SpriteData sprEnemy1_Up0;
//extern GameLib::SpriteData sprEnemy1_Up1;
//extern GameLib::SpriteData sprEnemy1_Up2;

//âEï‡Ç´
extern GameLib::SpriteData sprEnemy1_Right0;
extern GameLib::SpriteData sprEnemy1_Right1;
extern GameLib::SpriteData sprEnemy1_Right2;


//ç∂ï‡Ç´
extern GameLib::SpriteData sprEnemy1_Left0;
extern GameLib::SpriteData sprEnemy1_Left1;
extern GameLib::SpriteData sprEnemy1_Left2;


//================================
//       ìG1shot
//================================
extern GameLib::SpriteData sprEnemy01_shot1;
extern GameLib::SpriteData sprEnemy01_shot2;
extern GameLib::SpriteData sprEnemy01_shot3;
extern GameLib::SpriteData sprEnemy01_shot4;


//================================
//      ìG5
//================================


//âEï‡Ç´
extern GameLib::SpriteData sprEnemy5_Right0;
extern GameLib::SpriteData sprEnemy5_Right1;
extern GameLib::SpriteData sprEnemy5_Right2;


//ç∂ï‡Ç´
extern GameLib::SpriteData sprEnemy5_Left0;
extern GameLib::SpriteData sprEnemy5_Left1;
extern GameLib::SpriteData sprEnemy5_Left2;


//================================
//      ìG7
//================================

extern GameLib::SpriteData sprEnemy7;

//================================
//      ìG9
//================================


//âEï‡Ç´
extern GameLib::SpriteData sprEnemy9_Right0;
extern GameLib::SpriteData sprEnemy9_Right1;
extern GameLib::SpriteData sprEnemy9_Right2;


//ç∂ï‡Ç´
extern GameLib::SpriteData sprEnemy9_Left0;
extern GameLib::SpriteData sprEnemy9_Left1;
extern GameLib::SpriteData sprEnemy9_Left2;


//================================
//      ìG10
//================================


//âEï‡Ç´
extern GameLib::SpriteData sprEnemy10_0;
extern GameLib::SpriteData sprEnemy10_1;
extern GameLib::SpriteData sprEnemy10_2;


//âEï‡Ç´
extern GameLib::SpriteData sprEnemy10_3;
extern GameLib::SpriteData sprEnemy10_4;
extern GameLib::SpriteData sprEnemy10_5;


//================================
//      ìG11
//================================


//âEï‡Ç´
extern GameLib::SpriteData sprEnemy11;



//================================
//      miniwater
//================================

extern GameLib::SpriteData sprWatermini1;
extern GameLib::SpriteData sprWatermini2;
extern GameLib::SpriteData sprWatermini3;
extern GameLib::SpriteData sprWatermini4;



//================================
//      miniwater2
//================================

extern GameLib::SpriteData sprWatermini_re1;
extern GameLib::SpriteData sprWatermini_re2;
extern GameLib::SpriteData sprWatermini_re3;
extern GameLib::SpriteData sprWatermini_re4;


//================================
//      water
//================================




//================================
//      BOSS
//================================

//è„ï‡Ç´
extern GameLib::SpriteData sprEnemy3_Init;

//íé
extern GameLib::SpriteData sprEnemy3_Attack00;
//íé
extern GameLib::SpriteData sprEnemy3_Attack01;
//â‘Ç™óéÇø
extern GameLib::SpriteData sprEnemy3_Attack02;
//Ç®êÖ
extern GameLib::SpriteData sprEnemy3_Attack03;
//îöíeÅEè„
extern GameLib::SpriteData sprEnemy3_Attack04;
//îöíeÅEâ∫
extern GameLib::SpriteData sprEnemy3_Attack05;


//================================
//      Pattenr02,3
//================================


extern GameLib::SpriteData sprStage5_pinkfront;
extern GameLib::SpriteData sprStage5_blueback;
extern GameLib::SpriteData sprStage5_pinkback;
extern GameLib::SpriteData sprStage5_bluefront;



//================================
//      Pattenr04
//================================

extern GameLib::SpriteData sprStage5_water;


//================================
//      Pattenr05
//================================


extern GameLib::SpriteData sprStage5_bomb_0;
extern GameLib::SpriteData sprStage5_bomb_1;
extern GameLib::SpriteData sprStage5_bomb_2;
extern GameLib::SpriteData sprStage5_bomb_3;


//================================
//      BLOCKS
//================================
extern GameLib::SpriteData spr_parblock;
extern GameLib::SpriteData spr_dropblock;

extern GameLib::SpriteData spr_rubyblock_0;
extern GameLib::SpriteData spr_rubyblock_1;
extern GameLib::SpriteData spr_rubyblock_2;


//------< ïêäÌ >----------------------------------------------------------------
//extern GameLib::SpriteData sprWeapon_Sword;
//extern GameLib::SpriteData sprWeapon_Katana;
//extern GameLib::SpriteData sprWeapon_Axe;
//extern GameLib::SpriteData sprWeapon_Spear;
//extern GameLib::SpriteData sprWeapon_Shuriken;

//******************************************************************************

