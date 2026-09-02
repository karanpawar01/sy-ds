#include <stdio.h>
#define MAX 100

typedef struct {
    int ticketNo;
    char name[50];
} Request;

Request queue[MAX];
int front = -1, rear = -1;

void enqueue(Request r) {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = r;
    printf("Reservation request added.\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Processing request: Ticket %d, Name: %s\n",
           queue[front].ticketNo, queue[front].name);

    front++;

    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nReservation Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("Ticket: %d, Name: %s\n",
               queue[i].ticketNo, queue[i].name);
    }
}

int main() {
    Request r1 = {101, "Rahul"};
    Request r2 = {102, "Priya"};
    Request r3 = {103, "Amit"};

    enqueue(r1);
    enqueue(r2);
    enqueue(r3);

    display();

    dequeue();
    display();

    return 0;
}

