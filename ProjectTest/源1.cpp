#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <ctime>
#include "utils.h"
#include "image.h"
#include "bullet.h"
#include "main.h"
#include "player.h"
#include "dog.h"

//get git https://dev.azure.com/3039176805/ProjectTest/_git/ProjectTest

Player kaltsit;

int main() {
	srand(time(0));
	kaltsit.create();

	createAllBullet();
	createAllDog();

	initgraph(1500, 750);
	camera.create();
	kaltsit.camera = camera;

	char input;

	loadIMG();

	BeginBatchDraw();

	while (1) {
		if (_kbhit()) {
			input = _getch();
			if (input == ' ') {
				kaltsit.shoot();
				spawnRandom();
			}
			else {
				if (input == 'a') {
					kaltsit.flag = 0;
					kaltsit.move_h();
				}
				if (input == 'd') {
					kaltsit.flag = 1;
					kaltsit.move_h();
				}
				if (input == 'w') {
					kaltsit.move_v(-1);
				}
				if (input == 's') {
					kaltsit.move_v(1);
				}
			}
		}
		else {
			kaltsit.idle();
		}
	}
	return 0;
}

void putActionL(int x, int y, int w, int h, int n, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p) {
	destroyBulletWithDistance();
	triggerMobwithBullet();
	triggerCloseAttackToPlayer();
	clearrectangle(-3000, -3000, 6000, 6000);
	putimage(0, 0, 1500, 750, p, 0, 0);
	drawBullet();
	drawObj(x, y, w, h, n - i, p1, p2, a);
	drawBox(kaltsit.getBox());
	initAll();
	kaltsit.printUI();
	bar3d(0, 300, 100, 400, 100, true);
	FlushBatchDraw();
	Sleep(t);
}

void putActionR(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p) {
	destroyBulletWithDistance();
	triggerMobwithBullet();
	triggerCloseAttackToPlayer();
	clearrectangle(-3000, -3000, 6000, 6000);
	putimage(0, 0, 1500, 750, p, 0, 0);
	drawBullet();
	drawObj(x, y, w, h, i, p1, p2, a);
	drawBox(kaltsit.getBox());
	initAll();
	kaltsit.printUI();
	FlushBatchDraw();
	Sleep(t);
}

void AttackL(int x, int y, int w, int h, int n, IMAGE* p1, IMAGE* p2, int t, int ax, int ay, int a, IMAGE* p) {
	int i;
	x = x + ax;
	y = y + ay;
	for (i = 0; i < n; i++) {
		putActionL(x, y, w, h, n, i, p1, p2, t, a, p);
		if (i == 8) {
			int temp = getUsefulBullet();
			bullets[temp].onUse = 1;
			bullets[temp].x = x + 10;
			bullets[temp].y = y + 95;
			bullets[temp].origX = x + 10;
			bullets[temp].origY = y + 95;
			bullets[temp].speed = -20;
		}
	}
	x = x - ax;
	y = y - ay;
}

void AttackR(int x, int y, int w, int h, int n, IMAGE* p1, IMAGE* p2, int t, int ax, int ay, int a, IMAGE* p) {
	int i;
	x = x + ax;
	y = y + ay;
	for (i = 0; i < n; i++) {
		putActionR(x, y, w, h, i, p1, p2, t, a, p);
		if (i == 8) {
			int temp = getUsefulBullet();
			bullets[temp].onUse = 1;
			bullets[temp].x = x + 130;
			bullets[temp].y = y + 95;
			bullets[temp].origX = x + 130;
			bullets[temp].origY = y + 95;
			bullets[temp].speed = 20;
		}
	}
	x = x - ax;
	y = y - ay;
}

void triggerMobwithBullet() {
	//dog
	int i, j;
	for (i = 0; i < 10; i++) {
		if (!dogs[i].onLive) continue;
		if (dogs[i].dying) continue;
		for (j = 0; j < 100; j++) {
			if (!bullets[j].onUse) continue;
			if (triggerBox(dogs[i].getBox(), bullets[j].getBox())) {
				dogs[i].dying = true;
				bullets[j].destroy();
				break;
			}
		}
	}
}

void spawnRandom() {
	int i = getUsefulDog();
	if (i == -1) return;
	int x = rand() % 1500;
	int y = rand() % 750;
	int flag = rand() % 2;
	dogs[i].onLive = true;
	dogs[i].x = x;
	dogs[i].y = y;
	dogs[i].flag = flag;
	PlaySound(L".\\music\\gulp.wav", NULL, SND_FILENAME | SND_ASYNC);//SND_LOOP
}

void triggerCloseAttackToPlayer() {
	int i;
	//dog
	for (i = 0; i < 10; i++) {
		if (!dogs[i].onLive) continue;
		if (dogs[i].attacking)
			if (triggerBox(dogs[i].getAttackBox(), kaltsit.getBox())) {
				PlaySound(L".\\music\\gulp.wav", NULL, SND_FILENAME | SND_ASYNC);//SND_LOOP
				kaltsit.health -= 1;
				kaltsit.printUI();
			}
	}
}

void initAll() {
	int i;
	//dog
	for (i = 0; i < 10; i++) {
		if (dogs[i].onLive) {
			dogs[i].init(kaltsit);
		}
	}
}