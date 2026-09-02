#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    struct Song *prev;
    struct Song *next;
};

struct Song *head = NULL;
struct Song *current = NULL;

// Add a song to the end of the playlist
void addSong() {
    struct Song *newSong, *temp;

    newSong = (struct Song *)malloc(sizeof(struct Song));

    printf("Enter song title: ");
    scanf(" %[^\n]", newSong->title);

    printf("Enter artist name: ");
    scanf(" %[^\n]", newSong->artist);

    newSong->prev = NULL;
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
        current = head;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newSong;
        newSong->prev = temp;
    }

    printf("Song added successfully.\n");
}

// Display playlist from beginning to end
void displayForward() {
    struct Song *temp = head;

    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n===== Playlist (Forward) =====\n");

    while (temp != NULL) {
        printf("Song: %s | Artist: %s\n",
               temp->title, temp->artist);
        temp = temp->next;
    }
}

// Display playlist from end to beginning
void displayBackward() {
    struct Song *temp = head;

    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    // Move to the last song
    while (temp->next != NULL)
        temp = temp->next;

    printf("\n===== Playlist (Backward) =====\n");

    while (temp != NULL) {
        printf("Song: %s | Artist: %s\n",
               temp->title, temp->artist);
        temp = temp->prev;
    }
}

// Move to the next song
void nextSong() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    if (current->next != NULL) {
        current = current->next;
        printf("Now Playing: %s - %s\n",
               current->title, current->artist);
    } else {
        printf("Already at the last song.\n");
    }
}

// Move to the previous song
void previousSong() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    if (current->prev != NULL) {
        current = current->prev;
        printf("Now Playing: %s - %s\n",
               current->title, current->artist);
    } else {
        printf("Already at the first song.\n");
    }
}

// Show currently selected song
void currentSong() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\nCurrently Playing:\n");
    printf("Song   : %s\n", current->title);
    printf("Artist : %s\n", current->artist);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Music Playlist =====");
        printf("\n1. Add Song");
        printf("\n2. Next Song");
        printf("\n3. Previous Song");
        printf("\n4. Display Forward");
        printf("\n5. Display Backward");
        printf("\n6. Current Song");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;

            case 2:
                nextSong();
                break;

            case 3:
                previousSong();
                break;

            case 4:
                displayForward();
                break;

            case 5:
                displayBackward();
                break;

            case 6:
                currentSong();
                break;

            case 7:
                printf("Exiting playlist.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

