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

    printf("Pushed %d to the top\n\n", newData);
}

void pop(STACK *top) {
    if(isEmpty(*top)) {
        printf("Stack is empty\n");
        return;
    }

    STACK temp = *top;
    *top = temp->next;
    free(temp);

    printf("Popped top of stack\n\n");
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
    push(&stackList, 50);
    push(&stackList, 30);
    push(&stackList, 90);

    printf("Original Stack:\n");
    printStack(stackList);

    pop(&stackList);

    printf("New Stack:\n");
    printStack(stackList);
}