#include "calculator.h"

int main(){

  uint16_t *input;
  uint16_t result;

  lcd_init();
  keypad_init();

  while(1){
    lcd_write_word("Enter Expression!");
    lcd_goto_xy(1,0);
    input=read_exp();
    result= infix_exp_eval(input);
    print_result(result);
  }

  return 0;
}
