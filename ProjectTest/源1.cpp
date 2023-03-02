#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <cstdlib>
#include <ctime>
#include <cmath>

//get git https://dev.azure.com/3039176805/ProjectTest/_git/ProjectTest

IMAGE img_kaltsit_attack_r;//161*211
IMAGE img_kaltsit_attack_r_bg;
IMAGE img_kaltsit_move_r;//157*220
IMAGE img_kaltsit_move_r_bg;
IMAGE img_kaltsit_attack_l;
IMAGE img_kaltsit_attack_l_bg;
IMAGE img_kaltsit_move_l;
IMAGE img_kaltsit_move_l_bg;
IMAGE img_kaltsit_idle_r1;//145*212
IMAGE img_kaltsit_idle_r1_bg;
IMAGE img_kaltsit_idle_r2;
IMAGE img_kaltsit_idle_r2_bg;
IMAGE img_kaltsit_idle_l1;
IMAGE img_kaltsit_idle_l1_bg;
IMAGE img_kaltsit_idle_l2;
IMAGE img_kaltsit_idle_l2_bg;
IMAGE img_kaltsit_bullet;
IMAGE img_kaltsit_bullet_bg;
IMAGE img_dog_attack_r;//150 ^ 2
IMAGE img_dog_attack_r_bg;
IMAGE img_dog_attack_l;//150 ^ 2
IMAGE img_dog_attack_l_bg;
IMAGE img_bg;

void putActionL(int x, int y, int w, int h, int n, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p);
void putActionR(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p);

void AttackL(int x, int y, int w, int h, int n, IMAGE* p1, IMAGE* p2, int t, int ax, int ay, int a, IMAGE* p);
void AttackR(int x, int y, int w, int h, int n, IMAGE* p1, IMAGE* p2, int t, int ax, int ay, int a, IMAGE* p);

void createAllBullet();
void destroyBulletWithDistance();

void createAllDog();

void drawBullet();
void drawObj(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int a);
void drawDog();

int getUsefulBullet();
int getUsefulDog();

void triggerMobwithBullet();
void triggerCloseAttackToPlayer();
void initAll();
void spawnRandom();

class Camera {
public:
	void move(int x, int y) {
		setorigin(x, y);
	}

	void create() {
		setorigin(0, 0);
	}
};
//Åö×²Ïä
class Box {
public:
	int x;
	int y;
	int width;
	int height;
};

bool triggerBox(Box box1, Box box2);
//×Óµ¯
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
		putimage(x, y, 16, 8, &img_kaltsit_bullet_bg, 0, 0, SRCAND);
		putimage(x, y, 16, 8, &img_kaltsit_bullet, 0, 0, SRCPAINT);
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

class Player {
public:
	int idlewidth = 145;
	int idleheight = 212;
	int movewidth = 157;
	int moveheight = 220;
	int attwidth = 161;
	int attheight = 211;
	int speed;
	int x;
	int y;
	int left_i;
	int right_i;
	int left_j;
	int right_j;
	int health;
	int flag;
	int animType;
	Camera camera;

	Box getBox() {
		Box box;
		box.x = x + 5;
		box.y = y;
		if (animType == 0) {
			box.width = idlewidth;
			box.height = idleheight;
		}
		else if (animType == 1) {
			box.width = movewidth;
			box.height = moveheight;
		}
		else {
			box.width = attwidth;
			box.height = attheight;
		}
		return box;
	}

	void idle() {
		animType = 0;
		if (flag == 0) {
			while (_kbhit() == NULL) {
				left_j++;
				if (left_j < 90) {
					putActionL(x, y, idlewidth, idleheight, 90, left_j, &img_kaltsit_idle_l1, &img_kaltsit_idle_l1_bg, 35, 0, &img_bg);
				}
				else if (left_j >= 90) {
					putActionL(x, y, idlewidth, idleheight, 90, left_j - 90, &img_kaltsit_idle_l2, &img_kaltsit_idle_l2_bg, 35, 0, &img_bg);
				}
				if (left_j == 179) {
					left_j = 0;
				}
				camera.move(700 - x, 350 - y);
			}
			left_j = 0;
		}
		else if (flag == 1) {
			while (_kbhit() == NULL) {
				right_j++;
				if (right_j < 90) {
					putActionR(x, y, idlewidth, idleheight, right_j, &img_kaltsit_idle_r1, &img_kaltsit_idle_r1_bg, 35, 0, &img_bg);
				}
				else if (right_j >= 90) {
					putActionR(x, y, idlewidth, idleheight, right_j - 90, &img_kaltsit_idle_r2, &img_kaltsit_idle_r2_bg, 35, 0, &img_bg);
				}
				if (right_j == 179) {
					right_j = 0;
				}
				camera.move(700 - x, 350 - y);
			}
			right_j = 0;
		}
	}

