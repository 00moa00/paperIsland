#pragma once
#include <fstream>

class GameLoading : public Scene
{
private:
	static GameLoading instance_;

	int state = 0;
	int timer = 0;
	int bookTimer = 0;

	int stageNumSave = 0;
	bool Drawflag = false;

	SpriteManager* sprGameloading = nullptr;
	SpriteManager* sprLoadingBook = nullptr;
	SpriteManager* sprNotice = nullptr;
	SpriteManager* sprWarning = nullptr;

public:
	static GameLoading* instance() { return &instance_; }
	~GameLoading();

	void init() override;
	void update() override;
	void draw() override;
	void deinit() override;
	std::ofstream ofSavedata; //‘‚«‚İ—p
	std::ifstream ifSavedata; //“Ç‚İ‚İ—p

	int getofstageNum() { return stageNumSave; }


private:
	GameLoading();

};
