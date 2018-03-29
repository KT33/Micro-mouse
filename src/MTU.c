#include "iodefine.h"
#include "MTU.h"
#include "variable.h"

void interrupt_mtu20(void) { //右モータ

	MTU20.TSR.BIT.TGFA = 0; //フラグクリアp186
	MTU20.TGRA = 196349.54 * diameter
			/ (speed + control_amount + (83.0 * omega_l * 3.14 / (2 * 180))
					- (83.0 * omega_r * 3.14 / (2 * 180)));
	//-(83.0*omega/2)
}

void interrupt_mtu21(void) { //左モーター

	MTU21.TSR.BIT.TGFA = 0; //フラグクリアp186
	MTU21.TGRA = 196349.54 * diameter
			/ (speed - control_amount - (83.0 * omega_l * 3.14 / (2 * 180))
					+ (83.0 * omega_r * 3.14 / (2 * 180)));
	//+(83.0*omega/2)
}

void initMTU(void) { //右が0左が1ch
	STB.CR4.BIT._MTU2 = 0; //省電力モード解除
	PFC.PECRL1.BIT.PE1MD = 1; //ピンの設定（MTU2）
	PFC.PECRL2.BIT.PE5MD = 1;
	PFC.PEIORL.BIT.B1 = 1; //ピンの設定（PE1）
	PFC.PEIORL.BIT.B5 = 1;
	MTU20.TCR.BIT.TPSC = 0; //カウントのタイミングを設定(MPΦ/１でカウント)　p161
	MTU21.TCR.BIT.TPSC = 0;
	MTU20.TCR.BIT.CKEG = 0; //立ち上がりエッジでカウントに設定　p159
	MTU21.TCR.BIT.CKEG = 0;
	MTU20.TCR.BIT.CCLR = 1; //TGRAでTCNTクリア p160
	MTU21.TCR.BIT.CCLR = 1; //TGRAでTCNTクリア
	MTU20.TIOR.BIT.IOB = 2; //初期出力0でTGRBで1出力 p167
	MTU21.TIOR.BIT.IOB = 2;
	MTU20.TGRA = 55000; //TGRAの初期値（ほぼ最大値65000）
	MTU21.TGRA = 55000;
	MTU20.TGRB = 300; //TGRBの初期値
	MTU21.TGRB = 300;
	MTU20.TIER.BIT.TGIEA = 1; //TGIAによる割り込みを許可
	MTU21.TIER.BIT.TGIEA = 1;
	INTC.IPRD.BIT._MTU20G = 0xe;
	INTC.IPRD.BIT._MTU21G = 0xd;
	MTU20.TMDR.BIT.MD = 3; //PWMモード2に設定
	MTU21.TMDR.BIT.MD = 3;
	MTU2.TSTR.BIT.CST0 = 0; //カウントスタート
	MTU2.TSTR.BIT.CST1 = 0;

}
