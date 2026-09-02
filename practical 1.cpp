#include <stdio.h>

#define MAX 100

// Structure to store student details
struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

// Function to input student details using a pointer
void inputStudent(struct Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Age: ");
    scanf("%d", &s->age);

    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

// Function to display student details using a pointer
void displayStudent(struct Student *s) {
    printf("\nRoll Number : %d", s->rollNo);
    printf("\nName        : %s", s->name);
    printf("\nAge         : %d", s->age);
    printf("\nMarks       : %.2f\n", s->marks);
}

int main() {
    struct Student students[MAX];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    // Input student records
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details of Student %d ---\n", i + 1);
        inputStudent(&students[i]);
    }

    // Display student records
    printf("\n\n===== STUDENT RECORDS =====\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d:", i + 1);
        displayStudent(&students[i]);
    }

    return 0;
}

