// Sangat sederhana. Hanya perlu menduplikasi fungsi search dan menjadikannya bertipe void. \
Setelah itu, setiap traversal, cukup mencetak LEFT atau RIGHT sesuai dengan arahnya.\
Untuk permasalahan apakah surga ada atau tidak,\
cukup bandingkan key surga yang diminta dengan key input bst

/**
 Dan surga merupakan node yang memiliki key 7, maka cetaklah jalan (left or right), terpisah oleh new line, dari root node (8) menuju surga tersebut. Contoh kasus ini, berarti:

LEFT

RIGHT

RIGHT.

Jika tidak ada surga (tidak ada node yang memiliki nilai yang diminta), maka cetak "AHH MASUK NERAKA" dengan new line

Input Format

    Sebuah integer N
    N baris berikutnya berisi bilangan-bilangan bulat a[i]...a[N] yang akan dimasukkan ke tree (bilangan pertama = root)
    Selanjutnya integer b yang menandakan lokasi pintu SYURGA

Constraints

Output Format

SELALU PRINT DENGAN NEW LINE

Jika ada syurga cetak pathnya, jika tidak cetak "AHH MASUK NERAKA"

Lihat sample testcase pasti ngerti

Sample Input 0

9
8 3 10 1 6 14 4 7 13
7

Sample Output 0

LEFT
RIGHT
RIGHT

Explanation 0

Strukutr bstnya

image

karena posisi surga ada di node yang keynya 7, maka pathnya LEFT, RIGHT, RIGHT.

** NOTE: SURGA TIDAK MUNGKIN BERADA DI ROOT**

Sample Input 1

9
8 3 10 1 6 14 4 7 13
20

Sample Output 1

AHH AKU MASUK NERAKA

Explanation 1

Struktur tree sama seperti gambar diatas. Kali ini pintu surga yang dicari tidak ada sehingga dicetak AHH AKU MASUK NERAKA
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
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

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
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

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
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

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
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

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void cari(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key){
            printf("LEFT\n");
            root = root->left;
        }
        else if (value > root->key){
            printf("RIGHT\n");
            root = root->right;
        }
        else
            return;
    }
}
 
int main()
{
    BST set;
    bst_init(&set);
    char *msg = "AHH AKU MASUK NERAKA";

    int n;
    scanf("%d", &n);
    int arr_num[n];
    int heaven;

    for(int i=0;i<n;i++){
        scanf("%d", &arr_num[i]);
        bst_insert(&set, arr_num[i]);
    }

    scanf("%d", &heaven);
    
    bool tidak_ada = true;
    for(int i=0;tidak_ada && i<n;i++){
        if(heaven == arr_num[i]){
            tidak_ada = false;
            cari(set._root, heaven);
        }
    }
    if(tidak_ada){
        printf("%s\n", msg);
    }
    
    
    return 0;
}
