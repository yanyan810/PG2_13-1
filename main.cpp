#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Hit.h"

const char kWindowTitle[] = "LC1B_24_ミヤザワハルヒ_タイトル";

int Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;

	Enemy* enemy[3];

	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			enemy[i] = new Enemy1;
		} else {
			enemy[i] = new Enemy2;
		}
	}


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive = true;
		}

		player->Updata(keys);

		for (int i = 0; i < 2; i++) {
			enemy[i]->Update();

			// 当たり判定
			for (int j = 0; j < Player::MAX_BULLETS; j++) {
				// 弾が発射中かどうかを確認
				if (player->bullet_[j]->isShot) {
					// 敵が生きているか確認
					if (enemy[i]->isAlive) {
						// 当たり判定処理
						if (IsCircleHit(
							enemy[i]->posX_, enemy[i]->posY_, enemy[i]->radius_,
							player->bullet_[j]->posX, player->bullet_[j]->posY, player->bullet_[j]->radius)) {
							enemy[i]->isAlive = false;             // 敵を倒す
							player->bullet_[j]->isShot = false;   // 弾を消す
							 Enemy::isAlive = false;
						}
					}
				}

				
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}
		player->Draw();

		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemy[0]->isAlive);
		Novice::ScreenPrintf(0, 32, "enemyB isAlive = %d", enemy[1]->isAlive);
		Novice::ScreenPrintf(0, 64, "WASD : player Move");
		Novice::ScreenPrintf(0, 96, "shot : SPACE");
		Novice::ScreenPrintf(0, 128, "enemy respawn : R");

		///
		/// ↑描画処理ここまで
		///

		 

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// メモリの解放
	delete player;
	for (int i = 0; i < 2; i++) {
		delete enemy[i];
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
