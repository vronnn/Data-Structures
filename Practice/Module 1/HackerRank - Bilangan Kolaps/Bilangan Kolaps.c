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

int main()
{
    Stack bin = initStack(), temp = initStack();

    int t,n,tmp,opt,hold;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        while(n > 0){
            tmp = n % 2;
            push(bin, tmp);
            n = n / 2;
        }

        opt = 1;
        while(opt != 0){

            if(empty(bin)) opt = 0;
            else{
                while(!empty(bin)){
                    hold = top(bin);
                    pop(bin);
                    if(!empty(bin)){
                        if(top(bin) == hold){
                            opt = 2;
                            pop(bin);
                        }
                        else push(temp, hold);
                    }
                    else{
                        push(temp, hold);
                        if(opt == 2) opt = 1;
                        else opt = 0;
                    }
                }
                while(!empty(temp)){
                    hold = top(temp);
                    pop(temp);
                    if(!empty(temp)){
                        if(top(temp) == hold){
                            opt = 2;
                            pop(temp);
                        }
                        else push(bin, hold);
                    }
                    else{
                        push(bin, hold);
                        if(opt == 2) opt = 1;
                        else opt = 0;
                    }
                }
            }
        }
        int sum = 0;
        while (!empty(bin))
        {
            sum = sum * 2;
            if (top(bin) == 1) sum = sum + 1;
            pop(bin);
        }
        printf("%d\n", sum);
    }
    return 0;
}
