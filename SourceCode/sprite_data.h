#pragma once

//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

#include "../GameLib/texture.h"

// ���x����`
enum TEXNO
{
    // �Q�[��
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

//------< �v���C���[ >----------------------------------------------------------
//�ҋ@
extern GameLib::SpriteData sprPlayer_Wait0;
extern GameLib::SpriteData sprPlayer_Wait1;
extern GameLib::SpriteData sprPlayer_Wait2;
extern GameLib::SpriteData sprPlayer_Wait3;
extern GameLib::SpriteData sprPlayer_Wait4;
extern GameLib::SpriteData sprPlayer_Wait5;
extern GameLib::SpriteData sprPlayer_Wait6;
extern GameLib::SpriteData sprPlayer_Wait7;



//�����
//extern GameLib::SpriteData sprPlayer_Up0;
//extern GameLib::SpriteData sprPlayer_Up1;
//extern GameLib::SpriteData sprPlayer_Up2;

//�E����
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


//�W�����v
extern GameLib::SpriteData sprPlayer_Jump0;

//�U��(���)
extern GameLib::SpriteData sprPlayer_attack_make0;
extern GameLib::SpriteData sprPlayer_attack_make1;
extern GameLib::SpriteData sprPlayer_attack_make2;
extern GameLib::SpriteData sprPlayer_attack_make3;
extern GameLib::SpriteData sprPlayer_attack_make4;

//�U��(����)
extern GameLib::SpriteData sprPlayer_attack_throw0;
extern GameLib::SpriteData sprPlayer_attack_throw1;
extern GameLib::SpriteData sprPlayer_attack_throw2;
extern GameLib::SpriteData sprPlayer_attack_throw3;
extern GameLib::SpriteData sprPlayer_attack_throw4;

//�v���C���[�̒e
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

//��e
extern GameLib::SpriteData sprPlayer_hit0;

//�Q�[���I�[�o�[
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



//------< �A�C�e�� >-------------------------------------------------------------
extern GameLib::SpriteData sprItemWeapon;
extern GameLib::SpriteData sprItemHp;
extern GameLib::SpriteData sprItemMove;
extern GameLib::SpriteData sprItemMoveFlag;
extern GameLib::SpriteData sprItemPaper;


//------< �G >------------------------------------------------------------------

//================================
//      �G hit
//================================
extern GameLib::SpriteData sprEnemyHit;
extern GameLib::SpriteData sprEnemyHit2;
extern GameLib::SpriteData sprEnemyHit3;


//================================
//      �G ���S�A�j��
//================================

extern GameLib::SpriteData sprDe_Enemy0;
extern GameLib::SpriteData sprDe_Enemy1;
extern GameLib::SpriteData sprDe_Enemy2;
extern GameLib::SpriteData sprDe_Enemy3;

//================================
//      �G ���S�A�j��
//================================

extern GameLib::SpriteData sprDe2_Enemy0;
extern GameLib::SpriteData sprDe2_Enemy1;
extern GameLib::SpriteData sprDe2_Enemy2;
extern GameLib::SpriteData sprDe2_Enemy3;

//================================
//      �G0
//================================

//�E����
extern GameLib::SpriteData sprEnemy0_Right0;
extern GameLib::SpriteData sprEnemy0_Right1;
extern GameLib::SpriteData sprEnemy0_Right2;


//������
extern GameLib::SpriteData sprEnemy0_Left0;
extern GameLib::SpriteData sprEnemy0_Left1;
extern GameLib::SpriteData sprEnemy0_Left2;

//================================
//      �G1
//================================

//�����
//extern GameLib::SpriteData sprEnemy1_Up0;
//extern GameLib::SpriteData sprEnemy1_Up1;
//extern GameLib::SpriteData sprEnemy1_Up2;

//�E����
extern GameLib::SpriteData sprEnemy1_Right0;
extern GameLib::SpriteData sprEnemy1_Right1;
extern GameLib::SpriteData sprEnemy1_Right2;


//������
extern GameLib::SpriteData sprEnemy1_Left0;
extern GameLib::SpriteData sprEnemy1_Left1;
extern GameLib::SpriteData sprEnemy1_Left2;


//================================
//       �G1shot
//================================
extern GameLib::SpriteData sprEnemy01_shot1;
extern GameLib::SpriteData sprEnemy01_shot2;
extern GameLib::SpriteData sprEnemy01_shot3;
extern GameLib::SpriteData sprEnemy01_shot4;


//================================
//      �G5
//================================


//�E����
extern GameLib::SpriteData sprEnemy5_Right0;
extern GameLib::SpriteData sprEnemy5_Right1;
extern GameLib::SpriteData sprEnemy5_Right2;


//������
extern GameLib::SpriteData sprEnemy5_Left0;
extern GameLib::SpriteData sprEnemy5_Left1;
extern GameLib::SpriteData sprEnemy5_Left2;


//================================
//      �G7
//================================

extern GameLib::SpriteData sprEnemy7;

//================================
//      �G9
//================================


//�E����
extern GameLib::SpriteData sprEnemy9_Right0;
extern GameLib::SpriteData sprEnemy9_Right1;
extern GameLib::SpriteData sprEnemy9_Right2;


//������
extern GameLib::SpriteData sprEnemy9_Left0;
extern GameLib::SpriteData sprEnemy9_Left1;
extern GameLib::SpriteData sprEnemy9_Left2;


//================================
//      �G10
//================================


//�E����
extern GameLib::SpriteData sprEnemy10_0;
extern GameLib::SpriteData sprEnemy10_1;
extern GameLib::SpriteData sprEnemy10_2;


//�E����
extern GameLib::SpriteData sprEnemy10_3;
extern GameLib::SpriteData sprEnemy10_4;
extern GameLib::SpriteData sprEnemy10_5;


//================================
//      �G11
//================================


//�E����
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

//�����
extern GameLib::SpriteData sprEnemy3_Init;

//��
extern GameLib::SpriteData sprEnemy3_Attack00;
//��
extern GameLib::SpriteData sprEnemy3_Attack01;
//�Ԃ�����
extern GameLib::SpriteData sprEnemy3_Attack02;
//����
extern GameLib::SpriteData sprEnemy3_Attack03;
//���e�E��
extern GameLib::SpriteData sprEnemy3_Attack04;
//���e�E��
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


//------< ���� >----------------------------------------------------------------
//extern GameLib::SpriteData sprWeapon_Sword;
//extern GameLib::SpriteData sprWeapon_Katana;
//extern GameLib::SpriteData sprWeapon_Axe;
//extern GameLib::SpriteData sprWeapon_Spear;
//extern GameLib::SpriteData sprWeapon_Shuriken;

//******************************************************************************

