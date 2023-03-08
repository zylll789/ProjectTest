#include <graphics.h>

IMAGE img_kaltsit_attack_r;//161*211
IMAGE img_kaltsit_attack_r_bg;
IMAGE img_kaltsit_move_r;//157*220
IMAGE img_kaltsit_move_r_bg;
IMAGE img_kaltsit_attack_l;
IMAGE img_kaltsit_attack_l_bg;
IMAGE img_kaltsit_move_l;
IMAGE img_kaltsit_move_l_bg;
IMAGE img_kaltsit_idle_r1;//145*212
IMAGE img_kaltsit_idle_r1_bg;
IMAGE img_kaltsit_idle_r2;
IMAGE img_kaltsit_idle_r2_bg;
IMAGE img_kaltsit_idle_l1;
IMAGE img_kaltsit_idle_l1_bg;
IMAGE img_kaltsit_idle_l2;
IMAGE img_kaltsit_idle_l2_bg;
IMAGE img_kaltsit_bullet;
IMAGE img_kaltsit_bullet_bg;
IMAGE img_dog_attack_r;//150 ^ 2
IMAGE img_dog_attack_r_bg;
IMAGE img_dog_attack_l;//150 ^ 2
IMAGE img_dog_attack_l_bg;
IMAGE img_dog_move_r;//150 ^ 2
IMAGE img_dog_move_r_bg;
IMAGE img_dog_move_l;//150 ^ 2
IMAGE img_dog_move_l_bg;
IMAGE img_dog_idle_r;//150 ^ 2
IMAGE img_dog_idle_r_bg;
IMAGE img_dog_idle_l;//150 ^ 2
IMAGE img_dog_idle_l_bg;
IMAGE img_dog_run_r;//150 ^ 2
IMAGE img_dog_run_r_bg;
IMAGE img_dog_run_l;//150 ^ 2
IMAGE img_dog_run_l_bg;
IMAGE img_dog_die_r;//150 ^ 2
IMAGE img_dog_die_r_bg;
IMAGE img_dog_die_l;//150 ^ 2
IMAGE img_dog_die_l_bg;
IMAGE img_bg;
IMAGE img_ui_head;//120 ^ 2
IMAGE img_ui_head_bg;
IMAGE img_ui_health;//20 * 200
IMAGE img_ui_health_bg;

void loadIMG() {
	loadimage(&img_kaltsit_attack_r, L".\\kal'tsit\\attack\\kal'tsit_attack_all_r.png");
	loadimage(&img_kaltsit_attack_r_bg, L".\\kal'tsit\\attack\\kal'tsit_attack_all_r_bg.png");
	loadimage(&img_kaltsit_move_r, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_r.png");
	loadimage(&img_kaltsit_move_r_bg, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_r_bg.png");
	loadimage(&img_kaltsit_attack_l, L".\\kal'tsit\\attack\\kal'tsit_attack_all_l.png");
	loadimage(&img_kaltsit_attack_l_bg, L".\\kal'tsit\\attack\\kal'tsit_attack_all_l_bg.png");
	loadimage(&img_kaltsit_move_l, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_l.png");
	loadimage(&img_kaltsit_move_l_bg, L".\\kal'tsit\\move_bg\\kal'tsit_move_all_l_bg.png");
	loadimage(&img_kaltsit_idle_r1, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_r.png");
	loadimage(&img_kaltsit_idle_r1_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_r_bg.png");
	loadimage(&img_kaltsit_idle_r2, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_r.png");
	loadimage(&img_kaltsit_idle_r2_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_r_bg.png");
	loadimage(&img_kaltsit_idle_l1, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_l.png");
	loadimage(&img_kaltsit_idle_l1_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_1_l_bg.png");
	loadimage(&img_kaltsit_idle_l2, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_l.png");
	loadimage(&img_kaltsit_idle_l2_bg, L".\\kal'tsit\\idle_bg\\kal'tsit_idle_2_l_bg.png");
	loadimage(&img_kaltsit_bullet, L".\\kal'tsit\\F_Bullet.png");
	loadimage(&img_kaltsit_bullet_bg, L".\\kal'tsit\\F_Bullet_bg.png");

	loadimage(&img_dog_attack_r, L".\\enemy\\dog\\attack\\attack.png");
	loadimage(&img_dog_attack_r_bg, L".\\enemy\\dog\\attack\\attack_bg.png");
	loadimage(&img_dog_attack_l, L".\\enemy\\dog\\attack\\attack_l.png");
	loadimage(&img_dog_attack_l_bg, L".\\enemy\\dog\\attack\\attack_l_bg.png");
	loadimage(&img_dog_move_r, L".\\enemy\\dog\\move\\move.png");
	loadimage(&img_dog_move_r_bg, L".\\enemy\\dog\\move\\move_bg.png");
	loadimage(&img_dog_move_l, L".\\enemy\\dog\\move\\move_l.png");
	loadimage(&img_dog_move_l_bg, L".\\enemy\\dog\\move\\move_l_bg.png");
	loadimage(&img_dog_idle_r, L".\\enemy\\dog\\idle\\idle.png");
	loadimage(&img_dog_idle_r_bg, L".\\enemy\\dog\\idle\\idle_bg.png");
	loadimage(&img_dog_idle_l, L".\\enemy\\dog\\idle\\idle_l.png");
	loadimage(&img_dog_idle_l_bg, L".\\enemy\\dog\\idle\\idle_l_bg.png");
	loadimage(&img_dog_run_r, L".\\enemy\\dog\\run\\run.png");
	loadimage(&img_dog_run_r_bg, L".\\enemy\\dog\\run\\run_bg.png");
	loadimage(&img_dog_run_l, L".\\enemy\\dog\\run\\run_l.png");
	loadimage(&img_dog_run_l_bg, L".\\enemy\\dog\\run\\run_l_bg.png");
	loadimage(&img_dog_die_r, L".\\enemy\\dog\\die\\die.png");
	loadimage(&img_dog_die_r_bg, L".\\enemy\\dog\\die\\die_bg.png");
	loadimage(&img_dog_die_l, L".\\enemy\\dog\\die\\die_l.png");
	loadimage(&img_dog_die_l_bg, L".\\enemy\\dog\\die\\die_l_bg.png");

	loadimage(&img_bg, L".\\bgtest.jpg");
	loadimage(&img_ui_head, L".\\kal'tsit\\ui\\head.png");
	loadimage(&img_ui_head_bg, L".\\kal'tsit\\ui\\head_bg.png");
	loadimage(&img_ui_health, L".\\kal'tsit\\ui\\health.png");
	loadimage(&img_ui_health_bg, L".\\kal'tsit\\ui\\health_bg.png");
}

void drawObj(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int a) {
	putimage(x, y, w, h, p2, i * w + a, 0, SRCAND);
	putimage(x, y, w, h, p1, i * w + a, 0, SRCPAINT);
}