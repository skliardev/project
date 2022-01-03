/*
 * project001.c
 *
 * Created: 06.12.2021 16:55:08
 * Author : skliardev
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "libs/system.h"
#include "libs/lcd.h"

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

int main(void)
{
	cpu_init(CLK_DIV_1);
	lcd_initialization();
	lcd_clean(0);
	g_print_str(0, 0, "Dima");
	g_print_str(0, 1, "Ksusha");
	g_print_str(0, 1, "Vladimir");
	while(1) {
		
    }
}

