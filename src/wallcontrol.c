/*
 * wallcontrol.c
 *
 *  Created on: 2017/09/19
 *      Author: takao keisuke
 */
#include "iodefine.h"
#include "wallcontrol.h"
#include "stdio.h"
#include "variable.h"

void wallContorol(void) {
	if ((wallcontorol_flag == 1) && (speed > 300) && (SEN_f < e_SEN_f)
			&& (abs(SEN_r - SEN_r_before3) < 15)
			&& (abs(SEN_l - SEN_l_before3) < 15)) {
		if (SEN_l > e_SEN_l && SEN_r > e_SEN_r) {
			control_amount = Kp * ((SEN_r - c_SEN_r) - (SEN_l - c_SEN_l));

			//L7seg_1();

		} else if (SEN_l > e_SEN_l && SEN_r <= e_SEN_r) {
			control_amount = Kp * (-(SEN_l - c_SEN_l) * 2);

			//L7seg_2();

		} else if (SEN_l <= e_SEN_l && SEN_r > e_SEN_r) {
			control_amount = Kp * ((SEN_r - c_SEN_r) * 2);

			//L7seg_3();

		} else {
			control_amount = 0000000000000000001;

			//L7seg_4();

		}
	} else {
		control_amount = 0.00000000000000000002;


//		PB.DR.BIT.B1 = 1;
//		PB.DR.BIT.B2 = 1;
//		PB.DR.BIT.B3 = 1;
//		PB.DR.BIT.B5 = 1;
	}
//	PB.DR.BIT.B1 = 0;
//	PB.DR.BIT.B2 = 0;
//	PB.DR.BIT.B3 = 0;
//	PB.DR.BIT.B5 = 0;

}

