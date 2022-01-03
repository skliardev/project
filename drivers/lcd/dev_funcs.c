/*
 * dev_funcs.c
 *
 * Created: 03.01.2022 12:44:48
 *  Author: skliardev
 */ 
#include "../../libs/lcd.h"


void lcd_clean(uint8_t val) {
	uint8_t addr[2] = {0x80, 0x80};
	for(uint8_t vstr = 0; vstr < 32; ++vstr) {
		addr[0] = 0x80 | vstr;
		lcd_send(P_INSTRUCTION, M_WRITE_BYTE_SEQ, 2, addr);
		for(uint8_t hstr = 0; hstr < 32; ++hstr) {
			lcd_send(P_DATA, M_WRITE_BYTE, val, 0);
		}
	}
}