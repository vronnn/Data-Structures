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

void print(Stack S){
    if(empty(S)) return;

    int x = S->top->key;
    pop(S);
    printf("%d ", x);

    print(S);
    push(S,x);
}

unsigned size(Stack S) {
    return S->size;
}

int main(int argc, char const *argv[])
{
    Stack ian = initStack(),
          aan = initStack();

    int soal, nilai;
    char query[15];
    scanf("%d", &soal);
    while(soal--){
        scanf("%s", query);
        if(strcmp(query, "IAN") == 0){
            scanf("%d", &nilai);
            push(ian, nilai);
        }
        if(strcmp(query, "AAN") == 0){
            scanf("%d", &nilai);
            push(aan, nilai);
        }
        if(strcmp(query, "mundur") == 0){
            if((!empty(ian)) && (!empty(aan))){
                pop(ian);
                pop(aan);
            }
            else continue;
        }
    }
    if(size(ian) == (size(aan))){
        while((!empty(ian)) && (!empty(aan))){
            if(top(ian) == top(aan)){
                pop(ian);
                pop(aan);
            }
            else{
                printf("SIP SI PALING JUJUR");
                break;
            }
        }
        if((empty(ian)) && (empty(aan))) printf("DIH TUKANG NYONTEK");
        if((empty(ian)) && (!empty(aan))) printf("SIP SI PALING JUJUR");
        if((!empty(ian)) && (empty(aan))) printf("SIP SI PALING JUJUR");
    }
    else{
        printf("SIP SI PALING JUJUR");
    }
    return 0;
}
