#include "calulator.h"

int main(){

  uint8_t * input[20];
  uint16_t result;

  lcd_init();
  Keypad_init();

  while(1){
    lcd_write_word("Enter Expression!");
    lcd_goto_xy(1,0);
    read_eq();
    result= infix_exp_eval();
    print_result(result);
  }

  return 0;
}
