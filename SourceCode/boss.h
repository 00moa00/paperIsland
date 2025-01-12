#pragma once

#define BOSSHP 45

class Ch1boss {

private:
	static Ch1boss instance_;

	//~Ch1boss();

	bool attack00;
	bool attack01;
	bool attack02;
	bool attack03;
	bool attack04;
	bool attack05;
	bool BossisAlive = true;

	float bossHp;
	int next_timer;
	int appear_timer;
	int end_timer;
	int end_state;

	float speedY_Up1 = 1.0f;
	float speedX_Up1 = 1.0f;

	float speedY_Up2 = 1.0f;
	float speedX_Up2 = 1.0f;

	float speedY_Down1 = 1.0f;
	float speedX_Down1 = 1.0f;

	float speedY_Down2 = 1.0f;
	float speedX_Down2 = 1.0f;

	SpriteManager* sprHp_frame = nullptr;
	SpriteManager* sprHp_graph = nullptr;
	SpriteManager* sprHP_base = nullptr;
	SpriteManager* sprAppear = nullptr;


	SpriteManager* right_up = nullptr;
	SpriteManager* right_down = nullptr;
	SpriteManager* left_up = nullptr;
	SpriteManager* left_down = nullptr;



public:
	static Ch1boss* instance() { return &instance_; }

	Ch1boss()
		:
		attack00(false),
		attack01(false),
		attack02(false),
		attack03(false),
		attack04(false),
		attack05(false),
		sprHp_frame(nullptr),
		sprHp_graph(nullptr),
		sprHP_base(nullptr),
		bossHp(0),
		next_timer(0),
		appear_timer(0),
		end_timer(0),
		end_state(0)
	{}


	//================================
	//      ƒMƒ~ƒbƒN
	//================================

	//getter
	bool GetAttack00() { return attack00; }
	bool GetAttack01() { return attack01; }
	bool GetAttack02() { return attack02; }
	bool GetAttack03() { return attack03; }
	bool GetAttack04() { return attack04; }
	bool GetAttack05() { return attack05; }
	


	//setter
	void SetAttack00(bool b) { attack00 = b; }
	void SetAttack01(bool b) { attack01 = b; }
	void SetAttack02(bool b) { attack02 = b; }
	void SetAttack03(bool b) { attack03 = b; }
	void SetAttack04(bool b) { attack04 = b; }
	void SetAttack05(bool b) { attack05 = b; }


	void init();
	void update();
	void draw();
	void deinit();

	void end_update();
	void end_draw();

	float GetBosshp() { return bossHp; }
	void SupBosshp(int i);

	void setBossAlive(bool b) { BossisAlive = b; }
	bool getBossAlive() { return BossisAlive; }

	//getter


private:
	//Ch1boss() {}
	//Ch1boss(const Ch1boss&) = delete;
};


class Midboss {

private:
	static Midboss instance_;


	bool MBossisAlive = true;

	float midBossHp;

	SpriteManager* sprMhp_frame = nullptr;
	SpriteManager* sprMhp_graph = nullptr;
	SpriteManager* sprMhP_base = nullptr;

	SpriteManager* spr_MAppear = nullptr;

	int state = 0;
	int timer = 0;
	int appear_timer = 0;
	float setAlphaSpeed = 0;


public:
	static Midboss* instance() { return &instance_; }

	Midboss()
		:
		
		sprMhp_frame(nullptr),
		sprMhp_graph(nullptr),
		sprMhP_base(nullptr),
		spr_MAppear(nullptr),
		midBossHp(323),
		state(0),
		timer(0),
		appear_timer(0),
		setAlphaSpeed(0)
		
	{}




	void init() { 
		midBossHp = 323.0f; 

		sprMhp_frame = new SpriteManager(L"./Data/Images/ENEMY/midBoss_hp.png", VECTOR2(3730, 530), VECTOR2(1, 0.7f), VECTOR2(0, 0), VECTOR2(323, 59));
		sprMhp_graph = new SpriteManager(L"./Data/Images/ENEMY/midBoss_hpGraph.png", VECTOR2(3730, 530), VECTOR2(1, 0.7f), VECTOR2(0, 0), VECTOR2(323, 59));
		sprMhP_base = new SpriteManager(L"./Data/Images/ENEMY/midBoss_hpBack.png", VECTOR2(3730, 530), VECTOR2(1, 0.7f), VECTOR2(0, 0), VECTOR2(323, 59));

		spr_MAppear = new SpriteManager(L"./Data/Images/ENEMY/boss/stage4appear.png", VECTOR2(0, 0), VECTOR2(1, 1), VECTOR2(0, 0), VECTOR2(1920, 1088));

		spr_MAppear->setAlphaA(0.0f);
		setAlphaSpeed = 0.01f;
		state = 0;
		timer = 0;

	}
	void update() {
		//Game::instance()->bg()->addScrollX(10.0f);

		switch (state)
		{
		case 0:
			if (Game::instance()->player()->actorComponent()->isPlayerMove()) {
				spr_MAppear->addAlpha(setAlphaSpeed);
			}
		//spr_MAppear->addAlpha(setAlphaSpeed);
		if (spr_MAppear->getAlpha() >= 1.0f) state++;
		break;

		case 1:
			spr_MAppear->addAlpha(-setAlphaSpeed);
			break;

		}

	}
	void draw(const VECTOR2 scrollPos) {

		if (midBossHp > 5) {
			sprMhP_base->draw_cloud(scrollPos);
			sprMhp_graph->draw_cloud(scrollPos);
			sprMhp_frame->draw_cloud(scrollPos);
			spr_MAppear->draw();
		}
	}
	void deinit() {
		delete sprMhP_base;
		delete sprMhp_frame;
		delete sprMhp_graph;
		delete spr_MAppear;
		state = 0;
		timer = 0;
		setAlphaSpeed = 0.1f;

	}


	float GetBosshp() { return midBossHp; }
	void SupBosshp(int i) { 
		midBossHp -= i * 14.0f; 
		sprMhp_graph->subTexsizeX(i*14.0f);
	}

	void setBossAlive(bool b) { MBossisAlive = b; 
	}
	bool getBossAlive() { return MBossisAlive; }

	void setPositionX(float a) { 
		sprMhP_base->setPosX(a); 
		sprMhp_frame->setPosX(a);
		sprMhp_graph->setPosX(a);

	}



	void setPositionY(float a) {
		sprMhP_base->setPosY(a);
		sprMhp_frame->setPosY(a);
		sprMhp_graph->setPosY(a);

	}

	//getter


private:
	//Ch1boss() {}
	//Ch1boss(const Ch1boss&) = delete;
};


