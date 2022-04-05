/*
mamat adalah pekerja keras yang labil. setiap hari dia menulis kegiatannya(dalam bentuk bilangan) secara berurutan layaknya queue. namun karena mamat adalah orang yang labil, terkadang dia menulis kegiatan baru nya didepan, melakukan kegiatan diurutan belakang, bahkan memutar balik urutan pekerjaan nya. hal ini menyebabkan mamat sering kali bingung untuk melalukan pekerjaan apa selanjutnya dan banyak pekerjaan yang akhirnya terhambat. akhirnya mamat memutuskan membuat list yang fleksibel terhadap perilaku labilnya. list tersebut harus bisa menambahkan kegiatan di depan maupun belakang, menampilkan dan menghapus kegiatan di depan maupun belakang, memutar urutan kegiatan secara terbalik. bantulah mamat untuk dapat membuat list tersebut.

Input Format

baris pertama berisi Q queri yang dilakukan

baris kedua dan selanjut berisi queri yang dilakukan

queri yang ada:

Front - menampilkan dan menghapus kegiatan di depan

Back - menampilkan dan menghapus kegiatan di belakang

Push_Back N - menambahkan kegiatan N di belakang

toFront N - menambahkan kegiatan N di depan

Reverse - memutar urutan semua kegiatan secara terbalik

List - menampilkan isi dari list secara berurutan(bila list telah di reverse maka list juga harus dalam keadaan yang terbalik)

Constraints


Output Format

untuk front/back tampilkan kegiatan nya

bila list kosong print "Mamat gabut"

untuk list print semua kegiatan

Sample Input 0

10
Push_Back 12
Push_Back 13
Push_Back 14
List
Reverse
List
Back
Back
Back
Back

Sample Output 0

12 13 14
14 13 12
12
13
14
Mamat gabut

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} List;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void dlist_init(List *list);
bool dlist_isEmpty(List *list);
void dlist_pushFront(List *list, int value);
void dlist_pushBack(List *list, int value);
void dlist_insertAt(List *list, unsigned index, int value);
int  dlist_front(List *list);
int  dlist_back(List *list);
void dlist_popFront(List *list);
void dlist_popBack(List *list);
// void dlist_remove(List *list, int element);
// void dlist_removeAt(List *list, int index);

/* Function definition */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{ 
//
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

bool dlist_isEmpty(List *list) {
    return (list->_head == NULL && \
            list->_tail == NULL);
}

void dlist_pushFront(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        newNode->next = list->_head;
        list->_head->prev = newNode;
        list->_head = newNode;
    }
}

void dlist_pushBack(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}

void dlist_insertAt(List *list, unsigned index, int value)
{
    if (index == 0) { 
        dlist_pushFront(list, value);
        return;
    }
    else if (index >= list->_size) {
        dlist_pushBack(list, value);
        return;
    }

    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        DListNode *temp = list->_head;

        unsigned _i = 0;
        while (_i < index - 1 && temp->next != NULL) {
            temp = temp->next;
            _i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        list->_size++;
    }
}

int dlist_front(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_head->data);
    }
    return 0;
}

int dlist_back(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_tail->data);
    }
    return 0;
}

void dlist_popFront(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp = list->_head;
        if (list->_head == list->_tail) {
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            list->_head = list->_head->next;
            list->_head->prev = NULL;
            free(temp);
        }
        list->_size--;
    }
}

void dlist_popBack(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp;
        if (list->_head == list->_tail) {
            temp = list->_head;
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            temp = list->_tail;
            list->_tail = list->_tail->prev;
            list->_tail->next = NULL;
            free(temp);
        }
        list->_size--;
    }
}

void dlist_printlist(List *list){
	DListNode *temp = list->_head;
	while(temp->next != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

void dlist_reversePrintlist(List *list){
	DListNode *temp = list->_tail;
	while(temp->prev != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("%d\n", temp->data);
}

int main(){
	bool reverse = false;
	int n, num;
	char a[10];
	List myList;
	dlist_init(&myList);
	scanf("%d", &n);
	for(int i = 0; i < n;i++){
		scanf("%s", a);
		if(a[0] == 'B'){
			if(!reverse){
				if(dlist_isEmpty(&myList)){
					printf("Mamat gabut\n");
				}
				else{
					printf("%d\n", dlist_back(&myList));
					dlist_popBack(&myList);	
				}
			}
			else{
				if(dlist_isEmpty(&myList)){
					printf("Mamat gabut\n");
				}
				else{
					printf("%d\n", dlist_front(&myList));
					dlist_popFront(&myList);
				}
			}
		}
		if(a[0] == 'F'){
			if(!reverse){
				if(dlist_isEmpty(&myList)){
					printf("Mamat gabut\n");
				}
				else{
					printf("%d\n", dlist_front(&myList));
					dlist_popFront(&myList);
				}
			}
			else{
				if(dlist_isEmpty(&myList)){
					printf("Mamat gabut\n");
				}
				else{
					printf("%d\n", dlist_back(&myList));
					dlist_popBack(&myList);	
				}
			}
		}
		if(a[0] == 'R'){
			reverse = !reverse;
		}
		if(a[0] == 'P'){
			scanf("%d", &num);
			if(!reverse){
				dlist_pushBack(&myList, num);
			}
			else{
				dlist_pushFront(&myList, num);
			}
		}
		if(a[0] == 't'){
			scanf("%d", &num);
			if(!reverse){
				dlist_pushFront(&myList, num);
			}
			else{
				dlist_pushBack(&myList, num);
			}
		}
		if(a[0] == 'L'){
			if(!reverse){
				if(dlist_isEmpty(&myList)){
					printf("Mamat gabut\n");
				}
				else{
					dlist_printlist(&myList);
				}
			}
			else{
				if(dlist_isEmpty(&myList)){
					printf("Mamat gabut\n");
				}
				else{
					dlist_reversePrintlist(&myList);
				}
			}	
		}
	}
}
