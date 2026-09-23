#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayStack {
private:
    string pages[MAX];
    int top;

public:
    // Constructor
    ArrayStack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push a webpage onto the stack
    void push(string page) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot visit more pages.\n";
            return;
        }

        pages[++top] = page;
        cout << "Visited: " << page << endl;
    }

    // Pop the most recently visited webpage
    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No previous page.\n";
            return "";
        }

        string page = pages[top--];
        return page;
    }

    // Peek at the top webpage without removing it
    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return "";
        }

        return pages[top];
    }

    // Display all webpages in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\nVisited Webpages (Back Stack):\n";

        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }
};

int main() {
    ArrayStack backStack;

    // Visiting webpages
    backStack.push("Home");
    backStack.push("Google");
    backStack.push("YouTube");
    backStack.push("Wikipedia");

    // Display stack
    backStack.display();

    // Peek operation
    cout << "\nTop webpage (Peek): "
         << backStack.peek() << endl;

    // Pop operation - Back button
    cout << "\nBack button pressed.\n";
    string page = backStack.pop();

    if (!page.empty()) {
        cout << "Going back from: " << page << endl;
    }

    cout << "Current top page: " << backStack.peek() << endl;

    // Display after first back
    backStack.display();

    // Pop again
    cout << "\nBack button pressed.\n";
    page = backStack.pop();

    if (!page.empty()) {
        cout << "Going back from: " << page << endl;
    }

    cout << "Current top page: " << backStack.peek() << endl;

    // Final display
    backStack.display();

    return 0;
}
