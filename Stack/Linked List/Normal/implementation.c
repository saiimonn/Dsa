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

    printf("%d pushed to the top of the list\n");
}

void pop(node **top) {
    if(isEmpty(*top)) {
        printf("The stack is empty\n");
        return;
    }

    node *temp = *top;
    *top = temp->next;
    free(temp);

    printf("The top of the stack is popped\n");
}

void top(node *top) {
    if(isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("The top of the stack is %d\n", top->data);
}

void display(node *top) {
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
    node *stackTop = NULL;

    int choice;

    do {
        printf("\n---Stack Linked List Implementation---\n");
        printf("1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                int newData;
                printf("Enter element: ");
                scanf("%d", &newData);
                push(&stackTop, newData);
                break;
            
            case 2:
                pop(&stackTop);
                break;

            case 3:
                top(&stackTop);
                break;

            case 4:
                display(&stackTop);
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