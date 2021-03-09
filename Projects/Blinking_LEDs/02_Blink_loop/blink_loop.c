/* -------------------------------- INCLUDES -------------------------------- */
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>


/* -------------------------- FUNCTIONS DECLARATION ------------------------- */
uint8_t config();


/* ------------------------------ MAIN ROUTINE ------------------------------ */
int main() {

    uint8_t index = PB0;
    
    if( (uint8_t) 0 == config() ) {
        while( 1 ) {
            
            /* Turn-off all the LEDs. */
            PORTB = 0;

            /* Turn-on the corresponding LED. */
            PORTB ^= ( 1 << index );
            index++;

            if( index > PB4 ) {
                index = PB0;
            }

            _delay_ms( 200 );
        }
    }

    return 0;
}


/* -------------------------- FUNCTIONS DEFINITION -------------------------- */

/* Configuration routine. */
uint8_t config() {
    /* Set pins 1 to 5 direction as OUTPUTs. */
    DDRB = ( 1 << DDB4 )
         | ( 1 << DDB3 )
         | ( 1 << DDB2 )
         | ( 1 << DDB1 )
         | ( 1 << DDB0 );

    return (uint8_t) 0;
}