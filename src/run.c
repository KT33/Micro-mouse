/*
 * run.c
 *
 *  Created on: 2017/09/18
 *      Author: takao keisuke
 */
#include "iodefine.h"
#include "CMT.h"
#include "run.h"
#include "serial.h"
#include "variable.h"
#include "7seg.h"

void go90(void) {
//	L7seg_direction();
	wallcontorol_flag = 1;
	PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
	PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前
	speed = minspeed;
	distance = 0.0;
	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
	MTU2.TSTR.BIT.CST1 = 1;
	while (distance <= 88.0) {
		if (speed < maxspeed) {
			status = 1;
			//	L7seg_1();
		} else if (speed >= maxspeed) {
			//	wallcontorol_flag=1;
			speed = maxspeed;
			status = 0;
			//L7seg_1();
		}
	}
	distance = 0.0;
}

void stop90(void) {
//	L7seg_direction();
	wallcontorol_flag = 1;
	PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
	PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前

	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
	MTU2.TSTR.BIT.CST1 = 1;
	while (distance <= 88.0) {
		if (speed > minspeed) {
			status = 2;
			//	L7seg_3();
		} else if (speed <= minspeed) {
			speed = minspeed;
			status = 0;
			//L7seg_4();
		}

	}
	distance = 0.0;
	MTU2.TSTR.BIT.CST0 = 0; //カウント停止
	MTU2.TSTR.BIT.CST1 = 0;

}

void maintainmaxspeed180(void) {
//	L7seg_direction();
	wallcontorol_flag = 1;
	speed = maxspeed;
	while (distance < 176.4) { //157.0
//		myprintf("sen_r:%4d,sen_l:%4d,control_amount:%4f\n", SEN_r, SEN_l,
//				control_amount);
		status = 0;
		//L7seg_2();
	}
	distance = 0;
}

void move(int mode, float distance_degree) { //(mode,i_distance) 0前進 1右折 2左折 3後退
//	float l_accel;
//	if(mode==1||mode==2){
//		l_accel=3000;
//	}else{
//		l_accel=accel;
//	}
//	L7seg_direction();
	triangle = (maxspeed * maxspeed - minspeed * minspeed) / accel;
	if (mode == 0) { //前進
		wallcontorol_flag = 1;
		i_distance = distance_degree - 0.25;
		PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
		PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前
	} else if (mode == 1) { //右折
		i_distance = 83 * distance_degree * 3.14 / 360;
		PE.DRL.BIT.B0 = 1; //右のCW/CCW 0が前
		PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前
		wallcontorol_flag = 0;
		if (distance_degree < 100) {
			direction++;
		} else {
			direction += 2;
		}
	} else if (mode == 2) { //左折
		i_distance = 83 * distance_degree * 3.14 / 360;
		PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
		PE.DRL.BIT.B4 = 0; //左のCW/CCW 1が前
		wallcontorol_flag = 0;
		if (distance_degree < 100) {
			direction += 3;
		} else {
			direction += 2;
		}
	} else if (mode == 3) { //後退
		i_distance = distance_degree;
		PE.DRL.BIT.B0 = 1; //右のCW/CCW 0が前
		PE.DRL.BIT.B4 = 0; //左のCW/CCW 1が前
		wallcontorol_flag = 0;

	}

	if (direction > 4) {
		direction -= 4;
	}
	speed = minspeed;
	distance = 0.0;

	//i = 0;
	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
	MTU2.TSTR.BIT.CST1 = 1;
	//status  0速度維持 1加速 2減速
	if (i_distance > triangle) {
		while (distance < triangle / 2) { //加速区間
			if (speed < maxspeed) {
//				L7seg_1();
				status = 1;
			} else {
				speed = maxspeed;
				status = 0;
//				L7seg_6();
			}
		}
		while (distance <= (i_distance - triangle / 2)) { //等速区間　最高速維持
			//	allAD();

			status = 0;
			speed = maxspeed;
//				L7seg_2();
		}
		while (distance < i_distance) { //減速区間
			if (speed > minspeed) { //減速
				status = 2;
//					L7seg_3();
			} else { //最低速維持
				status = 0;
				speed = minspeed;
				//			L7seg_9();
			}
		}
	} else if (i_distance <= triangle) {
		while (distance < (i_distance / 2)) { //加速区間
			status = 1;
			//L7seg_4();
		}
		while (distance < i_distance) { //減速区間
			if (speed > minspeed) { //減速
				status = 2;
				//L7seg_5();
			} else { //最低速維持
				status = 0;
				speed = minspeed;
				//	L7seg_8();
			}
		}
	}
	status = 0;
	MTU2.TSTR.BIT.CST0 = 0; //カウント停止
	MTU2.TSTR.BIT.CST1 = 0;
	distance = 0.0;
	//O7seg();
}

