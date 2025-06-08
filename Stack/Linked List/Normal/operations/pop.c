#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int isEmpty(node *top) {
    return top == NULL;
}

void push(node **top, int newData) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);

    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;
}

void pop(node **top) {
    if(isEmpty(*top)) {
        printf("Stack is empty\n");
        return;
    }

    node *temp = *top;
    *top = temp->next;
    free(temp);

    printf("Top of stack popped\n\n");
}

void printStack(node *top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("STACK ELEMENTS:\n");

    node *ptr;
    for(ptr = top; ptr != NULL; ptr = ptr->next) printf("|  %d  |\n", ptr->data);
}

int main() {
    node *nodeStack = NULL;

    push(&nodeStack, 10);
    push(&nodeStack, 20);
    push(&nodeStack, 30);

    printf("ORIGINAL STACK:\n");
    printStack(nodeStack);

    pop(&nodeStack);

    printf("POPPED STACK:\n");
    printStack(nodeStack);
}