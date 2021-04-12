/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #3  Exercise #1
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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0x01; PORTB = 0x00;

	unsigned char tmpB = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char finalB = 0x00;
	unsigned short totalWeight = 0x0000;
    /* Insert your solution below */
    while (1) {
	    tmpD = PIND;
	    tmpB = PINB;
	    finalB = 0x00;
	    totalWeight = (tmpD << 1) | (tmpB & 0x01);
	    if(totalWeight >= 0x0046) {
		finalB = 0x02;
	    } else if (totalWeight > 0x0005) {
		 finalB = 0x03;
	    } else {
		finalB = 0x00;
	    }
	    PORTB = finalB;
	
    }
    return 1;

}
