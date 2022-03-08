#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Struktur Node */


typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

unsigned stack_size(Stack *stack) 
{
    return stack->_size;
}

void stack_init(Stack *);
bool stack_isEmpty(Stack *);
void stack_push(Stack *, int);
void stack_pop(Stack *);
bool solve_Uva(Stack *, int, int*);
