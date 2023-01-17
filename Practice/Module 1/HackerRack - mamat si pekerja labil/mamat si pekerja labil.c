#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct dnode_t {
    int data;
    struct dnode_t
        *next,
        *prev;
} dListNode, *dlistNodePtr;

typedef struct deque_t {
    dlistNodePtr
        head,
        tail;
    unsigned _size;
} dequeType, *deque;

dlistNodePtr __createNode(int value)
{
    dlistNodePtr newNode = (dlistNodePtr) malloc (sizeof(dListNode));

    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

deque init()
{
    deque d = (deque) malloc(sizeof(dequeType));
    d->head = d->tail = NULL;
    d->_size = (unsigned) 0;
    return d;
}

bool empty(deque d) {
    return (d->head == NULL && d->tail == NULL);
}

void push_front(deque d, int value)
{
    dlistNodePtr newNode = __createNode(value);
    if (newNode) {
        d->_size++;
        if (empty(d)) {
            d->head = newNode;
            d->tail = newNode;
            return;
        }

        newNode->next = d->head;
        d->head->prev = newNode;
        d->head = newNode;
    }
}

void push_back(deque d, int value)
{
    dlistNodePtr newNode = __createNode(value);
    if (newNode) {
        d->_size++;
        if (empty(d)) {
            d->head = newNode;
            d->tail = newNode;
            return;
        }

        d->tail->next = newNode;
        newNode->prev = d->tail;
        d->tail = newNode;
    }
}

int front(deque d) {
    if (!empty(d)) {
        return (d->head->data);
    }
    return 0;
}

int back(deque d) {
    if (!empty(d)) {
        return (d->tail->data);
    }
    return 0;
}

void pop_front(deque d)
{
    if (!empty(d)) {
        dlistNodePtr temp = d->head;
        if (d->head == d->tail) {
            d->head = NULL;
            d->tail = NULL;
            free(temp);
        }
        else {
            d->head = d->head->next;
            d->head->prev = NULL;
            free(temp);
        }
        d->_size--;
    }
}

void pop_back(deque d)
{
    if (!empty(d)) {
        dlistNodePtr temp;
        if (d->head == d->tail) {
            temp = d->head;
            d->head = NULL;
            d->tail = NULL;
            free(temp);
        }
        else {
            temp = d->tail;
            d->tail = d->tail->prev;
            d->tail->next = NULL;
            free(temp);
        }
        d->_size--;
    }
}

void print(deque d)
{
    dlistNodePtr temp = d->head;
    while(temp != d->tail->next){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

void reverse_print(deque d)
{
    dlistNodePtr temp = d->tail;
    while(temp != d->head->prev){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    puts("");
}

int main()
{
    deque act = init();
    int q,n, rev = 0;
    scanf("%d", &q);
    char ques[20];
    while(q--){
        scanf("%s", ques);
        if(strcmp(ques, "Reverse") == 0){
            rev = !rev;
        }
        if((rev == 0) && (strcmp(ques, "Front") == 0)){
            if(!empty(act)){
                printf("%d\n", front(act));
                pop_front(act);
            }
            else printf("Mamat gabut\n");
        }
        if((rev == 1) && (strcmp(ques, "Front") == 0)){
            if(!empty(act)){
                printf("%d\n", back(act));
                pop_back(act);
            }
            else printf("Mamat gabut\n");
        }
        if((rev == 0) && strcmp(ques, "Back") == 0){
            if(!empty(act)){
                printf("%d\n", back(act));
                pop_back(act);
            }
            else printf("Mamat gabut\n");
        }
        if((rev == 1) && strcmp(ques, "Back") == 0){
            if(!empty(act)){
                printf("%d\n", front(act));
                pop_front(act);
            }
            else printf("Mamat gabut\n");
        }
        if((rev == 0) &&(strcmp(ques, "Push_Back") == 0)){
            scanf("%d", &n);
            push_back(act, n);
        }
        if((rev == 1) &&(strcmp(ques, "Push_Back") == 0)){
            scanf("%d", &n);
            push_front(act, n);
        }
        if((rev == 0) &&(strcmp(ques, "toFront") == 0)){
            scanf("%d", &n);
            push_front(act, n);
        }
        if((rev == 1) && (strcmp(ques, "toFront") == 0)){
            scanf("%d", &n);
            push_back(act, n);
        }
        if((rev == 0) && (strcmp(ques, "List") == 0)){
            if(!empty(act))
                print(act);
            else
                printf("Mamat gabut\n");
        }
        if((rev == 1) && (strcmp(ques, "List") == 0)){
            if(!empty(act))
                reverse_print(act);
            else
                printf("Mamat gabut\n");
        }
    }
    return 0;
}
