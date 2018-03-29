/*
 * trash.c
 *
 *  Created on: 2017/09/18
 *      Author: takao keisuke
 */


//以下廃材置き場
//union wall_date wall_x1;
//union wall_date wall_x2;
//union wall_date wall_x3;
//union wall_date wall_x4;
//union wall_date wall_x5;
//union wall_date wall_x6;
//union wall_date wall_x7;
//union wall_date wall_x8;
//union wall_date wall_x9;
//union wall_date wall_x10;
//union wall_date wall_x11;
//union wall_date wall_x12;
//union wall_date wall_x13;
//union wall_date wall_x14;
//union wall_date wall_x15;

//union wall_date wall_y1;
//union wall_date wall_y2;
//union wall_date wall_y3;
//union wall_date wall_y4;
//union wall_date wall_y5;
//union wall_date wall_y6;
//union wall_date wall_y7;
//union wall_date wall_y8;
//union wall_date wall_y9;
//union wall_date wall_y10;
//union wall_date wall_y11;
//union wall_date wall_y12;
//union wall_date wall_y13;
//union wall_date wall_y14;
//union wall_date wall_y15;

//extern union wall_date wall_y2;
//extern union wall_date wall_y3;
//extern union wall_date wall_y4;
//extern union wall_date wall_y5;
//extern union wall_date wall_y6;
//extern union wall_date wall_y7;
//extern union wall_date wall_y8;
//extern union wall_date wall_y9;
//extern union wall_date wall_y10;
//extern union wall_date wall_y11;
//extern union wall_date wall_y12;
//extern union wall_date wall_y13;
//extern union wall_date wall_y14;
//extern union wall_date wall_y15;
//extern union wall_date wall_x0;
//extern union wall_date wall_x1;
//extern union wall_date wall_x2;
//extern union wall_date wall_x3;
//extern union wall_date wall_x4;
//extern union wall_date wall_x5;
//extern union wall_date wall_x6;
//extern union wall_date wall_x7;
//extern union wall_date wall_x8;
//extern union wall_date wall_x9;
//extern union wall_date wall_x10;
//extern union wall_date wall_x11;
//extern union wall_date wall_x12;
//extern union wall_date wall_x13;
//extern union wall_date wall_x14;
//extern union wall_date wall_x15;

//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);
//wait_Time(1000);
//move(2,180);


//チャタリング関連
//		i = 0;
//		if (PA.DRL.BIT.B6 == 0 && PB.DR.BIT.B1 == 0) {
//			while (i < 1000) {
//				i++;
//			}
//			while (PA.DRL.BIT.B6 == 0) {
//
//			}
//			PB.DR.BIT.B1 = 1;
//
//		}
//
//		else if (PA.DRL.BIT.B6 == 0 && PB.DR.BIT.B1 == 1) {
//			while (i < 1000) {
//				i++;
//			}
//			while (PA.DRL.BIT.B6 == 0) {
//
//			}
//
//			PB.DR.BIT.B1 = 0;
//
//		}

//
//triangle = (maxspeed * maxspeed - minspeed * minspeed)/accel;
//
//PE.DRL.BIT.B0 = 1; //右のCW/CCW 0が前
//PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前
//PE.DRL.BIT.B8 = 1; //Motor_Enableに1を代入
//
//speed = minspeed;
//
//MTU2.TSTR.BIT.CST0 = 0; //カウント停止
//MTU2.TSTR.BIT.CST1 = 0;

//

//	wait_time(3000);
//	distance = 0;
//	speed = minspeed;
//	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
//	MTU2.TSTR.BIT.CST1 = 1;
//
//	while (distance < i_distance) {
//
//	}
//	MTU2.TSTR.BIT.CST0 = 0; //カウントスタート
//	MTU2.TSTR.BIT.CST1 = 0;
//	PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
//	PE.DRL.BIT.B4 = 0; //左のCW/CCW 1が前
//	wait_time(1500);
//
//	MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
//	MTU2.TSTR.BIT.CST1 = 1;
//	distance = 0;
//	while (distance < i_distance) {
//
//	}


//
//void turn(int mode, int degree) { //(mode,degree)モード0で右折1で左折
//	MTU2.TSTR.BIT.CST0 = 0; //カウント停止
//	MTU2.TSTR.BIT.CST1 = 0;
//	speed = minspeed;
//	i_distance = 80.0 * 3.14 * (float) degree / 360.0;
//	if (mode == 0) { //右折
//		PE.DRL.BIT.B0 = 1; //右のCW/CCW 0が前
//		PE.DRL.BIT.B4 = 1; //左のCW/CCW 1が前
//		daikeikasoku = 1;
//		distance = 0;
//		MTU2.TSTR.BIT.CST0 = 1; //カウントスタート
//		MTU2.TSTR.BIT.CST1 = 1;
//		while (distance <= i_distance) {
//
//		}
//		MTU2.TSTR.BIT.CST0 = 0; //カウント停止
//		MTU2.TSTR.BIT.CST1 = 0;
//
//	} else if (mode == 1) {
//		PE.DRL.BIT.B0 = 0; //右のCW/CCW 0が前
//		PE.DRL.BIT.B4 = 0; //左のCW/CCW 1が前
//		daikeikasoku = 1;
//		distance = 0;
//		i = 0;
//		MTU2.TSTR.BIT.CST0 = 1; //カウント停止
//		MTU2.TSTR.BIT.CST1 = 1;
//		while (distance <= i_distance) {
//
//		}
//		MTU2.TSTR.BIT.CST0 = 0; //カウント停止
//		MTU2.TSTR.BIT.CST1 = 0;
//	} else {
//
//	}
//	daikeikasoku = 0;
//}

//		i++;
//		for (j = 0; j < 1; j++) {
//			if (j == 0) {
//				date[i][j] = distance;
//			} else if (j == 1) {
//				date[i][j] = speed;
//			}

//	}
//i++;
//		for (j = 0; j < 1; j++) {
//			if (j == 0) {
//				date[i][j] = distance;
//			} else if (j == 1) {
//				date[i][j] = speed;
//			}

