/*Dibuat 1 bst tree yang dapat menyimpan nama-nama dari keluarga RahelChan(key-nya string). 
Dimasukkan variabel-variabel yang diperlukan yaitu testcase, nama keluarga, dan indikator pencari nama ibu atau anak. 
Lalu diinput nama-nama dari Keluarga RahelChan kedalam bst tree dengan syarat nama harus huruf kecil semua, 
nama dimasukkan kedalam soal dengan asumsi jika nama yang dijumpai lebih kecil geser ke kiri jika lebih besar geser ke kanan,
 dan nama orang didalam suatu keluarga pasti tidak akan sama, maka jika sama akan dimasukkan sekali saja. Lalu dimasukkan apa-apa yang dicari. 
 Jika dicari anak maka print lah root.left dan root.right nya jika tidak memiliki salah satunya maka print lah "-", 
 jika tidak memiliki keduanya maka print lah "Anak-aNakkuu lagi otw Gan". Jika dicari ibu, maka print lah prevnode.key(Sebuah bst baru yang diasumsikan menjadi 
 langkah sebelum root yang di cari) dari node dicari, jika node yang dicari berupa root maka printlah "Aku adalah Komandan 1 keluarga Rahel", 
 jika nama ibu yang dicari tidak ada, karena sifat pencariannya mencari dari node paling kiri hingga yang terakhir(sistem inorder) 
 maka akan sampai ke node paling ujung kanan yang didapat akan diprint menjadi ibu dari nama yang tidak ada tersebut.*/
/*
Rahel ternyata selama salah sangka dengan dirinya maka dari itu dia mengubah namanya menjadi RahelChan.

Karena hal tersebut maka rahel sangat ingin mempelajari silsilah dari Keluarga Besarnya maka dari itu dia membuat sebuah program yang dimana dapat menginputkan nama-nama dari anggota keluarganya serta cara untuk mencari posisi dari anggota keluarga tersebut.

NB:

Karena Rahel itu baik, ramah, rajin menabung, berbakti kepada orangtua, tidak menumpuk pakaian kotor, strukdat selalu ac semua, maka dia mengingatkan kita semua bahwa keluarganya itu tidak memiliki nama orang yang sama

Jadi kalau dia lalai memasukkan nama keluarganya lebih dari 1 kali yang masuk jadinya 1 aja okeehhh Maafkan Rahelll lagi ya :((

Input Format

    Baris pertama adalah N T yang merupakan banyaknya jumlah test case.
    N baris berikutnya berisi S, yaitu nama anggota keluarga Rahel.
    T baris berikutnya memiliki format masukan ???O S???, O akan dijelaskan nanti. Sedangkan S merupakan nama salah satu anggota keluarga Rahel.
    Cara memasukkan S kedalam BST menggunakan STRCMP, jika node yang dijumpai lebih kecil geser ke kiri. Jika lebih besar geser ke kanan.

Constraints

    S selalu lowercase

Output Format

Untuk setiap test case terdapat dua tipe, jika O adalah ???anak??? maka keluarkan child node dari S. Jika memiliki dua child keluarkan sebagai ???A B???, A adalah child kiri sedangkan B adalah child kanan. Jika salah satu tidak ada ganti dengan ???-???. Jika tidak memiliki child keluarkan Anak-aNakkuu lagi otw Gan. Jika O adalah ???ibu???, keluarkan parent dari S. Jika S adalah root dari BST keluarkan Aku adalah Komandan 1 keluarga Rahel

Sample Input 0

8 5
oppung
poltak 
rahel
darwis
angkasa
reinata
michelle
tio
anak rahel
ibu oppung
anak tio
ibu darwis
anak darwis

Sample Output 0

reinata -
Aku adalah Komandan 1 keluarga Rahel
Anak-aNakkuu lagi otw Gan
oppung
michelle angkasa

*/


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct bstnode_t {
    char *key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(char *value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = (char*) malloc(sizeof(char)*(strlen(value)+15));
    strcpy(newNode->key, value);
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, char *value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (strcmp(root->key,value)<0)
        root->left = __bst__insert(root->left, value);
    else if (strcmp(root->key,value)>0)
        root->right = __bst__insert(root->right, value);
    
    
    return root;
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

void bst_insert(BST *bst, char *value) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
}

void carianak (BSTNode *root, char *ibu){
    if (root==NULL){
        return;
    }

    if(strcmp(root->key,ibu)==0){
        
        if(root->left==NULL ){
                if( root->right!=NULL)
                    printf("- %s\n",  root->right->key);
                else    
                    printf("Anak-aNakkuu lagi otw Gan\n");
        }
        else if(root->right==NULL){
                if( root->left!=NULL)
                    printf("%s -\n",  root->left->key);
                else    
                    printf("Anak-aNakkuu lagi otw Gan\n");           
        }
        else{
            printf("%s %s\n", root->left->key, root->right->key);
        }
        return;
    }

    else if(strcmp(root->key,ibu)>0){
        carianak (root->right, ibu);
    }
    else if(strcmp(root->key,ibu)<0){
        carianak (root->left, ibu);
    }

}

void cariibu(BSTNode *root, char *anak){
    if (root==NULL){
        return;
    }

    BSTNode *prevNode = root;

    while (root)
    { 
        if(strcmp(root->key,anak)==0){
             break;
        }
        prevNode = root;

        if(strcmp(root->key,anak)>0){
            root = root->right;
        }
        else if(strcmp(root->key,anak)<0){
        // akan terus mengkases ke paling kanan(node terakhir) jika tidak menemukan nama ibu yang diminta
            root = root->left;
        }
    }
    printf("%s\n", prevNode->key);

}
 
int main(){
    BST set;
    bst_init(&set);
    
    int N, T;
    char O[30];
    char S[30];

    scanf("%d %d", &N, &T);

    for (int a=0 ; a<N ; a++){
        scanf("%s",S);
        bst_insert(&set, S);
    }

    for (int a=0 ; a<T ; a++){
        scanf("%s %s" ,O ,S);
        
        if(strcmp(O, "anak")==0){
            carianak(set._root, S);
        }
        else if(strcmp(O, "ibu")==0){
            if(strcmp(set._root->key, S)==0){
                printf("Aku adalah Komandan 1 keluarga Rahel\n");
            }
            else{
                cariibu(set._root, S);
            }
        }         
    }

    return 0;
}

