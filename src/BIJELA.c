/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  BIJELA                                 */
/*      FILE         :  BIJELA.c                               */
/*      DESCRIPTION  :  Main Program                           */
/*      CPU SERIES   :  RX600                                  */
/*      CPU TYPE     :  RX631                                  */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
//#include "typedefine.h"
#include "iodefine.h"
#include "variable.h"
#include "machine.h"
#include "other.h"
#include "CMT.h"
#include "AD.h"
#include "Clock.h"
#include "SPI.h"
#include "MTU.h"
#include "speaker.h"
#include "Moter.h"

//PCKBは50Mhz

void main() {
	int i;

	Clock_Settting();
	LED_Setting();
	init_sci1();
	init_cmt0();
	init_AD();
	init_SPI();
	init_speaker();
	init_gyro();
	init_Encoder();
	init_Moter_PWM();

	FAN = 1;
	while (1) {
		AD_all();
		Battery_Check();
		while (1) {
			gyro_flag = 1;

			Moter_Stby=1;
			Moter_L_IN1=0;
			Moter_L_IN2=1;
			Moter_R_IN1=1;
			Moter_R_IN2=0;


//			myprintf("%f\n", angle*360.0/(2*3.14));
//			HPB(120,1);
//			for (i = 0; i < 3; i++) {
//				UI_LED1 = 1;
//				UI_LED2 = 0;
//				UI_LED3 = 1;
//				RIGHTWING = 0;
//				LEFTEING = 1;
//				RIGHTFRONT = 1;
//				CENTERFRONT = 0;
//				wait_time(500);
//				UI_LED1 = 0;
//				UI_LED2 = 1;
//				UI_LED3 = 0;
//				RIGHTWING = 1;
//				LEFTEING = 0;
//				RIGHTFRONT = 0;
//				CENTERFRONT=1;
//				wait_time(500);
//			}
//			UI_LED1 = 0;
//			UI_LED2 = 0;
//			UI_LED3 = 0;
//			RIGHTWING = 0;
//			LEFTEING = 0;
//			RIGHTFRONT = 0;
//			CENTERFRONT = 0;
//			wait_time(500);
//			for(i=0;i<3;i++){
//				UI_LED1=1;
//				wait_time(200);
//				UI_LED1=0;
//				UI_LED2=1;
//				wait_time(200);
//				UI_LED2=0;
//				UI_LED3=1;
//				wait_time(200);
//				UI_LED3=0;
//				RIGHTWING=1;
//				wait_time(200);
//				RIGHTWING=0;
//				RIGHTFRONT=1;
//				wait_time(200);
//				RIGHTFRONT=0;
//				CENTERFRONT=1;
//				wait_time(200);
//				CENTERFRONT=0;
//				LEFTEING=1;
//				wait_time(200);
//				LEFTEING=0;
//
//			}
		}

//		test_gyro();
//		gyro_r = communicate_gyro(0x80,0x0);
//		myprintf("WHO AM I %d\n", gyro_r);

//		speaker_on(A_4,8.0,120);
//
//		KirbyDance(180,1);
//		UI_LED1=1;
//		wait_time(1000);
	}
}

