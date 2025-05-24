#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
} Prisoner;

typedef struct {
    Prisoner prisoner[MAX];
    int count;
} List;

void initList(List *list) {
    list->count = 0;
}

void deleteFirst(List *list) { //Delete the first element of the array (index 0)
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count - 1; i++) list->prisoner[i] = list->prisoner[i + 1];

    list->count--;
}

void deleteLast(List *list) { //Delete the last element of the array
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    list->count--;
}

void deletePrisoner(List *list, const char *name) { //Delete element with string name
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    int idx = 0;
    for(; idx < list->count && strcmp(list->prisoner[idx].name, name) != 0; idx++) {}

    if(idx == list->count) {
        printf("Prisoner not found\n");
        return;
    }

    for(int i = idx; i < list->count - 1; i++) list->prisoner[i] = list->prisoner[i + 1];

    list->count--;
}

void deleteAtIndex(List *list, int idx) { //Delete element at index idx
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    } else if (idx < 0 || idx >= list->count) {
        printf("idx is out of bounds\n");
        return;
    }

    for(int i = idx; i < list->count - 1; i++) list->prisoner[i] = list->prisoner[i + 1];

    list->count--;
}

void display(List *list) {
    if (list->count == 0) {
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i < list->count; i++)
        printf("[%s, %d] ", list->prisoner[i].name, list->prisoner[i].age);
    printf("\n");
}

int main() {
    List myList;
    initList(&myList);

    strcpy(myList.prisoner[0].name, "Kai");
    myList.prisoner[0].age = 25;
    strcpy(myList.prisoner[1].name, "Jay");
    myList.prisoner[1].age = 30;
    strcpy(myList.prisoner[2].name, "Nya");
    myList.prisoner[2].age = 27;
    myList.count = 3;

    display(&myList);
    deletePrisoner(&myList, "Jay");
    display(&myList);
}