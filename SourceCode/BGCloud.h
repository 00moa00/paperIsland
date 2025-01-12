#pragma once

class BGCloud
{
private:
	SpriteManager* sprBackCloud1=nullptr;
	SpriteManager* sprBackCloud2 = nullptr;

	SpriteManager* sprBackSky = nullptr;

	float CloudSpeedY;

	int num = 0;
public:
	void cloudMove(SpriteManager* sprObj);

	BGCloud();
	// 初期化
	void init();



	//デストラクタ
	~BGCloud();
	//void deinit();

	// 更新
	void update();

	// 描画
	void draw(const VECTOR2 scrollPos);

private:
	// クリア
	//void clear();

};