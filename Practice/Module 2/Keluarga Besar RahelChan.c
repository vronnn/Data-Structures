#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct treenode {
    char nama[25];
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

TreeNodePtr create_node(char nama[]) {
    TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
    strcpy(newNode->nama, nama);
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool bst_isEmpty(BinaryTreePtr bst) {
    return(bst->root == NULL);
}

TreeNodePtr cari_ibu(TreeNodePtr temp, char nama[])
{
    TreeNodePtr ibu = NULL;
    while (temp != NULL)
    {
        if (strcmp(nama, temp->nama) > 0){
            ibu = temp;
            temp = temp->left;
        }
        else if (strcmp(nama, temp->nama) < 0){
            ibu = temp;
            temp = temp->right;
        }
        else return ibu;
    }
    return ibu;
}

void printibu(BinaryTreePtr bst, char nama[]){
    TreeNodePtr temp = cari_ibu(bst->root, nama);
    if(temp == NULL) printf("Aku adalah Komandan 1 keluarga Rahel\n");
    else printf("%s\n", temp->nama);
}

TreeNodePtr bst_search(TreeNodePtr temp, char nama[]) {
    while(temp != NULL){
        if (strcmp(temp->nama, nama) < 0)
            temp = temp->left;
        else if (strcmp(temp->nama, nama) > 0)
            temp = temp->right;
        else return temp;
    }
    return temp;
}

void printanak(BinaryTreePtr bst, char nama[]){
    TreeNodePtr temp = bst_search(bst->root, nama);
    if(temp->left != NULL && temp->right != NULL) printf("%s %s\n", temp->left->nama, temp->right->nama);
    else if(temp->left != NULL && temp->right == NULL) printf("%s -\n", temp->left->nama);
    else if(temp->right != NULL && temp->left == NULL) printf("- %s\n", temp->right->nama);
    else printf("Anak-aNakkuu lagi otw Gan\n");
}

bool bst_find(BinaryTreePtr bst, char nama[]) {
    TreeNodePtr temp = bst_search(bst->root, nama);
    if (temp == NULL) return false;
    if (strcmp(temp->nama, nama) == 0) return true;
    else return false;
}

TreeNodePtr bst_make(TreeNodePtr root, char nama[]) {
    if (root == NULL)
        return create_node(nama);
    if (strcmp(root->nama, nama) < 0)
        root->left = bst_make(root->left, nama);
    else if (strcmp(root->nama, nama) > 0)
        root->right = bst_make(root->right, nama);

    return root;
}

void bst_insert(BinaryTreePtr bst, char nama[]) {
    if (!bst_find(bst, nama)) {
        bst->root = bst_make(bst->root, nama);
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
        printf("%s ", root->nama);
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
    BinaryTreePtr rachel = bst_init();
    char nama[25];
    int n,t;
    scanf("%d %d", &n, &t);
    char posisi[25];
    while(n--){
        scanf("%s", nama);
        bst_insert(rachel, nama);
    }
    while(t--){
        scanf("%s", posisi);
        if(strcmp(posisi, "anak") == 0){
            scanf("%s", nama);
            printanak(rachel, nama);
        }
        if(strcmp(posisi, "ibu") == 0){
            scanf("%s", nama);
            printibu(rachel, nama);
        }
    }
    return 0;
}
