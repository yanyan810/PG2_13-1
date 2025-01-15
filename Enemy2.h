#pragma once
#include "Enemy.h"

class Enemy2 :public Enemy
{
public:

	/// <summary>
	/// コンストラクト
	/// </summary>
	Enemy2();

	~Enemy2();

	/// <summary>
	/// 移動関数
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw() override;

protected:

};
