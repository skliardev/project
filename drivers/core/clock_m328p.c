/*
 * clock.c
 *
 * Created: 03.01.2022 9:56:05
 *  Author: skliardev
 */ 

#include "../../libs/system.h"

void cpu_init(clock_t prescaler) {
	CLKPR = 0x80;
	switch(prescaler) {
		case CLK_DIV_1:
			CLKPR = 0;
			break;
		case CLK_DIV_2:
			CLKPR = 1;
			break;
		case CLK_DIV_4:
			CLKPR = 2;
			break;
		case CLK_DIV_8:
			CLKPR = 3;
			break;
		case CLK_DIV_16:
			CLKPR = 4;
			break;
		case CLK_DIV_32:
			CLKPR = 5;
			break;
		case CLK_DIV_64:
			CLKPR = 6;
			break;
		case CLK_DIV_128:
			CLKPR = 7;
			break;
		case CLK_DIV_256:
			CLKPR = 8;
			break;
	}
}