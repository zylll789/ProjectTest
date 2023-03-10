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
#include <Windows.h>
#include "background.h"

bool spawnCheck(Enemy* e);

//get git https://dev.azure.com/3039176805/ProjectTest/_git/ProjectTest

Player kaltsit;
Background recentBG;

int main() {
	srand(time(0));
	kaltsit.create();

	createAllBullet();
	createAllDog();

	initgraph(1500, 750);
	
	camera.create();
	kaltsit.camera = camera;

	loadIMG();
	loadBackground();
	recentBG = allBG[3];
	kaltsit.bg = recentBG;
	BeginBatchDraw();

	while (1) {
		
		if (GetAsyncKeyState(VK_SPACE)|| GetAsyncKeyState('A')|| GetAsyncKeyState('D')|| GetAsyncKeyState('W')|| GetAsyncKeyState('S')) {
			if (GetAsyncKeyState(VK_SPACE)) {
				kaltsit.shoot();
				spawnRandom();
			}
			else {
				if (GetAsyncKeyState('A')) {
					//kaltsit.x -= 20;
					kaltsit.setPos(kaltsit.x - 20, kaltsit.y);
					kaltsit.flag = 0;
				}
				if (GetAsyncKeyState('D')) {
					//kaltsit.x += 20;
					kaltsit.setPos(kaltsit.x + 20, kaltsit.y);
					kaltsit.flag = 1;
				}
				if (GetAsyncKeyState('W')) {
					//kaltsit.y -= 20;
					kaltsit.setPos(kaltsit.x, kaltsit.y - 20);
				}
				if (GetAsyncKeyState('S')) {
					//kaltsit.y += 20;
					kaltsit.setPos(kaltsit.x, kaltsit.y + 20);
				}
				kaltsit.move();
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
	putimage(0, 0, recentBG.width, recentBG.height, recentBG.img, 0, 0);
	drawBoxs(kaltsit.bg.box, kaltsit.bg.count);
	drawBullet();
	drawObj(x, y, w, h, n - i, p1, p2, a);
	drawBox(kaltsit.getBox());
	initAll();
	kaltsit.printUI();
	FlushBatchDraw();
	Sleep(t);
}

void putActionR(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p) {
	destroyBulletWithDistance();
	triggerMobwithBullet();
	triggerCloseAttackToPlayer();
	clearrectangle(-3000, -3000, 6000, 6000);
	putimage(0, 0, recentBG.width, recentBG.height, recentBG.img, 0, 0);
	drawBoxs(kaltsit.bg.box, kaltsit.bg.count);
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
				dogs[i].health--;
				dogs[i].isHitByPlayer = true;
				if (dogs[i].health <= 0)dogs[i].dying = true;
				bullets[j].destroy();
				break;
			}
		}
	}
}

void spawnRandom() {
	int i = getUsefulDog();
	if (i == -1) return;
	int x, y;
	do {
		x = rand() % recentBG.width;
		y = rand() % recentBG.height;
		dogs[i].x = x;
		dogs[i].y = y;
	} while (!spawnCheck(&dogs[i]));
	int flag = rand() % 2;
	dogs[i].onLive = true;
	dogs[i].flag = flag;
	dogs[i].health = 2;
	dogs[i].bg = recentBG;
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

bool spawnCheck(Enemy* e) {
	int i = 0;
	if(kaltsit.bg.box[0].y==0)PlaySound(L".\\music\\gulp.wav", NULL, SND_FILENAME | SND_ASYNC);//SND_LOOP
	while (i < kaltsit.bg.count) {
		if (enterBox(e->getBox(), kaltsit.bg.box[i])) {
			return true;
		}
		i++;
	}
	return false;
}