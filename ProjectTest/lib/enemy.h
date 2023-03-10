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