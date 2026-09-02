
#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    int queue[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    // Add customer request
    void enqueue(int request)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "\nQueue is FULL!";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = request;
        cout << "\nRequest " << request << " added.";
    }

    // Remove customer request
    void dequeue()
    {
        if (front == -1)
        {
            cout << "\nQueue is EMPTY!";
            return;
        }

        cout << "\nRequest " << queue[front] << " is being handled.";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    // Display requests
    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is EMPTY!";
            return;
        }

        cout << "\nPending customer requests: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
    }
};

int main()
{
    CircularQueue normalQueue;
    CircularQueue priorityQueue;

    int choice, request;

    do
    {
        cout << "\n\n===== CALL CENTER REQUEST SYSTEM =====";
        cout << "\n1. Add Normal Customer Request";
        cout << "\n2. Add Priority Customer Request";
        cout << "\n3. Handle Priority Request";
        cout << "\n4. Handle Normal Request";
        cout << "\n5. Display Priority Requests";
        cout << "\n6. Display Normal Requests";
        cout << "\n7. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter request number: ";
            cin >> request;
            normalQueue.enqueue(request);
            break;

        case 2:
            cout << "\nEnter priority request number: ";
            cin >> request;
            priorityQueue.enqueue(request);
            break;

        case 3:
            priorityQueue.dequeue();
            break;

        case 4:
            normalQueue.dequeue();
            break;

        case 5:
            priorityQueue.display();
            break;

        case 6:
            normalQueue.display();
            break;

        case 7:
            cout << "\nProgram ended.";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 7);

    return 0;
}

