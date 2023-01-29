#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head = NULL, *tail = NULL, *third = NULL, *tail3 = NULL, *tail2 = NULL, *head2 = NULL;

void createLL()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter data for Node" << endl;
        cin >> d;
        Node *p = new Node();
        p->data = d;
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        cout << "Do you want to enter more Node (0/1)" << endl;
        cin >> t;
    }
}

void createLL2()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter data " << endl;
        Node *p = new Node();
        cin >> d;
        p->data = d;
        p->next = NULL;
        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
        }
        else
        {
            tail2->next = p;
            tail2 = tail2->next;
        }
        cout << "Do you want to add more node" << endl;
        cin >> t;
    }
}

class solution
{
public:
    Node *addTwoLists(Node *first, Node *second)
    {
        Node *a = first;
        Node *b = second;
        int n1 = 0, n2 = 0;
        while (a != NULL)
        {
            n1 = 10 * n1 + a->data;
        }
        while (b != NULL)
        {
            n2 = 10 * n2 + b->data;
        }
        int n3 = n1 + n2;
        while (n3 != 0)
        {
            Node *p = new Node();
            p->data = n3 % 10;
            p->next = NULL;
            if (third != NULL)
            {
                third = tail3 = p;
            }
            else
            {
                tail3->next = p;
                tail = tail->next;
            }
            n3 = n3 / 10;
        }
        reverseLL(third);
        return third;
    }

    Node *reverseLL(Node *p)
    {
        Node *a = NULL;
        Node *b = p;
        Node *c = NULL;
        while (a!=NULL)
        {
                c = b->next;
                b->next = a;
                a = b;
                b = c;  
        }
        third = a;
    }
};

void printLL(Node *p)
{
    cout << "Linked list are" << endl;
    while(p!=NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    createLL();
    createLL2();
    solution obj;
    printLL(obj.addTwoLists(head,head2));
}