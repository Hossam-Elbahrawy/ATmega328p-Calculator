#include "calculator.h"

/*
*Function name 	: read_exp
*Parameters	    : void
*return		   		: uint8_t* input_str
*purpose       	: reads the input equation string of the calulator
*/
uint8_t* read_exp(void){
  uint8_t input_str[20];
  uint8_t i=0;
  uint8_t key_press;
  while(1){
    key_press=keypad_scan();
    if(key_press=='='){
      break;
    }
    else
      input_str[i++]=key_press;
  }

  return input_str;
}

/*
*Function name 	: string_to_number
*Parameters	    : uint8_t str_num
*return		   		: uint16_t number
*purpose       	: converting a string to decimal number
*/
uint16_t string_to_number(uint8_t* str_num){
  uint16_t number=0;
  uint8_t i=0;
  uint8_t size;
  while(str_num[i]!='\0'){
    number += 10*number + (str_num[i++]-48);
  }

  return number;
}

/*
*Function name 	: number_to_string
*Parameters	    : uint16_t number
*return		   		: uint8_t* str_num
*purpose       	: converting a decimal number to string
*/
uint8_t* number_to_string(uint16_t number){
  uint8_t str_num[20];
  uint8_t i=0;
  while(number){
    str_num[i++]=number%10;
    number/=10;
  }
  str_num[i]='\0';
  return str_num;
}

/*
*Function name 	: infix_exp_eval
*Parameters	    : uint8_t* input
*return		   		: uint16_t result
*purpose       	: algorithm for evaluating the input
*           mathimatical expression in infix form
*/
uint16_t infix_exp_eval(uint8_t* input){
  uint16_t result;

  return result;
}

/*
*Function name 	: do_math
*Parameters	    : uint8_t num_1, uint8_t num_2
*return		   		: uint16_t result
*purpose       	: calculaing the operation between two
*           numbers (+ or - or * or /)
*/
uint16_t do_math(uint16_t num_1,uint16_t num_2,uint8_t op){
  uint16_t result;
  switch (op){
    case '+':
      result=num2+num1;
      break;
    case '-':
      result=num2-num1;
      break;
    case '*':
      result=num1*num2;
      break;
    case '/':
        if(num1==0){
          return -1;
        }
        resutl=num2/num1;
        break;
  }

  return result;
}

/*
*Function name 	: print_result
*Parameters	    : uint16_t result
*return		   		: void
*purpose       	: printing the resutl on the LCD
*/

void print_result(uint16_t result){
  uint8_t str_num[20];
  str_num=number_to_string(result);
  lcd_write_word(str_num);
}
