/**
 * @file Activity3.c
 * @author Vivek Ashar
 * @brief To generate a pwm signal based on the output of the ADC
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>

#include <avr/interrupt.h>


#include "Activity3.h"

#define Switch PD0
#define pushbutton PB0
#define temp PC2
#define LED PC0
#define heater PB1
#define F_CPU 16000000UL
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*0x16UL)-1)


/**
 * @brief This function generates the PWM of the required duty cycle, according to the o/p of temperature sensor, for the heater to operate
 *
 * @param temperature temperature recorded by the temperature sensor
 * @return uint8_t to return the emperature to be communicated to another ECU(car dashbord) for display purpose
 */

int dispense_heat(uint16_t temperature)
{
    if (0<=temperature && temperature<=205)
    {
        OCR1A=205;
        return 20;
    }

    else if (206<=temperature && temperature<=505)
    {
        OCR1A=410;
        return 25;
    }

    else if (506<=temperature && temperature<=705)
    {
        OCR1A=716;
        return 29;
    }

    else if (706<=temperature && temperature<=1023)
    {
        OCR1A=972;
        return 33;
    }

}