	void create() {
		x = 700;
		y = 350;
		left_i = 0;
		right_i = 0;
		left_j = 0;
		right_j = 0;
		flag = 0;
		animType = 0;
	}

	void move_h() {
		animType = 1;
		if (flag == 0) {
			left_i++;
			x -= 20;
			putActionL(x, y - 5, movewidth, moveheight, 80, left_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 35, 0, &img_bg);
			if (left_i == 79) {
				left_i = 0;
			}
		} else {
			right_i++;
			x += 20;
			putActionR(x, y - 5, movewidth, moveheight, right_i, &img_kaltsit_move_r, &img_kaltsit_move_r_bg, 35, 0, &img_bg);
			if (right_i == 79) {
				right_i = 0;
			}
		}
		camera.move(700 - x, 350 - y);
	}

	void move_v(int dir) {
		animType = 1;
		if (flag == 0) {
			left_i++;
			y += 20 * dir;
			putActionL(x, y - 5, 157, 220, 80, left_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 35, 0, &img_bg);
			if (left_i == 79) {
				left_i = 0;
			}
		}
		else if (flag == 1) {
			right_i++;
			y += 20 * dir;
			putActionR(x, y - 5, 157, 220, right_i, &img_kaltsit_move_r, &img_kaltsit_move_r_bg, 35, 0, &img_bg);
			if (right_i == 79) {
				right_i = 0;
			}
		}
		camera.move(700 - x, 350 - y);
	}

	void shoot() {
		animType = 2;
		if (flag == 0) {
			AttackL(x, y, attwidth, attheight, 20, &img_kaltsit_attack_l, &img_kaltsit_attack_l_bg, 35, -17, 1, -5, &img_bg);
		}
		else if (flag == 1) {
			AttackR(x, y, attwidth, attheight, 20, &img_kaltsit_attack_r, &img_kaltsit_attack_r_bg, 35, -4, 1, 0, &img_bg);
		}
	}
};

class Dog {
public:
	int width = 116;
	int height = 76;
	int speed;
	int x;
	int y;//y + 64
	int index;
	bool onLive;
	int left_i;
	int right_i;
	int flag;
	bool hasPathTarget;
	bool hasTarget;
	bool isAttack;
	int targetx;
	int targety;
	double speedx;
	double speedy;

	Box getBox() {
		Box box;
		box.x = x;
		box.y = y + 64;
		box.width = width;
		box.height = height;
		return box;
	}

	Box getAttackBox() {
		Box box;
		box.x = x;
		box.y = y + 64;
		box.width = 40;
		box.height = 45;
		return box;
	}

	Box getSpyBox() {
		Box box;
		if (flag == 0) {
			box.x = x - 300;
		}
		else {
			box.x = x;
		}
		box.y = y;
		box.width = 450;
		box.height = 150;
		return box;
	}

	void destroy() {
		onLive = false;
		speed = 0;
		x = -10000;
		y = -10000;
		hasPathTarget = false;
		hasTarget = false;
		isAttack = false;
	}

	void init(Player player) {
		if (isAttack) {
			//attack();
		}
		else {
			shouldMoveToPlayer(player);
			if (hasTarget) {
				moveToPlayer(player);
			}else{
				shouldWander();
				if (hasPathTarget) {
					wanderAround();
				}else{
					if (!onLive) {

					}
					else {
						//idle
					}

				}
			}
		}
	}
	

