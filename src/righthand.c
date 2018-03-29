/*
 * righthand.c
 *
 *  Created on: 2017/09/23
 *      Author: takao keisuke
 */
/*
 * righthand.c
 *
 *  Created on: 2017/09/20
 *      Author: takao keisuke
 */
#include "iodefine.h"
#include "righthand.h"
#include "run.h"
#include "CMT.h"
#include "variable.h"

void righthand(void) {
	int i,count=0;
	restMap();
//	restReachedMap();
	go90();
	coordinate();
	addWall();
	while (1) {
//		if (x == goal_x && y == goal_y) {
//			wallcontorol_flag = 1;
//			stop90();
//			move(1, 360);
//			stop();
//			break;
//		}
		if(x==0&&y==2){
			count++;
		}
		if(count==3){
			stop();
			break;
		}

		if (SEN_l < e_SEN_l) {
			wallcontorol_flag = 1;
			turnleft90();
//			stop90();
//
//			wait_Time(100);
//			move(2, 90);
//			wait_Time(100);
//			go90();
			coordinate();
			addWall();
		} else if (SEN_l >= e_SEN_l && SEN_lf + SEN_rf < e_SEN_f) {
			wallcontorol_flag = 1;
			maintainmaxspeed180();
			coordinate();
			addWall();
		} else if (SEN_r < e_SEN_r) {
			wallcontorol_flag = 1;
			turnright90();
			coordinate();
			addWall();
		} else {
			wallcontorol_flag = 1;
			stop90();
			wait_Time(100);
			move(2, 179);
			wait_Time(100);
			go90();
			coordinate();
			addWall();

		}
	}
}

