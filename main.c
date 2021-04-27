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
#include <avr/interrupt.h>

#include "Activity1.h"
#include "Activity2.h"

#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0

    /**
     * @brief configuring the GPIO pins as input or output
     * 
     */

void configure_pins()
{
    DDRD&=~(1<<Switch); // SETTING D0 AS INPUT - heater's switch
    
    DDRB&=~(1<<pushbutton); // SETTING B0 AS INPUT - PushButton for driver's detection on seat

    DDRC&=~(1<<temp); // Setting C2 as the input pin for analog temperature sensor

    DDRC|=(1<<LED); // Setting C0 AS OUTPUT - connection to LED 



    // Supplying 5V to the input pins internally as they are in default pull-up configuration

    PORTD|=(1<<Switch); // SUPPYING 5V TO D0 INTERNALLY

    PORTB|=(1<<pushbutton); // SUPPYING 5V TO B0 INTERNALLY


}


/**
 * @brief To configure all the regiters required for the successful operation of ADC to convert the analog o/p of temperature sensor to digital
 * 
 */


void configure_adc(uint8_t ch)
{
    ADMUX|=(1<<REFS0); // Aref=AVcc
    
    ADCSRA|=(1<<ADEN); // Enable ADC
    
    ADCSRA|=(1<<ADPS0); // Prescaler divisor = 128

    // Telling the ADC to take analog output of the temperature sensor from pin temp = C2
    
    ADMUX&=0XF8; // Clearing MUX2, MUX1, MUX0 bitS
    
    ch=ch&0b00000111; //Acquiring the input pin of temperature sensor as a binary number
    
    ADMUX|=ch; // Masking the input pin of temperature sensor on ADMUX resgister's MUX2, MUX1, MUX0 bitS
}


/**
 * @brief main function where the execution of code starts
 * 
 * @return return 0 if the program excutes successfully
 */


int main(void)
{
    sei();
    configure_pins();
    configure_adc(temp);

    while(1)
    {
        int led_state;
        led_state=turn_on();
        if (led_state)
        {
            uint16_t temp_value=readADC();    
        }
    }

    return 0;
}
