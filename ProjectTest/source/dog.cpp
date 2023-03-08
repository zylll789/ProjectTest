#include "dog.h"


Dog dogs[10];

int getUsefulDog() {
	for (int i = 0; i < 10; i++) {
		if (!dogs[i].onLive) {
			return dogs[i].index;
		}
	}
	return -1;
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
		dog.dying = false;
		dog.dieTick = 0;
		dog.attacking = false;
		dogs[i] = dog;
	}
}