void stop(void) {
	int i;
	MTU2.TSTR.BIT.CST0 = 0; //カウント停止
	MTU2.TSTR.BIT.CST1 = 0;
	for (i = 0; i < 10; i++) {
		L7seg_F();
		PB.DR.BIT.B1 = 1;
		PB.DR.BIT.B2 = 1;
		PB.DR.BIT.B3 = 1;
		PB.DR.BIT.B5 = 1;
		wait_Time(100);
		PB.DR.BIT.B1 = 0;
		PB.DR.BIT.B2 = 0;
		PB.DR.BIT.B3 = 0;
		PB.DR.BIT.B5 = 0;
		wait_Time(100);
	}
}

void L7seg_direction(void) {
	if (y == 1) {
		L7seg_1();
	} else if (y == 2) {
		L7seg_2();
	} else if (y == 3) {
		L7seg_3();
	} else if (y == 4) {
		L7seg_4();
	} else if (y == 0) {
		L7seg_0();
	} else {
		L7seg_9();
	}
}

void coordinate(void) {
	myprintf("x:%d y:%d direction:%d\n", x, y, direction);
	if (direction == 1) {
		y++;
	} else if (direction == 2) {
		x++;
	} else if (direction == 3) {
		y--;
	} else if (direction == 4) {
		x--;
	}
	myprintf("x:%d y:%d direction:%d\n", x, y, direction);
	myprintf("\n");

}

void turnright90(void) {
	stop90();
	wait_Time(100);
	move(1, 90.0);
	wait_Time(100);
	go90();
}
void turnright180(void) {
	stop90();
	wait_Time(100);
	move(1, 177.55);
	wait_Time(100);
	go90();
}
void turnleft90(void) {
	stop90();
	wait_Time(100);
	move(2, 91.4);
	wait_Time(100);
	go90();
}
void turnleft180(void) {
	stop90();
	wait_Time(100);
	move(2, 178.8);
	wait_Time(100);
	go90();
}

void go_ketuate(void) {
//	L7seg_direction();
	wallcontorol_flag = 1;
	PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
	PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前
	speed = minspeed;
	distance = 0.0;
	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
	MTU2.TSTR.BIT.CST1 = 1;
	while (distance <= 125.0) {
		if (speed < maxspeed) {
			status = 1;
			//	L7seg_1();
		} else if (speed >= maxspeed) {
			//	wallcontorol_flag=1;
			speed = maxspeed;
			status = 0;
			//L7seg_1();
		}
	}
	distance = 0.0;
}

void kabeate_blind_alley(void) {
	volatile float box_maxspeed;
	box_maxspeed = maxspeed;
	stop90();
	wait_Time(100);
	move(1, 89.9);
	wait_Time(100);
	maxspeed = 250;
	move(3, 110);
	maxspeed = box_maxspeed;
	wait_Time(100);
	move(0, 35.0);
	wait_Time(100);
	move(1, 89.9);
	wait_Time(100);
	maxspeed = 250;
	move(3, 110);
	maxspeed = box_maxspeed;
	go_ketuate();
}

