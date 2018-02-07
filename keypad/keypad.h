#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdint.h>
#include "pin_config.h"
#define ALL_LINES	    (((LINE0_PIN&(1U<<LINE0))>>LINE0)\
					   &((LINE1_PIN&(1U<<LINE1))>>LINE1)\
					   &((LINE2_PIN&(1U<<LINE2))>>LINE2)\
					   &((LINE3_PIN&(1U<<LINE3))>>LINE3))
		
//functions prototype
void KeypadInit(void);
uint8_t KeypadScan(void);





#endif	//KEYPAD_H_