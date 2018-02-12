#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>
#include <stdlib.h>
#define   IS_FULL         1
#define   IS_NOT_FULL     0
#define   IS_EMPTY        1
#define   IS_NOT_EMPTY    0

// Stack structure
struct Stack{
  uint16_t size;
  uint16_t top;
  uint16_t * data;
};


//Functions prototype
struct   Stack* create_stack(uint16_t);
void     push(struct Stack*,uint16_t);
uint16_t peek(struct Stack*);
uint16_t pop(struct Stack*);
uint8_t  is_empty(struct Stack*);
uint8_t  is_full(struct Stack*);

#endif
