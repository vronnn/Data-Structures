#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct AVLNode_t{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode, *nodeptr;

typedef struct AVL_t{
    nodeptr root;
    unsigned int size;
}AVL, *avlptr;

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode, *qnodeptr;

typedef struct queue_t {
    qnodeptr front,
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
    qnodeptr newNode = (qnodeptr) malloc(sizeof(QueueNode));
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
        qnodeptr temp = que->front;
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

nodeptr create_node(int value) {
    nodeptr newNode = (nodeptr) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

nodeptr search(nodeptr root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int ser(avlptr avl, int value){
    nodeptr temp = search(avl->root, value);
    return temp->height;
}

int get_height(nodeptr node){
    if(node == NULL)
        return 0;
    return node->height;
}

int max(int a,int b){
    return (a > b)? a : b;
}

nodeptr right_rotate(nodeptr pivotNode) {

    nodeptr newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = max(get_height(pivotNode->left), get_height(pivotNode->right)) + 1;
    newParrent->height = max(get_height(newParrent->left), get_height(newParrent->right)) + 1;

    return newParrent;
}

nodeptr left_rotate(nodeptr pivotNode) {

    nodeptr newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(get_height(pivotNode->left), get_height(pivotNode->right)) + 1;
    newParrent->height = max(get_height(newParrent->left), get_height(newParrent->right)) + 1;

    return newParrent;
}

nodeptr leftCaseRotate(nodeptr node){
    return right_rotate(node);
}

nodeptr rightCaseRotate(nodeptr node){
    return left_rotate(node);
}

nodeptr leftRightCaseRotate(nodeptr node){
    node->left = left_rotate(node->left);
    return right_rotate(node);
}

nodeptr rightLeftCaseRotate(nodeptr node){
    node->right = right_rotate(node->right);
    return left_rotate(node);
}

int getBalanceFactor(nodeptr node){
    if(node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

nodeptr AVL_insert(avlptr avl, nodeptr node, int value){

    if(node == NULL) // udah mencapai leaf
        return create_node(value);
    if(value < node->data)
        node->left = AVL_insert(avl, node->left, value);
    else if(value >= node->data)
    	node->right = AVL_insert(avl, node->right, value);

    node->height = 1 + max(get_height(node->left), get_height(node->right));

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) // kiri zig-zag (left-right case)
		return leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data) // skewed kanan (kanan-kanan case)
        return rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data) // kanan zig-zag (right-left case)
        return rightLeftCaseRotate(node);

    return node;
}

nodeptr findMinNode(nodeptr node) {
    nodeptr currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

nodeptr AVL_remove(nodeptr node, int value){
    if(node == NULL)
        return node;
    if(value > node->data)
    	node->right = AVL_remove(node->right, value);
    else if(value < node->data)
    	node->left = AVL_remove(node->left, value);
    else{
        nodeptr temp;
        if((node->left == NULL)||(node->right == NULL)){
            temp = NULL;
            if(node->left == NULL) temp = node->right;
            else if(node->right == NULL) temp = node->left;

            if(temp == NULL){
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;  //mindah pointer node biar nunjuk apa yang ditunjuk temp

            free(temp); /*karena temp nya udh gakepake bukan karena temp nunjuk ke 4 dan ngefree 4,
                          4 masih ada tapi ga ditunjuk siapa2*/
        }
        else{
            temp = findMinNode(node->right);
            node->data = temp->data;
            node->right =AVL_remove(node->right, temp->data);
        }
    }

	if(node == NULL) return node;

    node->height = max(get_height(node->left),get_height(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
        return leftCaseRotate(node);

    if(balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        return leftRightCaseRotate(node);

    if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
        return rightCaseRotate(node);

    if(balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        return rightLeftCaseRotate(node);

    printf("%d\n", node->data);
    return node;
}

avlptr init_avl() {
    avlptr avl = (avlptr) malloc(sizeof(AVL));
    avl->root = NULL;
    avl->size = 0u;
    return avl;
}

bool isEmpty_avl(avlptr avl) {
    return avl->root == NULL;
}

bool find_avl(avlptr avl, int value) {
    nodeptr temp = search(avl->root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void insert_avl(avlptr avl, int value){
    avl->root = AVL_insert(avl, avl->root, value);
    avl->size++;
}

void remove_avl(avlptr avl, int value){
    if(find_avl(avl, value)){
        avl->root = AVL_remove(avl->root, value);
        avl->size--;
    }
}

void inor(nodeptr root, queueptr que) {
    if (root){
        inor(root->left, que);
        push_queue(que, root->data);
        inor(root->right, que);
    }
}

void inorder(avlptr avl, queueptr que){
    inor(avl->root, que);
}

void pre(nodeptr root) {
    if (root){
        printf("%d ", root->data);
        pre(root->left);
        pre(root->right);
    }
}

void preorder(avlptr avl){
    pre(avl->root);
}

void post(nodeptr root) {
    if (root){
        post(root->left);
        post(root->right);
        printf("%d ", root->data);
    }
}

void postorder(avlptr avl){
    post(avl->root);
}

int main(){
    avlptr rahel = init_avl();
    queueptr temp = init_queue();
    int x,y,c = 1, arr[1000], n = 0;
    while(scanf("%d", &x) != EOF){
        if(x == 1){
            scanf("%d", &y);
            insert_avl(rahel, y);
        }
        else if(x == 2){
            scanf("%d", &y);
            if(find_avl(rahel, y)){
                inorder(rahel, temp);
                while(!empty_que(temp)){
                    if(front_queue(temp) != y){
                        pop_queue(temp);
                        c++;
                    }
                    else{
                        arr[n] = c;
                        pop_queue(temp);
                        c++;
                        n++;
                    }
                }
                if(n == 1) printf("%d\n", arr[0]);
                else{
                    if(n % 2 == 0){
                        printf("%d\n", arr[n/2 - 1]);
                    }
                    else{
                        printf("%d\n", arr[n/2]);
                    }
                }
                c = 1;
                n = 0;
            }
            else printf("M44f h3l c4r1 4ngk4 l4in y4\n");
            c = 1;
            n = 0;
        }
    }
}
