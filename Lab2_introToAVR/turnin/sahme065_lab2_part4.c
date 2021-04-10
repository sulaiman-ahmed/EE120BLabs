/*	Author: Sulaiman Ahmed
 *  Partner(s) Name: N/A
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #4
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
    DDRC = 0x00; PORTC = 0xFF; 
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;
    unsigned char totalWeight = 0x00;
    signed char difference = 0x00;

    while(1){
	    tmpA = PORTA;
	    tmpB = PORTB;
	    tmpC = PORTC;
	    totalWeight = 0x00;
	    tmpD = 0x00;

	    totalWeight = tmpA + tmpB + tmpC;
	    
	    if(tmpA > tmpC) {
	    	difference = tmpA - tmpC;
	    } else {
		difference = tmpC - tmpA;
	    }

	    if (totalWeight > 140) {
		tmpD = tmpD | 0x01;
	    }

	    totalWeight = totalWeight >> 2;

	    if(difference > 80) {
		tmpD = tmpD | 0x02;
	    }
	    
	    tmpD = totalWeight | tmpD;
	    PORTD = tmpD;
    }    
    return 0;
}
