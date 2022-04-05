#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main() {
   int n;
   Stack myStack;
   stack_init( & myStack);

   scanf("%d", & n);

   while (n--) {
      char cmd[7];
      
      scanf("%s", cmd);
      
      if (strcmp(cmd, "mundur") == 0) {
         if (!stack_isEmpty( & myStack)) {
            stack_pop( & myStack);
            stack_pop( & myStack);
         }
         
      } 
      
      else {
         int temp;
         scanf("%d", & temp);
         stack_push( & myStack, temp);
      }
      
   }
   int cek = 0;
   while (!stack_isEmpty( & myStack)) {
      int a = stack_top( & myStack);
      stack_pop( & myStack);
      int b = stack_top( & myStack);
      stack_pop( & myStack);
      if (a != b) {
         cek = 1;
         break;
      }
   }
   if (cek) {

      printf("SIP SI PALING JUJUR\n");
   } else {
      printf("DIH TUKANG NYONTEK\n");
   }
}