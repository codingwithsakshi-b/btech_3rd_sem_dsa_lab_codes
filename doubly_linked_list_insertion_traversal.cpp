#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head != nullptr)
        head->previous = newNode;
    head = newNode;
    cout << "Inserted at the beginning." << endl;
}

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
        newNode->previous = current;
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

    Node* current = head;
    for (int currentPosition = 1;
         current != nullptr && currentPosition < position - 1;
         ++currentPosition) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position. The list is not long enough." << endl;
        return;
    }

    Node* newNode = new Node{value, current, current->next};
    if (current->next != nullptr)
        current->next->previous = newNode;
    current->next = newNode;
    cout << "Inserted at position " << position << "." << endl;
}

void traverseForward() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Forward: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void traverseBackward() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
        current = current->next;

    cout << "Backward: ";
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->previous;
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
         << "4. Traverse forward\n"
         << "5. Traverse backward\n"
         << "6. Exit\n";

    do {
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            clearList();
            return 1;
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "Invalid value." << endl;
                    clearList();
                    return 1;
                }

                if (choice == 1) {
                    insertAtBeginning(value);
                } else if (choice == 2) {
                    insertAtEnd(value);
                } else {
                    cout << "Enter position (starting from 1): ";
                    if (!(cin >> position)) {
                        cout << "Invalid position." << endl;
                        clearList();
                        return 1;
                    }
                    insertAtPosition(value, position);
                }
                break;
            case 4:
                traverseForward();
                break;
            case 5:
                traverseBackward();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    clearList();
    return 0;
}
