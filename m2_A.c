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

