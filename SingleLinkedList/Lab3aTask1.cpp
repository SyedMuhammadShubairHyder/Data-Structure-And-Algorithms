/* Solve the following problem using a Singly Linked List:
Given a Linked List of integers (input by user), write a function to modify the linked list such that all even
numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and
odd numbers same.*/
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    
    Node(int val): data(val), next(NULL) {}
};

class SinglyLL {
    public:
    Node *head;
    
    SinglyLL() : head(NULL) {}
    
    void Display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout <<"NULL"<< endl;
    }


    void AddEnd(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) { 
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

void evenOdd(){
    if (head == NULL || head->next == NULL) return;

    Node * evenHead=NULL;
    Node * evenTail=NULL;
    Node * oddHead=NULL;
    Node * oddTail=NULL;
   
   
    Node * curr=head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead =curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else
        {
            if (oddHead == NULL) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }



    if(evenHead!=NULL)
    evenTail->next=NULL;

    if(oddHead!=NULL)
    oddTail->next=NULL;
    
    
    if(evenHead==NULL)
    head=oddHead;
    if(oddHead==NULL)
    head=evenHead;
    else 
    {
        head=evenHead;
        evenTail->next=oddHead;
        head=evenHead;
    }
}
};


int main()
{
    SinglyLL LL;
    LL.AddEnd(17);
    LL.AddEnd(15);
    LL.AddEnd(8);
    LL.AddEnd(12);
    LL.AddEnd(10);
    LL.AddEnd(5);
    LL.AddEnd(4);
    LL.AddEnd(1);
    LL.AddEnd(7);
    LL.AddEnd(6);

    LL.Display();
    LL.evenOdd();
    cout<<"Sorted List "<<endl;
    LL.Display();
}