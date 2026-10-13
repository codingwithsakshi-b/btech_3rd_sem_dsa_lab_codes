#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = newNode;
}

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* nodeToDelete = head;
    head = head->next;
    cout << "Deleted value: " << nodeToDelete->data << endl;
    delete nodeToDelete;
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        cout << "Deleted value: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr)
        current = current->next;

    Node* nodeToDelete = current->next;
    cout << "Deleted value: " << nodeToDelete->data << endl;
    current->next = nullptr;
    delete nodeToDelete;
}

void deleteAtPosition(int position) {
    if (position < 1) {
        cout << "Invalid position. Position must be at least 1." << endl;
        return;
    }

    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    Node* previous = head;
    for (int currentPosition = 1;
         previous != nullptr && currentPosition < position - 1;
         ++currentPosition) {
        previous = previous->next;
    }

    if (previous == nullptr || previous->next == nullptr) {
        cout << "Invalid position. The list is not long enough." << endl;
        return;
    }

    Node* nodeToDelete = previous->next;
    previous->next = nodeToDelete->next;
    cout << "Deleted value at position " << position << ": "
         << nodeToDelete->data << endl;
    delete nodeToDelete;
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

    cout << "First create the list by inserting values at the end.\n"
         << "1. Insert at end\n"
         << "2. Delete at beginning\n"
         << "3. Delete at end\n"
         << "4. Delete at any position (1-based)\n"
         << "5. Traverse (display)\n"
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
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "Invalid value." << endl;
                    clearList();
                    return 1;
                }
                insertAtEnd(value);
                cout << "Inserted at the end." << endl;
                break;
            case 2:
                deleteAtBeginning();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                cout << "Enter position to delete (starting from 1): ";
                if (!(cin >> position)) {
                    cout << "Invalid position." << endl;
                    clearList();
                    return 1;
                }
                deleteAtPosition(position);
                break;
            case 5:
                display();
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
