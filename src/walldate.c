/*
 * walldate.c
 *
 *  Created on: 2017/09/28
 *      Author: takao keisuke
 */

#include "iodefine.h"
#include  "walldate.h"
#include "variable.h"
#include "stdio.h"
#include  "serial.h"

void addWall(void) {
	unsigned short new;
	if (direction == 1) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= y;
			column[x] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= y;
			column[x + 1] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= x;
			row[y + 1] |= new;
		}
	} else if (direction == 2) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= x;
			row[y + 1] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= x;
			row[y] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= y;
			column[x + 1] |= new;
		}
	} else if (direction == 3) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= y;
			column[x + 1] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= y;
			column[x] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= x;
			row[y] |= new;
		}
	} else if (direction == 4) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= x;
			row[y] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= x;
			row[y + 1] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= y;
			column[x] |= new;
		}
	}
}

int getWall(int x_check, int y_check, int direction_check) { //(見たい座標のx,y,とその座標からの方角１～４壁があれば１
	int check_wall = 1;
	if (direction_check == 1) {
		check_wall <<= x_check;
		check_wall &= row[y_check + 1];
		if (check_wall != 0) {
			check_wall = 1;
		}
	} else if (direction_check == 2) {
		check_wall <<= y_check;
		check_wall &= column[x_check + 1];
		if (check_wall != 0) {
			check_wall = 1;
		}
	} else if (direction_check == 3) {
		check_wall <<= x_check;
		check_wall &= row[y_check];
		if (check_wall != 0) {
			check_wall = 1;
		}
	} else if (direction_check == 4) {
		check_wall <<= y_check;
		check_wall &= column[x_check];
		if (check_wall != 0) {
			check_wall = 1;
		}
	}
	return check_wall;
}

void output_Walldate(void) {
	int x_check, y_check;

/////////////////////////////////////////////////////////////
	for (y_check = 15; y_check >= 0; y_check--) {
		myprintf("+");
		for (x_check = 0; x_check < 16; x_check++) {
			if (getWall(x_check, y_check, 1) == 1) {
				myprintf("-----");
			} else {
				myprintf("     ");
			}
			myprintf("+");
		}
		myprintf("\n");
		for (x_check = 0; x_check < 16; x_check++) {
			if (getWall(x_check, y_check, 4) == 1) {
				myprintf("|");
			} else {
				myprintf(" ");
			}
			myprintf(" %3d ", step_Map[x_check][y_check]);
		}
		if (getWall(15, y_check, 2) == 1) {
			myprintf("|");
		} else {
			myprintf(" ");
		}
		myprintf("\n");
	}
	myprintf("+");
	for (x_check = 0; x_check < 16; x_check++) {
		if (getWall(x_check, y_check, 1) == 1) {
			myprintf("-----");
		} else {
			myprintf("     ");
		}
		myprintf("+");
	}
	myprintf("\n");

}

void restMap(void) {
	int i;
	for (i = 0; i < 16; i++) {
		column[i] = 0x0;
		row[i] = 0x0;
	}
	column[0] = 0xFFFF;
	row[0] = 0xFFFF;
	column[16] = 0xFFFF;
	row[16] = 0xFFFF;
	column[1] = 1;
}

void restReachedWall(void) {
	int i;
	for (i = 0; i < 16; i++) {
		column_reached[i] = 0x0;
		row_reached[i] = 0x0;
	}
	column_reached[0] = 0xFFFF;
	row_reached[0] = 0xFFFF;
	column_reached[16] = 0xFFFF;
	row_reached[16] = 0xFFFF;
	column_reached[1] = 1;
}

void add_lookedWall(void) {
	unsigned short new;
	if (direction == 1) {

		new = 1;
		new <<= y;
		column_reached[x] |= new;

		new = 1;
		new <<= y;
		column_reached[x + 1] |= new;

		new = 1;
		new <<= x;
		row_reached[y + 1] |= new;

	} else if (direction == 2) {

		new = 1;
		new <<= x;
		row_reached[y + 1] |= new;

		new = 1;
		new <<= x;
		row_reached[y] |= new;

		new = 1;
		new <<= y;
		column_reached[x + 1] |= new;

	} else if (direction == 3) {

		new = 1;
		new <<= y;
		column_reached[x + 1] |= new;

		new = 1;
		new <<= y;
		column_reached[x] |= new;

		new = 1;
		new <<= x;
		row_reached[y] |= new;

	} else if (direction == 4) {

		new = 1;
		new <<= x;
		row_reached[y] |= new;

		new = 1;
		new <<= x;
		row_reached[y + 1] |= new;

		new = 1;
		new <<= y;
		column_reached[x] |= new;

	}
}

