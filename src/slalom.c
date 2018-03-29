/*
 * slalom.c
 *
 *  Created on: 2017/10/13
 *      Author: takao keisuke
 */

#include "iodefine.h"
#include "variable.h"
#include "serial.h"
#include "run.h"
#include "CMT.h"
#include "MTU.h"
#include "slalom.h"

void slalom_right90(void) {
	float i_degree = 88.82;
	float triangle_slalom;
	wallcontorol_flag = 1;

	speed = v_turn;
	while (distance < 13.8) {
		PB.DR.BIT.B1 = 1;
		PB.DR.BIT.B2 = 1;
		PB.DR.BIT.B3 = 1;
		PB.DR.BIT.B5 = 1;
	}
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
	PB.DR.BIT.B3 = 1;
	PB.DR.BIT.B5 = 0;
	wallcontorol_flag = 0;
	speed = v_turn;
	omega_r = 0;
	degree_r = 0;
	PB.DR.BIT.B1 = 1;
	PB.DR.BIT.B2 = 1;
	PB.DR.BIT.B3 = 0;
	PB.DR.BIT.B5 = 0;
	triangle_slalom = (max_omega * max_omega) / alpha;

	if (i_degree > triangle_slalom) {
		while (degree_r < (triangle_slalom / 2)) { //加速区間
			if (omega_r < max_omega) {

				L7seg_1();
				status_slalom_r = 1;
			} else {

				omega_r = max_omega;
				status_slalom_r = 0;
				L7seg_6();

			}
		}
		while (degree_r <= (i_degree - (triangle_slalom / 2))) { //等速区間　最高速維持

			status_slalom_r = 0;
			omega_r = max_omega;
			L7seg_2();

		}
		while ((degree_r < i_degree) && (omega_r > 0)) { //減速区間
			status_slalom_r = 2;

			L7seg_3();

		}

	} else if ((i_degree) <= (triangle_slalom)) {
		while (degree_r < (i_degree / 2)) { //加速区間
			status_slalom_r = 1;
			L7seg_4();

		}
		while ((degree_r < i_degree) && (omega_r > 0)) { //減速区間
			status_slalom_r = 2;
			L7seg_5();

		}
	}

	status_slalom_r = 0;
	omega_r = 0;
	degree_r = 0;
	distance = 0;
	wallcontorol_flag = 1;
	while (distance < 25.0) {

	}
	PB.DR.BIT.B3 = 0;
	distance = 0;
	direction++;
	if (direction > 4) {
		direction -= 4;
	}
	distance = 0;
}

void slalom_left90(void) {
	float i_degree = 87.5;
	float triangle_slalom;
	wallcontorol_flag = 1;
	PB.DR.BIT.B5 = 1;
	distance = 0;
	while (distance <= 10.8) {
		PB.DR.BIT.B1 = 1;
		PB.DR.BIT.B2 = 1;
		PB.DR.BIT.B3 = 1;
		PB.DR.BIT.B5 = 1;
	}
	PB.DR.BIT.B1 = 0;
	PB.DR.BIT.B2 = 0;
	PB.DR.BIT.B3 = 0;
	PB.DR.BIT.B5 = 0;
//	PB.DR.BIT.B5 = 0;
//	PB.DR.BIT.B3 = 1;
//	PB.DR.BIT.B2 = 1;
	wallcontorol_flag = 0;
	speed = v_turn;
	omega_l = 0;
	degree_l = 0;
	triangle_slalom = (max_omega * max_omega) / alpha;
//	myprintf("triangle_slalom=%4f\n", triangle_slalom);
	if (i_degree > triangle_slalom) {
		while (degree_l < (triangle_slalom / 2)) { //加速区間
			if (omega_l < max_omega) {
				//	L7seg_1();
				status_slalom_l = 1;
				//			myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
			} else {
				omega_l = max_omega;
				status_slalom_l = 0;
				//	L7seg_6();
				//		myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
			}
		}
		while (degree_l <= (i_degree - (triangle_slalom / 2))) { //等速区間　最高速維持
			//	allAD();

			status_slalom_l = 0;
			omega_l = max_omega;
			//	L7seg_2();
			//myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
		}
		while ((degree_l < i_degree) && (omega_l > 0)) { //減速区間

			status_slalom_l = 2;
			//	L7seg_3();
			//myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
		}
	} else if ((i_degree) <= (triangle_slalom)) {
		while (degree_l < (i_degree / 2)) { //加速区間
			status_slalom_l = 1;
			//	L7seg_4();
			//	myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
		}
		while ((degree_l < i_degree) && (omega_l > 0)) { //減速区間
			status_slalom_l = 2;
			//	L7seg_5();
			//myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
		}
	}
//	myprintf("degree_l:%5f	omega_l:%5f\n", degree_l, omega_l);
	status_slalom_l = 0;
	PB.DR.BIT.B3 = 0;
	PB.DR.BIT.B2 = 0;
	PB.DR.BIT.B5 = 0;
	PB.DR.BIT.B1 = 0;
	wallcontorol_flag = 1;
	omega_l = 0;
	degree_l = 0;
	distance = 0;
	while (distance < 30.0) {

	}
	PB.DR.BIT.B5 = 0;
	PB.DR.BIT.B1 = 0;
	distance = 0;
	direction += 3;
	if (direction > 4) {
		direction -= 4;
	}
	distance = 0;

}
