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
    if (!newNode) exit(0);

    newNode->data = newData;
    newNode->next = *top;
    *top = newNode;

    printf("%d pushed to the top of the stack\n\n", newData);
}

void pop(STACK *top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    STACK temp = *top;
    *top = temp->next;
    free(temp);

    printf("Popped the element at the top of the list\n\n");
}

void top(STACK top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("%d is the element at the top of the stack\n\n", top->data);
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
    STACK stack = NULL;
    
    int choice;

    do {
        printf("\n---Stack Linked List Implementation---\n");
        printf("1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                int newData;
                printf("Enter element to push: ");
                scanf("%d", &newData);
                push(&stack, newData);
                break;
            
            case 2:
                pop(&stack);
                break;

            case 3:
                top(stack);
                break;

            case 4:
                printStack(stack);
                break;
            
            case 5:
                printf("exiting...\n");
                break;

            default: 
                printf("Invalid option!\n");
                break;
        }
    } while(choice != 5);
}