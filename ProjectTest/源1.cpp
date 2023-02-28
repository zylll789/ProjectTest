#include <graphics.h>
#include <conio.h>
#include <stdio.h>

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
IMAGE img_bg;

//Åö×²Ïä
class Box {
public:
	int x;
	int y;
	int width;
	int height;
};

//×Óµ¯
class Bullet {
public:
	int width = 16;
	int height = 8;
	int speed;
	int x;
	int y;
	int index;

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
};

void putActionL(int x, int y, int w, int h, int n, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p);
void putActionR(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p);
void AttackL(int x, int y, int w, int h, int n, IMAGE* p1, IMAGE* p2, int t, int ax, int ay, int a, IMAGE* p);
void AttackR(int x, int y, int w, int h, int n, IMAGE* p1, IMAGE* p2, int t, int ax, int ay, int a, IMAGE* p);

void drawBullet();

Bullet bullets[100];
int index = 0;
int shouldShoot = 1;

int main() {

	initgraph(1500, 750);
	setorigin(0, 0);//¾µÍ·

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

	loadimage(&img_bg, L".\\bgtest.jpg");

	BeginBatchDraw();
	putimage(x - 30, y, 16, 8, &img_kaltsit_bullet_bg, 0, 0, SRCAND);
	putimage(x - 30, y, 16, 8, &img_kaltsit_bullet, 0, 0, SRCPAINT);
	
	while (1) {
		//clearrectangle(0, 0, 1500, 750);
		putimage(0, 0, 1500, 750, &img_bg, 0, 0);
		drawBullet();
		if (_kbhit()) {
			input = _getch();
			if (input == ' ') {
				//shouldShoot = 0;
				if (flag == 0) {
					AttackL(x, y, 161, 211, 20, &img_kaltsit_attack_l, &img_kaltsit_attack_l_bg, 20, -17, 1, -5, &img_bg);
				}
				else if (flag == 1) {
					AttackR(x, y, 161, 211, 20, &img_kaltsit_attack_r, &img_kaltsit_attack_r_bg, 20, -4, 1, 0, &img_bg);
				}
			}
			else {
				if (input == 'a') {
					flag = 0;
					left_i++;
					x -= 3;
					putActionL(x, y - 5, 157, 220, 80, left_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 20, 0, &img_bg);
					if (left_i == 79) {
						left_i = 0;
					}
				}
				else if (input == 'd') {
					flag = 1;
					right_i++;
					x += 3;
					putActionR(x, y - 5, 157, 220, right_i, &img_kaltsit_move_r, &img_kaltsit_move_r_bg, 20, 0, &img_bg);
					if (right_i == 79) {
						right_i = 0;
					}
				}
				else if (input == 'w') {
					if (flag == 0) {
						left_k++;
						y -= 1;
						putActionL(x, y - 5, 157, 220, 80, left_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 20, 0, &img_bg);
						if (left_k == 79) {
							left_k = 0;
						}
					}
					else if (flag == 1) {
						right_k++;
						y -= 1;
						putActionR(x, y - 5, 157, 220, right_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 20, 0, &img_bg);
						if (right_k == 79) {
							right_k = 0;
						}
					}
				}
				else if (input == 's') {
					if (flag == 0) {
						left_k++;
						y += 1;
						putActionL(x, y - 5, 157, 220, 80, left_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 20, 0, &img_bg);
						if (left_k == 79) {
							left_k = 0;
						}
					}
					else if (flag == 1) {
						right_k++;
						y += 1;
						putActionR(x, y - 5, 157, 220, right_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 20, 0, &img_bg);
						if (right_k == 79) {
							right_k = 0;
						}
					}
				}
			}
		}
		else {
			if (flag == 0) {
				while (_kbhit() == NULL) {
					left_j++;
					if (left_j < 90) {
						putActionL(x, y, 145, 212, 90, left_j, &img_kaltsit_idle_l1, &img_kaltsit_idle_l1_bg, 20, 0, &img_bg);
					}
					else if (left_j >= 90) {
						putActionL(x, y, 145, 212, 90, left_j - 90, &img_kaltsit_idle_l2, &img_kaltsit_idle_l2_bg, 20, 0, &img_bg);
					}
					if (left_j == 179) {
						left_j = 0;
					}
				}
				left_j = 0;
			}
			else if (flag == 1) {
				while (_kbhit() == NULL) {
					right_j++;
					if (right_j < 90) {
						putActionR(x, y, 145, 212, right_j, &img_kaltsit_idle_r1, &img_kaltsit_idle_r1_bg, 20, 0, &img_bg);
					}
					else if (right_j >= 90) {
						putActionR(x, y, 145, 212, right_j - 90, &img_kaltsit_idle_r2, &img_kaltsit_idle_r2_bg, 20, 0, &img_bg);
					}
					if (right_j == 179) {
						right_j = 0;
					}
				}
			}
		}
	}
	return 0;
}

void putActionL(int x, int y, int w, int h, int n, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p) {
	//clearrectangle(x, y, x + w-1, y + h-1);
	putimage(0, 0, 1500, 750, p, 0, 0);
	drawBullet();
	putimage(x, y, w, h, p2, (n - i) * w + a, 0, SRCAND);//SRCINVERT
	putimage(x, y, w, h, p1, (n - i) * w + a, 0, SRCPAINT);//NOTSRCERASE
	FlushBatchDraw();
	Sleep(t);
}

void putActionR(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int t, int a, IMAGE* p) {
	//clearrectangle(x, y, x + w-1, y + h-1);
	putimage(0, 0, 1500, 750, p, 0, 0);
	drawBullet();
	putimage(x, y, w, h, p2, i * w + a, 0, SRCAND);
	putimage(x, y, w, h, p1, i * w + a, 0, SRCPAINT);
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
			Bullet bullet;
			bullet.x = x + 10;
			bullet.y = y + 95;
			bullet.speed = -20;
			bullets[index] = bullet;
			index++;
		}
	}
	shouldShoot = 1;
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
			Bullet bullet;
			bullet.x = x + 130;
			bullet.y = y + 95;
			bullet.speed = 20;
			bullets[index] = bullet;
			index++;
		}
	}
	x = x - ax;
	y = y - ay;
}

void drawBullet() {
	for (int i = 0; i < index; i++) {
		bullets[i].move();
		bullets[i].draw();
	}
}
