#include "bullet.h"

Bullet bullets[100];

void createAllBullet() {
	for (int i = 0; i < 100; i++) {
		Bullet bullet;
		bullet.index = i;
		bullet.onUse = 0;
		bullet.speed = 0;
		bullet.x = -10000;
		bullet.y = -10000;
		bullet.origX = -10000;
		bullet.origY = -10000;
		bullets[i] = bullet;
	}
}

int getUsefulBullet() {
	for (int i = 0; i < 100; i++) {
		if (!bullets[i].onUse) {
			return bullets[i].index;
		}
	}
	return -1;
}

void destroyBulletWithDistance() {
	for (int i = 0; i < 100; i++) {
		if (bullets[i].onUse) {
			if (bullets[i].x - bullets[i].origX >= 300 || bullets[i].x - bullets[i].origX <= -300) {
				bullets[i].destroy();
			}
		}
	}
}

void drawBullet() {
	for (int i = 0; i < 100; i++) {
		if (bullets[i].onUse) {
			bullets[i].move();
			bullets[i].draw();
		}
	}
}