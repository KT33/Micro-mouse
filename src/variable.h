/*
 * variable.h
 *
 *  Created on: 2017/09/26
 *      Author: takao keisuke
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

extern volatile int SEN_l, SEN_lf, SEN_r, SEN_rf, SEN_f, SEN_f, batt;
extern volatile int SEN_r_before1, SEN_r_before2, SEN_r_before3, SEN_r_before4;
extern volatile int SEN_l_before1, SEN_l_before2, SEN_l_before3, SEN_l_before4,
		SEN_l_before5;
extern volatile float minspeed, maxspeed, accel;
extern volatile float speed;
extern volatile float distance;
extern volatile int g_cnt_wait;
extern volatile float diameter;
extern volatile float i_distance;
extern volatile float triangle;
extern volatile int daikeikasoku;
extern volatile float tgraR, tgraL;
extern volatile int i, j, a;
//extern float date[1000];
extern volatile int status;
extern volatile float control_amount;
extern volatile int mode;
extern volatile float diameter, speed, diameter; //diameterタイヤ径
extern volatile float control_amount;
extern volatile int e_SEN_r, e_SEN_l; //壁が存在するかどうかの境目
extern volatile int daikeikasoku, direction, x, y, mode_flag, chatt;
extern volatile float distance;
extern volatile float minspeed;
extern volatile float accel;
extern volatile float maxspeed;
extern volatile float control_amount;
extern volatile float speed;
extern volatile float distance;
extern volatile int g_cnt_wait;
extern volatile float diameter;
extern volatile float i_distance;
extern volatile float triangle;
extern volatile int daikeikasoku;
extern volatile float tgraR, tgraL;
extern volatile int status;
extern volatile int mode;
extern volatile int wallcontorol_flag;
extern volatile int SEN_l, SEN_lf, SEN_r, SEN_rf, SEN_l_before5, SEN_r_before5;
extern volatile float control_amount;
extern volatile float speed;
extern volatile int SEN_l, SEN_lf, SEN_r, SEN_rf;
extern volatile int mode;
extern volatile int c_SEN_r, c_SEN_l;
extern volatile int e_SEN_r, e_SEN_l, e_SEN_f;
extern volatile int mode;
extern volatile int wallcontorol_flag,return_mode_select_flag;
extern volatile float Kp;
extern volatile float battery;
extern volatile int batt;
extern volatile unsigned short column[17];
extern volatile unsigned short row[17];
extern volatile unsigned short reached[16];
extern volatile unsigned short step_Map[16][16];
extern volatile int goal_x, goal_y;
extern volatile float degree_r, degree_l, omega_r, omega_l, alpha, pre, fol,
		v_turn, max_omega, slalom_amount;
extern volatile int status_slalom_r, status_slalom_l;
extern volatile short pass[500];
extern volatile unsigned short column_reached[17];
extern volatile unsigned short row_reached[17];
extern volatile unsigned short column_box[17];
extern volatile unsigned short row_box[17];
extern volatile unsigned short column_reached_interim[17];
extern volatile unsigned short row_reached_interim[17];
extern volatile unsigned short column_interim[17]; //上の壁がMSB
extern volatile unsigned short row_interim[17]; //左がMSB
//union wall_date {
//	unsigned short BYTE;
//	struct {
//		unsigned short B15 :1;
//		unsigned short B14 :1;
//		unsigned short B13 :1;
//		unsigned short B12 :1;
//		unsigned short B11 :1;
//		unsigned short B10 :1;
//		unsigned short B9 :1;
//		unsigned short B8 :1;
//		unsigned short B7 :1;
//		unsigned short B6 :1;
//		unsigned short B5 :1;
//		unsigned short B4 :1;
//		unsigned short B3 :1;
//		unsigned short B2 :1;
//		unsigned short B1 :1;
//		unsigned short B0 :1;
//	} BIT;
//};
//
//extern union set_wall_date wall_y[15];
//extern union set_wall_date wall_x[15];

#endif /* VARIABLE_H_ */
