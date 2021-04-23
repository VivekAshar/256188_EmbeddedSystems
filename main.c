/*
 */

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD&=~(1<<0); // SETTING D0 AS INPUT - heater's switch

    DDRB&=~(1<<0); // SETTING B0 AS INPUT - PushButton for driver's detection on seat

    PORTD|=(1<<0); // SUPPYING 5V TO D0 INTERNALLY

    PORTB|=(1<<0); // SUPPYING 5V TO B0 INTERNALLY

    DDRC|=(1<<0); // SETTING



    while(1)
    {
        if(!(PIND&(1<<0)) && !(PINB&(1<<0)))
        {
            PORTC|=(1<<0);
            _delay_ms(20);
        }
        else
        {
            PORTC&=~(1<<0);
            _delay_ms(20);
        }
    }

    return 0;
}
