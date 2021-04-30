/**
 * @file Activity4.c
 * @author Vivek Ashar
 * @brief To send the temperture data to another MCU(Car's dashboard) via USART
 * @version 0.1
 * @date 2021-04-30
 *
 * @copyright Copyright (c) 2021
 *
 */


#include <avr/io.h>

#include <avr/interrupt.h>

#include "Activity4.h"


#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0
#define heater PB1
#define F_CPU 16000000UL
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*0x16UL)-1)



void make_string(char *a)
{
	uint8_t i=0;
	while(a[i]!='\0') /* runs till end of character */
	{
		write_usart(a[i]);
		i++;
	}
	write_usart(176); /* ascii value of degree(˚)  */
	write_usart('C');
	write_usart('\n');
}


/**
 * @brief To write the 8-bit data to be tranmitted via USART on the transmitter buffer
 *
 * @param data the dataframe to be transmitted
 */

void write_usart(char data)
{
    while(!(UCSR0A&(1<<UDRE0))){} // NULL loop - waiting for the successful transfer of the previous 8-bits

    UDR0=data; //Writing data to USART transmitter Buffer

}


