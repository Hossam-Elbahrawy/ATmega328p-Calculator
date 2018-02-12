#include "calculator.h"
void reset_display(){
	
}
int main(){
  uint8_t key_press;
  uint16_t *input;
  uint16_t result;

  lcd_init();
  keypad_init();
	
  
  while(1){
	   key_press=keypad_scan();
	   if(key_press !=0){	
	   
		if(key_press=='c'){
			lcd_send_command(LCD_CMD_CLEAR_DISPLAY);
			lcd_write_word("Enter Expression!");
			lcd_goto_xy(1,0);
			result=scan_and_eval();
			print_result(result);
			
			}
		}
		
   }

  return 0;
}
