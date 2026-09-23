#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) {
        url = u;
        next = nullptr;
    }
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string url) {
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            return "Stack Underflow";
        }
        Node* temp = top;
        string poppedUrl = temp->url;
        top = top->next;
        delete temp;
        return poppedUrl;
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }
        return top->url;
    }

    void display() {
        if (isEmpty()) {
            cout << "Browser history is empty.\n";
            return;
        }
        vector<string> history;
        Node* current = top;
        while (current != nullptr) {
            history.push_back(current->url);
            current = current->next;
        }
        cout << "Browser History (Bottom to Top): ";
        for (int i = history.size() - 1; i >= 0; i--) {
            cout << history[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedListStack backStack;
    string sites[] = {"Home", "Google", "YouTube", "Wikipedia"};

    for (string site : sites) {
        cout << "Visiting: " << site << endl;
        backStack.push(site);
    }

    cout << "\n";
    backStack.display();

    cout << "\nBack button pressed.\n";
    backStack.pop();
    cout << "Current page: " << backStack.peek() << endl;

    backStack.display();
    return 0;
}