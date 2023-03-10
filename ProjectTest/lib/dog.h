#pragma once

#include "enemy.h"

class Dog : public Enemy{
public:
	int width = 116;
	int height = 76;

	virtual Box getBox() {
		Box box;
		box.x = x;
		box.y = y + 64;
		box.width = width;
		box.height = height;
		return box;
	}

	virtual Box getAttackBox() {
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

	virtual Box getSpyBox() {
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

	virtual void draw() {
		if (!onLive) return;
		if (dying) {
			return;
		}
		drawObj(x+30,y+50,80,6,0, &img_healthbar, &img_healthbar_bg, 40 * (2 - health));
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

	virtual void drawAnim(int n, IMAGE* p1, IMAGE* p2, IMAGE* p3, IMAGE* p4) {
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

	virtual void init(Player player) {
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

	virtual void die() {
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

	virtual void attack(Player player) {
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
};

extern Dog dogs[10];

void createAllDog();

int getUsefulDog();