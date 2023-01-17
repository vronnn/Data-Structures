#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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
    Stack kotor = initStack();
    Stack sabun = initStack();
    Stack bersih = initStack();

    int glass, tmp;
    scanf("%d", &glass);
    while(glass--){
        scanf("%d", &tmp);
        push(kotor, tmp);
    }
    int com, n;
    scanf("%d", &com);
    char cmd[com];
    while(com--){
        scanf("%s", cmd);
        if(strcmp(cmd, "CLEAN") == 0){
            if(empty(kotor)) continue;
            else{
                int hold = pop(kotor);
                push(sabun, hold);
            }
        }
        else if(strcmp(cmd, "RINSE") == 0){
            if(empty(sabun)) continue;
            else{
                int hold = pop(sabun);
                push(bersih, hold);
            }
        }
        else{
            scanf("%d", &n);
            while(n--){
                int hold = pop(kotor);
                push(bersih, hold);
            }
        }
    }
    if(empty(kotor)) push(kotor, 0);
    if(empty(sabun)) push(sabun, 0);
    if(empty(bersih)) push(bersih, 0);

    printf("KOTOR: ");
    while(!empty(kotor)) printf("%d ", pop(kotor));
    printf("\n");
    printf("SABUN: ");
    while(!empty(sabun)) printf("%d ", pop(sabun));
    printf("\n");
    printf("BERSIH: ");
    while(!empty(bersih)) printf("%d ", pop(bersih));

    return 0;
}
