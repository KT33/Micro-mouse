#include "iodefine.h"
#include  "AD.h"
#include "variable.h"
#include "stdlib.h"

void initAD(void) {
	STB.CR4.BIT._AD1 = 0; //省電力モード解除　p599
	AD1.ADCR.BIT.ADST = 0; //AD変換中断  p441
	AD1.ADCSR.BIT.ADCS = 0; //１サイクルスキャンモード　p440
	AD1.ADCSR.BIT.TRGE = 0; //トリガによる開始は無効　p439
	AD1.ADCSR.BIT.CKSL = 0; //クロックセレクト　p440
	AD1.ADCSR.BIT.ADIE = 0; //AD変換インタラプトイネーブル　p439
	AD1.ADCSR.BIT.ADM = 0; //シングルモードに設定　p440
	AD1.ADCSR.BIT.CH = 0; //チャンネルセレクト

	STB.CR4.BIT._AD0 = 0; //省電力モード解除　p599
	AD0.ADCR.BIT.ADST = 0; //AD変換中断  p441
	AD0.ADCSR.BIT.ADCS = 0; //１サイクルスキャンモード　p440
	AD0.ADCSR.BIT.TRGE = 0; //トリガによる開始は無効　p439
	AD0.ADCSR.BIT.CKSL = 0; //クロックセレクト　p440
	AD0.ADCSR.BIT.ADIE = 0; //AD変換インタラプトイネーブル　p439
	AD0.ADCSR.BIT.ADM = 0; //シングルモードに設定　p440
	AD0.ADCSR.BIT.CH = 0; //チャンネルセレクト
}

void allAD(void) {
	int i;

//	SEN_l = 0;
//	SEN_lf = 0;
//	SEN_r = 0;
//	SEN_rf = 0;

	PA.DRL.BIT.B13 = 0; //左(senLED)
//	for(i=0;i<500;i++){
//	}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 0; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始

	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_l = AD1.ADDR4 >> 6;

	PA.DRL.BIT.B13 = 1; //左(senLED)
	for (i = 0; i < 500; i++) {
	}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 0; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始

	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_l -= AD1.ADDR4 >> 6;

	PA.DRL.BIT.B13 = 0; //左(senLED)

	PA.DRL.BIT.B12 = 0; //左前(senLED)
//	for(i=0;i<500;i++){
//		}

	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 1; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_lf = AD1.ADDR5 >> 6;

	PA.DRL.BIT.B12 = 1; //左前(senLED)
	for (i = 0; i < 500; i++) {
	}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 1; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_lf -= AD1.ADDR5 >> 6;

	PA.DRL.BIT.B12 = 0; //左前(senLED)

	PA.DRL.BIT.B15 = 0; //右前(senLED)
//	for(i=0;i<500;i++){
//		}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 2; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_rf = AD1.ADDR6 >> 6;

	PA.DRL.BIT.B15 = 1; //右前(senLED)
	for (i = 0; i < 500; i++) {
	}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 2; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_rf -= AD1.ADDR6 >> 6;
	PA.DRL.BIT.B15 = 0; //右前(senLED)
	PA.DRL.BIT.B14 = 0; //右(senLED)
//	for(i=0;i<500;i++){
//		}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 3; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_r = AD1.ADDR7 >> 6;

	PA.DRL.BIT.B14 = 1; //右(senLED)
	for (i = 0; i < 500; i++) {
	}
	AD1.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD1.ADCSR.BIT.CH = 3; //チャンネル選択
	AD1.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD1.ADCSR.BIT.ADF == 0) {
	}
	AD1.ADCSR.BIT.ADF = 0;

	SEN_r -= AD1.ADDR7 >> 6;

	PA.DRL.BIT.B14 = 0; //右(senLED)

	AD0.ADCR.BIT.ADST = 0; //AD変換中断(待機)
	AD0.ADCSR.BIT.CH = 0; //チャンネル選択
	AD0.ADCR.BIT.ADST = 1; //AD変換開始
	while (AD0.ADCSR.BIT.ADF == 0) {
	}
	AD0.ADCSR.BIT.ADF = 0;

	batt = AD0.ADDR0 >> 6;

	SEN_r = abs(SEN_r);
	SEN_l = abs(SEN_l);
	SEN_lf = abs(SEN_lf);
	SEN_rf = abs(SEN_rf);

//
//	if (SEN_f < 0) {
//		SEN_f = 0;
//	}
//	if (SEN_r < 0) {
//		SEN_r = 0;
//	}
//	if (SEN_l < 0) {
//		SEN_l = 0;
//	}

	//SEN_l_before5=SEN_l_before4;
	//SEN_l_before4=SEN_l_before3;
	SEN_l_before3 = SEN_l_before2;
	SEN_l_before2 = SEN_l_before1;
	SEN_l_before1 = SEN_l;

	//SEN_r_before5=SEN_r_before4;
	//SEN_r_before4=SEN_r_before3;
	SEN_r_before3 = SEN_r_before2;
	SEN_r_before2 = SEN_r_before1;
	SEN_r_before1 = SEN_r;
	SEN_f = SEN_lf + SEN_rf;

//	if (SEN_f < 0) {
//		SEN_f = 0;
//	}
//	if (SEN_r < 0) {
//		SEN_r = 0;
//	}
//	if (SEN_l < 0) {
//		SEN_l = 0;
//	}
	//以上AD変換
}
