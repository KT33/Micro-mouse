/*
 * mode.c
 *
 *  Created on: 2017/09/25
 *      Author: takao keisuke
 */

/*
 * mode.c
 *
 *  Created on: 2017/09/21
 *      Author: takao keisuke
 */
#include "iodefine.h"
#include "mode.h"
#include "AD.h"
#include  "other.h"
#include "variable.h"
#include "run.h"
#include "CMT.h"
#include "MTU.h"
#include "serial.h"
#include "7seg.h"
#include "slalom.h"
#include "adachi_slalome.h"
#include "pass.h"

void mode_1(void) {
	int count = 0;
	return_mode_select_flag = 0;
	batterycheck();
	moter_enable();

	restMap();
//	restReachedMap();
	adachi_map();
	for (count = 0; count < 1; count++) {
		adachi_fast(goal_x, goal_y, 1);
		wait_Time(3000);
		adachi_fast(0, 0, 1);
		wait_Time(3000);
	}
//	if ((return_mode_select_flag == 0) && (PA.DRL.BIT.B8 == 1)) {
//		shortest_knowwayfast(goal_x, goal_y, 0);
//		wait_Time(3000);
//	}
//	if ((return_mode_select_flag == 0) && (PA.DRL.BIT.B8 == 1)) {
//		adachi_fast(0, 0, 1);
//		wait_Time(3000);
//		x = 0;
//		y = 0;
//		direction = 1;
//	}
	if ((return_mode_select_flag == 0) && (PA.DRL.BIT.B8 == 1)) {
		shortest_knowwayfast(goal_x, goal_y, 1);
		wait_Time(3000);
	}
	if ((return_mode_select_flag == 0) && (PA.DRL.BIT.B8 == 1)) {
		adachi_fast(0, 0, 1);
		wait_Time(3000);
		x = 0;
		y = 0;
		direction = 1;
	}
	if ((return_mode_select_flag == 0) && (PA.DRL.BIT.B8 == 1)) {
		shortest_slalom_knowwayfast(goal_x, goal_y, 1);
		wait_Time(3000);
	}
	if ((return_mode_select_flag == 0) && (PA.DRL.BIT.B8 == 1)) {
		adachi_fast(0, 0, 1);
		wait_Time(3000);
		x = 0;
		y = 0;
		direction = 1;
	}

	O7seg();
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入
	return_mode_select_flag = 0;
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;

}
void mode_2(void) {
	int count;
	return_mode_select_flag = 0;
	moter_enable();
	batterycheck();
//	restMap();
//	restReachedMap();
	adachi_map();

	shortest_knowwayfast(goal_x, goal_y, 0);

	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入
}
void mode_3(void) {
	int count;
	//L7seg_1();
	return_mode_select_flag = 0;
	moter_enable();
	batterycheck();
	//restMap();
//	restReachedMap();

//	shortest_slalom_knowwayfast(goal_x, goal_y, 0);
	shortest_slalom_knowwayfast(goal_x, goal_y, 0);
	wait_Time(3000);
	adachi_fast(0, 0, 1);
	wait_Time(3000);

	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入

}
void mode_4(void) {
	int count = 0;

	return_mode_select_flag = 0;

	batterycheck();
	moter_enable();

	adachi_map();

	shortest_knowwayfast(goal_x, goal_y, 1);
	wait_Time(3000);
	adachi_fast(0, 0, 1);
	wait_Time(3000);

	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入

}
void mode_5(void) {
	return_mode_select_flag = 0;
	moter_enable();

	PE.DRL.BIT.B2 = 0;

	batterycheck();

	adachi_map();
	adachi_fast(goal_x, goal_y, 1);
	wait_Time(3000);
	adachi_fast(0, 0, 1);
	wait_Time(3000);
	return_mode_select_flag = 0;
	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入

}
void mode_6(void) {
	int i;
	batterycheck();
	moter_enable();

	adachi_fast(goal_x, goal_y, 1);
	wait_Time(3000);
	adachi_fast(0, 0, 1);
	wait_Time(3000);
	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入

}
void mode_7(void) {
	int count = 0;
	return_mode_select_flag = 0;
	batterycheck();
	moter_enable();

	O7seg();
	PE.DRL.BIT.B8 = 0; //Motor_Enableに1を代入
	return_mode_select_flag = 0;
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;

}

