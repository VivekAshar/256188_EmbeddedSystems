/**
 * @file main.c
 * @author Vivek Ashar
 * @brief Project to Take two inputs in the form of a switch and a push-botton and operate an LED
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief main function where the execution of code starts
 * 
 * @return return 0 if the program excutes successfully
 */


int main(void)
{

    /**
     * @brief Setting the direction of the pins D0 and BO as input 
     * 
     * @note SETTING D0 AS INPUT - heater's switch
     * 
     * @note SETTING B0 AS INPUT - PushButton for driver's detection on seat
     * 
     */

   

    DDRD&=~(1<<0);



    DDRB&=~(1<<0);

    /**
     * @brief Supplying 5V to the input D0 and B0 pins internally as they are in default pull-up configuration
     * 
     * @note SUPPYING 5V TO D0 INTERNALLY
     * 
     * @note SUPPYING 5V TO B0 INTERNALLY
     * 
     */



    PORTD|=(1<<0); 


    PORTB|=(1<<0); 

    /**
     * @brief Setting the direction of the pin C0 as output
     * 
     * @note  Setting C0 AS OUTPUT - connection to LED 
     * 
     */

    DDRC|=(1<<0); 



    while(1)
    {
        /* if both the switch and push-button are pressed, then turn on the LED */ 
        if(!(PIND&(1<<0)) && !(PINB&(1<<0)))
        {
            PORTC|=(1<<0);
            _delay_ms(20);
        }

        /* any other condition, turn the LED off */ 
        else
        {
            PORTC&=~(1<<0);
            _delay_ms(20);
        }
    }

    return 0;
}
