#include "Novice.h"
#include "Enemy2.h"
#include "math.h"

const int rightWall = 1280;
const int Dirt = 720;

const int minusNum = -1;

Enemy2::Enemy2() {

	posX_ = 500;
	posY_ = 200;

	radius_ = 50;

	speed_ = -5;

	isAlive = true;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i] = new Bullet(); // Bulletオブジェクトを初期化
	}


}

void Enemy2::Update() {

	posY_ += speed_;

	if (posY_ > Dirt - radius_ || posY_ < radius_) {

		speed_ *= minusNum;

	}

	if (isAlive) {
		for (int i = 0; i < MAX_BULLETS; i++) {
			if (sqrtf(float((posX_ - bullet_[i]->posX) * (posX_ - bullet_[i]->posX) +
				(posY_ - bullet_[i]->posY) * (posY_ - bullet_[i]->posY))) <= radius_/2 + bullet_[i]->radius/2) {
				isAlive = false;
			}


		}
	}


}

void Enemy2::Draw() {

	if (isAlive) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLACK, kFillModeSolid);
	}
}