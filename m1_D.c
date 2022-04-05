/*Fenomena bilangan kolaps terjadi ketika bentuk biner dari bilangan N terdapat pertemuan antara nilai 0 dengan 0 ataupun 1 dengan 1 
(tentu saja, ini hanya akal-akalan penulis). Buatlah program yang mengeluarkan hasil dari suatu bilangan N yang mengalami fenomena bilangan kolaps.

Input Format

Sebuah baris yang berisi bilangan T yang menyatakan banyaknya bilangan N, diikuti dengan T baris yang berisi bilangan N yang akan mengalami fenomena bilangan kolaps.

Constraints

Output Format

T Baris yang masing-masing berisi bilangan N yang telah kolaps.

Sample Input 0

2
7
18

Sample Output 0

1
0
*/
setelah bilangan N diubah menjadi bentuk biner, masukkan kedalam stack jika yang akan dimasukkan tidak sama dengan stack top dari stack tersebut. Jika sama, lakukan pop, tidak usah dimasukkan.

//Set by naufal_f

//Problem Setter's code :

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
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
    return -1;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        while(n){
            if(n&1){
                if(stack_top(&myStack)==1) stack_pop(&myStack);
                else stack_push(&myStack, 1);
            }
            else{
                if(stack_top(&myStack)==1 || stack_isEmpty(&myStack)) stack_push(&myStack, 0);
                else stack_pop(&myStack);
            }
            n >>= 1;
        }
        int res=0;
        while(!stack_isEmpty(&myStack)){
            res <<= 1;
            res += stack_top(&myStack);
            stack_pop(&myStack);
        }
        printf("%d\n", res);
    }

    
    return 0;
}

