/*cek dulu dequenya, kalau bilangan yang akan dimasukkan lebih kecil daripada front dequenya, 
lakukan push front. Sebaliknya, lakukan push back.*/

//Set by naufal_f
/*
Pada suatu hari, Yuta melihat sebuah mesin yang unik. Mesin ini mengubah suatu permutasi menjadi permutasi yang lain. Yuta sangat ingin memiliki mesin ini. Sayangnya, dompetnya berkata lain. Karenanya, Yuta berniat untuk membuat mesin ini sendiri. bantulah Yuta menulis program untuk mengubah permutasi sebagaimana mesin tersebut mengubahnya.

Input Format

Sebuah baris yang berisi bilangan T yang menyatakan banyaknya kasus uji, diikuti dengan T pasang baris yang berisi N yang menyatakan banyaknya deret permutasi dan N bilangan antara 1 hingga N yang dipisahkan oleh spasi dibawahnya.

Constraints

    1 ≤ T ≤ 10

    1 ≤ N ≤ 100

Output Format

T Baris yang masing-masing berisi hasil permutasi yang telah diubah.

Catatan: Permutasi yang diubah bisa saja sama seperti permutasi sebelumnya.

Sample Input 0

2
4
3 1 2 4
6
1 2 3 4 5 6

Sample Output 0

1 3 2 4 
1 2 3 4 5 6 

Explanation 0

Perhatikan bahwa front/top dari suatu struktur data akan menentukan darimana bilangan selanjutnya dimasukkan ke dalam struktur data tersebut.
*/


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct dnode_t {
    unsigned long long data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(unsigned long long value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, unsigned long long value);
void deq_pushBack(Deque *deque, unsigned long long value);
unsigned long long  deq_front(Deque *deque);
unsigned long long  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/* Definisi Fungsi */

DListNode* __dlist_createNode(unsigned long long value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, unsigned long long value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, unsigned long long value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

unsigned long long deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

unsigned long long deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

int main(int argc, char const *argv[]){

    unsigned long long t, n, input; // catatan: penggunaan unsigned long long disini adalah kebiasaan problem setter, tidak wajib.
    Deque deque;
    deq_init(&deque);
    scanf("%llu", &t);
    while(t--){    
        scanf("%llu", &n);
        for(long i=0; i<n; i++){
            scanf("%llu", &input);
            if(deq_isEmpty(&deque) || input < deq_front(&deque)){
                deq_pushFront(&deque, input);
            }
            else deq_pushBack(&deque, input);
        }
        for(long i=0; i<n; i++){
            printf("%llu ", deq_front(&deque));
            deq_popFront(&deque);
        }
        printf("\n");
    }
    
    return 0;
}

