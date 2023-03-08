#pragma once

#include "player.h"
#include "utils.h"
#include "main.h"
#include "image.h"
#include <math.h>


class Dog {
public:
	int width = 116;
	int height = 76;
	int speed;
	int x;
	int y;//y + 64
	int index;
	bool onLive;
	bool attacking;
	int left_i;
	int right_i;
	int flag;
	bool hasPathTarget;
	bool hasTarget;
	bool isAttack;
	bool dying;
	int targetx;
	int targety;
	int attackN;
	int dieTick;
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
		if (flag) {
			box.x = x + width - 40;
		}
		else {
			box.x = x;
		}
		box.y = y + 64;
		box.width = 40;
		box.height = 45;
		return box;
	}

	Box getSpyBox() {
		Box box;
		if (flag == 0) {
			box.x = x - 450;
		}
		else {
			box.x = x;
		}
		box.y = y;
		box.width = 600;
		box.height = 150;
		return box;
	}

	void destroy() {
		onLive = false;
		speed = 0;
		x = -10000;
		y = -10000;
		attackN = 0;
		dieTick = 0;
		hasPathTarget = false;
		hasTarget = false;
		isAttack = false;
		attacking = false;
		dying = false;
	}

	void draw() {
		if (!onLive) return;
		if (dying) {
			return;
		}
		if (isAttack) {
			drawAnim(51, &img_dog_attack_r, &img_dog_attack_r_bg, &img_dog_attack_l, &img_dog_attack_l_bg);
			drawBox(getAttackBox());
		}
		else if (hasTarget) {
			drawAnim(42, &img_dog_run_r, &img_dog_run_r_bg, &img_dog_run_l, &img_dog_run_l_bg);
			drawBox(getBox());
		}
		else if (hasPathTarget) {
			drawAnim(70, &img_dog_move_r, &img_dog_move_r_bg, &img_dog_move_l, &img_dog_move_l_bg);
			drawBox(getBox());
		}
		else {
			drawAnim(90, &img_dog_idle_r, &img_dog_idle_r_bg, &img_dog_idle_l, &img_dog_idle_l_bg);
			drawBox(getBox());
		}
	}

	void drawAnim(int n, IMAGE* p1, IMAGE* p2, IMAGE* p3, IMAGE* p4) {
		if (flag) {
			right_i++;
			drawObj(x, y, 150, 150, right_i, p1, p2, 0);
			if (right_i >= n) {
				right_i = 0;
			}
		}
		else {
			left_i++;
			drawObj(x, y, 150, 150, n - left_i, p3, p4, 0);
			if (left_i >= n) {
				left_i = 0;
			}
		}
	}

	void init(Player player) {
		if (dying) {
			die();
		}
		else if (onLive) {
			if (isAttack) {
				attack(player);
			}
			else {
				shouldMoveToPlayer(player);
				if (hasTarget) {
					moveToPlayer(player);
				}
				else {
					shouldWander();
					if (hasPathTarget) {
						wanderAround();
					}
				}
			}
		}
		draw();
		drawBox(getSpyBox());
	}

	void die() {
		if (flag) {
			dieTick++;
			drawObj(x, y, 150, 150, dieTick, &img_dog_die_r, &img_dog_die_r_bg, 0);
		}
		else {
			dieTick++;
			drawObj(x, y, 150, 150, 58 - dieTick, &img_dog_die_l, &img_dog_die_l_bg, 0);
		}
		if (dieTick == 58) {
			dying = false;
			onLive = false;
			destroy();
		}
	}

	void shouldMoveToPlayer(Player player) {
		if (triggerBox(getSpyBox(), player.getBox())) {
			hasTarget = true;
			hasPathTarget = false;
			speed = 6;
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
			speed = 4;
			targetx = rand() % 200 - 100 + x;
			targety = rand() % 200 - 100 + y;
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

	void attack(Player player) {
		speed = 0;
		if (attackN == 33) {
			attacking = true;
		}
		else {
			attacking = false;
		}
		attackN++;
		if (attackN == 52) {
			if (abs(player.x - x) <= 110 && abs(player.y - y) <= 40) {
				isAttack = true;
				attackN = 0;
			}
			else {
				isAttack = false;
			}
		}
	}

	void moveToPlayer(Player player) {
		if (flag == 0 && player.x - x > 0) turnAround();
		if (flag == 1 && player.x - x < 0) turnAround();
		if (abs(player.x - x) <= 110 && abs(player.y - y) <= 40) {
			hasTarget = false;
			isAttack = true;
			attackN = 0;
			speedx = 0;
			speedy = 0;
			speed = 0;
			return;
		}
		x += speedx;
		y += speedy;
	}

	void wanderAround() {
		if (flag == 0 && targetx - x > 0) turnAround();
		if (flag == 1 && targetx - x < 0) turnAround();
		if (abs(targetx - x) <= 4 || abs(targety - y) <= 4) {
			hasPathTarget = false;
			speedx = 0;
			speedy = 0;
			speed = 0;
		}
		x += speedx;
		y += speedy;
	}

	void turnAround() {
		flag = abs(flag - 1);
	}
};

extern Dog dogs[10];

void createAllDog();

int getUsefulDog();