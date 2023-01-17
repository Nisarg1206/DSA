#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev, *next;
} *head = NULL, *tail = NULL;


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
    }
}


// Inserting Node in Doubly Linked List
void InsertNode()
{
    int t;
    cout << "Enter position for inserting in linked list" << endl;
    cin >> t;
    cout << "Enter value for inserting node" << endl;
    node *temp = new node();
    cin >> temp->data;
    temp->next = NULL;
    temp->prev = NULL;
    if (t == 1)
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        int i = 2;
        node *a = head;
        while (i < t)
        {
            a = a->next;
            i++;
        }
        temp->prev = a;
        temp->next = a->next;
        a->next = temp;
        temp->next->prev = temp;
        if (temp->next == NULL)
        {
            tail = temp;
        }
        cout << "End element is " << tail->data << endl;
    }
}


// Deleting Node from Linked List
void deleteNode()
{
    int t;
    cout << "Enter position to delete node" << endl;
    cin >> t;
    node *b = head, *a = NULL;
    if (t == 1)
    {
        b = b->next;
        b->prev = NULL;
        free(head);
        head = b;
    }
    else
    {
        int i = 2;
        while (i <= t)
        {
            a = b;
            b = b->next;
            i++;
        }
        if (b->next == NULL)
        {
            tail = a;
            free(b);
            tail->next = NULL;
        }
        else
        {
            a->next = b->next;
            b = b->next;
            b->prev = a;
        }
    }
    cout << "End element is " << tail->data << endl;
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
    InsertNode();
    printLinkedList();
    deleteNode();
    printLinkedList();
}