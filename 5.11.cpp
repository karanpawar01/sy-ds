#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayStack {
    string pages[MAX];
    int top = -1;

public:
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(string page) {
        if (!isFull()) pages[++top] = page;
        else cout << "Stack Overflow!\n";
    }

    string pop() {
        return isEmpty() ? "Stack Underflow" : pages[top--];
    }

    string peek() {
        return isEmpty() ? "" : pages[top];
    }

    void display() {
        cout << "History: ";
        for (int i = 0; i <= top; i++) 
            cout << pages[i] << (i < top ? " -> " : "");
        cout << endl;
    }
};

int main() {
    ArrayStack stack;
    string sites[] = {"Home", "Google", "YouTube", "Wikipedia"};

    for (string site : sites) {
        cout << "Visiting: " << site << endl;
        stack.push(site);
    }

    cout << "\n";
    stack.display();

    cout << "\nBack button pressed.\n";
    stack.pop();
    cout << "Current: " << stack.peek() << endl;

    stack.display();
    return 0;
}