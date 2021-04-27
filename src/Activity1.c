#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "Activity1.h"

#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0



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