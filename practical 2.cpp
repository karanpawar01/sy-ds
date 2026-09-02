#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for an employee node
struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee *next;
};

struct Employee *head = NULL;

// Insert employee at the end
void insertEmployee() {
    struct Employee *newNode, *temp;

    newNode = (struct Employee *)malloc(sizeof(struct Employee));

    printf("Enter Employee ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Salary: ");
    scanf("%f", &newNode->salary);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Employee inserted successfully.\n");
}

// Delete employee by ID
void deleteEmployee() {
    int id;
    struct Employee *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Employee deleted successfully.\n");
}

// Search employee by ID
void searchEmployee() {
    int id;
    struct Employee *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nEmployee Found!\n");
            printf("ID     : %d\n", temp->id);
            printf("Name   : %s\n", temp->name);
            printf("Salary : %.2f\n", temp->salary);
            return;
        }

        temp = temp->next;
    }

    printf("Employee not found.\n");
}

// Display all employees
void displayEmployees() {
    struct Employee *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("\n===== Employee Records =====\n");

    while (temp != NULL) {
        printf("\nID     : %d", temp->id);
        printf("\nName   : %s", temp->name);
        printf("\nSalary : %.2f\n", temp->salary);

        temp = temp->next;
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n\n===== Employee Management System =====");
        printf("\n1. Insert Employee");
        printf("\n2. Delete Employee");
        printf("\n3. Search Employee");
        printf("\n4. Display Employees");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEmployee();
                break;

            case 2:
                deleteEmployee();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                displayEmployees();
                break;

            case 5:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

