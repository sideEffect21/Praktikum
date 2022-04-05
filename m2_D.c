// Cukup sederhana. Pertama, buatlah struct siswa dengan attribut nama,\
 nilai fisika, matematika, karate, dan nilai rerata. Selanjutnya, hanya perlu memasukkan nilai\
  rerata pada binary search tree dan menambahkan key berupa index pada tree sebagai refrence pada struct  
//Sisanya hanya perlu melakukan traversal pre,in,dan post order dan mencetak attribut yang diminta.

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    double key;
    int index;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value, int index) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->index = index;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int index) {
    if (root == NULL) 
        return __bst__createNode(value, index);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, index);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, index);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

// STRUCTURE SISWA
typedef struct siswa_sekolah{
    char nama[100];
    double rerata, fisika, matematika, karate;
}Siswa;

void print_struck(Siswa sis){
    printf("Nama: %s\n", sis.nama);
    printf("Fisika: %.2lf\n", sis.fisika);
    printf("Matematika: %.2lf\n", sis.matematika);
    printf("Karate: %.2lf\n", sis.karate);
    printf("Rerata: %.2lf\n\n", sis.rerata);
}

void __bst__inorder(BSTNode *root, Siswa sis[]) {
    if (root) {
        __bst__inorder(root->left, sis);
        print_struck(sis[root->index]);
        __bst__inorder(root->right, sis);
    }
}

void __bst__postorder(BSTNode *root, Siswa sis[]) {
    if (root) {
        __bst__postorder(root->left, sis);
        __bst__postorder(root->right, sis);
        print_struck(sis[root->index]);
    }
}

void __bst__preorder(BSTNode *root, Siswa sis[]) {
    if (root) {
        print_struck(sis[root->index]);
        __bst__preorder(root->left, sis);
        __bst__preorder(root->right, sis);
    }
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

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int index) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, index);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst, Siswa sis[]) {
    printf("IN ORDER\n");
    __bst__inorder(bst->_root, sis);
}

void bst_postorder(BST *bst, Siswa sis[]) {
    printf("POST ORDER\n");
    __bst__postorder(bst->_root, sis);
}

void bst_preorder(BST *bst, Siswa sis[]) {
    printf("PRE ORDER\n");
    __bst__preorder(bst->_root, sis);
}


 
int main()
{
    BST set;
    bst_init(&set);

    int n;
    scanf("%d", &n);
    Siswa siswa[n];
    for(int i=0; i<n; i++){
        scanf("%s", siswa[i].nama);
        scanf("%lf", &siswa[i].fisika);
        scanf("%lf", &siswa[i].matematika);
        scanf("%lf", &siswa[i].karate);
        siswa[i].rerata = (siswa[i].fisika + siswa[i].matematika + siswa[i].karate) / 3;

        bst_insert(&set, siswa[i].rerata, i);
    }
    
    printf("================\n");
    bst_preorder(&set, siswa);
    printf("================\n");
    bst_inorder(&set, siswa);
    printf("================\n");
    bst_postorder(&set, siswa);
    
    return 0;
}