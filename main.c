/**
 * @file main.c
 * @author Vivek Ashar
 * @brief Project for seat-heating application in a car
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>

#include <avr/interrupt.h>

#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"


#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0
#define heater PB1
#define F_CPU 16000000UL
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*0x16UL)-1)

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

    DDRB|=(1<<heater); // Settting D6 as OUTPUT - connection to HEATER



    // Supplying 5V to the input pins internally as they are in default pull-up configuration

    PORTD|=(1<<Switch); // SUPPYING 5V TO D0 INTERNALLY

    PORTB|=(1<<pushbutton); // SUPPYING 5V TO B0 INTERNALLY


}


/**
 * @brief To configure all the regiters required for the successful operation of ADC to convert the analog o/p of temperature sensor to digital
 *
 * @note ch is the channel of ADC to be used
 */


void configure_adc(uint8_t ch)
{
    ADMUX|=(1<<REFS0); // Aref=AVcc

    ADCSRA|=(1<<ADEN); // Enable ADC

    ADCSRA|=(1<<ADPS0); // Prescaler divisor for ADC = 128

    // Telling the ADC to take analog output of the temperature sensor from pin temp = C2

    ADMUX&=0XF8; // Clearing MUX2, MUX1, MUX0 bitS

    ch=ch&0b00000111; //Acquiring the input pin of temperature sensor as a binary number

    ADMUX|=ch; // Masking the input pin of temperature sensor on ADMUX resgister's MUX2, MUX1, MUX0 bitS
}


/**
 * @brief To configure all the regiters required for the successful production of PWM according to the o/p of the temperature sensor
 *
 */

void configure_pwm()
{
    TCCR1A|=(1<<COM1A1); // non-inverting mode for PWM gneration;

    TCCR1A|=(1<<WGM11) | (1<<WGM10); // fast PWM - 10 bit mode with TOP = 0x03ff for TCCR1A

    TCCR1B|=(1<<WGM12); // fast PWM - 10 bit mode with TOP = 0x03ff for TCCR1B

    TCCR1B|=(1<<CS11) | (1<<CS10); // Prescalar divisor for timer = 64

}


/**
 * @brief To configure all the registers of USART for successful ransmission of 8-bit data
 *
 */

void configure_usart()
{
    UBRR0H=(BAUDRATE>>8);

    UBRR0L=BAUDRATE;

    UCSR0B|= (1<<RXEN0)|(1<<TXEN0); //Enable Rx and Tx

    UCSR0B|= (1<<RXCIE0)|(1<<TXCIE0); //Enable receiver and transmitter complete interrupt

    UCSR0C|=(1<<UMSEL00);  //Select USART Mode of operation - Asynchronous

    UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01); // Dataframe size = 8-bits
}



/**
 * @brief main function where the execution of code starts
 *
 * @return return 0 if the program excutes successfully
 */


int main(void)
{
    // sei();

    configure_pins();

    configure_adc(temp);

    configure_pwm();

    configure_usart();

    while(1)
    {
       int led_state;

       led_state=turn_on();

       if (led_state)
       {
           uint16_t temp_value=readADC();

           int temp_display=dispense_heat(temp_value);

           if (temp_display==20)
           {
               make_string("20");
            }

           else if (temp_display==25)
           {
               make_string("25");
            }

           else if (temp_display==29)
           {
               make_string("29");
            }

           else if (temp_display==33)
           {
               make_string("33");
            }


       }
    }

    return 0;
}
