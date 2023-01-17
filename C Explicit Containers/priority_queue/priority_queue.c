#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// default priority : minimum value

typedef struct pqnode_t {
    int data;
    struct pqnode_t *next;
} pqueueNode, *pqueueNodePtr;

typedef struct pqueue_t {
    pqueueNodePtr top;
    unsigned _size;
} priorityQueueType, *priority_queue;

priority_queue init()
{
    priority_queue pq = (priority_queue) malloc(sizeof(priorityQueueType));
    pq->top = NULL;
    pq->_size = 0;
    return pq;
}

bool empty(priority_queue pq) {
    return (pq->top == NULL);
}

void push(priority_queue pq, int value)
{
    pqueueNodePtr temp = pq->top;
    pqueueNodePtr newNode = (pqueueNodePtr) malloc (sizeof(pqueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (empty(pq)) {
        pq->top = newNode;
        return;
    }

    if (value < pq->top->data) {
        newNode->next = pq->top;
        pq->top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pop(priority_queue pq)
{
    if (!empty(pq)) {
        pqueueNodePtr temp = pq->top;
        pq->top = pq->top->next;
        free(temp);
    }
}

int top(priority_queue pq) {
    if (!empty(pq))
        return pq->top->data;
    else 
        return 0;
}

int main()
{
    // create and init a priority_queue
    priority_queue myPque = init();

    // insert random numbers to test pqueue's sort property
    for(int i=1; i<=5; i++)
        push(myPque, 1+(rand()%10));

    // cetak isi pque
    while (!empty(myPque)) {
        printf("%d ", top(myPque));
        pop(myPque);
    }
    puts("");

    return 0;
}