void output_lookedWalldate(void) {
	int x_check, y_check;

/////////////////////////////////////////////////////////////
	for (y_check = 15; y_check >= 0; y_check--) {
		myprintf("+");
		for (x_check = 0; x_check < 16; x_check++) {
			if (get_lookedWall(x_check, y_check, 1) == 1) {
				myprintf("-----");
			} else {
				myprintf("     ");
			}
			myprintf("+");
		}
		myprintf("\n");
		for (x_check = 0; x_check < 16; x_check++) {
			if (get_lookedWall(x_check, y_check, 4) == 1) {
				myprintf("|");
			} else {
				myprintf(" ");
			}
			myprintf(" %3d ", step_Map[x_check][y_check]);
		}
		if (get_lookedWall(15, y_check, 2) == 1) {
			myprintf("|");
		} else {
			myprintf(" ");
		}
		myprintf("\n");
	}
	myprintf("+");
	for (x_check = 0; x_check < 16; x_check++) {
		if (get_lookedWall(x_check, y_check, 1) == 1) {
			myprintf("-----");
		} else {
			myprintf("     ");
		}
		myprintf("+");
	}
	myprintf("\n");

}

int get_lookedWall(int x_check, int y_check, int direction_check) { //(見たい座標のx,y,とその座標からの方角１～４壁があれば１
	int check_wall = 1;

	if (direction_check == 1) {
		check_wall <<= x_check;
		check_wall &= row_reached[y_check + 1];
		if (check_wall != 0) {
			check_wall = 1;
		}
	} else if (direction_check == 2) {
		check_wall <<= y_check;
		check_wall &= column_reached[x_check + 1];
		if (check_wall != 0) {
			check_wall = 1;
		}
	} else if (direction_check == 3) {
		check_wall <<= x_check;
		check_wall &= row_reached[y_check];
		if (check_wall != 0) {
			check_wall = 1;
		}
	} else if (direction_check == 4) {
		check_wall <<= y_check;
		check_wall &= column_reached[x_check];
		if (check_wall != 0) {
			check_wall = 1;
		}
	}
	return check_wall;
}

void addWall_interim(void) {
	unsigned short new;
	int i;
	for (i = 0; i < 16; i++) {
		column_interim[i] = 0x0;
		row_interim[i] = 0x0;
	}
	column_interim[0] = 0xFFFF;
	row_interim[0] = 0xFFFF;
	column_interim[16] = 0xFFFF;
	row_interim[16] = 0xFFFF;
	column_interim[1] = 1;
	if (direction == 1) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= y;
			column_interim[x] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= y;
			column_interim[x + 1] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= x;
			row_interim[y + 1] |= new;
		}
	} else if (direction == 2) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= x;
			row_interim[y + 1] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= x;
			row_interim[y] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= y;
			column_interim[x + 1] |= new;
		}
	} else if (direction == 3) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= y;
			column_interim[x + 1] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= y;
			column_interim[x] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= x;
			row_interim[y] |= new;
		}
	} else if (direction == 4) {
		if (SEN_l > e_SEN_l) {
			new = 1;
			new <<= x;
			row_interim[y] |= new;
		}
		if (SEN_r > e_SEN_r) {
			new = 1;
			new <<= x;
			row_interim[y + 1] |= new;
		}
		if (SEN_lf + SEN_rf > e_SEN_f) {
			new = 1;
			new <<= y;
			column_interim[x] |= new;
		}
	}
}

//void add_lookedWall(void) {
//
//	unsigned short new;
//	if (direction == 1) {
//
//		new = 1;
//		new <<= y;
//		column_reached_interim[x] |= new;
//
//		new = 1;
//		new <<= y;
//		column_reached_interim[x + 1] |= new;
//
//		new = 1;
//		new <<= x;
//		row_reached_interim[y + 1] |= new;
//
//	} else if (direction == 2) {
//
//		new = 1;
//		new <<= x;
//		row_reached_interim[y + 1] |= new;
//
//		new = 1;
//		new <<= x;
//		row_reached_interim[y] |= new;
//
//		new = 1;
//		new <<= y;
//		column_reached_interim[x + 1] |= new;
//
//	} else if (direction == 3) {
//
//		new = 1;
//		new <<= y;
//		column_reached_interim[x + 1] |= new;
//
//		new = 1;
//		new <<= y;
//		column_reached_interim[x] |= new;
//
//		new = 1;
//		new <<= x;
//		row_reached_interim[y] |= new;
//
//	} else if (direction == 4) {
//
//		new = 1;
//		new <<= x;
//		row_reached_interim[y] |= new;
//
//		new = 1;
//		new <<= x;
//		row_reached_interim[y + 1] |= new;
//
//		new = 1;
//		new <<= y;
//		column_reached_interim[x] |= new;
//
//	}
//}

//void restReachedMap(void) {
//	int i;
//	for (i = 0; i < 16; i++) {
//		reached[i] = 0x0;
//	}
//}
