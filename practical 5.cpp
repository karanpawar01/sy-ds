#include <stdio.h>
#include <string.h>

#define MAX 100

char history[MAX][100];
int top = -1;

// Push a webpage onto the stack
void visitPage(char url[]) {
    if (top == MAX - 1) {
        printf("History is full.\n");
        return;
    }

    strcpy(history[++top], url);
    printf("Visited: %s\n", url);
}

// Go back to the previous webpage
void back() {
    if (top <= 0) {
        printf("No previous page available.\n");
        return;
    }

    printf("Going back from: %s\n", history[top]);
    top--;

    printf("Current page: %s\n", history[top]);
}

// Display browsing history
void displayHistory() {
    int i;

    if (top == -1) {
        printf("History is empty.\n");
        return;
    }

    printf("\n===== Browser History =====\n");

    for (i = top; i >= 0; i--) {
        printf("%s\n", history[i]);
    }
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n===== Browser =====");
        printf("\n1. Visit Page");
        printf("\n2. Back");
        printf("\n3. Display History");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf(" %[^\n]", url);
                visitPage(url);
                break;

            case 2:
                back();
                break;

            case 3:
                displayHistory();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

