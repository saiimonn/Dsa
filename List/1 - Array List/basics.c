#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

typedef struct {
    Employee employees[MAX];
    int count;
} List;

void initialize(List *list) {
    list->count = 0;
}

void insert(List *list, Employee newEmployee) {
    if(list->count >= MAX) {
        printf("List is at max capacity\n");
        return;
    }

    int idx;
    for(idx = 0; idx < list->count && list->employees[idx].salary < newEmployee.salary; idx++) {}

    for(int i = list->count; i > idx; i--) list->employees[i] = list->employees[i - 1];

    list->employees[idx] = newEmployee;
    list->count++;
}

void delete(List *list, const char *name) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    int idx = 0;
    for(;idx < list->count && strcmp(list->employees[idx].name, name) != 0; idx++) {}

    if(idx == list->count) {
        printf("Employee not found\n");
        return;
    }

    for(int i = idx; i < list->count - 1; i++) list->employees[i] = list->employees[i + 1];

    list->count--;
}

void print(List *list) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i =0; i < list->count; i++) printf("{%s - %d - %.2f}, ", list->employees[i].name, list->employees[i].age, list->employees[i].salary);
    printf("\n");
}

void update(List *list, const char *name) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->employees[i].name, name) == 0) {
            printf("Enter new age: ");
            scanf("%d", &list->employees[i].age);
            printf("Enter new salary: ");
            scanf("%f", &list->employees[i].salary);
            return;
        }
    }
}

bool search(List *list, const char *name) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->employees[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    List employeeList;
    initialize(&employeeList);

    int choice;
    char name[50];
    Employee emp;

    do {
        printf("\n========== Employee Management ==========\n");
        printf("[1] Insert Employee\n");
        printf("[2] Delete Employee\n");
        printf("[3] Update Employee\n");
        printf("[4] Search Employee\n");
        printf("[5] Print All Employees\n");
        printf("[0] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(emp.name, sizeof(emp.name), stdin);
                emp.name[strcspn(emp.name, "\n")] = 0; // remove newline

                printf("Enter age: ");
                scanf("%d", &emp.age);

                printf("Enter salary: ");
                scanf("%f", &emp.salary);
                getchar(); // consume newline

                insert(&employeeList, emp);
                break;

            case 2:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                delete(&employeeList, name);
                break;

            case 3:
                printf("Enter name to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                update(&employeeList, name);
                break;

            case 4:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                if (search(&employeeList, name))
                    printf("%s found in the list.\n", name);
                else
                    printf("%s not found.\n", name);
                break;

            case 5:
                print(&employeeList);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}