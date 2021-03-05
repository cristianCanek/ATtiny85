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
        while( 1 ) {
            PORTB ^= ( 1 << PINB0 );
            _delay_ms( 1000 );
        }
    }

    return 0;
}


/* -------------------------- FUNCTIONS DEFINITION -------------------------- */

/* Configuration routine. */
uint8_t config() {
    DDRB |= ( 1 << PINB0 ); /* Set pin PB1 as OUTPUT */

    return (uint8_t) 0;
}