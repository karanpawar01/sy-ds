#include <stdio.h>
#include <string.h>

#define MAX 5

struct Reservation {
    int id;
    char name[50];
    int tickets;
};

struct Queue {
    struct Reservation data[MAX];
    int front;
    int rear;
};

// Initialize queue
void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

// Add reservation
void enqueue(struct Queue *q, struct Reservation r) {
    if (isFull(q)) {
        printf("Reservation queue is full!\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->data[q->rear] = r;

    printf("Reservation request added successfully.\n");
}

// Process reservation
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No reservation requests available.\n");
        return;
    }

    printf("Processing Reservation ID: %d\n", q->data[q->front].id);
    printf("Name: %s\n", q->data[q->front].name);
    printf("Tickets: %d\n", q->data[q->front].tickets);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

// Display reservations
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No reservation requests.\n");
        return;
    }

    printf("\n--- Reservation Queue ---\n");

    for (int i = q->front; i <= q->rear; i++) {
        printf("ID: %d | Name: %s | Tickets: %d\n",
               q->data[i].id,
               q->data[i].name,
               q->data[i].tickets);
    }
}

int main() {
    struct Queue q;
    struct Reservation r;
    int choice;

    initialize(&q);

    while (1) {
        printf("\n--- Ticket Reservation System ---\n");
        printf("1. Add Reservation Request\n");
        printf("2. Process Reservation\n");
        printf("3. Display Requests\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Reservation ID: ");
                scanf("%d", &r.id);

                printf("Enter Customer Name: ");
                scanf("%s", r.name);

                printf("Enter Number of Tickets: ");
                scanf("%d", &r.tickets);

                enqueue(&q, r);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

