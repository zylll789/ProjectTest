#pragma once

#include "utils.h"

class Background {
public:
	int width;
	int height;

	IMAGE* img;

	Box* box;
	int count;
};

extern Background rooftop;

void loadBackground();
