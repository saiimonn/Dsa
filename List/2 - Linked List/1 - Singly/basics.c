#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Person;

typedef struct node {
    Person person;
    struct node *next;
} node, *LIST;

LIST createNode(Person person) {
    LIST newPerson = malloc(sizeof(node));
    if(!newPerson) exit(0);
    newPerson->person = person;
    newPerson->next = NULL;
    return newPerson;
}
 
void insert(LIST *head, Person person) { //sort by age
    LIST newPerson = createNode(person);

    if(*head == NULL || person.age < (*head)->person.age) {
        newPerson->next = *head;
        *head = newPerson;
        return;
    }

    LIST trav;
    for(trav = *head; trav->next != NULL && trav->next->person.age < person.age; trav = trav->next) {}

    newPerson->next = trav->next;
    trav->next = newPerson;
}

void delete(LIST *head, const char *name) {
    if(!(*head)) {
        printf("List is empty\n");
        return;
    }

    LIST temp;
    if(strcmp((*head)->person.name, name) == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    LIST prev;
    for(temp = *head, prev = NULL; temp != NULL && strcmp(temp->person.name, name) != 0; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Name not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void update(LIST *head, const char *name) {
    if(!(*head)) {
        printf("List is empty\n");
        return;
    }

    LIST trav;
    for(trav = *head; trav != NULL && strcmp(trav->person.name, name) != 0; trav = trav->next) {}

    if(trav == NULL) {
        printf("Person not found\n");
        return;
    }

    printf("Enter new age: ");
    scanf("%d", &trav->person.age);
    printf("Enter new salary: ");
    scanf("%f", &trav->person.salary);
}

bool search(LIST head, const char *name) {
    if(!head) {
        printf("List is empty\n");
        return;
    }

    LIST trav;
    for(trav = head; trav != NULL && strcmp(trav->person.name, name) != 0; trav = trav->next) {}

    return (trav == NULL) ? false : true;
}

void display(LIST head) {
    if(!head) {
        printf("List is empty\n");
        return;
    }

    LIST ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("{%s - %d - %.2f} -> ", ptr->person.name, ptr->person.age, ptr->person.salary);
    printf("NULL\n");
}

int main() {
    LIST head = NULL;
    int choice;
    char name[50];

    do {
        printf("\n=================\n");
        printf("Person Management\n");
        printf("=================\n");
        printf("1. Insert Person\n");
        printf("2. Delete Person\n");
        printf("3. Update Person\n");
        printf("4. Search Person\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        Person p;

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = '\0'; // remove newline
                printf("Enter age: ");
                scanf("%d", &p.age);
                printf("Enter salary: ");
                scanf("%f", &p.salary);
                insert(&head, p);
                printf("Inserted successfully.\n");
                break;

            case 2:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                delete(&head, name);
                break;

            case 3:
                printf("Enter name to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                update(&head, name);
                break;

            case 4:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                if (search(head, name)) printf("Person found.\n");
                else printf("Person not found.\n");
                break;

            case 5:
                printf("Current List:\n");
                display(head);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}