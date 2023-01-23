#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev, *next;
} *head = NULL, *tail = NULL;

static int k=0;
// Creating Doubly Linked List
void createLinkedList()
{
    int t = 1;

    while (t)
    {
        cout << "Enter value for linked list" << endl;
        node *p = new node();
        cin >> p->data;
        p->next = NULL;
        p->prev = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
        cout << "Do you want to enter more linked list (0/1)" << endl;
        cin >> t;
        k++;
    }
}


//Reversing Linked list
void reverseLinkedList()
{
    node *a = NULL, *b = head, *c;
    int i = 1;
    while(i<=k)
    {
        if (i == 1)
        {
            c = b->next;
            b->next = a;
            b->prev = c;
            a = b;
            b = c;
            tail = a;
        }
        else
        {
            c = b->next;
            b->next = a;
            b->prev = c;
            a = b;
            b = c;
        }
        i++;
    }
    head = a;
}

// Printing Doubly Linked List
void printLinkedList()
{
    node *p = head;
    cout << "Linked List are " << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{
    createLinkedList();
    printLinkedList();
    reverseLinkedList();
    printLinkedList();
}