void mode_8(void) {
	int count = 0;
	float i_distance, more_maxspeed, more_accel, special_Kp = 0.05, Kp_bpx;
	return_mode_select_flag = 0;
	batterycheck();
	moter_enable();

	Kp_bpx = Kp;
	Kp = special_Kp;

	i_distance = 176.88;
	more_accel = 2000;
	more_maxspeed = 2000;
	go_ketuate();

	for (j = 0; j < 4; j++) {

		more_run(i_distance * 14, more_maxspeed, more_accel);
		slalom_right90();
		more_run(i_distance * 6, more_maxspeed, more_accel);
		slalom_right90();
	}
	stop90();
	Kp = Kp_bpx;

	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;

}
void mode_9(void) {
	int count = 0;
	float i_distance, more_maxspeed, more_accel, special_Kp = 0.02, Kp_bpx;
	return_mode_select_flag = 0;
	batterycheck();
	moter_enable();

	Kp_bpx = Kp;
	Kp = special_Kp;

	i_distance = 177.0;
	more_accel = 3000;
	more_maxspeed = 2100;
	go_ketuate();

	for (j = 0; j < 4; j++) {

		more_run(i_distance * 14, more_maxspeed, more_accel);
		slalom_right90();
		more_run(i_distance * 6, more_maxspeed, more_accel);
		slalom_right90();
	}
	stop90();
	Kp = Kp_bpx;

	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;

}
void mode_0(void) {
	int i, j;

	adachi_map(goal_x, goal_y);
	output_Walldate();
	output_lookedWalldate();

	make_pass(goal_x, goal_y);

	for (i = 0; pass[i] != 0; i++) {
		myprintf("pass:%d\n", pass[i]);
	}
	restMap();
	O7seg();
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;

}

void mode_11(void) {
	int i;
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;

	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);
	go_ketuate();
	for (i = 0; i < 20; i++) {
		turnleft90_fast();
	}

	stop90();

	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}

void mode_12(void) {
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;

	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);

	moter_enable();
	wait_Time(1500);

	go_ketuate();
	for (i = 0; i < 20; i++) {
		turnright90_fast();
	}

	stop90();
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_13(void) {
	moter_enable();
	wait_Time(1500);

	go_ketuate();
	more_run(177.00 * 14, 2100.0, 3000.0);
	kabeate_goal();
	wait_Time(4000);
	go_ketuate();
	more_run(177.00 * 14, 2100.0, 3000.0);
	stop90();

	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_14(void) {
	int i;
	i = 0;
	moter_enable();
	wait_Time(1500);
	go_ketuate();
	more_run(16.6 * 14, 1000.0, 2000.0);
	stop90();
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}

void mode_15(void) {
	int i = 0;
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;

	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);
	go_ketuate();
	maintainmaxspeed180();
	slalom_right90();
	maintainmaxspeed180();

	stop90();
	O7seg();
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_16(void) {
	int i;
	batterycheck();
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);
	go90();
	for (i = 0; i < 20; i++) {
		turnright90();
	}

	stop90();

	batterycheck();
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_17(void) {
	int i;
	batterycheck();
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);
	go90();
	for (i = 0; i < 20; i++) {
		turnright90();
	}

	stop90();

	batterycheck();
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_18(void) {
	int i = 0, j;
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;

	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);

	go_ketuate();
	for (i = 0; i < 6; i++) {
		maintainmaxspeed180();
	}
	kabeate_goal();
	go_ketuate();
	for (i = 0; i < 6; i++) {
		maintainmaxspeed180();
	}
	stop90();

	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_19(void) {
	int i;
	batterycheck();
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;
	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);
	go90();
	for (i = 0; i < 20; i++) {
		turnleft90();
	}

	stop90();

	batterycheck();
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
void mode_10(void) {
	int i;
	while (1) {

		myprintf("SEN_lf=%6d SEN_l=%6d SEN_r=%6d SEN_rf=%6d\n", SEN_lf, SEN_l,
				SEN_r, SEN_rf);
	}

	batterycheck();
	while (1) {

		myprintf("SEN_lf=%6d SEN_l=%6d SEN_r=%6d SEN_rf=%6d\n", SEN_lf, SEN_l,
				SEN_r, SEN_rf);
	}
	O7seg();
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
}
//PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
//	while (1) {
//		allAD();
//		myprintf("SEN_lf=%6d SEN_l=%6d SEN_r=%6d SEN_rf=%6d\n", SEN_lf, SEN_l,
//				SEN_r, SEN_rf);
//	}
//	O7seg();
