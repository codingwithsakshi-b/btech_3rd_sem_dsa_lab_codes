#include <iostream>
using namespace std;

const int MAX = 100;

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue overflow!" << endl;
        return;
    }

    if (isEmpty())
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow!" << endl;
        return;
    }

    cout << "Deleted value: " << queue[front] << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; ; i = (i + 1) % MAX) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
    }
    cout << endl;
}

int main() {
    int choice, value;

    cout << "1. Insert (Enqueue)\n"
         << "2. Delete (Dequeue)\n"
         << "3. Traverse (Display)\n"
         << "4. Exit\n";

    do {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
