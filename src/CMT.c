#include  "iodefine.h"
#include "CMT.h"
#include "variable.h"

void interrupt_cmt0(void) {

	CMT0.CMCSR.BIT.CMF = 0;

	g_cnt_wait++;
	distance += 0.001 * speed;
	degree_r += omega_r * 0.001;
	degree_l += omega_l * 0.001;
	//status  0速度維持 1加速 2減速
	if (status == 1) {
		speed += accel * 0.001;
	} else if (status == 2) {
		speed -= accel * 0.001;
	} else if (status == 0) {

	}
	if (status_slalom_r == 1) {
		omega_r += alpha * 0.001;
	} else if (status_slalom_r == 2) {
		omega_r -= alpha * 0.001;
	} else if (status_slalom_r == 0) {

	}
	if (status_slalom_l== 1) {
		omega_l += alpha * 0.001;
	} else if (status_slalom_l == 2) {
		omega_l -= alpha * 0.001;
	} else if (status_slalom_l == 0) {

	}
	allAD();
 	wallContorol();

//	date[i]=control_amount;
}

void initCMT(void)	//CMT割込の設定
{
	STB.CR4.BIT._CMT = 0;	//CMTスタンバイ解除

//  (1)コンペアマッチタイマスタートレジスタ（CMSTR）
	CMT.CMSTR.BIT.STR0 = 0;	// ステータスレジスタ　0：カウント停止, 1：カウント開始
//  (2)コンペアマッチタイマコントロール／ステータスレジスタ（CMCSR）
	CMT0.CMCSR.BIT.CMIE = 1;     //割り込みイネーブル許可
	CMT0.CMCSR.BIT.CKS = 0;     //1/8
	CMT0.CMCSR.BIT.CMF = 0;     //フラグをクリア
	CMT0.CMCOR = 3124;  //割り込み周期 (25MHz/8 0から始まるよ～）
	INTC.IPRJ.BIT._CMT0 = 0xf;  //割り込み優先度(15)
	CMT.CMSTR.BIT.STR0 = 1;	// ステータスレジスタ　0：カウント停止, 1：カウント開始

}

void wait_Time(volatile int ms) {
	g_cnt_wait = 0;
	CMT.CMSTR.BIT.STR0 = 1;
	while (g_cnt_wait <= ms) {

	}
//	CMT.CMSTR.BIT.STR0 = 0;
}
