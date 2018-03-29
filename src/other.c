/*
 * other.c
 *
 *  Created on: 2017/09/18
 *      Author: takao keisuke
 */
#include "iodefine.h"
#include  "other.h"
#include "variable.h"

void moter_enable(void) {
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;

	PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
	wait_Time(1500);
}

void batterycheck(void) {
	battery = (float) batt * 3.12765 * 5.0 / 1023.0;
	if (battery < 10.9) {
		while (1) {
			L7seg_E();
			PB.DR.BIT.B1 = 1;
			PB.DR.BIT.B2 = 0;
			PB.DR.BIT.B3 = 1;
			PB.DR.BIT.B5 = 0;
			wait_Time(100);
			PB.DR.BIT.B1 = 0;
			PB.DR.BIT.B2 = 1;
			PB.DR.BIT.B3 = 0;
			PB.DR.BIT.B5 = 1;
			wait_Time(100);
			PB.DR.BIT.B2 = 0;
			PB.DR.BIT.B5 = 0;
		}
	}

}

void allPFC(void) {
	PFC.PBIORL.WORD = 0x2e; //read:0 write:1
	PFC.PEIORL.WORD = 0xFFFF; //モーター関連とスピーカー,7seg
	PFC.PAIORL.BIT.B12 = 1; //以下センサーLED
	PFC.PAIORL.BIT.B13 = 1;
	PFC.PAIORL.BIT.B14 = 1;
	PFC.PAIORL.BIT.B15 = 1; //以上センサーLED

}

void chattering(void) {
	i = 0;
	while (i < chatt) {
		i++;
	}
	while (PA.DRL.BIT.B6 == 0) {
	}
	while (i < chatt) {
		i++;
	}
}
void return_mode_select(void) {
	if (PA.DRL.BIT.B8 == 0) {
		return_mode_select_flag = 1;
		O7seg();
	}
}
