#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayQueue {
private:
    string queue[MAX];
    int front, rear;

public:
    // Constructor
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue: Add a reservation request
    void enqueue(string request) {
        if (rear == MAX - 1) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = request;

        cout << "Request added: " << request << endl;
    }

    // Dequeue: Process the first reservation request
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Request processed: " << queue[front] << endl;
        front++;

        // Reset queue when all requests are processed
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Display all reservation requests
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Ticket Reservation Queue:" << endl;

        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
};

int main() {
    ArrayQueue ticketQueue;

    // Enqueue reservation requests
    ticketQueue.enqueue("Reservation for Rahul - Train 101");
    ticketQueue.enqueue("Reservation for Priya - Train 102");
    ticketQueue.enqueue("Reservation for Amit - Train 103");
    ticketQueue.enqueue("Reservation for Sneha - Train 104");

    // Display queue
    cout << "\n";
    ticketQueue.display();

    // Dequeue requests
    cout << "\nProcessing requests:\n";
    ticketQueue.dequeue();
    ticketQueue.dequeue();

    // Display remaining requests
    cout << "\nRemaining requests:\n";
    ticketQueue.display();

    return 0;
}
