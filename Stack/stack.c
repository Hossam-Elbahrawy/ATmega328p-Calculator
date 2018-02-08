#include "stack.h"

/*
*Function name 	: creat_stack
*Parameters	    : uint8_t size
*return		   		: struct Stack
*purpose       	:creating a stack with the given size
*/
struct Stack* create_stack(uint16_t s){
  struct Stack* stack = (struct Stack *) malloc(sizeof(struct Stack));
  stack ->size=s;
  stack ->top=-1;
  stack  -> data= (uint16_t*) malloc(stack-> size *sizeof(uint16_t));
  return stack;
}
  /*
  *Function name 	: push
  *Parameters	    : uint8_t data
  *return		   		: void
  *purpose       	: adds item to the top of the stack
  */
void push(struct Stack* stack,uint16_t item){
  if(!is_full(stack)){
    stack->data[++stack->top]=item;
  }
  else
    return;
}

/*
*Function name 	: peek
*Parameters	    : void
*return		   		: void
*purpose       	: Returns the top of the stack
*/
uint16_t peek(struct Stack* stack){
  if(!is_empty(stack)){
  return stack->data[stack->top];
  }
  return -1;
}

/*
*Function name 	: pop
*Parameters	    : struct Stack* stack
*return		   		: uint16_t
*purpose       	: Removes the item on the top of
*						 the stack
*/
uint16_t pop(struct Stack* stack){
  if(!is_empty(stack)){
    return stack->data[stack->top--];
  }
  return -1;
}

/*
*Function name 	: is_empty
*Parameters	    : struct Stack* stack
*return		   		: IS_EMPTY or IS_NOT_EMPTY
*purpose       	: Checks if the stack i empty
*/
uint8_t is_empty(struct Stack* stack){
  if(stack->top==-1)
    return IS_EMPTY;
  else
    return IS_NOT_EMPTY;
}

/*
*Function name 	: is_full
*Parameters	    : struct Stack* stack
*return		   		: IS_FULL or IS_NOT_FULL
*purpose       	: Checks if the stack is full
*/
uint8_t is_full(struct Stack* stack){
  if(stack->top==stack->size)
    return IS_FULL;
  else
    return IS_NOT_FULL;
}
