#include "iodefine.h"

void senLEDon(void) {
	PA.DRL.BIT.B12 = 1; //左前(senLED)
	PA.DRL.BIT.B13 = 1; //左(senLED)
	PA.DRL.BIT.B14 = 1; //右(senLED)
	PA.DRL.BIT.B15 = 1; //右前(senLED)
}

void senLEDoff(void) {
	PA.DRL.BIT.B12 = 0; //左前(senLED)
	PA.DRL.BIT.B13 = 0; //左(senLED)
	PA.DRL.BIT.B14 = 0; //右(senLED)
	PA.DRL.BIT.B15 = 0; //右前(senLED)
}

void L7seg_0(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 0;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 1;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 1;
}
void L7seg_1(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 0;
	PE.DRL.BIT.B10 = 0;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 0;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 0;
}
void L7seg_2(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 0;
	PE.DRL.BIT.B11 = 1;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 0;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 1;
}
void L7seg_3(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 9;
	PE.DRL.BIT.B10 = 0;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 1;
}
void L7seg_4(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 0;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 0;
}
void L7seg_5(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 0;
	PE.DRL.BIT.B15 = 1;
}
void L7seg_6(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 1;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 0;
	PE.DRL.BIT.B15 = 0;
}
void L7seg_7(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 0;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 0;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 1;
}
void L7seg_8(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 1;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 1;
}

void L7seg_9(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 1;
	PE.DRL.BIT.B14 = 1;
	PE.DRL.BIT.B15 = 1;
}

void L7seg_E(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 1;
	PE.DRL.BIT.B12 = 1;
	PE.DRL.BIT.B13 = 0;
	PE.DRL.BIT.B14 = 0;
	PE.DRL.BIT.B15 = 1;
}

void L7seg_F(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 1;
	PE.DRL.BIT.B10 = 1;
	PE.DRL.BIT.B11 = 1;
	PE.DRL.BIT.B12 = 0;
	PE.DRL.BIT.B13 = 0;
	PE.DRL.BIT.B14 = 0;
	PE.DRL.BIT.B15 = 1;
}

void O7seg(void) {
	PE.DRL.BIT.B7 = 1;
	PE.DRL.BIT.B9 = 0;
	PE.DRL.BIT.B10 = 0;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 0;
	PE.DRL.BIT.B13 = 0;
	PE.DRL.BIT.B14 = 0;
	PE.DRL.BIT.B15 = 0;
}

void Off_7seg(void) {
	PE.DRL.BIT.B7 = 0;
	PE.DRL.BIT.B9 = 0;
	PE.DRL.BIT.B10 = 0;
	PE.DRL.BIT.B11 = 0;
	PE.DRL.BIT.B12 = 0;
	PE.DRL.BIT.B13 = 0;
	PE.DRL.BIT.B14 = 0;
	PE.DRL.BIT.B15 = 0;
}
