/**
 * simple code for rotary encode and launchpad ti msp430
 * In turn one step CW toggle LED2.
 * In turn one step CCW toggle LED1.
 * I'm use this encoder https://www.sparkfun.com/products/9117
 *
 * Set interrupt on ENCODER_A. In interrupt check ENCODER_B and determinate rotation.
 *
 * @author Little Piggy
 * This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 */

#include <msp430.h>
#include "rotary-encoder.h"

#define LED1 BIT0
#define LED2 BIT6

/**
 * function call on CCW rotation, modify code but don't rename it!
 */
void stepCCW(){
	P1OUT ^= LED1; //toogle led1
}

/**
 * function call on CW rotation, modify code but don't rename it!
 */
void stepCW(){
	P1OUT ^= LED2; //toogle led2
}

int main(void) {
	WDTCTL = WDTPW + WDTHOLD;
	P1DIR |= LED1 + LED2;
	P1OUT &= ~(LED1 + LED2);

	encoderInit();

	_BIS_SR(LPM4_bits + GIE); //set low power mode 4

}
