#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    cout << "Inserted at the beginning." << endl;
}

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }

    cout << "Inserted at the end." << endl;
}

void insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position. Position must be at least 1." << endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* previous = head;
    for (int currentPosition = 1;
         previous != nullptr && currentPosition < position - 1;
         ++currentPosition) {
        previous = previous->next;
    }

    if (previous == nullptr) {
        cout << "Invalid position. The list is not long enough." << endl;
        return;
    }

    Node* newNode = new Node{value, previous->next};
    previous->next = newNode;
    cout << "Inserted at position " << position << "." << endl;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Singly linked list: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void clearList() {
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
}

int main() {
    int choice, value, position;

    cout << "1. Insert at beginning\n"
         << "2. Insert at end\n"
         << "3. Insert at any position (1-based)\n"
         << "4. Traverse (display)\n"
         << "5. Exit\n";

    do {
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            clearList();
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "Invalid value." << endl;
                    clearList();
                    return 1;
                }
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "Invalid value." << endl;
                    clearList();
                    return 1;
                }
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "Invalid value." << endl;
                    clearList();
                    return 1;
                }
                cout << "Enter position (starting from 1): ";
                if (!(cin >> position)) {
                    cout << "Invalid position." << endl;
                    clearList();
                    return 1;
                }
                insertAtPosition(value, position);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    clearList();
    return 0;
}
