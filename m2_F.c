// karena bantuan kalian, mamat telah diangkat sebagai manager di gudang perusahaan nya.
/*tugas nya adalah mencatat semua barang yang disimpan. setiap barang akan diletakan disuatu 
tempat dengan index tertentu, namun index tersebut akan berubah setiap kali ada barang baru yang masuk atau ada barang yang keluar. 
karena hal tersebut, mamat kesulitan akan pekerjaan dia sebagai manager.
 kamu sebagai programmer handal diminta tolong oleh mamat untuk membantu nya dalam mengatur letak 
 dari barang barang tersebut. note: untuk index bisa menggunakan inorder.

Input Format

baris pertama Q queri yang dilakukan
baris selanjut nya berisi queri queri tertentu:
1 N: memasukan barang N ke dalam list
2 N: mengeluarkan barang N ke dalam list
3 N: mengeluarkan index tempat dari barang N

Constraints


Output Format

untuk queri 2, jika barang tidak ada print "Tidak ada di gudang"
untuk queri 3, jika barang ada print index dari barang, jika tidak ada print "Tidak ada di gudang"
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int sort=0;
int id=0;
bool flag = false;

typedef struct bstnode_t {
    long long unsigned key;
    int index;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

//function BST;

BSTNode* __bst__createNode(long long unsigned value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, long long unsigned value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, long long unsigned value) {
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

BSTNode* __bst__remove(BSTNode *root, long long unsigned value) {
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

void __bst__inorderIndex(BSTNode *root) {
    if (root) {
        __bst__inorderIndex(root->left);
        root->index = id;
        id++;
        __bst__inorderIndex(root->right);
    }
}

//void __bst__inorderIndexReverse(BSTNode *root) {
//    if (root) {
//        __bst__inorderIndexReverse(root->right);
//        root->index = id;
//        id++;
//        __bst__inorderIndexReverse(root->left);
//    }
//}

//void __bst__inorder(BSTNode *root) {
//    if (root) {
//        __bst__inorder(root->left);
//        printf("%d ", root->index);
//        __bst__inorder(root->right);
//    }
//}

//function to BTS;

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

long long unsigned bst_findIndex(BST *bst, long long unsigned value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return temp->index;
    else{
        return false;
    }
}

bool bst_find(BST *bst, unsigned long long value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, long long unsigned value) {
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

//Tranversal

void bst_inorder(BST *bst) {
	if(!flag){
		__bst__inorderIndex(bst->_root);	
	}
//    else{
//    	__bst__inorderIndexReverse(bst->_root);
//	}
}
//void bst_printlist(BST *bst){
//	__bst__inorder(bst->_root);
//	printf("\n");
//}

int main(){
    BST set;
    bst_init(&set);
    long long unsigned Q, P, a;
    scanf("%llu", &Q);
    for(int i = 0; i < Q; i++){
        scanf("%llu", &P);
        if(P == 1){
        	scanf("%llu", &a);
            if(sort == 1){
                sort = 0;
            }
            bst_insert(&set, a);
//            bst_printlist(&set);
        }
        else if(P == 2){
        	scanf("%llu", &a);
        	if(sort == 1){
        		sort = 0;
			}
			if(bst_find(&set, a) != 0){
				bst_remove(&set, a);
			}
			else{
				printf("Tidak ada di gudang\n");
			}
//			bst_printlist(&set);
		}
        else if(P == 3){
        	scanf("%llu", &a);
            if(sort == 0){
                id = 1;
                bst_inorder(&set);
                sort = 1;
            }
            if(bst_find(&set, a) != 0){
                printf("%llu\n", bst_findIndex(&set, a));
            }
            else
                printf("Tidak ada di gudang\n");
//            bst_printlist(&set);
        }
    }
    return 0;
	
}