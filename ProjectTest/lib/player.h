#pragma once

#include "utils.h"
#include "image.h"
#include <conio.h>
#include "main.h"
#include <Windows.h>
#include "background.h"

class Player {
public:
	int health;
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
	int flag;
	int animType;
	Camera camera;
	Background bg;

	void setPos(int x1, int y1) {
		int i = 0;
		while (bg.count > i) {
			if (x1>=bg.box[i].x&&x1+175<=bg.box[i].x+bg.box[i].width&& y1 + 220 >= bg.box[i].y && y1 + 220 <= bg.box[i].y + bg.box[i].height) {
				x = x1;
				y = y1;
				return;
			}
			i++;
		}
	}

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
			while (!(GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState('A') || GetAsyncKeyState('D') || GetAsyncKeyState('W') || GetAsyncKeyState('S'))) {
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
				testCameraMove();
			}
			left_j = 0;
		}
		else if (flag == 1) {
			while (!(GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState('A') || GetAsyncKeyState('D') || GetAsyncKeyState('W') || GetAsyncKeyState('S'))) {
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
				testCameraMove();
			}
			right_j = 0;
		}
	}

	void create() {
		health = 10;
		x = 700;
		y = 1350;
		left_i = 0;
		right_i = 0;
		left_j = 0;
		right_j = 0;
		flag = 0;
		animType = 0;
	}

	void printUI() {
		drawObj(-1 * camera.x1, -1 * camera.y1, 120, 120, 0, &img_ui_head, &img_ui_head_bg, 0);
		drawObj(-1 * camera.x1 + 120, -1 * camera.y1 + 50, 180, 20, 0, &img_ui_health, &img_ui_health_bg, 20 * (10 - health));
	}

	void move() {
		animType = 1;
		if (flag == 0) {
			left_i++;
			putActionL(x, y - 5, movewidth, moveheight, 80, left_i, &img_kaltsit_move_l, &img_kaltsit_move_l_bg, 35, 0, &img_bg);
			if (left_i == 79) {
				left_i = 0;
			}
		}
		else {
			right_i++;
			putActionR(x, y - 5, movewidth, moveheight, right_i, &img_kaltsit_move_r, &img_kaltsit_move_r_bg, 35, 0, &img_bg);
			if (right_i == 79) {
				right_i = 0;
			}
		}
		testCameraMove();
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

	void testCameraMove() {
		int tempx = 700 - x, tempy = 350 - y;
		if (x - 700 <= 0) {
			tempx = 0;
		}
		if (y - 350 <= 0) {
			tempy = 0;
		}
		if (x + 800 >= bg.width) {
			tempx = 1500 - bg.width;
		}
		if (y + 400 >= bg.height) {
			tempy = 750 - bg.height;
		}
		camera.move(tempx, tempy);
	}
};

extern Player kaltsit;