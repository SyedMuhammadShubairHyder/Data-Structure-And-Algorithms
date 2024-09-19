/*Create a circular Double link list and perform the mentioned tasks:
i. Insert a new node at the end of the list.
ii. Insert a new node at the beginning of list.
iii. Insert a new node at given position.
iv. Delete any node.
v. Print the complete circular double link list.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyCircularList {
    Node *head;
    Node *tail;

public:
    DoublyCircularList() : head(NULL), tail(NULL) {}

    void Display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) {
                cout << " -> ";
            }
        } while (temp != head);
        cout << endl;
    }

    void AddEnd(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void AddStart(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddPos(int pos, int val) {
        if (pos == 0) {
            AddStart(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        int currPos = 0;

        while (currPos < pos - 1 && temp->next != head) {
            temp = temp->next;
            currPos++;
        }

        if (currPos != pos - 1) {
            cout << "Position Not Found" << endl;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        if (newNode->next == head) {
            tail = newNode;
        }
    }

    void DeleteFirst() {
        if (head == NULL) return;

        Node *temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
    }

    void DeletePos(int pos) {
        if (head == NULL) return;

        if (pos == 0) {
            DeleteFirst();
            return;
        }

        Node *curr = head;
        int currPos = 0;

        while (currPos < pos && curr->next != head) {
            curr = curr->next;
            currPos++;
        }

        if (currPos != pos) {
            cout << "Position Not Found" << endl;
            return;
        }

        if (curr->next == head) {
            curr->prev->next = head;
            head->prev = curr->prev;
            tail = curr->prev;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }
};

int main() {
    DoublyCircularList cl;
    cl.AddEnd(1);
    cl.AddEnd(2);
    cl.AddEnd(3);
    cl.AddStart(0);
    cl.AddPos(2, 9);    
    cout << "Doubly Circular List" << endl;
    cl.Display();
    cl.DeletePos(2);
    cl.Display();
    return 0;
}
