
#include "keypad.h"

/*
*Function name : keypad_init
*Parameters	   : void
*return		   : void
*purpose       : initialize keypad rows as output 
*				 and lines as input
*/
void keypad_init(void)
{
//set the rows direction as output
ROW0_DDR |=(1U<<ROW0);
ROW1_DDR |=(1U<<ROW1);
ROW2_DDR |=(1U<<ROW2);
ROW3_DDR |=(1U<<ROW3);
//set the line direction as input
LINE0_DDR &=~(1U<<LINE0);
LINE1_DDR &=~(1U<<LINE1);
LINE2_DDR &=~(1U<<LINE2);
LINE3_DDR &=~(1U<<LINE3);
//enable line pullup
LINE0_PULLUP |=(1U<<LINE0);
LINE1_PULLUP |=(1U<<LINE1);
LINE2_PULLUP |=(1U<<LINE2);
LINE3_PULLUP |=(1U<<LINE3);
//set the rows high
ROW0_PORT |=(1U<<ROW0);
ROW1_PORT |=(1U<<ROW1);
ROW2_PORT |=(1U<<ROW2);
ROW3_PORT |=(1U<<ROW3);
}


/*
*Function name : keypad_scan
*Parameters	   : void
*return		   : unsigned char
*purpose       : scan the keypad and return the pressed key 
*				and returns null if no key pressed
*/
uint8_t keypad_scan(void)
{
uint8_t row=0,input;
//loop on row 
	for(row=0;row<4;row++)
	{
	//set all row high
	ROW0_PORT |=(1<<ROW0);
	ROW1_PORT |=(1<<ROW1);
	ROW2_PORT |=(1<<ROW2);
	ROW3_PORT |=(1<<ROW3);
	//clear row number from iteration
	switch(row)
		{
		case 0:ROW0_PORT &=~(1<<ROW0);
				break;
		case 1:ROW1_PORT &=~(1<<ROW1);
				break;
		case 2:ROW2_PORT &=~(1<<ROW2);
				break;
		case 3:ROW3_PORT &=~(1<<ROW3);
				break;
		}
		//read the input
		input  = (LINE0_PIN&(1<<LINE0));
		input |= (LINE1_PIN&(1<<LINE1));
		input |= (LINE2_PIN&(1<<LINE2));
		input |= (LINE3_PIN&(1<<LINE3));
		
		//if it was input
		if(ALL_LINES != 1)
		{
			//wait till the input is gone
			while(ALL_LINES != 1);
			break;
		}
	}
	if(row == 4) 
	{
		return 0;
	}
	//switch the rows
	switch(row)
	{
		case 0://switch the input
				switch(input)
					{
					case 0x70: return '/';
					case 0xB0: return '9';
					case 0xD0: return '8';
					case 0xE0: return '7';
					}
		case 1://switch the input
					switch(input)
					{
						case 0x70: return '*';
						case 0xB0: return '6';
						case 0xD0: return '5';
						case 0xE0: return '4';
					}
		case 2://switch the input
					switch(input)
					{
						case 0x70: return '-';
						case 0xB0: return '3';
						case 0xD0: return '2';
						case 0xE0: return '1';
					}
		case 3://switch the input
					switch(input)
					{
						case 0x70: return '+';
						case 0xB0: return '=';
						case 0xD0: return '0';
						case 0xE0: return 'c';
					}
	}
	return 0;
}
