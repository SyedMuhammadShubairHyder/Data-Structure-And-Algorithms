/*Given a Linked List (input by user) of integers or string (as per your choice), write a function to check if
the entirety of the linked list is a palindrome or not.*/
#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class SinglyLL
{
public:
    Node *head;

    SinglyLL() : head(NULL) {}

    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void AddEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool checkPalindrome()
    {
        if (head == NULL || head->next == NULL)
            return true;

        Node *curr = head;
        int count = 0;

        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        int middle = count / 2;
        curr = head;
        Node *prev = NULL;
        for (int i = 0; i < middle; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        Node *End;
        if (count % 2 == 0)
            End = curr; 
        else
            End = curr->next;        
        End = reverse(End);

  
        Node *Start = head;
        Node *temp =End;

        while (temp != NULL)
        {
            if (Start->data != temp->data)
                return false;
            
            Start = Start->next;
            temp = temp->next;
        }

        reverse(End);

        return true; 
    }
};

int main()
{
    SinglyLL LL;

    LL.AddEnd('B');
    LL.AddEnd('O');
    LL.AddEnd('R');
    LL.AddEnd('R');
    LL.AddEnd('O');
    LL.AddEnd('W');
    LL.AddEnd('O');
    LL.AddEnd('R');
    LL.AddEnd('R');
    LL.AddEnd('O');
    LL.AddEnd('B');
    LL.Display();
    if (LL.checkPalindrome())
        cout << "List is Palindrome  " << endl;
    else
        cout << "List is Not Palindrome  " << endl;

    return 0;
}
