

/*

Di suatu ujian Ian dan Aan dicurigai menyontek. Rahel yang terkenal akan keadilannya ingin membuktikan bahwa Ian dan Aan mencontek saat ujian berlangsung. Rahel membuat sebuah program yang dapat mengecek kecurangan dalam ujian. Mereka berdua dianggap menyontek ketika jawaban dan jumlah soal mereka semua sama, tetapi terkadang Rahel salah menginputkan nilai jadi dia membuat fungsi undo yang bertuliskan "mundur".

Input Format

Baris pertama merupakan X jumlah soal yang mereka jawab

Baris kedua berisi STRING nama atau STRING mundur dan Y sebagai nilai mereka berdua

Constraints

Output Format

DIH TUKANG NYONTEK atau SIP SI PALING JUJUR

Sample Input 0

10
IAN 40
AAN 40
IAN 78
AAN 78
IAN 66
AAN 66
IAN 50
AAN 50
IAN 56
AAN 34

Sample Output 0

SIP SI PALING JUJUR

Sample Input 1

9
IAN 40
AAN 40
IAN 78
AAN 78
IAN 66
AAN 65
mundur
IAN 50
AAN 50

Sample Output 1

DIH TUKANG NYONTEK


*/
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
