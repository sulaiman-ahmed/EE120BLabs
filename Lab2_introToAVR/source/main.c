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
    unsigned char tmpDD = 0x00;
    unsigned char totalWeight = 0x00;
    unsigned char difference = 0x00;

    while(1){
	    tmpA = PINA;
	    tmpB = PINB;
	    tmpC = PINC;
	    totalWeight = 0x00;
	    tmpD = 0x00;
	    tmpDD = 0x00;

	    totalWeight = tmpA + tmpB + tmpC;
	    
	    if(totalWeight > 0x008C) {
		    tmpD = 0x01;
	    } else {
		    tmpD = 0x00;
	    }

	    if(tmpA > tmpC) {
		    if(tmpA - tmpC > 0x50) {
			tmpDD = 0x02;	    
		    }
	    } else {
		    if(tmpC - tmpA > 0x50) {
			tmpDD = 0x02;
		    }
	    }
	    difference = (totalWeight & 0x00FC) | tmpD | tmpDD;
	    PORTD = difference;
    }    
    return 0;
}
