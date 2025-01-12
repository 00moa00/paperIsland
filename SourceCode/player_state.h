#pragma once

class PlayerWeapon
{
private:
	static PlayerWeapon instance_;

	bool hasWeapon = false;
	bool shotIsAlive = false;

	//SpriteManager* sprGameloading = nullptr;

public:
	static PlayerWeapon* instance() { return &instance_; }
	//~GameLoading();
	void SethasWeapon(bool b) { hasWeapon = b; }
	bool GethasWeapon() { return hasWeapon; }

	void setShotFlag(bool b) { shotIsAlive = b; }
	bool getShotFlag() { return shotIsAlive; }

private:
	PlayerWeapon() :
		hasWeapon(false),
		shotIsAlive(false)
	{
		if (StageSelect::instance()->getNum() > 1) hasWeapon = true;
	};

};

class PlayerJumpState
{
	static PlayerJumpState instance_;

	bool playerJump = false;

public:
	static PlayerJumpState* instance() { return &instance_; }

	void SetPlayerJump(bool b) { playerJump = b; }
	bool GetPlayerJump() { return playerJump; }
	void init() { playerJump = true; }

private:
	PlayerJumpState() :
		playerJump(true)
	{};
};

class PlayerClear
{
	static PlayerClear instance_;

	bool playerClear = false;

public:
	static PlayerClear* instance() { return &instance_; }

	void SetPlayerClear( ) { playerClear = true; }
	bool GetPlayerClear() { return playerClear; }
	void init() { playerClear = false; }

//private:
	//PlayerClear() :
	//{};


};


class Restart
{
	static Restart instance_;

	bool restart = false;

public:
	static Restart* instance() { return &instance_; }

	void SetRestart(bool b) { restart = b; }
	bool GetRestart() { return restart; }
	void init() { restart = false; }

	//private:
	Restart() { restart = false; }
	~Restart() { restart = false; }

		//{};


};
