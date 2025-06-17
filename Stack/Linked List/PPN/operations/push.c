#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *STACK, node;

void push(STACK *top, int newData) {
    STACK newNode = malloc(sizeof(node));
    if(!newNode) exit(0);

    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;

    printf("%d added to the top of the list\n\n", newData);
}

int isEmpty(STACK top) {
    return top == NULL;
}

void printStack(STACK top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    STACK ptr;
    for(ptr = top; ptr != NULL; ptr = ptr->next) printf("|  %d  |\n", ptr->data);
}

int main() {
    STACK nodeStack = NULL;

    int num, newData;

    printf("Enter the size of stack: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        printf("Enter element: ");
        scanf("%d", &newData);

        push(&nodeStack, newData);
    }

    printStack(nodeStack);
}