void kabeate_goal(void) {
	volatile float box_maxspeed;
	int flag = 0; //1:袋小路 2:前と右 3:前と左 0:その他(超信地のみ)

	box_maxspeed = maxspeed;

	if (direction == 1) {
		if ((getWall(x, y, 1) == 1) && (getWall(x, y, 2) == 1)
				&& (getWall(x, y, 4) == 1)) {
			flag = 1;
		} else if ((getWall(x, y, 1) == 1) && (getWall(x, y, 2) == 1)) {
			flag = 2;
		} else if ((getWall(x, y, 1) == 1) && (getWall(x, y, 4) == 1)) {
			flag = 3;
		} else {
			flag = 0;
		}
	}

	if (direction == 2) {
		if ((getWall(x, y, 1) == 1) && (getWall(x, y, 2) == 1)
				&& (getWall(x, y, 3) == 1)) {
			flag = 1;
		} else if ((getWall(x, y, 2) == 1) && (getWall(x, y, 3) == 1)) {
			flag = 2;
		} else if ((getWall(x, y, 2) == 1) && (getWall(x, y, 1) == 1)) {
			flag = 3;
		} else {
			flag = 0;
		}
	}

	if (direction == 3) {
		if ((getWall(x, y, 3) == 1) && (getWall(x, y, 2) == 1)
				&& (getWall(x, y, 4) == 1)) {
			flag = 1;
		} else if ((getWall(x, y, 3) == 1) && (getWall(x, y, 2) == 1)) {
			flag = 3;
		} else if ((getWall(x, y, 3) == 1) && (getWall(x, y, 4) == 1)) {
			flag = 2;
		} else {
			flag = 0;
		}
	}

	if (direction == 4) {
		if ((getWall(x, y, 1) == 1) && (getWall(x, y, 3) == 1)
				&& (getWall(x, y, 4) == 1)) {
			flag = 1;
		} else if ((getWall(x, y, 4) == 1) && (getWall(x, y, 1) == 1)) {
			flag = 2;
		} else if ((getWall(x, y, 4) == 1) && (getWall(x, y, 3) == 1)) {
			flag = 3;
		} else {
			flag = 0;
		}
	}

	if ((flag == 1) || (flag == 3)) { //袋小路or左壁あり
		stop90();
		wait_Time(100);
		move(1, 89.9);
		wait_Time(100);
		maxspeed = 250;
		move(3, 110);
		maxspeed = box_maxspeed;
		wait_Time(100);
		move(0, 35.0);
		wait_Time(100);
		move(1, 89.9);
		wait_Time(100);
		maxspeed = 250;
		move(3, 110);
		maxspeed = box_maxspeed;
	} else if (flag == 2) { //右壁と前のみ
		stop90();
		wait_Time(100);
		move(2, 89.8);
		wait_Time(100);
		maxspeed = 250;
		move(3, 110);
		maxspeed = box_maxspeed;
		wait_Time(100);
		move(0, 35.0);
		wait_Time(100);
		move(2, 89.8);
		wait_Time(100);
		maxspeed = 250;
		move(3, 110);
		maxspeed = box_maxspeed;
	} else {
		stop90();
		wait_Time(100);
		move(2, 178.8);
		wait_Time(100);
		move(3, 44);
		wait_Time(100);
	}
	maxspeed = box_maxspeed;
}

void more_run(float i_distance, float more_maxspeed, float more_accel) { //(mode,i_distance) 0前進 1右折 2左折 3後退
//accel,2000 ,maxv,2000,176.88
//      3000 ,    ,2100,177.00
	float more_minspeed = maxspeed;
	float maxspeed_box, accel_box;
//	maxspeed_box=maxspeed;
	accel_box = accel;
	accel = more_accel;

	triangle = (more_maxspeed * more_maxspeed - more_minspeed * more_minspeed)
			/ more_accel;

	wallcontorol_flag = 1;
	PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
	PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前

	distance = 0.0;

	//i = 0;
	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
	MTU2.TSTR.BIT.CST1 = 1;
	//status  0速度維持 1加速 2減速
	if (i_distance > triangle) {
//		while (distance < triangle / 2) { //加速区間
//			if (speed < more_maxspeed) {
////				L7seg_1();
//				status = 1;
//			} else {
//				speed = more_maxspeed;
//				status = 0;
////				L7seg_6();
//			}
//		}
		while (speed < more_maxspeed) {
			status = 1;
		}

		while (distance <= (i_distance - triangle / 2)) { //等速区間　最高速維持
			//	allAD();

			status = 0;
			speed = more_maxspeed;
//				L7seg_2();
		}
		while (distance < i_distance) { //減速区間
			if (speed > more_minspeed) { //減速
				status = 2;
//					L7seg_3();
			} else { //最低速維持
				status = 0;
				speed = more_minspeed;
				//			L7seg_9();
			}
		}
	} else if (i_distance <= triangle) {
		while (distance < (i_distance / 2)) { //加速区間
			status = 1;
			//L7seg_4();
		}
		while (distance < i_distance) { //減速区間
			if (speed > more_minspeed) { //減速
				status = 2;
				//L7seg_5();
			} else { //最低速維持
				status = 0;
				speed = more_minspeed;
				//	L7seg_8();
			}
		}
	}
	status = 0;
//	maxspeed=maxspeed_box;
	accel = accel_box;
//	MTU2.TSTR.BIT.CST0 = 0; //カウント停止
//	MTU2.TSTR.BIT.CST1 = 0;
	distance = 0.0;
	//O7seg();
}

void turnright90_fast(void) {
	stop90();
	wait_Time(30);
	move(1, 90.9);
	wait_Time(30);
	go90();
}
void turnright180_fast(void) {
	stop90();
	wait_Time(30);
	move(1, 177.55);
	wait_Time(30);
	go90();
}
void turnleft90_fast(void) {
	stop90();
	wait_Time(30);
	move(2, 92.3);
	wait_Time(30);
	go90();
}
void turnleft180_fast(void) {
	stop90();
	wait_Time(30);
	move(2, 178.8);
	wait_Time(30);
	go90();
}
