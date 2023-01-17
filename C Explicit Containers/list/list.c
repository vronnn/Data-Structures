#include <stdlib.h>
#include <stdbool.h>

typedef struct dnode_t {
    int data;
    struct dnode_t *next,
                   *prev;
} DListNode, *listNodePtr;


typedef struct dlist_t {
    listNodePtr head,
                tail;
    unsigned _size;
} listType, *list;

listNodePtr __createNode(int value)
{
    listNodePtr newNode = (listNodePtr) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

list init()
{
    list l = (list) malloc(sizeof(listType));
    l->head = l->tail = NULL;
    l->_size = (unsigned) 0;
    return l;
}

bool empty(list l) {
    return (l->head == NULL && l->tail == NULL);
}

void push_front(list l, int value)
{
    listNodePtr newNode = __createNode(value);
    if (newNode) {
        l->_size++;
        if (empty(l)) {
            l->head = newNode;
            l->tail = newNode;
            return;
        }

        newNode->next = l->head;
        l->head->prev = newNode;
        l->head = newNode;
    }
}

void push_back(list l, int value)
{
    listNodePtr newNode = __createNode(value);
    if (newNode) {
        l->_size++;
        if (empty(l)) {
            l->head = newNode;
            l->tail = newNode;
            return;
        }

        l->tail->next = newNode;
        newNode->prev = l->tail;
        l->tail = newNode;
    }
}

void insert(list l, unsigned index, int value)
{
    if (index == 0) { 
        push_front(l, value);
        return;
    }
    else if (index >= l->_size) {
        push_back(l, value);
        return;
    }

    listNodePtr newNode = __createNode(value);
    if (newNode) {
        if (empty(l)) {
            l->head = newNode;
            l->tail = newNode;
            return;
        }

        listNodePtr temp = l->head;

        unsigned _i = 0;
        while (_i < index - 1 && temp->next != NULL) {
            temp = temp->next;
            _i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        l->_size++;
    }
}

int front(list l) {
    if (!empty(l)) {
        return (l->head->data);
    }
    return 0;
}

int back(list l) {
    if (!empty(l)) {
        return (l->tail->data);
    }
    return 0;
}

void pop_front(list l)
{
    if (!empty(l)) {
        listNodePtr temp = l->head;
        if (l->head == l->tail) {
            l->head = NULL;
            l->tail = NULL;
            free(temp);
        }
        else {
            l->head = l->head->next;
            l->head->prev = NULL;
            free(temp);
        }
        l->_size--;
    }
}

void pop_back(list l)
{
    if (!empty(l)) {
        listNodePtr temp;
        if (l->head == l->tail) {
            temp = l->head;
            l->head = NULL;
            l->tail = NULL;
            free(temp);
        }
        else {
            temp = l->tail;
            l->tail = l->tail->prev;
            l->tail->next = NULL;
            free(temp);
        }
        l->_size--;
    }
}

#include <stdio.h>

int main()
{
    // create and init a list
    list myList = init();

    // list's operations :
    for(int i=1; i<=5; i++)
        push_back(myList, i);

    for(int i=10; i>=6; i--)
        push_front(myList, i);

    // list's content : [6, 7, 8, 9, 10, 1, 2, 3, 4, 5]
    pop_back(myList);
    pop_front(myList);

    // list's content : [7, 8, 9, 10, 1, 2, 3, 4]
    insert(myList, 6, 69);
    insert(myList, 1, 21);
    
    // list's content : [7, 21, 8, 9, 10, 1, 2, 69, 3, 4]
    // print list
    while (!empty(myList)) {
        printf("%d ", front(myList));
        pop_front(myList);
    }
    puts("");

    return 0;
}