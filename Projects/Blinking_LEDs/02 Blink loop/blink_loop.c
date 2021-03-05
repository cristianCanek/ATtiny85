/* -------------------------------- INCLUDES -------------------------------- */
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>


/* -------------------------- FUNCTIONS DECLARATION ------------------------- */
uint8_t config();


/* ------------------------------ MAIN ROUTINE ------------------------------ */
int main() {

    uint8_t index = PINB0;
    
    if( (uint8_t) 0 == config() ) {
        while( 1 ) {/* Turn-off all the leds. */

            PORTB &= ( 0 << PINB0 );
            PORTB &= ( 0 << PINB1 );
            PORTB &= ( 0 << PINB2 );
            PORTB &= ( 0 << PINB3 );
            PORTB &= ( 0 << PINB4 );

            if( index <= PINB4 ) {
                PORTB ^= ( 1 << index );
                index++;
            }

            if( index > PINB4 ) {
                index = PINB0;
            }

            _delay_ms( 200 );
        }
    }

    return 0;
}


/* -------------------------- FUNCTIONS DEFINITION -------------------------- */

/* Configuration routine. */
uint8_t config() {
    DDRB |= ( 1 << PINB0 ); /* Set pin PB1 as OUTPUT */
    DDRB |= ( 1 << PINB1 ); /* Set pin PB2 as OUTPUT */
    DDRB |= ( 1 << PINB2 ); /* Set pin PB3 as OUTPUT */
    DDRB |= ( 1 << PINB3 ); /* Set pin PB4 as OUTPUT */
    DDRB |= ( 1 << PINB4 ); /* Set pin PB5 as OUTPUT */

    return (uint8_t) 0;
}