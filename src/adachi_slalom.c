/*
 * adachi_slalom.c
 *
 *  Created on: 2017/11/09
 *      Author: takao keisuke
 */
#include "iodefine.h"
#include "variable.h"
#include "adachi.h"
#include "run.h"
#include "CMT.h"
#include "righthand.h"
#include "adachi_slalome.h"



void adachi_slalome(int goal_x, int goal_y,int kabeate_per_blind_alley) {
	int flag = 0, i = 0, step;
	int kabeate_count=0;

	//move(0, 90);
	go_ketuate();
	coordinate();
	addWall();
	adachi_map(goal_x, goal_y);
	while (1) {
		adachi_map(goal_x, goal_y);
		flag = 0;
		if (x == goal_x && y == goal_y) {
			kabeate_goal();
			//move(0, 90);
			stop();
			break;
		}

		step = 225;

		if (direction == 1) { //flag 0:前　1:右折　2:左折　3:ターン

			if ((x > 0) && (getWall(x, y, 4) == 0)) {
				if (step_Map[x - 1][y] < step) {
					step = step_Map[x - 1][y];
					flag = 2;
				}
			}
			if ((x < 15) && (getWall(x, y, 2) == 0)) {
				if (step_Map[x + 1][y] < step) {
					step = step_Map[x + 1][y];
					flag = 1;
				}
			}
			if (y > 0) {
				if (step_Map[x][y - 1] < step) {
					step = step_Map[x][y - 1];
					if ((getWall(x, y, 1) == 1) && (getWall(x, y, 2) == 1)
							&& (getWall(x, y, 4) == 1)) {
						flag = 4;
						kabeate_count++;
					} else {
						flag = 3;
					}
				}
			}

			if ((y < 15) && (getWall(x, y, 1) == 0)) {
				if ((step_Map[x][y + 1] <= step)) {
					step = step_Map[x][y + 1];
					flag = 0;
				}
			}
		} else if (direction == 2) {

			if ((y < 15) && (getWall(x, y, 1) == 0)) {
				if (step_Map[x][y + 1] < step) {
					step = step_Map[x][y + 1];
					flag = 2;
				}
			}
			if ((y > 0) && (getWall(x, y, 3) == 0)) {
				if (step_Map[x][y - 1] < step) {
					step = step_Map[x][y - 1];
					flag = 1;
				}
			}
			if (x > 0) {
				if (step_Map[x - 1][y] < step) {
					step = step_Map[x - 1][y];
					if ((getWall(x, y, 2) == 1) && (getWall(x, y, 1) == 1)
							&& (getWall(x, y, 3) == 1)) {
						flag = 4;
						kabeate_count++;
					} else {
						flag = 3;
					}
				}
			}

			if ((x < 15) && (getWall(x, y, 2) == 0)) {
				if (step_Map[x + 1][y] <= step) {
					step = step_Map[x + 1][y];
					flag = 0;
				}
			}
		} else if (direction == 3) {

			if ((x < 15) && (getWall(x, y, 2) == 0)) {
				if (step_Map[x + 1][y] < step) {
					step = step_Map[x + 1][y];
					flag = 2;
				}
			}
			if ((x > 0) && (getWall(x, y, 4) == 0)) {
				if (step_Map[x - 1][y] < step) {
					step = step_Map[x - 1][y];
					flag = 1;
				}
			}
			if (y < 15) {
				if (step_Map[x][y + 1] < step) {
					step = step_Map[x][y + 1];
					if ((getWall(x, y, 3) == 1) && (getWall(x, y, 2) == 1)
							&& (getWall(x, y, 4) == 1)) {
						flag = 4;
						kabeate_count++;
					} else {
						flag = 3;
					}
				}
			}

			if ((y > 0) && (getWall(x, y, 3) == 0)) {
				if (step_Map[x][y - 1] <= step) {
					step = step_Map[x][y - 1];
					flag = 0;
				}
			}
		} else if (direction == 4) {

			if ((y > 0) && (getWall(x, y, 3) == 0)) {
				if (step_Map[x][y - 1] <= step) {
					step = step_Map[x][y - 1];
					flag = 2;
				}
			}
			if ((y < 15) && (getWall(x, y, 1) == 0)) {
				if (step_Map[x][y + 1] <= step) {
					step = step_Map[x][y + 1];
					flag = 1;
				}
			}
			if (x < 15) {
				if (step_Map[x + 1][y] < step) {
					step = step_Map[x + 1][y];
					if ((getWall(x, y, 4) == 1) && (getWall(x, y, 1) == 1)
							&& (getWall(x, y, 3) == 1)) {
						flag = 4;
						kabeate_count++;
					} else {
						flag = 3;
					}
				}
			}
			if ((x > 0) && (getWall(x, y, 4) == 0)) {
				if (step_Map[x - 1][y] <= step) {
					step = step_Map[x - 1][y];
					flag = 0;
				}
			}

		}

		if (flag == 0) { //北向き時の直進条件
			wallcontorol_flag=1;
			maintainmaxspeed180();
			//move(0, 180);
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
		} else if (flag == 2) {		//北向き時の左折条件
			wallcontorol_flag = 1;
			slalom_left90();
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);

		} else if (flag == 1) {				//北向き時の右折条件
			wallcontorol_flag = 1;
			slalom_right90();
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
		}else if ((flag == 4)&&(kabeate_count>=kabeate_per_blind_alley)&&(kabeate_per_blind_alley!=0)) {				//尻当て
			kabeate_blind_alley();
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
			kabeate_count=0;

		} else {
			wallcontorol_flag = 1;
			turnleft180();
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
		}

	}

}
