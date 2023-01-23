#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *NAdd;
} *head = NULL, *tail = NULL;

// Create Linked list
void createLL()
{
    int d, t = 1;
    while (t)
    {
        cout << "Enter data for node" << endl;
        cin >> d;
        node *p = new node();
        p->data = d;
        p->NAdd = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->NAdd = p;
            tail = tail->NAdd;
        }
        cout << "Do you want to enter more node(0/1)" << endl;
        cin >> t;
    }
}

node *reverseLLKGroup(node *head,int k)
{
    int i = 0;if(head==NULL)
    {
        return NULL;
    }
    node *p = NULL, *r = NULL, *q = head;
    while (q != NULL && i < k)
    {
        p = q->NAdd;
        q->NAdd = r;
        r = q;
        q = p;
        i++;
    }
    if(p!=NULL)
    {
        head->NAdd = reverseLLKGroup(p, k);
    }
    return r;
}

void printLL(node *p)
{
    cout << "Linked list are" << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->NAdd;
    }
}
int main()
{
    createLL();
    printLL(head);
    int k;
    cout << "Reverse in group of " << endl;
    cin >> k;
    node *z = reverseLLKGroup(head,k);
    printLL(z);
}