	void shouldMoveToPlayer(Player player) {
		if (triggerBox(getSpyBox(), player.getBox())) { 
			hasTarget = true;
			if (player.x > x) {
				speedx = speed * cos(atan(1.0 * (player.y - y) / (player.x - x)));
				speedy = speed * sin(atan(1.0 * (player.y - y) / (player.x - x)));
			}
			else {
				speedx = -1 * speed * cos(atan(1.0 * (player.y - y) / (player.x - x)));
				speedy = -1 * speed * sin(atan(1.0 * (player.y - y) / (player.x - x)));
			}
		}
		else hasTarget = false;
	}

	void shouldWander() {
		if (rand() % 100 < 1 && !hasPathTarget) {
			targetx = rand() % 200-100+x;
			targety = rand() % 200-100+y;
			if (targetx > x) {
				speedx = speed * cos(atan(1.0 * (targety - y) / (targetx - x)));
				speedy = speed * sin(atan(1.0 * (targety - y) / (targetx - x)));
			}
			else {
				speedx = -1 * speed * cos(atan(1.0 * (targety - y) / (targetx - x)));
				speedy = -1 * speed * sin(atan(1.0 * (targety - y) / (targetx - x)));
			}
			hasPathTarget = true;
		}
	}

	void attack() {
		isAttack = false;
	}

	void moveToPlayer(Player player) {
		if (flag == 0 && player.x - x > 0) turnAround();
		if (flag == 1 && player.x - x < 0) turnAround();
		x += speedx;
		y += speedy;
		if (abs(player.x - x) <= 120 && abs(player.y - y) <= 40) {
			hasTarget = false;
			isAttack = true;
			speedx = 0;
			speedy = 0;
		}
	}

	void wanderAround() {
		if (flag == 0 && targetx - x > 0) turnAround();
		if (flag == 1 && targetx - x < 0) turnAround();
		x += speedx;
		y += speedy;
		if (abs(targetx - x) <= 4 || abs(targety - y) <= 4) {
			hasPathTarget = false;
			speedx = 0;
			speedy = 0;
		}
	}

	void turnAround() {
		flag = abs(flag - 1);
	}
};

Camera camera;
Bullet bullets[100];
Dog dogs[10];
Player kaltsit;
bool shouldMove = false;

