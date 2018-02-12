#include "calculator.h"

/*
*Function name 	: scan_and_eval
*Parameters	    : void
*return		   		: uint16_t result
*purpose       	: reads the input expression and converting
*            it to number and evalu' the expression result
*/
uint16_t scan_and_eval(void){
  uint16_t result;
  uint8_t key_press;
  uint8_t i=0,j=0;
  uint16_t num_1=0,num_2=0,op_temp=0;
  struct Stack * op = create_stack(100);
  struct Stack * number = create_stack(100);
  uint8_t temp[20]={0};
  uint8_t precedence [50]={0};
  precedence[42]=2;				// precedence of (*)
  precedence[47]=2;				// precedence of (/)
  precedence[43]=1;				// precedence of (+)
  precedence[45]=1;				// precedence of (-)
  push(op,0);

  while(1){

    key_press=keypad_scan();
	if(key_press !=0){			
		lcd_write_character(key_press);

		if(key_press=='='){
			temp[j]='\0';
			input[i]=string_to_number(temp);
			push(number,input[i++]);
			while(peek(op)!=0){
			  num_2=pop(number);
			  num_1=pop(number);
			  op_temp=pop(op);
			  result=do_math(num_1,num_2,op_temp);
			  push(number,result);
			}
			return peek(number);
		}

		else if (key_press=='+'||key_press=='*'||key_press=='-'||key_press=='/'){
		  temp[j]='\0';
		  input[i]=string_to_number(temp);
		  push(number,input[i++]);
		  if(precedence[key_press] < precedence[peek(op)]){
			  num_2=pop(number);
			  num_1=pop(number);
			  op_temp=pop(op);
			  result=do_math(num_1,num_2,op_temp);
			  push(number,result);
			  push(op,key_press);
			}
			else{
			 push(op,key_press);
			}
			j=0;
		}
		else
		  temp[j++]=key_press;
		}
	}
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
  while(str_num[i]!='\0'){
    number = 10*number + (str_num[i++]-48);
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
   uint8_t i=0;
  struct Stack * num=create_stack(20);
  while(number){
    push(num,(number%10)+48);
    number/=10;
  }
  while(!is_empty(num)){
	str_num[i++]=pop(num);
  }
  str_num[i]='\0';
  return str_num;
}


/*
*Function name 	: do_math
*Parameters	    : uint8_t num_1, uint8_t num_2
*return		   		: uint16_t result
*purpose       	: calculaing the operation between two
*           numbers (+ or - or * or /)
*/
uint16_t do_math(uint16_t num_1,uint16_t num_2,uint8_t op){
  uint16_t result=0;
  switch (op){
    case '+':
      result=num_1+num_2;
      break;
    case '-':
      result=num_1-num_2;
      break;
    case '*':
      result=num_1*num_2;
      break;
    case '/':
        result=num_1/num_2;
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
  uint8_t * str_num;
  str_num = number_to_string(result);
  lcd_write_word(str_num);
}
