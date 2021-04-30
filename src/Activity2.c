/**
 * @file Activity2.c
 * @author Vivek Ashar
 * @brief To take the analog output of the temperature sensor and digitalise it using ADC(analog-to-digital converter)
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>

#include <avr/interrupt.h>


#include "Activity2.h"

#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0
#define heater PB1
#define F_CPU 16000000UL
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*0x16UL)-1)

/**
 * @brief to read the analog o/p of the temperature sensor at pin temp=PC2 and convert it into a 10-bit binary number
 *
 * @return uint16_t
 */





uint16_t readADC()
{
    ADCSRA|=(1<<ADSC); // Start the conversion of the analog input at pin PC2

    while(!(ADCSRA & (1<<ADIF))); // NULL loop that keeps excuting until the analog-to-digital onversion is over

    ADCSRA&=~(1<<ADIF); // Clearing the ADIF interrupt flag that was raised after the completion of coversion

    return(ADC);

}
