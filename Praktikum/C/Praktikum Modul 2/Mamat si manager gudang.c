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

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode, *nodeptr;

typedef struct queue_t {
    nodeptr front,
            rear;
    unsigned size;
} Queue, *queueptr;

queueptr init_queue()
{
    queueptr que = (queueptr) malloc(sizeof(Queue));
    que->size = 0;
    que->front = NULL;
    que->rear = NULL;
    return que;
}

bool empty_que(queueptr que) {
    return (que->front == NULL && que->rear == NULL);
}

void push_queue(queueptr que, int value)
{
    nodeptr newNode = (nodeptr) malloc(sizeof(QueueNode));
    if (newNode) {
        que->size++;
        newNode->data = value;
        newNode->next = NULL;

        if (empty_que(que))
            que->front = que->rear = newNode;
        else {
            que->rear->next = newNode;
            que->rear = newNode;
        }
    }
}

void pop_queue(queueptr que)
{
    if (!empty_que(que)) {
        nodeptr temp = que->front;
        que->front = que->front->next;
        free(temp);

        if (que->front == NULL)
            que->rear = NULL;
        que->size--;
    }
}

int front_queue(queueptr que)
{
    if (!empty_que(que)) {
        return (que->front->data);
    }
    return 0;
}

BinaryTreePtr bst_init() {
    BinaryTreePtr bst = (BinaryTreePtr) malloc(sizeof(BinaryTree));
    bst->root = NULL;
    bst->size = 0u;
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
    int c = 0;
    if (root) {
        printf("%d ", root->key);
        c++;
        preor(root->left);
        preor(root->right);
    }
}

void preorder(BinaryTreePtr bst){
    preor(bst->root);
}

void inor(TreeNodePtr root, queueptr que) {
    if (root) {
        inor(root->left, que);
        push_queue(que, root->key);
        inor(root->right, que);
    }
}

void inorder(BinaryTreePtr bst, queueptr que){
    inor(bst->root, que);
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
    BinaryTreePtr gudang = bst_init();
    queueptr temp = init_queue();
    int q, c, n, a = 1;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &c);
        if(c == 1){
            scanf("%d", &n);
            bst_insert(gudang, n);
        }
        if(c == 2){
            scanf("%d", &n);
            if(bst_find(gudang, n))
                bst_remove(gudang, n);
            else printf("Tidak ada di gudang\n");
        }
        if(c == 3){
            scanf("%d", &n);
            if(bst_find(gudang, n)){
                inorder(gudang, temp);
                while(front_queue(temp) != n){
                    pop_queue(temp);
                    a++;
                }
                printf("%d\n", a);
                while(!empty_que(temp)){
                    pop_queue(temp);
                }
                a = 1;
            }
            else printf("Tidak ada di gudang\n");
        }
    }
    return 0;
}

