/*
Create a C++ program to search for a value in a singly linked list, using non-tail recursion?
*/
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

    bool RecursioninLL(Node *tem,int key)
    {
        if (!tem) return false;

        if(tem->data==key)
        return true;

        return RecursioninLL(tem->next,key);
    }

 
    bool SearchValue(int key)
    {
        Node * temp=head;
        RecursioninLL(temp,key);
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
    int Key;
    cout<<"Enter Key : ";
    cin>>Key;
    if (list.SearchValue(Key))
        cout << "Value " << Key << " found in the list." << endl;
    else
        cout << "Value " << Key << " not found in the list." << endl;

}