/*Create a circular link list and perform the mentioned tasks:
i. Insert a new node at the end of the list.
ii. Insert a new node at the beginning of list.
iii. Insert a new node at given position.
iv. Delete any node.
v. Print the complete circular link list.*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class CircularList
{

    Node *head;
    Node *tail;

public:
    CircularList() : head(NULL), tail(NULL) {};

    void Display()
    {
        if (head == NULL)
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

    void AddEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {

            tail->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void AddStart(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }


    void AddPos(int pos,int val)
    {
        if(pos==0)
        {
            AddStart(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        int currPos = 0;
        
        while(currPos<pos-1 && temp->next!=head)
        {
            temp=temp->next;
            currPos++;
        }

      
        newNode->next = temp->next;
        temp->next = newNode;
        
        if(temp->next==head)
        tail=newNode;
    }

    void DeleteFirst() {
        if (head == NULL) return;
 
        Node *temp = head;
 
        if(head==tail)
        {
            head=NULL;
            tail=NULL;
        }
        else{
            head = head->next;
            tail->next=head;
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
    Node *prev = NULL;
    int currPos = 0;

    while (curr->next != head && currPos < pos) {
        prev = curr;
        curr = curr->next;
        currPos++;
    }

    if (currPos != pos) {
        cout << "Position Not Found" << endl;
        return;
    }

    if (curr->next == head) { 
        prev->next = head; 
        tail = prev; 
    } else {
        prev->next = curr->next; 
    }

    delete curr;
}


};

int main()
{
    CircularList cl;
    cl.AddEnd(1);
    cl.AddEnd(2);
    cl.AddEnd(3);
    cl.AddStart(0);
    cl.AddPos(2,9);    
    cout << "Circular List"<<endl;
    cl.Display();
    cl.DeletePos(0);
    cl.Display();
    return 0;
}