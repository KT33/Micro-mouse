/*
 * variable.c
 *
 *  Created on: 2017/09/26
 *      Author: takao keisuke
 */

#include "iodefine.h"
#include "variable.h"
#include "variable.h"

volatile int x = 0, y = 0;
volatile int i, j, flag = 0, a, b, mode, direction = 1, mode_flag = 0, chatt =
		5000;
volatile float Kp = 0.27;
volatile float minspeed = 180.0;
volatile float maxspeed = 500.0;
volatile float accel = 1700.0;//1700
volatile float battery, i_distance, triangle;
volatile float speed = 0.0;
volatile float distance = 0.0;
volatile int g_cnt_wait = 0;
volatile float diameter = 51.0;
volatile int status; //0速度維持 1加速 2減速
volatile float control_amount = 0;
volatile int SEN_l, SEN_lf, SEN_r, SEN_rf, SEN_f, batt;
volatile int SEN_r_before1, SEN_r_before2, SEN_r_before3, SEN_r_before4;
volatile int SEN_l_before1, SEN_l_before2, SEN_l_before3, SEN_l_before4,
		SEN_l_before5;
volatile float tgraR, tgraL;
volatile int wallcontorol_flag = 0,return_mode_select_flag=0;
volatile int c_SEN_l = 670, c_SEN_r = 727;
volatile int e_SEN_l = 230, e_SEN_r = 320, e_SEN_f = 250;
volatile unsigned short column[17]; //上の壁がMSB
volatile unsigned short row[17]; //左がMSB
volatile unsigned short column_interim[17]; //上の壁がMSB
volatile unsigned short row_interim[17]; //左がMSB
volatile unsigned short column_reached_interim[17];
volatile unsigned short row_reached_interim[17];
volatile unsigned short column_box[17];
volatile unsigned short row_box[17];
volatile unsigned short column_reached[17];
volatile unsigned short row_reached[17];
volatile unsigned short column_box[17];
volatile unsigned short row_box[17];
volatile unsigned short reached[16];
volatile unsigned short step_Map[16][16] = { 255 };
volatile int goal_x, goal_y;
volatile float omega_r = 0, omega_l = 0, degree_r = 0, degree_l = 0, alpha =
		9000, pre = 20, fol = 20, v_turn = 500, max_omega = 500;
volatile float slalom_amount = 0;
volatile int status_slalom_r = 0, status_slalom_l = 0;
volatile short pass[500]; //1:直進 2:右折 3:左折 0:終了

//union wall_date set_wall_y[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//union wall_date set_wall_x[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

