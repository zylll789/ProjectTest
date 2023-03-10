#pragma once

#include "player.h"
#include "main.h"
#include <math.h>


class Enemy {
public:
	int width;
	int height;
	int speed;
	int x;
	int y;
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

	bool isHitByPlayer;
	int health;
	Background bg;

	bool setPos(int x1, int y1, int width1, int height1, int dx, int dy) {
		int i = 0;
		while (bg.count > i) {
			if (x1 + dx >= bg.box[i].x && x1 + dx + width1 <= bg.box[i].x + bg.box[i].width && y1 + dy + height1 >= bg.box[i].y && y1 + dy + height1 <= bg.box[i].y + bg.box[i].height) {
				x = x1;
				y = y1;
				return true;
			}
			i++;
		}
		return false;
	}

	virtual Box getBox(){
		Box box;
		box.x = 0;
		return box;
	}

	virtual Box getAttackBox(){
		Box box;
		box.x = 0;
		return box;
	}

	virtual Box getSpyBox(){
		Box box;
		box.x = 0;
		return box;
	}

	void destroy() {
		onLive = false;
		health = 0;
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
		isHitByPlayer = false;
	}

	virtual void draw(){}

	virtual void drawAnim(int n, IMAGE* p1, IMAGE* p2, IMAGE* p3, IMAGE* p4){}

	virtual void init(Player player){}

	virtual void die(){}

	void shouldMoveToPlayer(Player player) {
		if (triggerBox(getSpyBox(), player.getBox()) || isHitByPlayer) {
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

	virtual void attack(Player player){}

	virtual void moveToPlayer(Player player){}

	virtual void wanderAround(){}

	void turnAround() {
		flag = abs(flag - 1);
	}
};