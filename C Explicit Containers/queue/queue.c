#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *queueNodePtr;

typedef struct queue_t {
    queueNodePtr front,
            rear;
    unsigned size;
} queueType, *queue;

queue init()
{
    queue q = (queue) malloc(sizeof(queueType));
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool empty(queue q) {
    return (q->front == NULL && q->rear == NULL);
}

void push(queue q, int value)
{
    queueNodePtr newNode = (queueNodePtr) malloc(sizeof(Node));
    if (newNode) {
        q->size++;
        newNode->data = value;
        newNode->next = NULL;

        if (empty(q))
            q->front = q->rear = newNode;
        else {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

void pop(queue q)
{
    if (!empty(q)) {
        queueNodePtr temp = q->front;
        q->front = q->front->next;
        free(temp);

        if (q->front == NULL)
            q->rear = NULL;
        q->size--;
    }
}

int front(queue q)
{
    if (!empty(q)) {
        return (q->front->data);
    }
    return 0;
}

int size(queue q) {
    return q->size;
}

void print(queue q)
{
    queueNodePtr temp = q->front;
    while(temp != q->rear->next){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

int main()
{
    // create and init queue
    queue q = init();
    // insert elements
    for(int i=1; i<=5; i++)
        push(q, i);
    // print size() and init value
    printf("\nqueue : ") , print(q);
    printf("size : %d\n", size(q));
    // front()
    printf("queue's top element : %d\n", front(q));
    // pop an element
    pop(q) , printf("after popping last element : ");
    print(q);
    puts("");

    return 0;
}
