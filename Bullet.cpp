#include "Novice.h"
#include "bullet.h"
#include "math.h"

Bullet::Bullet() {
	posX = -100;
	posY = -100;

	speed = 10;

	radius = 8;

	isShot = false;
}

Bullet::~Bullet() {};

void Bullet::Fire(int& startPosX, int& startPosY) {
	posX = startPosX;
	posY = startPosY;
	isShot = true;

}

void Bullet::Update() {

	if (isShot) {
		posY -= speed;
	}
}

void Bullet::Draw() {
	if (isShot) {
		Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, WHITE, kFillModeSolid);
	}
}

void Bullet::Hit(int& posX_, int& posY_,int& radius_,int& isAlive) {

	int dx = posX- posX_;
	int dy = posY - posY_;
	int r1 = radius + radius_;

	if (sqrtf(float((dx * dx) + (dy * dy)) <= r1)) {

		isAlive = false;


	}

}