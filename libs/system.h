/*
 * system.h
 *
 * Created: 03.01.2022 9:54:23
 *  Author: skliardev
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

/* Types */
typedef enum _e_clock clock_t;

/* Funcs */
extern void cpu_init(clock_t prescaler);

/* Data types and structs */
enum _e_clock {
	CLK_DIV_1,
	CLK_DIV_2,
	CLK_DIV_4,
	CLK_DIV_8,
	CLK_DIV_16,
	CLK_DIV_32,
	CLK_DIV_64,
	CLK_DIV_128,
	CLK_DIV_256,
};

#endif /* SYSTEM_H_ */