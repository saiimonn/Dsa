#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

typedef struct node{
    Student students;
    struct node *next;
} node;

void deleteAtStart(node **head) {
    if(!(*head)) {
        printf("List is empty\n");
        return;
    }

    node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(node **head) {
    if(!(*head)) {
        printf("List is empty\n");
        return;
    }

    node *temp;
    if((*head)->next == NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node *prev;
    for(temp = *head, prev = NULL; temp->next != NULL; prev = temp, temp = temp->next) {}

    prev->next = temp->next;
    free(temp);
}

void deleteAtIdx(node **head, int idx) {
    if(!(*head)) {
        printf("List is empty\n");
        return;
    }

    node *temp;
    if(idx == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node *prev;
    int i = 0;
    for(temp = *head, prev = NULL; i < idx && temp != NULL; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Index is out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void deleteNodeWithName(node **head, const char *name) {
    if(!(*head)) {
        printf("List is empty\n");
        return;
    }

    node *temp;
    if(strcmp((*head)->students.name, name) == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node *prev;
    for(temp = *head, prev = NULL; temp != NULL && strcmp(temp->students.name, name) != 0; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Person doesn't exist in the list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(node *head) {
    while (head != NULL) {
        printf("Name: %s, Age: %d, Grade: %.2f\n", head->students.name, head->students.age, head->students.grade);
        head = head->next;
    }
}

int main() {
    node *head = NULL;
}