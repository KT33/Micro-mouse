/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  mouce1                                 */
/*      FILE         :  mouce1.c                               */
/*      DESCRIPTION  :  Main Program                           */
/*      CPU SERIES   :  SH-2                                   */
/*      CPU TYPE     :  SH7125                                 */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/

#include "iodefine.h"
#include "stdio.h"
#include "serial.h"
#include "AD.h"
#include "7seg.h"
#include "MTU.h"
#include  "CMT.h"
#include "other.h"
#include "run.h"
#include "wallcontrol.h"
#include "righthand.h"
#include "variable.h"
#include "slalom.h"
#include "adachi_slalome.h"



void main(void) {
// マウス製作頑張っていきましょー！！

//(mode,i_distance(or)degree) 0前進 1右折 2左折 3後退
	int large_mode_flag = 0;

	CPG.FRQCR.BIT.IFC = 1;
	goal_x = 4;
	goal_y = 6;
	mode_flag = 0;
	initCMT();
	init_sci1();
	initAD();
	initMTU();
	allPFC();
	restMap();
	PE.DRL.BIT.B2 = 1; //MD_Reset
	wait_Time(1000);
	PE.DRL.BIT.B2 = 0;

	batterycheck();
	O7seg();



	while (1) {
		//myprintf("FND\n");
		//restMap();
		if (PA.DRL.BIT.B8 == 0) {
			if (large_mode_flag == 0) {
				chattering();
				large_mode_flag = 1;
				PB.DR.BIT.B1 = 1;
				PB.DR.BIT.B2 = 1;
				mode_flag = 10;
			} else if (large_mode_flag == 1) {
				chattering();
				large_mode_flag = 0;
				PB.DR.BIT.B1 = 0;
				PB.DR.BIT.B2 = 0;
				mode_flag = 0;
			}
		}

		if (large_mode_flag == 0) {
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 0) {
				chattering();
				L7seg_1();
				mode_flag = 1;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_1();

					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 1) {
				chattering();
				L7seg_2();
				mode_flag = 2;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_2();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_2();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 2) {
				chattering();
				L7seg_3();
				mode_flag = 3;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_3();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_3();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 3) {
				chattering();
				L7seg_4();
				mode_flag = 4;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_4();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_4();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 4) {
				chattering();
				L7seg_5();
				mode_flag = 5;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_5();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_5();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 5) {
				chattering();
				L7seg_6();
				mode_flag = 6;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_6();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_6();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 6) {
				chattering();
				L7seg_7();
				mode_flag = 7;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_7();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_7();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 7) {
				chattering();
				L7seg_8();
				mode_flag = 8;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_8();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_8();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 8) {
				chattering();
				L7seg_9();
				mode_flag = 9;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_9();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_9();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 9) {
				chattering();
				L7seg_0();
				mode_flag = 0;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_0();
							wait_Time(500);
							L7seg_0();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_0();
					}
				}
			}
		} else if (large_mode_flag == 1) {
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 10) {
				chattering();
				L7seg_1();
				mode_flag = 11;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_1();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_11();

					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 11) {
				chattering();
				L7seg_2();
				mode_flag = 12;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_2();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_12();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 12) {
				chattering();
				L7seg_3();
				mode_flag = 13;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_3();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_13();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 13) {
				chattering();
				L7seg_4();
				mode_flag = 14;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_4();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_14();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 14) {
				chattering();
				L7seg_5();
				mode_flag = 15;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_5();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_15();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 15) {
				chattering();
				L7seg_6();
				mode_flag = 16;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_6();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_16();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 16) {
				chattering();
				L7seg_7();
				mode_flag = 17;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_7();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_17();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 17) {
				chattering();
				L7seg_8();
				mode_flag = 18;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_8();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_18();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 18) {
				chattering();
				L7seg_9();
				mode_flag = 19;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_9();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_19();
					}
				}
			}
			if (PA.DRL.BIT.B6 == 0 && mode_flag == 19) {
				chattering();
				L7seg_0();
				mode_flag = 10;
				while (PA.DRL.BIT.B6 == 1) {
					if (PA.DRL.BIT.B7 == 0) {
						for (i = 0; i < 3; i++) {
							L7seg_1();
							wait_Time(500);
							L7seg_0();
							wait_Time(500);
							Off_7seg();
							wait_Time(500);
						}
						mode_10();
					}
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//
//if (PA.DRL.BIT.B6 == 0 && flag == 0) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//
//	L7seg_1();
//	flag = 1;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 1) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_2();
//	flag = 2;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 2) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_3();
//	flag = 3;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 3) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_4();
//	flag = 4;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 4) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_5();
//	flag = 5;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 5) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_6();
//	flag = 6;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 6) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_7();
//	flag = 7;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 7) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_8();
//	flag = 8;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 8) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_9();
//	flag = 9;
//}
//if (PA.DRL.BIT.B6 == 0 && flag == 9) {
//	i = 0;
//	while (i < chatt) {
//		i++;
//	}
//	while (PA.DRL.BIT.B6 == 0) {
//	}
//	while (i < chatt) {
//		i++;
//	}
//	L7seg_0();
//	flag = 0;
//}
//
//}

//	output_Walldate();
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);
//	wait_Time(1000);
//	move(1,90.05);

//stop();

//	while (1) {
//		allAD();
//		myprintf("SEN_lf=%6d SEN_l=%6d SEN_r=%6d SEN_rf=%6d\n", SEN_lf, SEN_l,
//				SEN_r, SEN_rf);
//	}

//	SEN_l = 1000;
//	SEN_r = 1000;
//	SEN_lf = 1000;
//	direction=0;
//	for (x = 15; x >=0; x--) {
//		for (y = 15; y >=0; y--) {
//			addWall();
//			myprintf("(x,y)=(%d.%d) column=%d row=%d \n", x, y,column,row);
//		}
