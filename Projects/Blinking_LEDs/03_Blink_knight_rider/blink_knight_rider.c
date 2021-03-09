/* -------------------------------- INCLUDES -------------------------------- */
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>


/* ---------------------------- CUSTOM DATATYPES ---------------------------- */

/* Helps to handle the blinking direction. */
typedef enum BLINK_DIRECTION {
    forward  = 0,
    backward = 1
} BLINK_DIRECTION;


/* -------------------------- FUNCTIONS DECLARATION ------------------------- */
uint8_t config();


/* ------------------------------ MAIN ROUTINE ------------------------------ */
int main() {

    uint8_t index = PB0;
    BLINK_DIRECTION direction = forward;
    
    if( (uint8_t) 0 == config() ) {
        while( 1 ) {
            
            /* Turn-off all the LEDs. */
            PORTB = 0;

            if( forward == direction ) {
                PORTB ^= ( 1 << index );
                index++;
                
                if( index > PB4 ) {
                    index = PB3;
                    direction = backward;
                }
            }
            else {
                PORTB ^= ( 1 << index );
                
                if( PB0 == index ) {
                    index = PB1;
                    direction = forward;
                }
                else {
                    index--;
                }
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