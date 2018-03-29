//
#ifndef INCLUDED_SERIAL
#define INCLUDED_SERIAL


#include "iodefine.h"
//注意：iodefine.hの多重インクルードが起こりえます
//インクルードガードをつけるようにしてください
#include <stdio.h>
#include <stdarg.h>

void init_sci1(void);
void put1byte(char );
void putnbyte(char *,int );
int myprintf(const char *, ...);



#endif

/*
How to use.SHIRIAL
//	init_sci1();
//	myprintf("%d\n\r", value);
*/
