/*
Kali ini, Yuta ingin mengembangkan caranya untuk memperbesar nilai suatu bilangan hanya dengan mengubah susunan bitnya. 
dengan cara demikian, bantulah Yuta menulis program untuk mengetahui potensi dari suatu bilangan
(bilangan terbesar yang dapat dibentuk dari susunan bilangan biner).

Input Format

Sebuah baris yang berisi bilangan T yang menyatakan banyaknya bilangan N,
diikuti dengan T baris yang berisi bilangan N yang akan dicari potensi.

Constraints

    1 ≤ T, N ≤ 1000

Output Format

T Baris yang masing-masing berisi potensi terbesar dari bilangan N.

Sample Input 0

2
7
18

Sample Output 0

7
24

Explanation 0

Bilangan 7 memiliki bentuk biner 111, sehingga potensinya juga akan 111 (7). 
Sementara itu, 18 memiliki bentuk biner 10010, kemungkinan bilangan terbesar yang didapat dari susunan biner tersebut adalah 11000 (24).
*/



#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
/* Struktur Node */

typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

int main()

{
     // Buat objek PriorityQueue
  PriorityQueue myPque;

     // PENTING! Jangan lupa diinisialisasi
  pqueue_init(&myPque);

  int a, num;

  scanf("%d", &a);

  for (int i = 0; i < a; i++)
  {

    scanf("%d", &num);

    while (num > 0)
    {
      pqueue_push(&myPque, num % 2);
      num = num / 2;
    }

    int geser = 0, hasil = 0;

    while (!pqueue_isEmpty(&myPque))
    {

      hasil += pqueue_top(&myPque) *pow(2, geser);
      geser++;

         //printf(pqueue_top(&myPque));
      pqueue_pop(&myPque);
    }
    printf("%d\n", hasil);
  }
  return 0;
}
