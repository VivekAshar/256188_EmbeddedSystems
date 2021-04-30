/**
 * @file Activity1.c
 * @author Vivek Ashar
 * @brief To turn on the heater's LED if the switch and the push-button are pressed
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <avr/io.h>

#include <avr/interrupt.h>


#include "Activity1.h"

#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0
#define heater PB1
#define F_CPU 16000000UL
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*0x16UL)-1)



/**
 * @brief if both the switch and push-button are pressed, then turn on the heater's LED
 *
 * @return int
 */

int turn_on()
{
        if(!(PIND&(1<<Switch)) && !(PINB&(1<<pushbutton)))
        {
            PORTC|=(1<<LED);
            return 1;
        }

        /* any other condition, turn the LED off */
        else
        {
            PORTC&=~(1<<LED);
            return 0;
        }
}
