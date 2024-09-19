/*Given a Double Circular Linked List 1-7-4-2-6-4-5-3-9-8 (You can take your own list as input as well).
Your task is to swap the nodes (not values) given their indexes along with its previous and next pointers.
Input: Enter two nodes keys = 3 7
Output:
Initial Linked List = 1-7-4-2-6-4-5-3-9-8
After Swapping = 1-7-4-3-6-4-5-2-9-8*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyCircularLinkedList
{
    Node *head;

public:
    DoublyCircularLinkedList() : head(NULL) {}

    void AddEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void Display()
    {
        if (!head)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
            {
                cout << " -> ";
            }
        } while (temp != head);
        cout << endl;
    }

    Node *GetNode(int pos)
    {
        if (head == NULL)
            return NULL;

        Node *temp = head;
        int count = 0;

        do
        {
            if (count == pos)
            {
                return temp;
            }
            temp = temp->next;
            count++;
        } while (temp != head);

        return NULL;
    }

    void SwapNodes(int pos1, int pos2)
    {
        if (pos1 == pos2)
            return;

        Node *node1 = GetNode(pos1);
        Node *node2 = GetNode(pos2);

        if (node1 == NULL || node2 == NULL)
        {
            cout << "Position Not Found." << endl;
            return;
        }

        Node *pre1 = node1->prev;
        Node *pre2 = node2->prev;
        Node *next1 = node1->next;
        Node *next2 = node2->next;

        if (next1 == node2)
        {
            pre1->next = node2;
            node2->prev = pre1;
            node2->next = node1;
            node1->prev = node2;
            node1->next = next2;
            next2->prev = node1;
        }
        else if (next2 == node1)
        {
            pre2->next = node1;
            node1->prev = pre2;
            node1->next = node2;
            node2->prev = node1;
            node2->next = next1;
            next1->prev = node2;
        }
        else
        {
            pre1->next = node2;
            next1->prev = node2;
            pre2->next = node1;
            next2->prev = node1;

            node2->prev = pre1;
            node2->next = next1;
            node1->prev = pre2;
            node1->next = next2;
        }

        if (node1 == head)
            head = node2;
        else if (node2 == head)
            head = node1;
    }
};

int main()
{

    DoublyCircularLinkedList dll;

    dll.AddEnd(1);
    dll.AddEnd(7);
    dll.AddEnd(4);
    dll.AddEnd(2);
    dll.AddEnd(6);
    dll.AddEnd(4);
    dll.AddEnd(5);
    dll.AddEnd(3);
    dll.AddEnd(9);
    dll.AddEnd(8);

    cout << "Initial Linked List: ";
    dll.Display();
    int pos1, pos2;
    cout << "Enter two Nodes keys ";
    cin >> pos1 >> pos2;

    dll.SwapNodes(pos1, pos2);
    cout << "After Swapping: ";
    dll.Display();

    return 0;
}
