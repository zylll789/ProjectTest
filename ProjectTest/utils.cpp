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


bool triggerBox(Box box1, Box box2) {
	if (abs(box1.x + box1.width / 2 - box2.x - box2.width / 2) < (box1.width + box2.width) / 2 && abs(box1.y + box1.height / 2 - box2.y - box2.height / 2) < (box1.height + box2.height) / 2) return true;
	return false;
}

void drawBox(Box box) {
	rectangle(box.x, box.y, box.width + box.x, box.y + box.height);
}