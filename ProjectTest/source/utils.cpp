#include <graphics.h>
#include "utils.h"

Camera camera;

bool triggerBox(Box box1, Box box2) {
	if (abs(box1.x + box1.width / 2 - box2.x - box2.width / 2) < (box1.width + box2.width) / 2 && abs(box1.y + box1.height / 2 - box2.y - box2.height / 2) < (box1.height + box2.height) / 2) return true;
	return false;
}

bool enterBox(Box box1, Box box2) {
	if (box1.x >= box2.x && box1.x + box1.width <= box2.x + box2.width && box1.y + box1.height >= box2.y && box1.y + box1.height <= box2.y + box2.height) return true;
	return false;
}

void drawBox(Box box) {
	rectangle(box.x, box.y, box.width + box.x, box.y + box.height);
}

void drawBoxs(Box* box, int count) {
	for (int i = 0; i < count; i++) {
		rectangle(box[i].x, box[i].y, box[i].width + box[i].x, box[i].y + box[i].height);
	}
}

Box createBox(int x, int y, int width, int height) {
	Box box;
	box.x = x;
	box.y = y;
	box.width = width;
	box.height = height;
	return box;
}

