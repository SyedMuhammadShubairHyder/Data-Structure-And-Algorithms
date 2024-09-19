/*Given a linked list (input by user), you have to perform the following task:

i. Extract the alternative nodes starting from second node.
ii. Reverse the extracted list.
iii. Append the extracted list at the end of the original list.
Note: Try to solve the problem without using any extra memory.
Example:
Input:
LinkedList = 10-&gt;4-&gt;9-&gt;1-&gt;3-&gt;5-&gt;9-&gt;4
Output:
10 9 3 9 4 5 1 4
Explanation:
Alternative nodes in the given linked list are 4,1,5,4. Reversing the alternative nodes from the given list,
and then appending them to the end of the list results in a list 10-&gt;9-&gt;3-&gt;9-&gt;4-&gt;5-&gt;1-&gt;4.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyLL {
    Node *head;
    
public:
    DoublyLL() : head(NULL) {}
    
    void AddEnd(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    
    void Display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
            if (temp != NULL) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
 
    Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    return prev;
}
    void Process() {
        if (head == NULL) return;  

        Node *curr = head->next;        
        
        Node *AlterHead = NULL;
        Node *AlterTail = NULL;
        
         
        
        
        
        

        while (curr != NULL) {            
            Node *newNode = new Node(curr->data);
            
            if (AlterHead == NULL) {
                AlterHead = newNode;
                AlterTail =AlterHead;
            } else {
                AlterTail->next = newNode;
                newNode->prev = AlterTail;
                AlterTail = newNode;
            }
               curr = curr->next;   
            if (curr != NULL) {
                curr = curr->next;
            }
        }
        
   
   
   
        Node *RemainHead=NULL;
        Node * RemainTail=NULL;
        
            curr=head;

           Node *temp = AlterHead;



        while(curr!=NULL)
        {
            if(curr->data!=temp->data)
            {
            Node *newNode = new Node(curr->data);
            
            if (RemainHead == NULL) {
                RemainHead = newNode;
                RemainTail =RemainHead;
            } else {
                RemainTail->next = newNode;
                newNode->prev = RemainTail;
                RemainTail = newNode;
            }
               curr = curr->next;   
            if (curr != NULL) {
                curr = curr->next;
            }
            }

        }
    




        AlterHead=reverse(AlterHead);
        RemainTail->next=AlterHead;
        AlterHead->prev=RemainTail;
        head=RemainHead;
         }


};

int main() {
DoublyLL dll;

    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values for the nodes:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        dll.AddEnd(value);
    }

    cout << "Original List:" << endl;
    dll.Display();

    dll.Process();

    cout << "Processed List:" << endl;
    dll.Display();

    return 0;}
