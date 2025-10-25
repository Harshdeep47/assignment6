#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
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
    }

    bool isCircular() {
        if (head == NULL) return false;
        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;
        return (temp == head);
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);

    if (ll.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";

    return 0;
}

