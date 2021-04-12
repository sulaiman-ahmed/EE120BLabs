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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char fuelLevel;
	unsigned char lights;
    /* Insert your solution below */
    while (1) {
	    fuelLevel = PINA;
	    lights= 0x00;

	    if(fuelLevel == 2 || fuelLevel == 1) {
		    lights = lights | 0x20;
	    } else if (fuelLevel == 4 || fuelLevel == 3) {
		    lights = lights | 0x30;
	    } else if (fuelLevel == 6 || fuelLevel ==  5) {
		    lights = lights | 0x38;
	    } else if (fuelLevel == 9 || fuelLevel == 8 || fuelLevel == 7) {
		    lights = lights | 0x3c;
	    } else if (fuelLevel == 10 || fuelLevel == 11 || fuelLevel == 12) {
		    lights = lights | 0x3E;
	    } else if (fuelLevel == 13 || fuelLevel == 14 || fuelLevel == 15) {
		    lights = lights | 0x3F;
	    }
	    if(fuelLevel <= 4) {
		    lights = lights | 0x40;
	    }

	    PORTC = lights;
	
    }
    return 1;
}