int main() {
	srand(time(0));
	std::cout << "1";
	kaltsit.create();

	createAllBullet();
	createAllDog();

	initgraph(1500, 750);
	camera.create();
	kaltsit.camera = camera;

	char input;
	int x = 700, y = 350;
	int flag = 0;
	int left_i = 0, right_i = 0, left_j = 0, right_j = 0, left_k = 0, right_k = 0;

	loadimage(&img_kaltsit_attack_r, L".\\kal'tsit\\attack\\kal'tsit_attack_all_r.png");
	loadimage(&img_kaltsit_attack_r_bg, L".\\kal'tsit\\attack\\kal'tsit_attack_all_r_bg.png");
	loadimage(&img_kaltsit_move_r, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_r.png");
	loadimage(&img_kaltsit_move_r_bg, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_r_bg.png");
	loadimage(&img_kaltsit_attack_l, L".\\kal'tsit\\attack\\kal'tsit_attack_all_l.png");
	loadimage(&img_kaltsit_attack_l_bg, L".\\kal'tsit\\attack\\kal'tsit_attack_all_l_bg.png");
	loadimage(&img_kaltsit_move_l, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_l.png");
	loadimage(&img_kaltsit_move_l_bg, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_l_bg.png");
	loadimage(&img_kaltsit_idle_r1, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_r.png");
	loadimage(&img_kaltsit_idle_r1_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_r_bg.png");
	loadimage(&img_kaltsit_idle_r2, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_r.png");
	loadimage(&img_kaltsit_idle_r2_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_r_bg.png");
	loadimage(&img_kaltsit_idle_l1, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_l.png");
	loadimage(&img_kaltsit_idle_l1_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_l_bg.png");
	loadimage(&img_kaltsit_idle_l2, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_l.png");
	loadimage(&img_kaltsit_idle_l2_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_l_bg.png");
	loadimage(&img_kaltsit_bullet, L".\\kal'tsit\\F_Bullet.png");
	loadimage(&img_kaltsit_bullet_bg, L".\\kal'tsit\\F_Bullet_bg.png");

	loadimage(&img_dog_attack_r, L".\\enemy\\dog\\attack\\attack.png");
	loadimage(&img_dog_attack_r_bg, L".\\enemy\\dog\\attack\\attack_bg.png");
	loadimage(&img_dog_attack_l, L".\\enemy\\dog\\attack\\attack_l.png");
	loadimage(&img_dog_attack_l_bg, L".\\enemy\\dog\\attack\\attack_l_bg.png");

	loadimage(&img_bg, L".\\bgtest.jpg");

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
	initAll();
	triggerCloseAttackToPlayer();
	clearrectangle(-3000, -3000, 6000, 6000);
	putimage(0, 0, 1500, 750, p, 0, 0);
	drawBullet();
	drawObj(x, y, w, h, n - i, p1, p2, a);
	drawDog();
	FlushBatchDraw();
	Sleep(t);
}

void putActionR(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p) {
	destroyBulletWithDistance();
	triggerMobwithBullet();
	initAll();
	triggerCloseAttackToPlayer();
	clearrectangle(-3000, -3000, 6000, 6000);
	putimage(0, 0, 1500, 750, p, 0, 0);
 	drawBullet();
	drawObj(x, y, w, h, i, p1, p2, a);
	drawDog();
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

void drawBullet() {
	for (int i = 0; i < 100; i++) {
		if(bullets[i].onUse) {
			bullets[i].move();
			bullets[i].draw();
		}
	}
}

void drawObj(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int a) {
	putimage(x, y, w, h, p2, i * w + a, 0, SRCAND);
	putimage(x, y, w, h, p1, i * w + a, 0, SRCPAINT);
}

void drawDog() {
	for (int i = 0; i < 10; i++) {
		if(dogs[i].onLive) {
			if (dogs[i].flag) {
				dogs[i].right_i++;
				drawObj(dogs[i].x, dogs[i].y, 150, 150, dogs[i].right_i, &img_dog_attack_r, &img_dog_attack_r_bg, 0);
				if (dogs[i].right_i == 51) {
					dogs[i].right_i = 0;
				}
			}
			else {
				dogs[i].left_i++;
				drawObj(dogs[i].x, dogs[i].y, 150, 150, 51 - dogs[i].left_i, &img_dog_attack_l, &img_dog_attack_l_bg, 0);
				if (dogs[i].left_i == 51) {
					dogs[i].left_i = 0;
				}
			}
		} 
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

int getUsefulDog() {
	for (int i = 0; i < 10; i++) {
		if (!dogs[i].onLive) {
			return dogs[i].index;
		}
	}
	return -1;
}

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

void createAllDog() {
	for (int i = 0; i < 10; i++) {
		Dog dog;
		dog.index = i;
		dog.onLive = false;
		dog.x = -10000;
		dog.y = -10000;
		dog.left_i = 0;
		dog.right_i = 0;
		dog.flag = 0;
		dog.hasPathTarget = false;
		dog.hasTarget = false;
		dog.isAttack = false;
		dog.speed = 4;
		dogs[i] = dog;
	}
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

bool triggerBox(Box box1, Box box2) {
	if (abs(box1.x + box1.width / 2 - box2.x - box2.width / 2) < (box1.width + box2.width) / 2 && abs(box1.y + box1.height / 2 - box2.y - box2.height / 2) < (box1.height + box2.height) / 2) return true;
	return false;
}

void triggerMobwithBullet() {
	//dog
	int i,j;
	for (i = 0; i < 10; i++) {
		if (!dogs[i].onLive) continue;
		for (j = 0; j < 100; j++) {
			if (!bullets[j].onUse) continue;
			if (triggerBox(dogs[i].getBox(), bullets[j].getBox())) {
				dogs[i].destroy();
				bullets[j].destroy();
				break;
			}
		}
	}
}

void spawnRandom() {
	int i = getUsefulDog();
	if (i == -1) return;
	int x = rand()%1500;
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
		if (triggerBox(dogs[i].getAttackBox(), kaltsit.getBox())) {
			PlaySound(L".\\music\\gulp.wav", NULL, SND_FILENAME | SND_ASYNC);//SND_LOOP
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