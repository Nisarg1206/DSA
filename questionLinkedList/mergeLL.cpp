#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *NAdd;
} *head1 = NULL, *head2 = NULL, *head3 = NULL, *tail2 = NULL, *tail3 = NULL, *tail1 = NULL;

void createLL1()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter data " << endl;
        node *p = new node();
        cin >> d;
        p->data = d;
        p->NAdd = NULL;
        if (head1 == NULL)
        {
            head1 = p;
            tail1 = p;
        }
        else
        {
            tail1->NAdd = p;
            tail1 = tail1->NAdd;
        }
        cout << "Do you want to add more node" << endl;
        cin >> t;
    }
}

void createLL2()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter data " << endl;
        node *p = new node();
        cin >> d;
        p->data = d;
        p->NAdd = NULL;
        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
        }
        else
        {
            tail2->NAdd = p;
            tail2 = tail2->NAdd;
        }
        cout << "Do you want to add more node" << endl;
        cin >> t;
    }
}

void mergeLL()
{
    node *p = head1, *q = head2;
    if (head3==NULL)
    {
        if (p->data < q->data)
        {
            head3 = tail3 = p;
            p = p->NAdd;
            tail3->NAdd = NULL;
        }
        else
        {
            head3 = tail3 = q;
            q = q->NAdd;
            tail3->NAdd = NULL;
        }
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            tail3->NAdd = p;
            tail3=tail3->NAdd;
            p = p->NAdd;
            tail3->NAdd = NULL;
        }
        else
        {
            tail3->NAdd = q;
            tail3=tail3->NAdd;
            q = q->NAdd;
            tail3->NAdd = NULL;
        }
    }
    if (p != NULL)
    {
        tail3->NAdd = p;
    }
    else
    {
        tail3->NAdd = q;
    }
}

void printLL(node *p)
{
    cout << "Linked list is " << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->NAdd;
    }
}

int main()
{
    createLL1();
    printLL(head1);
    createLL2();
    printLL(head2);
    mergeLL();
    printLL(head3);
}