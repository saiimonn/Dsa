#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *s) { //Initialize the top of the stack array
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return (s->top == -1) ? true : false;
}

bool isFull(Stack *s) {
    return (s->top == MAX) ? true : false;
}

void push(Stack *s, int newData) { //Push data at the top of the stack
    if(isFull(s)){
        printf("Stack overflow\n");
        return;
    }

    s->data[++(s->top)] = newData;
    printf("%d pushed to stack\n", newData);
}

int pop(Stack *s) { //Remove top element of the stack
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    int popped = s->data[(s->top)--];
    printf("%d popped from stack.\n", popped);
    return popped;
}

int top(Stack *s) { //Returns top element of the stack
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    printf("Top element: %d\n", s->data[s->top]);
    return s->data[s->top];
}

void display(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents from top to bottom:\n");
    for(int i = s->top; i >= 0; i--) printf("|  %d  |\n", s->data[i]);
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                top(&stack);
                break;

            case 4:
                display(&stack);
                break;

            case 5:
                if (isEmpty(&stack)) printf("Stack is empty.\n");
                else printf("Stack is not empty.\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}