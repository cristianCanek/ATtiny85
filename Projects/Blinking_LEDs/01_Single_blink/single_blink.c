/* -------------------------------- INCLUDES -------------------------------- */
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>


/* -------------------------- FUNCTIONS DECLARATION ------------------------- */
uint8_t config();


/* ------------------------------ MAIN ROUTINE ------------------------------ */
int main() {
    if( (uint8_t) 0 == config() ) {
        while( 1 ) {
            /* Change the state of the LED from on-to-off and vice versa. */
            PORTB ^= ( 1 << PB0 );
            _delay_ms( 1000 );
        }
    }

    return 0;
}


/* -------------------------- FUNCTIONS DEFINITION -------------------------- */

/* Configuration routine. */
uint8_t config() {
    /* Set Pin 1 as OUTPUT */
    DDRB  = ( 1 << DDB0 );

    return (uint8_t) 0;
}