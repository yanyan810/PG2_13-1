#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy
{

public:

	/// <summary>
	/// コンストラクト	
	/// </summary>
	Enemy1();

	~Enemy1();

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