#include <iostream>
#include <string>
using namespace std;

#define MAX 100


class ArrayQueue {
    string queue[MAX];
    int front, rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }
    
    void enqueue(string request) {
        if (rear == MAX - 1) {
            cout << "Array Queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = request;

        cout << "Request added: " << request << endl;
    }

    // Remove a reservation request
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Array Queue is empty!" << endl;
            return;
        }

        cout << "Request processed: " << queue[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Array Queue is empty!" << endl;
            return;
        }
        cout << "Array Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " | ";
        }
        cout << endl;
    }
};

