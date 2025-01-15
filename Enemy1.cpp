#include "Novice.h"
#include "Enemy1.h"
#include "math.h"

const int rightWall = 1280;
const int Dirt = 720;

const int minusNum = -1;

Enemy1::Enemy1() {

	posX_ = 500;
	posY_ = 200;

	radius_ = 20;

	speed_ = 5;

	isAlive = true;

	dx = 0;
	dy = 0;
	distance = 0;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullet_[i] = new Bullet(); // Bulletオブジェクトを初期化
	}

}

void Enemy1::Update() {

	posX_ += speed_;

	if (posX_ > rightWall - radius_ || posX_ < radius_) {

		speed_ *= minusNum;

	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		dx = (posX_ - bullet_[i]->posX) * (posX_ - bullet_[i]->posX);
		dy = (posY_ - bullet_[i]->posY) * (posY_ - bullet_[i]->posY);
		distance = dx + dy;

	}

	if (isAlive) {
		for (int i = 0; i < MAX_BULLETS; i++) {
			if (sqrtf(float((posX_ - bullet_[i]->posX) * (posX_ - bullet_[i]->posX) +
				(posY_ - bullet_[i]->posY) * (posY_ - bullet_[i]->posY)
				<= radius_ + bullet_[i]->radius))) {

				isAlive = false;


			}

		}
	}

}


void Enemy1::Draw() {

	if (isAlive) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLACK, kFillModeSolid);
	}

}