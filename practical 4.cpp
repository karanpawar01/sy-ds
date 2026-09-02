#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team {
    char name[50];
    struct Team *next;
};

struct Team *head = NULL;
struct Team *current = NULL;

// Add a team to the circular linked list
void addTeam() {
    struct Team *newTeam, *temp;

    newTeam = (struct Team *)malloc(sizeof(struct Team));

    printf("Enter team name: ");
    scanf(" %[^\n]", newTeam->name);

    if (head == NULL) {
        head = newTeam;
        newTeam->next = head;
        current = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newTeam;
        newTeam->next = head;
    }

    printf("Team added successfully.\n");
}

// Display all teams
void displayTeams() {
    struct Team *temp;

    if (head == NULL) {
        printf("No teams available.\n");
        return;
    }

    temp = head;

    printf("\n===== Tournament Teams =====\n");

    do {
        printf("%s\n", temp->name);
        temp = temp->next;
    } while (temp != head);
}

// Schedule the next team
void nextTeam() {
    if (current == NULL) {
        printf("No teams available.\n");
        return;
    }

    printf("Current team: %s\n", current->name);

    current = current->next;

    printf("Next team: %s\n", current->name);
}

// Simulate round-robin scheduling
void simulateRoundRobin(int rounds) {
    struct Team *team1, *team2;
    int i;

    if (head == NULL || head->next == head) {
        printf("At least two teams are required.\n");
        return;
    }

    printf("\n===== Round Robin Schedule =====\n");

    team1 = head;

    for (i = 1; i <= rounds; i++) {
        team2 = team1->next;

        printf("Round %d: %s vs %s\n",
               i, team1->name, team2->name);

        team1 = team1->next;
    }
}

// Main function
int main() {
    int choice, rounds;

    while (1) {
        printf("\n===== Tournament Scheduler =====");
        printf("\n1. Add Team");
        printf("\n2. Display Teams");
        printf("\n3. Move to Next Team");
        printf("\n4. Simulate Round Robin");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTeam();
                break;

            case 2:
                displayTeams();
                break;

            case 3:
                nextTeam();
                break;

            case 4:
                printf("Enter number of rounds: ");
                scanf("%d", &rounds);
                simulateRoundRobin(rounds);
                break;

            case 5:
                printf("Exiting tournament scheduler.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

