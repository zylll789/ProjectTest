#include "background.h"
#include "image.h"

Background cher1;
Background cher2;
Background corridor;
Background desertoasis;
Background headquarter;
Background motorway;
Background perimeter;
Background rooftop;
Background sea;
Background snowcountry;
Background snowmount;
Background snowforest;
Background sunnytown;
Background yumenstreet;
Box cher1Box[2];
Box cher2Box[2];
Box corridorBox[5];
Box desertoasisBox[6];
Box headquarterBox;
Box motorwayBox;
Box perimeterBox;
Box rooftopBox[2];
Box seaBox;
Box snowcountryBox;
Box snowmountBox;
Box snowforestBox;
Box sunnytownBox;
Box yumenstreetBox;

Background allBG[14];

void loadBackground() {
	{
		cher1Box[0] = createBox(0, 1300, 3072, 428);
		cher1Box[1] = createBox(900, 1250, 2100, 50);
		cher1.box = cher1Box;
		cher1.width = 3072;
		cher1.height = 1728;
		cher1.img = &img_bg_cher1;
		cher1.count = 2;
		allBG[0] = cher1;
	}
	{
		cher2Box[0] = createBox(0, 1300, 3072, 428);
		cher2Box[1] = createBox(900, 1250, 2100, 50);
		cher2.box = cher2Box;
		cher2.width = 3072;
		cher2.height = 1728;
		cher2.img = &img_bg_cher2;
		cher2.count = 2;
		allBG[1] = cher2;
	}
	{
		corridorBox[0] = createBox(0, 1600, 2600, 128);
		corridorBox[1] = createBox(0, 1550, 2300, 50);
		corridorBox[2] = createBox(550, 1450, 1450, 100);
		corridorBox[3] = createBox(900, 1350, 1000, 100);
		corridorBox[4] = createBox(1000, 1150, 900, 200);
		corridor.box = corridorBox;
		corridor.width = 3072;
		corridor.height = 1728;
		corridor.img = &img_bg_corridor;
		corridor.count = 5;
		allBG[2] = corridor;
	}
	{
		desertoasisBox[0] = createBox(0, 1550, 3072, 178);
		desertoasisBox[1] = createBox(1800, 1350, 1272, 200);
		desertoasisBox[2] = createBox(2600, 850, 478, 500);
		desertoasisBox[3] = createBox(0, 850, 700, 700);
		desertoasisBox[4] = createBox(500, 1350, 700, 200);
		desertoasisBox[5] = createBox(0, 800, 3072, 100);
		desertoasis.box = desertoasisBox;
		desertoasis.width = 3072;
		desertoasis.height = 1728;
		desertoasis.img = &img_bg_desertoasis;
		desertoasis.count = 6;
		allBG[3] = desertoasis;
	}
	{
		rooftopBox[0] = createBox(0, 1400, 3072, 328);
		rooftopBox[1] = createBox(0, 1200, 1600, 200);
		rooftop.box = rooftopBox;
		rooftop.width = 3072;
		rooftop.height = 1728;
		rooftop.img = &img_bg_rooftop;
		rooftop.count = 2;
	}
}