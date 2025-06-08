#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void push(node **top, int newData) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);

    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(node *top) {
    return top == NULL;
}

void top(node *top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("The top of the stack is %d\n\n", top->data);
}

void printStack(node *top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("STACK ELEMENTS:\n");
    node *ptr;

    for(ptr = top; ptr != NULL; ptr = ptr->next) printf("|  %d  |\n", ptr->data);
    printf("\n");
}

int main() {
    node *nodeStack = NULL;

    push(&nodeStack, 30);
    push(&nodeStack, 20);
    push(&nodeStack, 70);
    push(&nodeStack, 60);

    printStack(nodeStack);

    top(nodeStack);
}