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
	// ������
	void init();



	//�f�X�g���N�^
	~BGCloud();
	//void deinit();

	// �X�V
	void update();

	// �`��
	void draw(const VECTOR2 scrollPos);

private:
	// �N���A
	//void clear();

};