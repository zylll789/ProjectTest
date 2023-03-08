#pragma once

#include <graphics.h>

extern IMAGE img_kaltsit_attack_r;//161*211
extern IMAGE img_kaltsit_attack_r_bg;
extern IMAGE img_kaltsit_move_r;//157*220
extern IMAGE img_kaltsit_move_r_bg;
extern IMAGE img_kaltsit_attack_l;
extern IMAGE img_kaltsit_attack_l_bg;
extern IMAGE img_kaltsit_move_l;
extern IMAGE img_kaltsit_move_l_bg;
extern IMAGE img_kaltsit_idle_r1;//145*212
extern IMAGE img_kaltsit_idle_r1_bg;
extern IMAGE img_kaltsit_idle_r2;
extern IMAGE img_kaltsit_idle_r2_bg;
extern IMAGE img_kaltsit_idle_l1;
extern IMAGE img_kaltsit_idle_l1_bg;
extern IMAGE img_kaltsit_idle_l2;
extern IMAGE img_kaltsit_idle_l2_bg;
extern IMAGE img_kaltsit_bullet;
extern IMAGE img_kaltsit_bullet_bg;
extern IMAGE img_dog_attack_r;//150 ^ 2
extern IMAGE img_dog_attack_r_bg;
extern IMAGE img_dog_attack_l;//150 ^ 2
extern IMAGE img_dog_attack_l_bg;
extern IMAGE img_dog_move_r;//150 ^ 2
extern IMAGE img_dog_move_r_bg;
extern IMAGE img_dog_move_l;//150 ^ 2
extern IMAGE img_dog_move_l_bg;
extern IMAGE img_dog_idle_r;//150 ^ 2
extern IMAGE img_dog_idle_r_bg;
extern IMAGE img_dog_idle_l;//150 ^ 2
extern IMAGE img_dog_idle_l_bg;
extern IMAGE img_dog_run_r;//150 ^ 2
extern IMAGE img_dog_run_r_bg;
extern IMAGE img_dog_run_l;//150 ^ 2
extern IMAGE img_dog_run_l_bg;
extern IMAGE img_dog_die_r;//150 ^ 2
extern IMAGE img_dog_die_r_bg;
extern IMAGE img_dog_die_l;//150 ^ 2
extern IMAGE img_dog_die_l_bg;
extern IMAGE img_bg;
extern IMAGE img_ui_head;//120 ^ 2
extern IMAGE img_ui_head_bg;
extern IMAGE img_ui_health;//20 * 200
extern IMAGE img_ui_health_bg;

void loadIMG();

void drawObj(int x, int y, int w, int h, int i, IMAGE* p1, IMAGE* p2, int a);