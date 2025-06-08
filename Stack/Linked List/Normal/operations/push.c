#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push(node **top, int newData) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;

    printf("%d pushed to the top of the stack\n\n", newData);
}

int isEmpty(node *top) {
    return top == NULL;
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