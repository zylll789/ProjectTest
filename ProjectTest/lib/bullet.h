#pragma once

#include "utils.h"
#include "image.h"

class Bullet {
public:
	int width = 16;
	int height = 8;
	int speed;
	int x;
	int y;
	int origX;
	int origY;
	int index;
	int onUse;

	Box getBox() {
		Box box;
		box.x = x;
		box.y = y;
		box.width = width;
		box.height = height;
		return box;
	}

	void move() {
		x += speed;
	}

	void draw() {
		drawObj(x, y, 16, 8, 0, &img_kaltsit_bullet, &img_kaltsit_bullet_bg, 0);
	}

	void destroy() {
		onUse = 0;
		speed = 0;
		x = -10000;
		y = -10000;
		origX = -10000;
		origY = -10000;
	}
};

extern Bullet bullets[100];

void createAllBullet();

int getUsefulBullet();

void destroyBulletWithDistance();

void drawBullet();