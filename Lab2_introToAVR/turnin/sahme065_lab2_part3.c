/*	Author: Sulaiman Ahmed
 *  Partner(s) Name: N/A
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF;
    PORTC = 0x00;

    unsigned char count = 0x00;
    unsigned char tmpA = 0x00;

    while(1){
	    count = 0x00;
	    tmpA = PINA;
	    tmpA = tmpA & 0x0F;
	    unsigned char i = 0;
	    for(i = 0; i < 4; i++) {
		if((tmpA & 0x01) == 0x00) {
			count = count + 1;
		}
		tmpA = tmpA >> 1;
	    }
	    if(count == 0x00) {
		PORTC = count | 0x80;
	    } else {
	    	PORTC = count;
	    }
    }
    return 0;
}
