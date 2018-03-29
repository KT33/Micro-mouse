/*
 * pass.c
 *
 *  Created on: 2017/11/13
 *      Author: takao keisuke
 */

#include "iodefine.h"
#include "variable.h"
#include "adachi.h"
#include "run.h"
#include "CMT.h"
#include "righthand.h"
#include "pass.h"
#include "serial.h"

void shortest_knowwayfast(int goal_x, int goal_y, int mode) { //mode 0:nomal 1:charenge
	int i = 0, j = 0;
	float i_distance, more_maxspeed, more_accel;
	volatile short pass_knowway[500];
	int straight_count = 0;

	for (i = 0; i < 500; i++) {
		pass_knowway[i] = 0;
	}
	if (mode == 1) {
		i_distance = 177.0;
		more_accel = 3000;
		more_maxspeed = 2100;
	} else {
		i_distance = 176.88;
		more_accel = 2000;
		more_maxspeed = 2000;
	}

	adachi_map(goal_x, goal_y);
	make_pass(goal_x, goal_y);

	for (i = 0; pass[i] != 0; i++) {
		if (pass[i] == 1) {
			straight_count++;
		} else if (straight_count != 0) {
			pass_knowway[j] = straight_count + 10;
			straight_count = 0;
			j++;
			pass_knowway[j] = pass[i];
			j++;
		} else {
			pass_knowway[j] = pass[i];
			j++;
		}
	}
	if (pass[i - 1] == 1) {
		pass_knowway[j] = straight_count + 10;
	}

//	for(i=0;pass_knowway!=0;i++){
//		myprintf("pass_knowway:%d\n",pass_knowway[i]);
//	}
//	while (PA.DRL.BIT.B8 == 1) {
//
//	}
	go_ketuate();
	coordinate();

	for (i = 0; pass_knowway[i] != 0; i++) {
		if (PA.DRL.BIT.B8 == 0) {
			return_mode_select_flag = 1;
			break;
		}
		if (pass_knowway[i] == 1) {
			//L7seg_direction();
			maintainmaxspeed180();
			coordinate();
			Off_7seg();
		} else if (pass_knowway[i] == 2) {
			//L7seg_direction();
			if (mode == 1) {
				turnright90_fast();
			} else {
				turnright90();
			}
			coordinate();
			Off_7seg();
		} else if (pass_knowway[i] == 3) {
			//L7seg_direction();
			if (mode == 1) {
				turnleft90_fast();
			} else {
				turnleft90();
			}
			coordinate();
			Off_7seg();
		} else if (pass_knowway[i] == 11) {
			if (mode == 1) {
				more_run(i_distance * 1, more_maxspeed, more_accel);
				coordinate();
			} else {
				maintainmaxspeed180();
				coordinate();
			}

		} else if (pass_knowway[i] == 12) {
			if (mode == 1) {
				more_run(i_distance * 2, more_maxspeed, more_accel);
				coordinate();
				coordinate();
			} else {
				maintainmaxspeed180();
				maintainmaxspeed180();
				coordinate();
				coordinate();
			}
		} else if (pass_knowway[i] == 13) {
			more_run(i_distance * 3, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 14) {
			more_run(i_distance * 4, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 15) {
			more_run(i_distance * 5, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 16) {
			more_run(i_distance * 6, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 17) {
			more_run(i_distance * 7, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 18) {
			more_run(i_distance * 8, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 19) {
			more_run(i_distance * 9, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 20) {
			more_run(i_distance * 10, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 21) {
			more_run(i_distance * 11, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 22) {
			more_run(i_distance * 12, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 23) {
			more_run(i_distance * 13, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 24) {
			more_run(i_distance * 14, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 25) {
			maintainmaxspeed180();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 26) {
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
		}
	}
	kabeate_goal();

}

void slalom_shortest(int goal_x, int goal_y) {
	int i = 0;
//	x = 0;
//	y = 0;
//	direction = 1;
	adachi_map(goal_x, goal_y);
	make_pass(goal_x, goal_y);

	go_ketuate();
	coordinate();

	for (i = 0; pass[i] != 0; i++) {
		if (PA.DRL.BIT.B8 == 0) {
			return_mode_select_flag = 1;
			break;
		}
		if (pass[i] == 1) {
			//L7seg_direction();
			maintainmaxspeed180();
			coordinate();
			Off_7seg();
		} else if (pass[i] == 2) {
			//L7seg_direction();
			slalom_right90();
			coordinate();
			Off_7seg();
		} else if (pass[i] == 3) {
			//L7seg_direction();
			slalom_left90();
			coordinate();
			Off_7seg();
		}
	}
	kabeate_goal();
}

void shortest(int goal_x, int goal_y) {
	int i = 0;
//	x = 0;
//	y = 0;
//	direction = 1;
	adachi_map(goal_x, goal_y);
	make_pass(goal_x, goal_y);

	go_ketuate();
	coordinate();

	for (i = 0; pass[i] != 0; i++) {
		if (PA.DRL.BIT.B8 == 0) {
			return_mode_select_flag = 1;
			break;
		}
		if (pass[i] == 1) {
			//L7seg_direction();
			maintainmaxspeed180();
			coordinate();
			Off_7seg();
		} else if (pass[i] == 2) {
			//L7seg_direction();
			turnright90();
			coordinate();
			Off_7seg();
		} else if (pass[i] == 3) {
			//L7seg_direction();
			turnleft90();
			coordinate();
			Off_7seg();
		}
	}
	kabeate_goal();
}

void make_pass( goal_x, goal_y) {
	int i, step, flag;
	int x_box, y_box, direction_box;
	x_box = x;
	y_box = y;
	direction_box = direction;

	for (i = 0; i < 500; i++) {
		pass[i] = 5;
	}
//	direction = 1;

//	output_Walldate();
//	output_lookedWalldate();
	for (i = 0; i < 17; i++) {
		row_box[i] = row[i];
		column_box[i] = column[i];
	}

//	for (i = 0; i < 17; i++) {
//		row[i] = (row[i] | (~row_reached[i]));
//		column[i] = (column[i] | (~column_reached[i]));
//	}
//	output_Walldate();

	adachi_map(goal_x, goal_y);
	i = 0;
	coordinate();
	while (1) {
		//flag = 0;
		if (x == goal_x && y == goal_y) {
			pass[i] = 0;

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
						//	kabeate_count++;
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
						//	kabeate_count++;
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
						//	kabeate_count++;
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
						//	kabeate_count++;
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
			pass[i] = 1;
			coordinate();
		} else if (flag == 2) {		//北向き時の左折条件
			pass[i] = 3;
			direction += 3;
			if (direction > 4) {
				direction -= 4;
			}
			coordinate();
		} else if (flag == 1) {				//北向き時の右折条件
			pass[i] = 2;
			direction++;
			if (direction > 4) {
				direction -= 4;
			}
			coordinate();
			//addWall();
		}

		i++;
	}
	for (i = 0; i < 17; i++) {
		row[i] = row_box[i];
		column[i] = column_box[i];
	}
	x = x_box;
	y = y_box;
	direction = direction_box;
//	output_Walldate();
}

void shortest_slalom_knowwayfast(int goal_x, int goal_y, int mode) {//mode 0:nomal 1:charenge
	int i = 0, j = 0;
	float i_distance, more_maxspeed, more_accel;
	volatile short pass_knowway[500];
	int straight_count = 0;
//	x = 0;
//	y = 0;
//	direction = 1;
	for (i = 0; i < 500; i++) {
		pass_knowway[i] = 0;
	}
	if (mode == 1) {
		i_distance = 177.0;
		more_accel = 3000;
		more_maxspeed = 2100;
	} else {
		i_distance = 176.88;
		more_accel = 2000;
		more_maxspeed = 2000;
	}

	adachi_map(goal_x, goal_y);
	make_pass(goal_x, goal_y);

	for (i = 0; pass[i] != 0; i++) {
		if (PA.DRL.BIT.B8 == 0) {
			return_mode_select_flag = 1;
			break;
		}
		if (pass[i] == 1) {
			straight_count++;
		} else if (straight_count != 0) {
			pass_knowway[j] = straight_count + 10;
			straight_count = 0;
			j++;
			pass_knowway[j] = pass[i];
			j++;
		} else {
			pass_knowway[j] = pass[i];
			j++;
		}
	}
	if (pass[i - 1] == 1) {
		pass_knowway[j] = straight_count + 10;
	}

	go_ketuate();
	coordinate();

	for (i = 0; pass_knowway[i] != 0; i++) {
		if (pass_knowway[i] == 1) {
			//L7seg_direction();
			L7seg_1();
			maintainmaxspeed180();
			coordinate();
			Off_7seg();
		} else if (pass_knowway[i] == 2) {
			//L7seg_direction();
			L7seg_2();
			slalom_right90();
			coordinate();
			Off_7seg();
		} else if (pass_knowway[i] == 3) {
			//L7seg_direction();
			L7seg_3();
			slalom_left90();
			coordinate();
			Off_7seg();
		} else if (pass_knowway[i] == 11) {
			maintainmaxspeed180();
			coordinate();
		} else if (pass_knowway[i] == 12) {
			if (mode == 1) {
				more_run(i_distance * 2, more_maxspeed, more_accel);
				coordinate();
				coordinate();
			} else {
				maintainmaxspeed180();
				maintainmaxspeed180();
				coordinate();
				coordinate();
			}
		} else if (pass_knowway[i] == 13) {
			more_run(i_distance * 3, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 14) {
			more_run(i_distance * 4, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 15) {
			more_run(i_distance * 5, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 16) {
			more_run(i_distance * 6, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 17) {
			more_run(i_distance * 7, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 18) {
			more_run(i_distance * 8, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 19) {
			more_run(i_distance * 9, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 20) {
			more_run(i_distance * 10, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 21) {
			more_run(i_distance * 11, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 22) {
			more_run(i_distance * 12, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 23) {
			more_run(i_distance * 13, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 24) {
			more_run(i_distance * 14, more_maxspeed, more_accel);
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 25) {
			maintainmaxspeed180();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
		} else if (pass_knowway[i] == 26) {
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
			maintainmaxspeed180();
			maintainmaxspeed180();
			coordinate();
			coordinate();
		}
	}
	kabeate_goal();
}
