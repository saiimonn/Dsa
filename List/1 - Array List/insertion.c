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

void insertBeginning(List *list, int val) {
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    for(int i = list->size; i > 0; i--) list->data[i] = list->data[i - 1];

    list->data[0] = val;
    list->size++;
}

void insertEnd(List *list, int val) {
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    list->data[list->size++] = val;
}

void insertAtIndex(List *list, int val, int idx) {
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    for(int i = list->size; i > idx; i--) list->data[i] = list->data[i - 1];

    list->data[idx] = val;
    list->size++;
}

void insertSorted(List *list, int val) {
    if(list->size >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    int idx;
    for(idx = 0; idx < list->size && val < list->data[idx]; idx++) {}

    for(int i = list->size; i > idx; i--) list->data[i] = list->data[i - 1];

    list->data[idx] = val;
    list->size++;
}

int main() {
    List myList;

    initializeList(&myList);
}