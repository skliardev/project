/*
 * lcd.h
 *
 * Created: 03.01.2022 11:41:43
 *  Author: skliardev
 */ 

#ifndef LCD_H_
#define LCD_H_

#include <avr/pgmspace.h>
#include <util/delay.h>

#define STARTCONFIG_WORD_SIZE 2
static const char STARTCONFIG_WORD_ARRAY[] PROGMEM = {
	0x30,
	0x36
};

/* Types */
typedef enum _e_package package_t;
typedef enum _e_message message_t;

/* Funcs */
extern void lcd_init();
extern void lcd_byte_output(package_t type, uint8_t val);
extern void lcd_send(package_t type, message_t message, uint8_t val, const void* args);
extern void lcd_clean(uint8_t val); //dev_funcs.c

/* Data types and structs */
enum _e_package {
	P_INSTRUCTION,
	P_DATA,
};

enum _e_message {
	M_WRITE_BYTE,
	M_WRITE_BYTE_SEQ,
	M_WRITE_BYTE_SEQ_PTR,
};

#endif /* LCD_H_ */