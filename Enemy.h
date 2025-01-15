#pragma once
#include "Bullet.h"

class Enemy
{
public:

	/// <summary>
	/// 移動関数
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw();

	static int enemyCount;

	//変数の追加
	int posX_;
	int posY_;

	int speed_;
	int radius_;

	int isAlive;

	int dx;
	int dy;
	int distance;

public:

	//最大の弾数
	static const int MAX_BULLETS = 100;

	//包含をするための変数
	Bullet* bullet_[MAX_BULLETS];

};
