#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return (s->top == MAX) ? true : false;
}

bool isEmpty(Stack *s) {
    return (s->top == -1) ? true : false;
}

void push(Stack *s, int newData) {
    if(isFull(s)) {
        printf("Stack overflow\n");
        return;
    }

    s->data[++(s->top)] = newData;
    printf("%d pushed to the top of the stack\n\n");
}

void pop(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    int popped = s->data[(s->top)--];
    printf("%d popped from list\n\n", popped);
}

void printStack(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("STACK ELEMENTS:\n");
    for(int i = s->top; i >= 0; i--) printf("|  %d  |\n", s->data[i]);
}

int main() {
    Stack stack;
    initialize(&stack);

    int num, newData;

    printf("Enter size of stack: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        printf("Enter element: ");
        scanf("%d", &newData);

        push(&stack, newData);
    }

    printf("Before popping:\n");
    printStack(&stack);

    pop(&stack);

    printf("After popping:\n");
    printStack(&stack);
}