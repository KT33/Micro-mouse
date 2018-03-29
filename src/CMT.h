/*
 * CMT.h
 *
 *  Created on: 2017/09/18
 *      Author: takao keisuke
 */

#ifndef CMT_H_
#define CMT_H_




void interrupt_cmt0(void);
void initCMT(void);
void wait_Time(volatile int ms);

#endif /* CMT_H_ */
