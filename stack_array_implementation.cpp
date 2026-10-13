#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int top;
    int data[MAX];

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return data[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    cout << "1. Push\n"
         << "2. Pop\n"
         << "3. Peek\n"
         << "4. Display\n"
         << "5. Exit\n";

    do {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                cout << "Popped value: " << s.pop() << endl;
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
