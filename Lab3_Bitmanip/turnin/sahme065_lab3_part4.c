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
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char input;
	unsigned char lower;
	unsigned char upper;
    /* Insert your solution below */
    while (1) {
	    input = PINA;
	    lower = PINA & 0x0f;
	    upper = PINA & 0xF0;

	    PORTB = upper >> 4;
	    PORTC = lower << 4;
	
    }
    return 1;
}
