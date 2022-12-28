#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct treenode {
    int key;
    struct treenode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct tree {
    TreeNodePtr root;
    unsigned int size;
} BinaryTree, *BinaryTreePtr;

BinaryTreePtr bst_init() {
    BinaryTreePtr bst = (BinaryTreePtr) malloc(sizeof(BinaryTree));
    bst->root = NULL;
    bst->size = 0u;
    return bst;
}

TreeNodePtr create_node(int value) {
    TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool bst_isEmpty(BinaryTreePtr bst) {
    return(bst->root == NULL);
}

TreeNodePtr bst_search(TreeNodePtr temp, int value) {
    while(temp != NULL){
        if (value < temp->key)
            temp = temp->left;
        else if (value > temp->key)
            temp = temp->right;
        else return temp;
    }
    return temp;
}

void search(BinaryTreePtr bst, int value) {
    TreeNodePtr temp = bst->root;
    while(temp->key != value){
        if (value < temp->key){
            temp = temp->left;
            printf("LEFT\n");
        }
        else if (value > temp->key){
            temp = temp->right;
            printf("RIGHT\n");
        }
    }
}

bool bst_find(BinaryTreePtr bst, int value) {
    TreeNodePtr temp = bst_search(bst->root, value);
    if (temp == NULL) return false;
    if (temp->key == value) return true;
    else return false;
}

TreeNodePtr bst_make(TreeNodePtr root, int value) {
    if (root == NULL)
        return create_node(value);
    if (value < root->key)
        root->left = bst_make(root->left, value);
    else if (value > root->key)
        root->right = bst_make(root->right, value);

    return root;
}

void bst_insert(BinaryTreePtr bst, int value) {
    if (!bst_find(bst, value)) {
        bst->root = bst_make(bst->root, value);
        bst->size++;
    }
}

void preor(TreeNodePtr root) {
    if (root) {
        printf("%d ", root->key);
        preor(root->left);
        preor(root->right);
    }
}

void preorder(BinaryTreePtr bst){
    preor(bst->root);
}

void inor(TreeNodePtr root) {
    if (root) {
        inor(root->left);
        printf("%d ", root->key);
        inor(root->right);
    }
}

void inorder(BinaryTreePtr bst){
    inor(bst->root);
}

void postor(TreeNodePtr root) {
    if (root) {
        postor(root->left);
        postor(root->right);
        printf("%d ", root->key);
    }
}

void postorder(BinaryTreePtr bst){
    postor(bst->root);
}

int main()
{
    BinaryTreePtr surga = bst_init();
    int n, a, b;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        bst_insert(surga, a);
    }
    scanf("%d", &b);
    if(bst_find(surga, b)){
        search(surga, b);
    }
    else printf("AHH AKU MASUK NERAKA\n");
    return 0;
}

