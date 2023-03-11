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

extern Background cher1;
extern Background cher2;
extern Background corridor;
extern Background desertoasis;
extern Background headquarter;
extern Background motorway;
extern Background perimeter;
extern Background rooftop;
extern Background sea;
extern Background snowcountry;
extern Background snowmount;
extern Background snowforest;
extern Background sunnytown;
extern Background yumenstreet;

extern Background allBG[14];

void loadBackground();
