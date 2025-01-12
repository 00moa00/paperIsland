#pragma once

//******************************************************************************
//
//
//      タイトルシーン
//
//
//******************************************************************************

//==============================================================================
//
//      Titleクラス
//
//==============================================================================



class Title : public Scene
{
private:
	static Title instance_;
	SpriteManager* sprTitle_front = nullptr;
	SpriteManager* sprTitle_back = nullptr;
	SpriteManager* sprTitle_move1 = nullptr;
	SpriteManager* sprTitle_move2 = nullptr;
	SpriteManager* sprTitle_start = nullptr;
	SpriteManager* sprTitle_exit = nullptr;
	SpriteManager* sprTitle_reset = nullptr;

	SpriteManager* sprTitle_notice = nullptr;

	SpriteManager* sprTitle_yes = nullptr;
	SpriteManager* sprTitle_no = nullptr;

	float move1_speedY = 0.0f;
	float move2_speedY = 0.0f;

	float moveSpeedY = 0.5f;
	//float exit_speedY = 0.0f;
	//float reset_speedY = 0.0f;

	int select = 0;
	int popUpState = 0;

	int state = 0;
	int timer = 0;

	bool yesFlag = false;
	bool noFlag = false;
	bool selectMove = true;
	bool titleFlag = false;

public:
	static Title* instance() { return &instance_; }
	~Title();

	void init() override;
	void update() override;
	void draw() override;
	void deinit() override;

	void popUp();

	void SetTitleFlag(bool b) { titleFlag = b; }
	bool GetTitleFlag() { return titleFlag; }


private:
	//Title(const Title&) = delete;
};

//******************************************************************************

