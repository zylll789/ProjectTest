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
Box headquarterBox[2];
Box motorwayBox[4];
Box perimeterBox[3];
Box rooftopBox[2];
Box seaBox[6];
Box snowcountryBox[3];
Box snowmountBox[2];
Box snowforestBox[2];
Box sunnytownBox[3];
Box yumenstreetBox[4];

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
		headquarterBox[0] = createBox(0, 1200, 3072, 528);
		headquarterBox[1] = createBox(1300, 1050, 1772, 150);
		headquarter.box = headquarterBox;
		headquarter.width = 3072;
		headquarter.height = 1728;
		headquarter.img = &img_bg_headquarter;
		headquarter.count = 2;
		allBG[4] = headquarter;
	}
	{
		motorwayBox[0] = createBox(0, 1400, 3072, 328);
		motorwayBox[1] = createBox(300, 1250, 2772, 150);
		motorwayBox[2] = createBox(750, 1100, 2322, 150);
		motorwayBox[3] = createBox(850, 1000, 1422, 100);
		motorway.box = motorwayBox;
		motorway.width = 3072;
		motorway.height = 1728;
		motorway.img = &img_bg_motorway;
		motorway.count = 4;
		allBG[5] = motorway;
	}
	{
		perimeterBox[0] = createBox(0, 1450, 2572, 278);
		perimeterBox[1] = createBox(300, 1325, 2772, 25);
		perimeterBox[2] = createBox(300, 1350, 2272, 100);
		perimeter.box = perimeterBox;
		perimeter.width = 3072;
		perimeter.height = 1728;
		perimeter.img = &img_bg_perimeter;
		perimeter.count = 3;
		allBG[6] = perimeter;
	}
	{
		rooftopBox[0] = createBox(0, 1400, 3072, 328);
		rooftopBox[1] = createBox(0, 1200, 1600, 200);
		rooftop.box = rooftopBox;
		rooftop.width = 3072;
		rooftop.height = 1728;
		rooftop.img = &img_bg_rooftop;
		rooftop.count = 2;
		allBG[7] = rooftop;
	}
	{
		seaBox[0] = createBox(0, 1678, 3072, 122);
		seaBox[1] = createBox(600, 1600, 2472, 78);
		seaBox[2] = createBox(2800, 1000, 400, 800);
		seaBox[3] = createBox(2600, 1150, 472, 450);
		seaBox[4] = createBox(1800, 1300, 1272, 428);
		seaBox[5] = createBox(1100, 1450, 1972, 150);
		sea.box = seaBox;
		sea.width = 3200;
		sea.height = 1800;
		sea.img = &img_bg_sea;
		sea.count = 6;
		allBG[8] = sea;
	}
	{
		snowcountryBox[0] = createBox(700, 1400, 1872, 328);
		snowcountryBox[1] = createBox(600, 1000, 1572, 400);
		snowcountryBox[2] = createBox(1200, 900, 1250, 100);
		snowcountry.box = snowcountryBox;
		snowcountry.width = 3072;
		snowcountry.height = 1728;
		snowcountry.img = &img_bg_snowcountry;
		snowcountry.count = 3;
		allBG[9] = snowcountry;
	}
	{
		snowmountBox[0] = createBox(0, 1250, 3072, 478);
		snowmountBox[1] = createBox(0, 1125, 2500, 125);
		snowmount.box = snowmountBox;
		snowmount.width = 3072;
		snowmount.height = 1728;
		snowmount.img = &img_bg_snowmount;
		snowmount.count = 2;
		allBG[10] = snowmount;
	}
	{
		snowforestBox[0] = createBox(0, 1350, 3072, 378);
		snowforestBox[1] = createBox(0, 1050, 2800, 300);
		snowforest.box = snowforestBox;
		snowforest.width = 3072;
		snowforest.height = 1728;
		snowforest.img = &img_bg_snowforest;
		snowforest.count = 2;
		allBG[11] = snowforest;
	} 
	{
		sunnytownBox[0] = createBox(0, 1400, 3072, 328);
		sunnytownBox[1] = createBox(650, 1300, 2422, 100);
		sunnytownBox[2] = createBox(800, 1250, 1500, 50);
		sunnytown.box = sunnytownBox;
		sunnytown.width = 3072;
		sunnytown.height = 1728;
		sunnytown.img = &img_bg_sunnytown;
		sunnytown.count = 3;
		allBG[12] = sunnytown;
	}
	{
		yumenstreetBox[0] = createBox(0, 1400, 3072, 328);
		yumenstreetBox[1] = createBox(550, 1250, 2300, 150);
		yumenstreetBox[2] = createBox(1000, 1175, 1500, 75);
		yumenstreetBox[3] = createBox(1550, 1100, 950, 75);
		yumenstreet.box = yumenstreetBox;
		yumenstreet.width = 3072;
		yumenstreet.height = 1728;
		yumenstreet.img = &img_bg_yumenstreet;
		yumenstreet.count = 4;
		allBG[13] = yumenstreet;
	}
}