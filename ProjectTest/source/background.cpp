#include "background.h"
#include "image.h"

Background rooftop;
Box rooftopBox[2];

void loadBackground() {
	rooftopBox[0] = createBox(0, 1400, 3072, 328);
	rooftopBox[1] = createBox(0, 1200, 1600, 200);
	rooftop.box = rooftopBox;
	rooftop.width = 3072;
	rooftop.height = 1728;
	rooftop.img = &img_bg_rooftop;
	rooftop.count = 2;
}