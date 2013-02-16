/**
 * @author Little Piggy
 * This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 */

#include "rotary-encoder.h"

/**
 * Inicialization rotary encoder
 * enable internal pull-up resistor
 *
 * @return void
 */
void encoderInit(){

	P1OUT |= (ENCODER_A+ENCODER_B);	//enable pull-up resistor
	P1REN |= ENCODER_A+ENCODER_B;	//enable pull-up resistor
	P1IFG &= ~ENCODER_A;			//clear interupt flag
	P1IE |= ENCODER_A;				//enable interupt for encoder

	__enable_interrupt();
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	if(P1IN & ENCODER_B){ //one step CCW
		stepCCW(); //call function for step CCW
	}else{ //one step CW
		stepCW(); //call function for step CW
	}

	P1IFG &= ~ENCODER_A;	//clear interupt flag
}
