/*
 * com_spi_m328p.c
 *
 * Created: 07.12.2021 13:16:52
 *  Author: skliardev
 */
#include "../../libs/spi.h"

void spi_init() {
	/* SPI Master FCPU/32 setup falling and /SS, MOSI, SCK as out */	
	DDRB = (1<<PINB2 | 1<<PINB3 | 1<<PINB5);
	SPCR = (1<<SPE | 1<<MSTR | 1<<CPHA | 1<<SPR1);
	SPSR = (1<<SPI2X);
}

void spi_shift_output(uint8_t val) {
	SPDR = val;
	while(!(SPSR & 1<<SPIF)) {}
}

void spi_chip_select(pinlvl_t val) {
	switch(val) {
		case HIGH:
			PORTB |= (1<<PINB2);
			break;
		case LOW:
			PORTB &= ~(1<<PINB2);
			break;
	}
}