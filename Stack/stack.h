#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>
#define   IS_FULL     1
#define   IS_EMPTY    0

//Functions prototype
void    push(uint8_t);
uint8_t peek(void);
void    pop(void);
uint8_t is_empty(void);
uint8_t is_full(void);

#endif
