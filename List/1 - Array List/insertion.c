#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} List;

void initializeList(List* list) {
    list->size = 0;
}

void insertBeginning(List *list, int val) { //Insert int val at the start of the array
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    for(int i = list->size; i > 0; i--) list->data[i] = list->data[i - 1];

    list->data[0] = val;
    list->size++;
}

void insertEnd(List *list, int val) { //Insert int val at the end of the array
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    list->data[list->size++] = val;
}

void insertAtIndex(List *list, int val, int idx) { //Inserting int val inside array at specific position idx
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    } else if (idx < 0 || idx > list->size) {
        printf("Index is out of bounds\n");
        return;
    }

    for(int i = list->size; i > idx; i--) list->data[i] = list->data[i - 1];

    list->data[idx] = val;
    list->size++;
}

void insertSorted(List *list, int val) { //Insert int val inside array while keeping array sorted
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    int idx;
    for(idx = 0; idx < list->size && val > list->data[idx]; idx++) {}

    for(int i = list->size; i > idx; i--) list->data[i] = list->data[i - 1];

    list->data[idx] = val;
    list->size++;
}

void display(List *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    List myList;
    initializeList(&myList);

    insertEnd(&myList, 30);
    insertBeginning(&myList, 10);
    insertAtIndex(&myList, 20, 1);
    insertSorted(&myList, 25);

    display(&myList);  // Expected: 10 20 25 30
}