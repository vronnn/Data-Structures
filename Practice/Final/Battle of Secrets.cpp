#include <bits/stdc++.h>
using namespace std;

vector <int> temp, danger;

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

bool bst_find(BinaryTreePtr bst, int value) {
    TreeNodePtr temp = bst_search(bst->root, value);
    if (temp == NULL) return false;
    if (temp->key == value) return true;
    else return false;
}

TreeNodePtr bst_minnode(TreeNodePtr node) {
    TreeNodePtr currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

TreeNodePtr bst_delete(TreeNodePtr root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = bst_delete(root->right, value);
    else if (value < root->key)
        root->left = bst_delete(root->left, value);
    else {

        if (root->left == NULL) {
            TreeNodePtr rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            TreeNodePtr leftChild = root->left;
            free(root);
            return leftChild;
        }

        TreeNodePtr temp = bst_minnode(root->right);
        root->key     = temp->key;
        root->right   = bst_delete(root->right, temp->key);
    }
    return root;
}

void bst_remove(BinaryTreePtr bst, int value) {
    if (bst_find(bst, value)) {
        bst->root = bst_delete(bst->root, value);
        bst->size--;
    }
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
        temp.push_back(root->key);
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

void left(TreeNodePtr root)
{
    if(root){
        danger.push_back(root->key);
        if(root->left != NULL)
            left(root->left);
        else
            left(root->right);
    }
}

void right(TreeNodePtr root)
{
    if(root){
        danger.push_back(root->key);
        if(root->right != NULL)
            right(root->right);
        else
            right(root->left);
    }
}

void left_side(BinaryTreePtr bst) {
    left(bst->root);
}

void right_side(BinaryTreePtr bst) {
    right(bst->root);
}

bool check_child(BinaryTreePtr bst, int value) {
    TreeNodePtr temp = bst_search(bst->root, value);
    if(temp->left == NULL && temp->right == NULL)
        return false;
    return true;
}

int main()
{
    BinaryTreePtr form = bst_init();
    int n,x,tag = 0;
    cin >> n;
    while(n--){
        cin >> x;
        bst_insert(form, x);
    }
    inorder(form);
    left_side(form);
    right_side(form);

    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < danger.size(); j++){
            if(temp[i] == danger[j]){
                temp.erase(temp.begin() + i);
                i--;
                break;
            }
        }
    }

    for(int i = 0; i < temp.size(); i++){
        if(check_child(form, temp[i])){
            cout << temp[i] << " ";
            tag = 1;
        }
    }
    if(!tag)
        cout << "It's not safe";

    return 0;
}
