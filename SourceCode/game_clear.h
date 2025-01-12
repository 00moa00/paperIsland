#pragma once

//******************************************************************************
//
//
//      ゲームオーバーシーン
//
//
//******************************************************************************

class GameClear : public Scene
{
private:
	static GameClear instance_;
	SpriteManager* sprGameclear = nullptr;


public:
	static GameClear* instance() { return &instance_; }
	~GameClear() {};

	void init() override;
	void update() override;
	void draw() override;
	void deinit() override;

private:
	//Title(const Title&) = delete;
};

//******************************************************************************

