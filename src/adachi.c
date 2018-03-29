/*
 * adachi.c
 *
 *  Created on: 2017/09/30
 *      Author: takao keisuke
 */

#include "iodefine.h"
#include "variable.h"
#include "adachi.h"
#include "run.h"
#include "CMT.h"
#include "righthand.h"


void adachi_fast(int goal_x, int goal_y,int kabeate_per_blind_alley) {
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
			wallcontorol_flag = 1;
			maintainmaxspeed180();
			//move(0, 180);
			coordinate();
			addWall();
			add_lookedWall();
			adachi_map(goal_x, goal_y);
		} else if (flag == 2) {		//北向き時の左折条件
			wallcontorol_flag = 1;
			turnleft90();
			coordinate();
			addWall();
			add_lookedWall();
			adachi_map(goal_x, goal_y);

		} else if (flag == 1) {				//北向き時の右折条件
			wallcontorol_flag = 1;
			turnright90();
			coordinate();
			addWall();
			add_lookedWall();
			adachi_map(goal_x, goal_y);
		} else if ((flag == 4)&&(kabeate_count>=kabeate_per_blind_alley)&&(kabeate_per_blind_alley!=0)) {				//尻当て
			kabeate_blind_alley();
			coordinate();
			addWall();
			add_lookedWall();
			adachi_map(goal_x, goal_y);
			kabeate_count=0;

		} else {
			wallcontorol_flag = 1;
			turnleft180();
			coordinate();
			addWall();
			add_lookedWall();
			adachi_map(goal_x, goal_y);
		}
	}

}

////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void adachi_slow(int goal_x, int goal_y) {
	int flag = 0, i = 0, step;

	move(0, 90);
	//go90();
	coordinate();
	addWall();
	adachi_map(goal_x, goal_y);
	while (1) {
		adachi_map(goal_x, goal_y);
		flag = 0;
		if (x == goal_x && y == goal_y) {
			//stop90();
			move(0, 90);
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
					flag = 3;
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
					flag = 3;
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
					flag = 3;
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
					flag = 3;
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
			//maintainmaxspeed180();
			move(0, 180);
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
		} else if (flag == 2) {		//北向き時の左折条件
			wallcontorol_flag = 1;
			//stop90();
			move(0, 90);
			wait_Time(100);
			move(2, 88.9);
			wait_Time(100);
			//go90();
			move(0, 90);
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);

		} else if (flag == 1) {				//北向き時の右折条件
			wallcontorol_flag = 1;
			//stop90();
			move(0, 90);
			wait_Time(100);
			move(1, 88.95);
			wait_Time(100);
			//go90();
			move(0, 90);
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
		} else {
			wallcontorol_flag = 1;
			//stop90();
			move(0, 90);
			wait_Time(100);
			move(2, 177);
			wait_Time(100);
			//go90();
			move(0, 90);
			coordinate();
			addWall();
			adachi_map(goal_x, goal_y);
		}
	}

}



