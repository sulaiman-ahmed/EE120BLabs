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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char count;
	unsigned char tmpA;
	unsigned char tmpB;
    /* Insert your solution below */
    while (1) {
	    count = 0x00;
	    tmpA = PINA;
	    tmpB = PINB;

	    for(unsigned char i = 0; i < 8; i++) {
		if(tmpA == 0x01) {
			count++;
		}
		if(tmpB == 0x01) {
			count++;
		}
		tmpA = tmpA >> 1;
		tmpB = tmpB >> 1;	
	    }
	    PORTC = count;
	
    }
    return 1;
}
