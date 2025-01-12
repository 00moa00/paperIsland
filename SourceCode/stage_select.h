#pragma once

class StageSelect /*: public Scene*/
{
private:
	static StageSelect instance_;

	int	stage_num = 0;


public:
	static StageSelect* instance() { return &instance_; }

	void init() ;
	void update() ;
	void draw() ;
	void deinit()  {};

	int getNum() { return stage_num; };
	void numUpdate();
	void addNum();
	void subNum();
	void setStageNum(int i) { stage_num = i; }


	//int getMap() { return stage_select; };


private:
	StageSelect() : stage_num(0) {}
	StageSelect(const StageSelect&) = delete;
};