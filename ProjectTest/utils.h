#pragma once

#include <graphics.h>

class Box {
public:
	int x;
	int y;
	int width;
	int height;
};

class Camera {
public:
	int x1;
	int y1;
	void move(int x, int y) {
		setorigin(x, y);
		x1 = x;
		y1 = y;
	}

	void create() {
		setorigin(0, 0);
	}
};

bool triggerBox(Box box1, Box box2);

void drawBox(Box box);
