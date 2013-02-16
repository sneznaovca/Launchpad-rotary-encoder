#ifndef ENC_ROT_H_
#define ENC_ROT_H_

#include <msp430.h>

#define ENCODER_A BIT3 //rotary encoder pin A
#define ENCODER_B BIT5 //rotary encoder pin B
//pin C (usually in the middle) connect on ground

void encoderInit();

#endif // ENC_ROT_H_
