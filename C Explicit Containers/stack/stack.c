// Implented as a list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node *next;
} Node, *NodePtr;

typedef struct stackType {
    NodePtr top;
    unsigned size;
} StackType, *Stack;

Stack initStack() {
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp -> top = NULL;
    sp -> size = 0;
    return sp;
}

int empty(Stack S) {
    return (S -> top == NULL);
}

void push(Stack S, int d) {
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np -> key = d;
    np -> next = S -> top;
    S -> top = np;
    S -> size++;
}

void pop(Stack S) {
    if(!empty(S)){
        NodePtr temp = S -> top;
        S -> top = S -> top -> next;
        free(temp);
        S -> size--;
    }
}

int top(Stack S){
    if(!empty(S))
        return S->top->key;
    return 0;
}

unsigned size(Stack S) {
    return S->size;
}

void print(Stack S){
    if(empty(S)) return;

    int x = S->top->key;
    pop(S);
    printf("%d ", x);

    print(S);
    push(S,x);
}

int main()
{
    // create and init stack
    Stack nums = initStack();
    // insert elements
    for(int i=1; i<=10; i++)
        push(nums,i);
    // print stack
    printf("stack init value: \n");
    print(nums);
    puts("");
    // top()
    printf("stack's top element : %d\n", top(nums));
    // pop elements
    for(int i=1; i<=5; i++)
        pop(nums);
    // print stack
    printf("stack after popping 5 elements : \n");
    print(nums);
    puts("");
    return 0;
}