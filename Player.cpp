#include "Novice.h"
#include "player.h"

Player::Player() {
	playerPosX = 640;
	playerPosY = 360;
	playerRadius = 32;
	playerSpeed = 10;
	shotCoolTime = 4;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i] = new Bullet(); // Bulletオブジェクトを初期化
	}

}

Player::~Player() {

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		delete bullet_[i];
	}
}

void Player::Updata(char* keys) {

	if (keys[DIK_D]) {
		playerPosX += playerSpeed;
	}

	if (keys[DIK_A]) {
		playerPosX -= playerSpeed;
	}

	if (keys[DIK_W]) {
		playerPosY -= playerSpeed;
	}

	if (keys[DIK_S]) {
		playerPosY += playerSpeed;
	}


	if (shotCoolTime > 0) {
		shotCoolTime--;
	}

	if (keys[DIK_SPACE] ) {
		if (shotCoolTime <= 0) {
			for (int i = 0; i < MAX_BULLETS; i++) {
				if (!bullet_[i]->isShot) {
					bullet_[i]->Fire(playerPosX, playerPosY);
					shotCoolTime = 4;
					break;
				}
			}
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullet_[i]->isShot) {
			bullet_[i]->Update();
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullet_[i]->posY < 0) {
			bullet_[i]->isShot = false;
		}
	}
}


void Player::Draw() {
	Novice::DrawEllipse(playerPosX, playerPosY, playerRadius, playerRadius, 0.0f, WHITE, kFillModeSolid);

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i]->Draw();

	}

}
