#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct node {
    int kode;
    struct node *next;
} Node, *NodePtr;

typedef struct stackType {
    NodePtr top;
} StackType, *Stack;

Stack initStack() {
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp -> top = NULL;
    return sp;
}

void push(Stack S, int d) {
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np -> kode = d;
    np -> next = S -> top;
    S -> top = np;
}

int pop(Stack S) {
    int hold = S -> top -> kode;
    NodePtr temp = S -> top;
    S -> top = S -> top -> next;
    free(temp);
    return hold;
}

int empty(Stack S) {
    return (S -> top == NULL);
}

int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--){
        Stack one = initStack();
        Stack zero = initStack();
        scanf("%d", &n);
        int tmp, d = 0, sum = 0;
        while(n != 0){
            tmp = n % 2;
            if(tmp == 1){
                push(one, tmp);
                d++;
            }
            else{
                push(zero, tmp);
                d++;
            }
            n = n / 2;
        }
        while(!empty(one)){
            int hold = pop(one);
            push(zero, hold);
        }
        d -= 1;
        while(!empty(zero)){
            int hold = pop(zero);
            sum = sum + (hold * pow(2,d--));
        }
        printf("%d\n", sum);
    }
    return 0;
}
