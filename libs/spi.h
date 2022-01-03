/*
 * spi.h
 *
 * Created: 03.01.2022 10:31:17
 *  Author: skliardev
 */ 

#ifndef SPI_H_
#define SPI_H_

/* Types */
typedef enum _e_pinlvl pinlvl_t;

/* Funcs */
extern void spi_init();
extern void spi_chip_select(pinlvl_t val);
extern void spi_shift_output(uint8_t val);

/* Data types and structs */
enum _e_pinlvl {
	HIGH,
	LOW,
};

#endif /* SPI_H_ */