#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
} *head = NULL, *tail = NULL;

static int k=0;
// Creating Linked List
void createLinkedList()
{
    int t = 1;
    while (t)
    {
        cout << "Enter value for linked list " << endl;
        node *p = new node();
        cin >> p->data;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        cout << "Do you want to add more node in linked list" << endl;
        cin >> t;
        k++;
    }
    tail->next = head;
}


//Inserting node in linked List
void insertNode()
{
    int t;
    cout << "Enter position for inserting node" << endl;
    cin >> t;
    node *p = new node();
    cout << "Enter value for new node" << endl;
    cin >> p->data;
    p->next = NULL;
    if(t==1)
    {
        p->next = head;
        tail->next = p;
        head = p;
    }
    else
    {
        int i = 2;
        node *a = head;
        while(i<t)
        {
            a = a->next;
            i++;
        }
        p->next=a->next;
        a->next = p;
        if(p->next==head)
        {
            tail = p;
        }
    }
    k++;
}


//Deleting Node from linked list
void deleteNode()
{
    cout << "Enter position to delete" << endl;
    int t;
    cin >> t;
    node *a = NULL, *b = head;
    if(t==1)
    {
        b = b->next;
        head = b;
        tail->next = head;
    }
    else
    {
        int i = 2;
        while(i<=t)
        {
            a = b;
            b = b->next;
            i++;
        }
        a->next = b->next;
        if(a->next==head)
        {
            tail = a;
            
        }
    }
    k--;
}

// Printing Linked list
void printLinkedList()
{
    node *p = new node();
    p = head;
    cout << "Total element in linked list is " << k<<endl;
    cout << "Linked List are" << endl;
    do{
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}
int main()
{
    createLinkedList();
    printLinkedList();
    insertNode();
    printLinkedList();
    deleteNode();
    printLinkedList();
}