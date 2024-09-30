/*
Write a C++ function to find the length of a singly linked list using tail recursion.
*/

// Single LL
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {};
};

class SinglyLL
{
public:
    Node *head;
    SinglyLL() { head = NULL; }

    void print()
    {
        Node *temp;
        temp = head;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void Add(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void Remove()
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
    }

    int RecursioninLL(Node *tem)
    {
        static int count = 0;
        if (!tem)
        {
            int result = count;
            count = 0;
            return result;
        }
        count++;
        return RecursioninLL(tem->next);
    }
    
    
    int sizeofLinkedList()
    {
        Node *temp = head;
        return RecursioninLL(temp);
    }
};

int main()
{
    SinglyLL list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    cout << "Size of linked List is : " << list.sizeofLinkedList();
}