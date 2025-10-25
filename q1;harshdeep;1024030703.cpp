#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node deleted.\n";
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) return;
        Node* temp = head;
        while (true) {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "Node not found!\n";
    }

    void insertBefore(int key, int val) {
        if (head == NULL) return;
        Node* temp = head;
        while (true) {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head)
                    head = newNode;
                return;
            }
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "Node not found!\n";
    }

    void deleteNode(int key) {
        if (head == NULL) return;
        Node* temp = head;
        while (true) {
            if (temp->data == key) {
                if (temp->next == temp) { delete temp; head = NULL; return; }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                delete temp;
                cout << "Node deleted.\n";
                return;
            }
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "Node not found!\n";
    }

    void searchNode(int key) {
        if (head == NULL) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        int pos = 1;
        while (true) {
            if (temp->data == key) { cout << "Node found at position " << pos << endl; return; }
            temp = temp->next;
            pos++;
            if (temp == head) break;
        }
        cout << "Node not found!\n";
    }

    void display() {
        if (head == NULL) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        cout << "List: ";
        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << endl;
    }
};

int main() {
    int choice, type, val, key;
    DoublyLinkedList dll;
    CircularDoublyLinkedList cdll;

    cout << "Select List Type:\n1. Doubly Linked List\n2. Circular Doubly Linked List\nChoice: ";
    cin >> type;

    while (true) {
        cout << "\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert After Node\n4. Insert Before Node\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 0) break;

        if (choice == 1) { cout << "Enter value: "; cin >> val; if (type == 1) dll.insertAtBeginning(val); else cdll.insertAtBeginning(val); }
        else if (choice == 2) { cout << "Enter value: "; cin >> val; if (type == 1) dll.insertAtEnd(val); else cdll.insertAtEnd(val); }
        else if (choice == 3) { cout << "Enter key after which to insert: "; cin >> key; cout << "Enter value: "; cin >> val; if (type == 1) dll.insertAfter(key,val); else cdll.insertAfter(key,val); }
        else if (choice == 4) { cout << "Enter key before which to insert: "; cin >> key; cout << "Enter value: "; cin >> val; if (type == 1) dll.insertBefore(key,val); else cdll.insertBefore(key,val); }
        else if (choice == 5) { cout << "Enter node to delete: "; cin >> key; if (type == 1) dll.deleteNode(key); else cdll.deleteNode(key); }
        else if (choice == 6) { cout << "Enter node to search: "; cin >> key; if (type == 1) dll.searchNode(key); else cdll.searchNode(key); }
        else if (choice == 7) { if (type == 1) dll.display(); else cdll.display(); }
        else { cout << "Invalid choice!\n"; }
    }

    cout << "Exiting program.\n";
    return 0;
}

