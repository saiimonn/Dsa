#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *STACK, node;

int isEmpty(STACK top) {
    return top == NULL;
}

void push(STACK *top, int newData) {
    STACK newNode = malloc(sizeof(node));
    if(!newNode) exit(0);

    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;

    printf("Pushed %d to the top of the stack\n\n", newData);
}

void top(STACK top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("%d is the top element of the stack\n\n", top->data);
}

void printStack(STACK top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    STACK ptr;
    for(ptr = top; ptr != NULL; ptr = ptr->next) printf("|  %d  |\n", ptr->data);
    printf("\n");
}

int main() {
    STACK stackList = NULL;

    push(&stackList, 10);
    push(&stackList, 40);
    push(&stackList, 20);

    printf("Original Stack:\n");
    printStack(stackList);

    top(stackList);
}