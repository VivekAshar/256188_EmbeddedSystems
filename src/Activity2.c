/**
 * @file Activity2.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "Activity2.h"

#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0


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
