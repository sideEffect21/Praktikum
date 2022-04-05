#include"header.h"

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) 
{
    return (stack->_top == NULL);
}
