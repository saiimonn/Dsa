#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void insertFirst(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertLast(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    node *ptr;
    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = newNode;
}

void insertAtIndex(node **head, int data, int idx) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    node *trav;
    int i = 0;
    for(trav = *head; trav != NULL && i < idx - 1; trav = trav->next, i++) {}

    if(trav == NULL) {
        printf("Out of bounds\n");
        return;
    }

    newNode->next = trav->next;
    trav->next = newNode;
}

void insertSorted(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    node *trav;
    for(trav = *head; trav->next != NULL && data > trav->next->data; trav = trav->next) {}

    newNode->next = trav->next;
    trav->next = newNode;
}

void display(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    insertFirst(&head, 50);
    insertFirst(&head, 30);
    insertLast(&head, 70);
    insertAtIndex(&head, 40, 1);   // between 30 and 50
    insertSorted(&head, 60);       // should go between 50 and 70

    display(head);  // Expected: 30 -> 40 -> 50 -> 60 -> 70 -> NULL
}