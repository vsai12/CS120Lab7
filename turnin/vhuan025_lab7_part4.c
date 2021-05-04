/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	//DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	unsigned short MAX = 512;
	unsigned short light = MAX / 8;
    /* Insert your solution below */
    while (1) {
	    unsigned short x = ADC;
	    //unsigned char b = (char)x;
	    //unsigned char d = (char)(x >> 8);
	    //PORTB = b;
	    if(x >= light)
	    	PORTB = 0x01;
	    if (x >= light * 2)
		PORTB |= 0x02;
	    if (x >= light * 3)
		PORTB |= 0x04;
	    if (x >= light * 4)
                PORTB |= 0x08;
            if (x >= light * 5)
                PORTB |= 0x10;
	    if (x >= light * 6)
                PORTB |= 0x20;
            if (x >= light * 7)
                PORTB |= 0x40;
	    if(x >= light * 8)
		PORTB |= 0x80;

    }
    return 1;
}
