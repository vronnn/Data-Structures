#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct treenode {
    char nama[60];
    double fis;
    double mat;
    double karate;
    double rerata;
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

TreeNodePtr create_node(char nama[], double fis, double mat, double karate) {
    TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
    strcpy(newNode->nama, nama);
    newNode->fis = fis;
    newNode->mat = mat;
    newNode->karate = karate;
    newNode->rerata = (fis + mat + karate) / 3;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool bst_isEmpty(BinaryTreePtr bst) {
    return(bst->root == NULL);
}

TreeNodePtr bst_minnode(TreeNodePtr node) {
    TreeNodePtr currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

TreeNodePtr bst_make(TreeNodePtr root, char nama[], double fis, double mat, double karate) {
    double rerata = (fis + mat + karate) / 3;
    if (root == NULL)
        return create_node(nama, fis, mat, karate);
    if (rerata < root->rerata)
        root->left = bst_make(root->left, nama, fis, mat, karate);
    else if (rerata > root->rerata)
        root->right = bst_make(root->right, nama, fis, mat, karate);

    return root;
}

void bst_insert(BinaryTreePtr bst, char nama[], double fis, double mat, double karate)
{
    bst->root = bst_make(bst->root, nama, fis, mat, karate);
    bst->size++;
}

void preor(TreeNodePtr root) {
    if (root) {
        printf("Nama: %s\n", root->nama);
        printf("Fisika: %.2f\n", root->fis);
        printf("Matematika: %.2f\n", root->mat);
        printf("Karate: %.2f\n", root->karate);
        printf("Rerata: %.2f\n", root->rerata);
        puts("");
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
        printf("Nama: %s\n", root->nama);
        printf("Fisika: %.2f\n", root->fis);
        printf("Matematika: %.2f\n", root->mat);
        printf("Karate: %.2f\n", root->karate);
        printf("Rerata: %.2f\n", root->rerata);
        puts("");
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
        printf("Nama: %s\n", root->nama);
        printf("Fisika: %.2f\n", root->fis);
        printf("Matematika: %.2f\n", root->mat);
        printf("Karate: %.2f\n", root->karate);
        printf("Rerata: %.2f\n", root->rerata);
        puts("");
    }
}

void postorder(BinaryTreePtr bst){
    postor(bst->root);
}

int main()
{
    BinaryTreePtr data = bst_init();
    int n;
    double fis, mat, karate;
    char nama[10];
    scanf("%d", &n);
    while(n--){
        scanf("%s %lf %lf %lf", nama, &fis, &mat, &karate);
        bst_insert(data, nama, fis, mat, karate);
    }
    puts("================");
    printf("PRE ORDER\n");
    preorder(data);
    puts("================");
    printf("IN ORDER\n");
    inorder(data);
    puts("================");
    printf("POST ORDER\n");
    postorder(data);
    return 0;
}