///////////////////////////////////////////////////////////////////
//		} else if (direction == 2) {
//			if ((step_Map[x + 1][y] <= step_Map[x - 1][y])
//					&& (step_Map[x + 1][y] <= step_Map[x][y + 1])
//					&& (step_Map[x + 1][y] <= step_Map[x][y - 1])
//					&& (SEN_lf + SEN_rf < e_SEN_f)) {				//東向き時の直進条件
//				//maintainmaxspeed180();
//				move(0, 180);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else if ((step_Map[x][y + 1] <= step_Map[x - 1][y])
//					&& (step_Map[x][y + 1] <= step_Map[x + 1][y])
//					&& (step_Map[x][y + 1] <= step_Map[x][y - 1])
//					&& (SEN_l < e_SEN_l)) {				//東向き時の左折条件
//				wallcontorol_flag = 1;
//				//	stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(2, 90);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else if ((step_Map[x][y - 1] <= step_Map[x - 1][y])
//					&& (step_Map[x][y - 1] <= step_Map[x][y + 1])
//					&& (step_Map[x][y - 1] <= step_Map[x + 1][y])
//					&& (SEN_r < e_SEN_r)) {		//東向き時の右折条件
//				wallcontorol_flag = 1;
//				//stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(1, 90);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else {
//				wallcontorol_flag = 1;
//				//stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(2, 179);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			}
////////////////////////////////////////////////////////////////////////////
//		} else if (direction == 3) {
//			if ((step_Map[x][y - 1] <= step_Map[x][y + 1])
//					&& (step_Map[x][y - 1] <= step_Map[x + 1][y])
//					&& (step_Map[x][y - 1] <= step_Map[x - 1][y])
//					&& (SEN_lf + SEN_rf < e_SEN_f)) {	//南向き時の直進条件
//				//maintainmaxspeed180();
//				move(0, 180);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else if ((step_Map[x + 1][y] <= step_Map[x][y + 1])
//					&& (step_Map[x + 1][y] <= step_Map[x - 1][y])
//					&& (step_Map[x + 1][y] <= step_Map[x][y - 1])
//					&& (SEN_l < e_SEN_l)) {
//				wallcontorol_flag = 1;
//				//	stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(2, 90);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else if ((step_Map[x - 1][y] < step_Map[x][y + 1])
//
//			&& (step_Map[x - 1][y] <= step_Map[x][y - 1])
//					&& (step_Map[x - 1][y] <= step_Map[x + 1][y])
//					&& (SEN_r < e_SEN_r)) {
//				wallcontorol_flag = 1;
//				//stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(1, 90);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else {
//				wallcontorol_flag = 1;
//				//stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(2, 179);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			}
//		} else if (direction == 4) {
//			if (((step_Map[x - 1][y] <= step_Map[x + 1][y])
//					&& (step_Map[x - 1][y] <= step_Map[x][y - 1])
//					&& (step_Map[x - 1][y] <= step_Map[x][y + 1])
//					&& (SEN_lf + SEN_rf < e_SEN_f))) {				//西向き時の直進条件
//				//maintainmaxspeed180();
//				move(0, 180);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else if ((step_Map[x][y - 1] <= step_Map[x + 1][y])
//					&& (step_Map[x][y - 1] <= step_Map[x - 1][y])
//					&& (step_Map[x][y - 1] <= step_Map[x][y + 1])
//					&& (SEN_l < e_SEN_l)) {				//西向き時の左折条件
//				wallcontorol_flag = 1;
//				//	stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(2, 90);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else if ((step_Map[x][y + 1] <= step_Map[x + 1][y])
//					&& (step_Map[x][y + 1] <= step_Map[x][y - 1])
//					&& (step_Map[x][y + 1] <= step_Map[x - 1][y])
//					&& (SEN_r < e_SEN_r)) {				//西向き時の右折条件
//				wallcontorol_flag = 1;
//				//stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(1, 90);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			} else {
//				wallcontorol_flag = 1;
//				//stop90();
//				move(0, 90);
//				wait_Time(100);
//				move(2, 179);
//				wait_Time(100);
//				//go90();
//				move(0, 90);
//				coordinate();
//				addWall();
//				adachi_map();
//			}
//		}
//		i++;
//	}
//}

void adachi_map(int goal_x, int goal_y) {
	int i, j, step = 0, flag = 1;
	int Q_top = 0, Q_low = 0;
	unsigned short Q[100];

	L7seg_0();
/////////////////////////////////////////////////
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			step_Map[i][j] = 255;
		}
	}
	step_Map[goal_x][goal_y] = 0;
//////////////////////////////////////////////////

//	while (flag == 1) {
//		flag = 0;
//
//				if (step_Map[i][j] == step) {
//					if ((getWall(i, j, 1) == 0) && (step_Map[i][j + 1] > step)
//							&& (j + 1 < 16)) {
//						step_Map[i][j + 1] = step + 1;
//						Q[Q_top]=i+16*(j+1);
//						flag = 1;
//					}
//					if ((getWall(i, j, 2) == 0) && (step_Map[i + 1][j] > step)
//							&& (i + 1 < 16)) {
//						step_Map[i + 1][j] = step + 1;
//						flag = 1;
//					}
//					if ((getWall(i, j, 3) == 0) && (step_Map[i][j - 1] > step)
//							&& ((j - 1) >= 0)) {
//						step_Map[i][j - 1] = step + 1;
//						flag = 1;
//					}
//					if ((getWall(i, j, 4) == 0) && (step_Map[i - 1][j] > step)
//							&& ((i - 1) >= 0)) {
//						step_Map[i - 1][j] = step + 1;
//						flag = 1;
//					}
//
//		}
//		step++;
//		Q_low++;
//
//	}

////////////////care///////////////care//////////////////////////////
	while (flag == 1) {
		flag = 0;
		for (i = 0; i < 16; i++) {
			for (j = 0; j < 16; j++) {
				if (step_Map[i][j] == step) {
					if ((getWall(i, j, 1) == 0) && (step_Map[i][j + 1] > step)
							&& (j + 1 < 16)) {
						step_Map[i][j + 1] = step + 1;
						flag = 1;
					}
					if ((getWall(i, j, 2) == 0) && (step_Map[i + 1][j] > step)
							&& (i + 1 < 16)) {
						step_Map[i + 1][j] = step + 1;
						flag = 1;
					}
					if ((getWall(i, j, 3) == 0) && (step_Map[i][j - 1] > step)
							&& ((j - 1) >= 0)) {
						step_Map[i][j - 1] = step + 1;
						flag = 1;
					}
					if ((getWall(i, j, 4) == 0) && (step_Map[i - 1][j] > step)
							&& ((i - 1) >= 0)) {
						step_Map[i - 1][j] = step + 1;
						flag = 1;
					}
				}
			}
		}
		step++;

	}

///////////////care//////////////////////care//////////////////care/////////
}
