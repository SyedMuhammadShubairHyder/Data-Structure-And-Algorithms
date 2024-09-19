/*Give an efficient algorithm for concatenating two doubly linked lists L and M, with head and tail
preserved nodes, into a single list that contains all the nodes of L followed by all the nodes of M.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void AddEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void Display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
            if (temp != NULL) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    void Concatenate(DoublyLinkedList& append) {
        if (head == NULL) {
            head = append.head;
            tail = append.tail;
        } else if (append.head != NULL) {
            tail->next = append.head;
            append.head->prev = tail;
            tail = append.tail;
        }
        if (tail != NULL) {
            tail->next = NULL;
        }
    }
};

int main() {
    DoublyLinkedList L, M;
    int n, value;
    cout << "Enter number of nodes for List L : ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        L.AddEnd(value);
    }

   
    cout << "Enter number of nodes for List M : ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        M.AddEnd(value);
    }

    
    cout << "List L:" << endl;
    L.Display();

    cout << "List M:" << endl;
    M.Display();

    L.Concatenate(M);

    cout << "After concatenation:" << endl;
    L.Display();

    return 0;
}
