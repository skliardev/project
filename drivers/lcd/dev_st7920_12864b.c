/*
 * dev_lcd_st7920_12864b.c
 *
 * Created: 07.12.2021 13:17:31
 *  Author: skliardev
 */ 
#include "../../libs/lcd.h"
#include "../../libs/spi.h"

void lcd_byte_output(package_t type, uint8_t val) {
	switch(type) {
		case P_INSTRUCTION:
			spi_shift_output(0b11111000);
			break;
		case P_DATA:
			spi_shift_output(0b11111010);
			break;
	}
	spi_shift_output(val & 0xf0);
	spi_shift_output(val << 4);
	if(type == P_INSTRUCTION) _delay_us(30);
}

void lcd_send(package_t type, message_t message, uint8_t val, const void* args) {
	spi_chip_select(HIGH);
	switch(message) {
		case M_WRITE_BYTE:
			lcd_byte_output(type, val);
			break;
		case M_WRITE_BYTE_SEQ:
			while( val > 0 ) {
				lcd_byte_output(type, *((uint8_t*)args));
				args++;
				val--;
			}
			break;
		case M_WRITE_BYTE_SEQ_PTR:
			while( val > 0 ) {
				lcd_byte_output(type, pgm_read_byte_near(args));
				args++;
				val--;
			}
			break;
	}
	spi_chip_select(LOW);
}

void lcd_initialization() {
	spi_init();
	lcd_send(P_INSTRUCTION, M_WRITE_BYTE_SEQ_PTR, STARTCONFIG_WORD_SIZE, STARTCONFIG_WORD_ARRAY);
}