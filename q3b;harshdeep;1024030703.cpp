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

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int size() {
        if (head == NULL) return 0;
        int count = 1;
        Node* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(5);
    cll.insertAtEnd(15);
    cll.insertAtEnd(25);
    cll.insertAtEnd(35);

    cout << "Size of Circular Linked List: " << cll.size() << endl;
    return 0;
}

