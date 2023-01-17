#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *NAdd;
} *head = NULL, *tail = NULL;

static int k = 0;
// Creating Linked list
void createLinkedList()
{
    int d, t = 1;
    while (t == 1)
    {
        cout << "Enter value for linked list" << endl;
        cin >> d;
        node *p = new node();
        p->data = d;
        p->NAdd = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->NAdd = p;
            tail = tail->NAdd;
        }
        cout << "Do you want to enter more linked list (0/1)" << endl;
        cin >> t;
        k++;
    }
}

// Reverse Linked List
void reverseLL()
{
    node *a = NULL, *b=head,*c;
    int i = 1;
    while (i <= k)
    {
        if (i == 1)
        {
            c = b->NAdd;
            b->NAdd = a;
            a = b;
            b = c;
            tail = a;
        }
        else
        {
            c = b->NAdd;
            b->NAdd = a;
            a = b;
            b = c;
        }
        i++;
    }
    head = a;
}

// For printing linked list
void printLinkedList()
{
    node *temp = head;
    cout << "Linked List are" << endl;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->NAdd;
    }
}

int main()
{
    createLinkedList();
    printLinkedList();
    reverseLL();
    printLinkedList();
}